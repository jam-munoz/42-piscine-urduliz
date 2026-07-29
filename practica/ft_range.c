/* Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/

#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int i = 0;
    int len = end - start;
    int ascending = 1;
    if (len < 0)
    {
        ascending = 0;
        len *= -1;
    }
    len++;

    int *out = malloc(len * sizeof(int));
    if (ascending)
    {
        while (i < len)
        {
            out[i] = start;
            i++;
            start++;
        }
    }
    else
    {
        while (i < len)
        {
            out[i] = start;
            i++;
            start--;
        }
    }
    return out;
}

#include <stdio.h>
int main(void)
{
    int *arr = ft_range(0, -3);
    for (int i = 0; i < 4; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}