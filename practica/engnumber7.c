/*Modify Programming Project 11 from Chapter 5 so that it uses arrays containing pointers to
strings instead of switch statements. For example, instead of using a switch statement
to print the word for the first digit, use the digit as an index into an array that contains the
strings "twenty", "thirty", and so forth..*/
#include <stdio.h>

int main(void)
{
    int number;
    char *ones[] = {"-one.", "-two.", "-three.", "-four.", "-five.", "-six.", "-seven.", "-eight.", "-nine."}, 
    *tens[] = {"Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}, 
    *teen[] = {"Ten.", "Eleven.", "Twelve.", "Thirteen.", "Fourteen.", "Fifteen.", "Sixteen.", "Seventeen.", "Eighteen.", "Nineteen."};
    printf ("Enter a two-digit number: ");
    scanf ("%d", &number);
    if (number < 10 || number > 99)
    {
        printf ("Invalid number.\n");
        return 1;
    }
    if (number >= 10 && number < 20)
    {
        printf("%s\n", teen[number-10]);
        return 0;
    }
    int digit1 = (number % 10) - 1;
    int digit10 = (number / 10) - 2;
    printf("%s%s\n", tens[digit10], ones[digit1]);
    return 0;
}