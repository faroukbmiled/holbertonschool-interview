#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"

/**
 *check_word_match - checks if a substring matches any word in the given array
 *@substring: the substring to check
 *@words: the array of words to match against
 *@nb_words: the number of elements in the array words
 *@len: the length of each word in the array
 *@visited: an array to keep track of visited words
 *
 *Return: 1 if a match is found, 0 otherwise
 */
static int check_word_match(const char *substring, const char
**words, int nb_words, int len, int *visited)
{
	for (int k = 0; k < nb_words; k++)
	{
		if (!visited[k] && strncmp(substring, words[k], len) == 0)
		{
			visited[k] = 1;
			return (1);
		}
	}

	return (0);
}

/**
 *process_substring - processes a substring
 *@s: the string to scan
 *@words: the array of words all substrings
 *@nb_words: the number of elements in the array words
 *@len: the length of each word in the array
 *@indices: an array to store the result indices
 *@n: the current count of valid indices
 *@i: the current index being processed
 *
 *Return: the updated count of valid indices
 */
static int process_substring(const char *s, const char
**words, int nb_words, int len, int *indices, int n, int i)
{
	int j;
	int *visited = calloc(nb_words, sizeof(int));

	if (visited == NULL)
	{
		free(indices);
		return (-1);
	}

	int found = 1;

	for (j = 0; j < nb_words; j++)
	{
		found = check_word_match(s + i + j * len, words, nb_words, len, visited);
		if (!found)
			break;
	}

	free(visited);

	if (found)
	{
		indices[n] = i;
		n++;
	}

	return (n);
}

/**
 *find_substring - finds all the possible substrings
 *@s: the string to scan
 *@words: the array of words all substrings
 *@nb_words: the number of elements in the array words
 *@n: holds the address at which to store the number
 *
 *Return: an allocated array, storing each index in s
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int len = strlen(words[0]);
	int word_len = len * nb_words;
	int str_len = strlen(s);
	int *indices = NULL;
	int i;

	*n = 0;

	if (str_len == 0 || word_len > str_len)
		return (NULL);

	indices = malloc(str_len * sizeof(int));
	if (indices == NULL)
		return (NULL);

	for (i = 0; i <= str_len - word_len; i++)
	{
		*n = process_substring(s, words, nb_words, len, indices, *n, i);
		if (*n == -1)
			return (NULL);
	}

	if (*n == 0)
	{
		free(indices);
		indices = NULL;
	}

	return (indices);
}
