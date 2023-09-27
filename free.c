#include "malloc.h"
/*
* _free - frees a chunk of memory allocated by _malloc
* @ptr: pointer to the memory to be freed
*/
void _free(void *ptr)
{
	Chunk_t *header;

	if (ptr)
	{
		header = ((Chunk_t*)ptr) - 1;
		header->status = 0;
	}
}