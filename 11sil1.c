#include <stdio.h>

int main()
{
    int arr[9];
    int max = 0;
    int num;

    for(int i = 0; i < 9 ; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int j = 0; j < 9 ; j++)
    {
        if(arr[j] > max)
        {
            max = arr[j];
            num = j + 1;
        }
    }

    printf("최댓값 : %d \n", max);
    printf("%d번째 수", num);


    return 0;
}