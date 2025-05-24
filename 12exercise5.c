#include <stdio.h>

int main()
{
    char input[101];
    int big_check = 0;
    int small_check = 0;

    gets(input);

    int num = 0;
    while (input[num] != '.') 
    {
        if(input[num] == '[')
        {
            big_check += 1;
        }
        else if(input[num] == '(')
        {
            small_check += 1;
        }
        else if(input[num] == ']')
        {
            big_check -= 1;
        }
        else if(input[num] == ')')
        {
            small_check -= 1;
        }

        num++;

        if(small_check < 0 || big_check < 0) 
        {
            printf("no\n");
            return 0;
        }
    }

    if(small_check != 0 || big_check != 0)
    {
        printf("no\n");
    }
    else
    {
        printf("yes\n");
    }

    return 0;
}