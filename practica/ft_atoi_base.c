int ft_is_number(char c)
{
    if ('0' <= c && c <= '9')
        return 1;
    else 
        return 0;
}

int ft_is_alpha(char c)
{
    if (('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'))
        return 1;
    else 
        return 0;
}

int ft_valid_base(char c, int str_base)
{
    int i = 0;
    int k = 0;
    char base1[] = "0123456789abcdef";
    char base2[] = "0123456789ABCDEF";

    while(base1[i] && i < str_base)
    {
        if (c == base1[i])
            return 1;
        i++;
    }
    i = 0;
    while(base2[i] && i < str_base)
    {
        if (c == base2[i])
            return 1;
        i++;
    }
    return 0;

}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sum = 0;
    int sign = 1;

    while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (str_base > 10)
    {
        while(ft_valid_base(str[i], str_base))
        {
            sum *= str_base;
            if (ft_is_number(str[i]))
                sum += str[i] - '0';
            else if ('a' <= str[i] && str[i] <= 'f') 
                sum += str[i] - 'a' + 10;
            else
                 sum += str[i] - 'A' + 10;
            i++;
        }
    }
    else
    {
        while(ft_valid_base(str[i], str_base))
        {
            sum *= str_base;
            sum += str[i] - '0';
            i++;
        }
    }
    return sum * sign;
}

#include <stdio.h>
int main(void)
{
    int n = ft_atoi_base("1012", 2);
    printf("%d\n", n);
}