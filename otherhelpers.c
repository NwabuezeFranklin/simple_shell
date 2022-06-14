#include "holberton.h"
/**
 * _getenv - gets PATH member from environ
 * @name: pointer to PATH string
 *
 * Return: pointer to PATH member string or NULL if not found
 */
char *_getenv(const char *name)
{
    int i, result;

    for (i = 0; environ[i]; i++)
    {
        result = _PATHstrcmp(name, environ[i]);
        if (result == 0)
        {
            return (environ[i]);
        }
    }
    return (NULL);
}
/**
 * _env - prints the environ
 *
 * Return: 0 on success
 */
int _env(void)
{
    int i;

    for (i = 0; environ[i]; i++)
        _puts(environ[i]);
    return (0);
}
/**
 * _puts - prints a string
 * @str: string to print
 */
void _puts(char *str)
{
    int c;

    for (c = 0; str[c] != '\0'; c++)
        _putchar(str[c]);
    _putchar('\n');
}
/**
 * _putchar - prints a character
 * @c: character to print
 *
 * Return: return value of write syscall
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
/**
 * _memset - fills memory with a constant byte
 * @s: character array to fill
 * @b: constant byte to fill with
 * @n: how many bytes to fill
 * Return: the pointer to the char array
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        s[i] = b;
    return (s);
}
