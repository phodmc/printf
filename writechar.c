#include "main.h"

/**
* _writechar - prints char c to standard output
* @c: char to print
* Return: 1 on success
*/

int _writechar(char c)
{
	return (write(1, &c, 1));
}
