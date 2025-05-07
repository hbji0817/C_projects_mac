#include <stdio.h>

int gcd(int num1, int num2)
{
    if (num2 == 0) 
    {
        return num1;
    }
    return gcd(num2, num1 % num2); 
}

int main()
{
    int num1, num2;
    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &num1, &num2);

    printf("최대공약수: %d\n", gcd(num1, num2));

    return 0;
}