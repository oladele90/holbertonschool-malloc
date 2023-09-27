#ifndef _MALLOC_H_
#define _MALLOC_H_

typedef struct ChunkHeader 
{
    size_t ChunkSize;
    size_t status;
    Chunk_t *next = NULL;
} Chunk_t;

void *naive_malloc(size_t size);
size_t chunker(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);

#endif