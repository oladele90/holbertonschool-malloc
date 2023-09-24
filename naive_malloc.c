#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

size_t chunker(size_t size)
{
    for (; size % 8 != 0; size++)
        ;
    return (size);
        
}

void *naive_malloc(size_t size)
{
    void *start_brk = sbrk(0), *new_brk;
    static size_t pagesize = 0;
    if(pagesize < size)
    {
        sbrk(_SC_PAGESIZE);
        pagesize += sysconf(_SC_PAGESIZE);
    }
    size = chunker(size);
    sbrk(size + sizeof(size_t));
    new_brk = sbrk(0);
    *((size_t *)start_brk) = size + sizeof(size_t);
    start_brk = (char *)new_brk - size;
    pagesize -= (size + sizeof(size_t));
    return(start_brk);
}