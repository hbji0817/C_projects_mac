#include <stdio.h>

int arr[100];
void stamp(int curr_island, int n);


int main()
{
    int num;
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        if (arr[i-1] != 1) { 
            printf("연세%d섬 방문!\n", i );
            arr[i-1] = 1;
            stamp(i, num);
        }
    }
}

void stamp(int curr_island, int n)
{
    if(2 * curr_island < n) 
    {
        printf("연세%d섬 방문!\n", 2 * curr_island);
        curr_island *= 2;
        arr[curr_island - 1] = 1;
        if(2 * curr_island < n) 
        {
            stamp(curr_island, n);
        }
    }

    if((2 * curr_island) + 1 < n)  
    {
        printf("연세%d섬 방문!\n", (2 * curr_island) + 1);
        curr_island = (2 * curr_island) + 1;
        arr[curr_island - 1] = 1;
        if((2 * curr_island) + 1 < n) 
        {
            stamp(curr_island, n);
        }
    }

    if(arr[curr_island] != 1)  
    {
        curr_island += 1;
        if(curr_island <= n) stamp(curr_island, n);

        return;
    }

    if(curr_island == n)
    {
        return;
    }
}