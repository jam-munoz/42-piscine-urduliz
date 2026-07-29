/* Assignment name  : brackets
Expected files   : brackets.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of strings in arguments. For each argument, print "OK" if the
expression is correctly bracketed, otherwise "Error", followed by a newline. Brackets are (), [], {}. Other
symbols are ignored. A string with no bracket is OK. If there are no arguments, print only a newline.

$> ./brackets '(johndoe)' | cat -e
OK$
$> ./brackets '([)]' | cat -e
Error$*/

#include <unistd.h>

void	ft_putstr(char *str);
int ft_open_bracket(char c);
int ft_close_bracket(char c);
int ft_strlen(char *str);

int main(int argc, char *argv[])
{
    int i = 1;
    char str[2] = { 0 };
    while (i < argc)
    {
        int start = 0;
        int end = ft_strlen(argv[i]);
        end--;

        while (start < end)
        {
            if (ft_open_bracket(argv[i][start]))
            {
                str[0] = argv[i][start];
                while(start < end)
                {
                    if (ft_close_bracket(argv[i][end]))
                    {
                        str[1] = argv[i][end];
                        break;
                    }
                    end--;
                }
                if (ft_close_bracket(str[i]))
                    break;
            }
            start++;
        }
        if (!str[0] || (str[0] == '(' && str[1] == ')') || (str[0] == '[' && str[1] == ']') || (str[0] == '{' && str[1] == '}'))
            ft_putstr("OK\n");
        else
            ft_putstr("Error\n");
        str[0] = '\0';
        i++;
    }
}

int ft_open_bracket(char c)
{
    if (c == '(' || c == '[' || c == '{')
        return 1;
    else
        return 0;
}

int ft_close_bracket(char c)
{
    if (c == ')' || c == ']' || c == '}')
        return 1;
    else
        return 0;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
