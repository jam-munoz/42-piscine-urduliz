/* Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str); */
#include <stdio.h>
char    *ft_strrev(char *str);
int	ft_atoi(const char *str);
int main(void)
{
    char string[] = "las papas s.a.";
    char *copy = "las papas a.s.";
    char numbers[] = "123675";
    int num = ft_atoi(numbers);
    copy = ft_strrev(string);
    printf("s %s\nc %s\nn %d\n", string, copy, num/2);
}
char    *ft_strrev(char *str)
{
    int len = 0, i = 0;
    char temp;
    while(str[len] != '\0')
        len++;
    while (i < len-1)
    {
        temp = str[i];
        str[i] = str[len-1];
        str[len-1] = temp;
        i++;
        len--;
    }
    return str;
}

int	ft_atoi(const char *str)
{
    int len = 0, sum = 0, pow = 1;
    while(str[len] != '\0')
        len++;
    while(len >= 0)
    {
        sum += (str[len] - '0') * pow;
        len--;
        pow *= 10;
    }
    return sum;
}

