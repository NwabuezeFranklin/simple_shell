#include "holberton.h"
/**
 * tokenize - creates array of tokens based on user string
 * @buffer: pointer to user string
 *
 * Return: pointer to array of user strings
 */
char **tokenize(char *buffer)
{
    char *token;
    int i = 0, wordcount = 0;
    char *delimiter = " \n";
    char **av;

    wordcount = _splitstring(buffer);
    if (!wordcount)
        return (NULL);
    av = malloc((wordcount + 1) * sizeof(char *));
    if (av == NULL)
        exit(1);
    token = strtok(buffer, delimiter);
    while (token != NULL)
    {
        av[i] = _strdup(token);
        token = strtok(NULL, delimiter);
        i++;
    }
    av[i] = NULL;
    return (av);
}
/**
 * _splitPATH - counts the number of PATH members
 * @str: pointer to string to count
 *
 * Return: number of PATH members
 */
int _splitPATH(char *str)
{
    int i;
    int searchflag = 1;
    int wordcount = 0;

    for (i = 0; str[i]; i++)
    {
        if (str[i] != ':' && searchflag == 1)
        {
            wordcount += 1;
            searchflag = 0;
        }
        if (str[i + 1] == ':')
        {
            searchflag = 1;
        }
    }
    return (wordcount);
}
/**
 * _PATHstrcmp - compares PATH with environ to find PATH value
 * @s1: pointer PATH string
 * @s2: pointer to environ string with actual value
 *
 * Return: 0 on success
 */
int _PATHstrcmp(const char *s1, const char *s2)
{
    int i;

    for (i = 0; s2[i] != '='; i++)
    {
        if (s1[i] != s2[i])
            return (-1);
    }
    return (0);
}
/**
 * _concat - concats user string with PATH member string and /
 * @tmp: static array to store concatenated string
 * @av: pointer to array of user strings
 * @tok: pointer to PATH token
 *
 * Return: 0 on success
 */
char *_concat(char *tmp, char **av, char *tok)
{
    int len = 0;

    _memset(tmp, 0, 256);
    len = _strlen(tok) + _strlen(av[0]) + 2;
    _strcat(tmp, tok);
    _strcat(tmp, "/");
    _strcat(tmp, av[0]);
    tmp[len - 1] = '\0';
    return (tmp);
}
