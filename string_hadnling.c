#include "main.h"

/**
 * CompareStrings - Compare two strings.
 *
 * This function compares two strings `s1` and `s2`. It iterates through the strings
 * character by character and returns the difference between the ASCII values
 * of the first differing characters, or 0 if the strings are identical.
 *
 * @s1: First string to be compared.
 * @s2: Second string to be compared.
 *
 * Return: Difference between `s1` and `s2`.
 */
ssize_t CompareStrings(char *s1, char *s2)
{
    ssize_t i = 0, output;

    while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
        i++;

    output = (*(s1 + i) - *(s2 + i));

    return (output);
}

/**
 * GetStringLength - Get the length of a string.
 *
 * This function calculates and returns the length of a given string `s`.
 *
 * @s: String for which the length is calculated.
 *
 * Return: Length of the string `s`.
 */
ssize_t GetStringLength(char *s)
{
    ssize_t count = 0;

    while (*s != '\0')
    {
        count++;
        s++;
    }
    return (count);
}

/**
 * CompareStringsN - Compare two strings up to n bytes.
 *
 * This function compares the first `n` bytes of two strings `s1` and `s2`. It
 * iterates through the strings character by character up to `n` bytes or until
 * a differing character is encountered. It returns the difference between the
 * ASCII values of the first differing characters, or 0 if the strings are identical.
 *
 * @s1: First string to be compared.
 * @s2: Second string to be compared.
 * @n: Number of bytes to compare.
 *
 * Return: Difference between `s1` and `s2`.
 */
ssize_t CompareStringsN(char *s1, char *s2, int n)
{
    ssize_t i;

    for (i = 0; s1[i] && s2[i] && i < n; i++)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}

/**
 * DuplicateString - Duplicate a string.
 *
 * This function duplicates a given string `s` by allocating memory for a new
 * string and copying the content of `s` into the new memory location.
 * The duplicate string is then returned.
 *
 * @s: String to be duplicated.
 *
 * Return: Pointer to the duplicated string, or NULL on failure.
 */
char *DuplicateString(char *s)
{
    char *ptr;
    ssize_t i, len;

    if (s == NULL)
        return (NULL);

    len = GetStringLength(s);

    ptr = malloc(sizeof(char) * (len + 1));
    if (!ptr)
        return (NULL);
    for (i = 0; *s != '\0'; s++, i++)
        ptr[i] = s[0];

    ptr[i++] = '\0';
    return (ptr);
}

/**
 * FindCharacterInString - Locate a character in a string.
 *
 * This function searches for the first
 * ... occurrence of character `c` in the string `s`.
 * If the character is found, a pointer to
 * ... its location in the string is returned.
 * If the character is not found and `c` is
 * ... the null terminator, a pointer to the end
 * of the string is returned.
 * ... Otherwise, NULL is returned.
 *
 * @s: String to be checked.
 * @c: Character to be located.
 *
 * Return: Pointer to the first occurrence
 * .... of `c` in `s`, or NULL if not found.
 */
char *FindCharacterInString(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return (s);
        s++;
    }
    if (!c)
        return (s);
    return (NULL);
}
