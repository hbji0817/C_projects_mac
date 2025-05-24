#include <stdio.h>

int fib(int a)
{
    if (a == 0)
        return 0;
    else if (a == 1)
        return 1;
    else
        return fib(a - 1) + fib(a - 2);
}

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n", fib(a));

    return 0;
}