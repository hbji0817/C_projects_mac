#include <stdio.h>

int main()
{
    int arr[9][9];
    int max = 0;
    int num1, num2;

    for(int i = 0;i < 9;i++)
    {
        for(int j = 0;j < 9;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0;i < 9;i++)
    {
        for(int j = 0;j < 9;j++)
        {
            if(arr[i][j] > max)
            {
                max = arr[i][j];
                num1 = i + 1;
                num2 = j + 1;
            }
        }
    }

    printf("%d\n", max);
    printf("%d행 %d열", num1, num2);


}