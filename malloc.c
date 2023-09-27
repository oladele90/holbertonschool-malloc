#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

size_t chunker(size_t size)
{
    for (; size % 8 != 0; size++)
        ;
    return (size + sizeof(size_t));
        
}

void *_malloc(size_t size)
{
    Chunk_t *heap_start;
    static void *start_brk, *chunk_arr[4096];
    void * new_brk;
    size_t pagesize = sysconf(_SC_PAGESIZE);
    static size_t page, chunks_available;

    size = chunker(size);
    if (!start_brk)
        start_brk = sbrk(0);
    if (chunks_available)
    {
        for (i = 0; i < chunk_available; i++)
		{
			heap_start = ((Chunk_t *)chunks[i]) - 1;
			if (heap_start->status == 0 && heap_start->ChunkSize >= size)
			{
				heap_start->status = size;
				return (chunks[i]);
			}
		}
    }
        
    while (page < size)
    {
        page += pagesize;
        sbrk(pagesize);
    }
    chunk_available++;
    new_brk = start_brk;
    start_brk = (char *) start_brk + size + sizeof(Chunk_t);
    heap_start = (Chunk_t *)new_brk;
    heap_start->status = size;
    heap_start->ChunkSize = size + sizeof(Chunk_t);
    *((size_t *)start_brk) = size;
    chunk_arr[chunk_available - 1] = new_brk;
    page -= (size + sizeof(Chunk_t));
    return(new_brk);
}

