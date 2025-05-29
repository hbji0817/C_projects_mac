#include <stdio.h>

// 복소수를 정의하는 구조체
typedef struct {
    double a;
    double b;
} num;

int main() 
{
    num x = {1.0, 2.0};
    num y = {2.0, -3.0};
    num result;

    result.a = (x.a * y.a + x.b * y.b) / (y.a * y.a + y.b * y.b);
    result.b = (x.b * y.a - x.a * y.b) / (y.a * y.a + y.b * y.b);

    printf("복소수 나눗셈 결과 = %.2f + %.2f i\n", result.a, result.b);

    return 0;
}
