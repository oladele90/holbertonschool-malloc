#ifndef _MALLOC_H_
#define _MALLOC_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct ChunkHeader 
{
    size_t ChunkSize;
    size_t status;
} Chunk_t;

void *naive_malloc(size_t size);
size_t chunker(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);

#endif