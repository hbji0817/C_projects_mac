#include <stdio.h>

int gcd(int num)
{
    if(num >= 2)
    {
        return fib(num-2) + fib(num-1);
    }
    else if(num == 1)
        return 1;
    else 
        return 0;

}

int main()
{
    int num;
    scanf("%d", &num);
    num = fib(num);
    printf("%d", num);

    return 0;
}