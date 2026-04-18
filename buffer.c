#include "main.h"

/**
 * buffer_flush - Writes the contents of the buffer to stdout and resets it
 * @b: Pointer to the buffer
 *
 * Return: Number of characters written (0 if buffer was empty)
 */
int buffer_flush(buffer_t *b)
{
	int written;

	if (b == NULL || b->len == 0)
		return (0);
	written = write(1, b->buf, b->len);
	b->len = 0;
	return (written);
}

/**
 * buffer_add_char - Adds one character to the buffer, flushing if full
 * @b: Pointer to the buffer
 * @c: Character to add
 *
 * Return: 1 on success (one character queued), 0 on failure
 */
int buffer_add_char(buffer_t *b, char c)
{
	if (b == NULL)
		return (0);
	if (b->len >= BUFFER_SIZE)
		buffer_flush(b);
	b->buf[b->len] = c;
	b->len++;
	return (1);
}
