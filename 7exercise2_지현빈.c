#include <stdio.h> // 표준 입출력 라이브러리

void cal(int a, int b, int c, char math) // 사칙연산 함수 선언
{
    char real_math; // 올바른 사칙연산 기호를 저장할 변수 선언
    if (a + b == c) real_math = '+'; // a + b == c일 때 '+' 저장
    else if (a - b == c) real_math = '-'; // a - b == c일 때 '-' 저장
    else if (a * b == c) real_math = '*'; // a * b == c일 때 '*' 저장
    else if (a != 0 && a / b == c) real_math = '/'; // a / b == c일 때 '/' 저장 (단, b가 0이 아니어야 함)
    
    switch(math)  // 입력된 math 값에 따라 실행할 case 결정
    {
    case '+':  // math가 '+'인 경우
        printf("바보야, +가 아니라 %c겠지!", real_math); // 올바른 연산자를 출력
        break;  // switch문 종료

    case '-':  // math가 '-'인 경우
        printf("바보야, -가 아니라 %c겠지!", real_math); // 올바른 연산자를 출력
        break;  // switch문 종료

    case '*':  // math가 '*'인 경우
        printf("바보야, *가 아니라 %c겠지!", real_math); // 올바른 연산자를 출력
        break;  // switch문 종료

    case '/':  // math가 '/'인 경우
        printf("바보야, /가 아니라 %c겠지!", real_math); // 올바른 연산자를 출력
        break;  // switch문 종료
    }
}

int main() // 메인 함수 선언
{
    char math; // 사칙연산 기호를 저장할 변수 선언
    int a, b, c; // 두 피연산자와 결과를 저장할 변수 선언
    
    scanf("%d %c %d = %d", &a, &math, &b, &c); // 틀린 사칙연산 식을 입력받음

    cal(a, b, c, math); // 입력받은 값으로 사칙연산 함수 호출

    return 0;  // 프로그램 종료
}