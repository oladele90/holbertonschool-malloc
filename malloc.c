#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

size_t chunker(size_t size)
{
    for (; size % 8 != 0; size++)
        ;
    return (size);
        
}

void *_malloc(size_t size)
{
    
    static void *start_brk;
    void * new_brk;
    size_t pagesize = sysconf(_SC_PAGESIZE);
    static size_t page;

    if (!start_brk)
        start_brk = sbrk(0);
    while (page < size)
    {
        page += pagesize;
        sbrk(pagesize);
    }
    size = chunker(size);
    *((size_t *)start_brk) = size + sizeof(size_t);
    new_brk = (char *)start_brk + sizeof(size_t);
    start_brk = (char *) start_brk + size + sizeof(size_t);
    page -= (size + sizeof(size_t));
    return(new_brk);
}