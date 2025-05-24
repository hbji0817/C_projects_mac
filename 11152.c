#include <stdio.h>

int main()
{
    char arr[100];
    int count = 1;

    scanf("%s", arr);

    for(int i = 0 ; arr[i] != '\0'; i++ )
    {
        if(arr[i] == ' ')
        {
            count += 1;
        }
    }
    printf("%d", count);

    //
    return 0;
}