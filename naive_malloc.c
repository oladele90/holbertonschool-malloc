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
    static void *start_brk;
    void *new_brk;
    static size_t page;

    if (!start_brk)
        start_brk = sbrk(0);
    size = chunker(size);
    if (page < size)
    {
        sbrk(sysconf(_SC_PAGESIZE));
        page += (sysconf(_SC_PAGESIZE));
    }
    *((size_t *)start_brk) = size + sizeof(size_t);
    new_brk = sbrk(*(size_t *)start_brk);
    start_brk = (char *)new_brk - size;
    return(start_brk);
}