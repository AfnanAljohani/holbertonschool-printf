#include "main.h"

/**
 * flush_buffer - writes the buffer to stdout and resets index
 * @buf: the buffer
 * @idx: pointer to current index in buffer
 */
void flush_buffer(char *buf, int *idx)
{
	if (*idx > 0)
	{
		write(1, buf, *idx);
		*idx = 0;
	}
}

/**
 * buffer_add - adds a character to buffer, flushes if full
 * @buf: the buffer
 * @idx: pointer to current index
 * @c: character to add
 */
void buffer_add(char *buf, int *idx, char c)
{
	if (*idx >= BUFFER_SIZE)
		flush_buffer(buf, idx);
	buf[*idx] = c;
	(*idx)++;
}
