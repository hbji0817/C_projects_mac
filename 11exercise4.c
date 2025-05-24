#include <stdio.h> // 표준 입출력 라이브러리

int zero_count = 0; // 0이 출력되는 횟수를 저장할 변수
int one_count = 0;  // 1이 출력되는 횟수를 저장할 변수

void fibonacci(int n) { // 피보나치 함수 선언
    if(n == 0) { // n이 0이면
        zero_count += 1; // zero_count 1 증가
    }
    else if(n == 1) { // n이 1이면
        one_count += 1; // one_count 1 증가
    }
    else { // n이 0이나 1이 아니면
        fibonacci(n-1); // n-1에 대해 재귀 호출
        fibonacci(n-2); // n-2에 대해 재귀 호출
    }
}

int main() // 메인 함수 시작
{
    int num; // 케이스 개수를 입력 받을 변수
    scanf("%d", &num); // 케이스 개수 입력 받기

    int arr[num]; // 입력받은 수들을 저장할 배열

    for(int i = 0; i < num ; i++) // 케이스 개수만큼 반복
    {
        scanf("%d", &arr[i]); // 각 케이스의 수 입력 받기
    }

    for(int i = 0; i < num ; i++) // 각 테스트 케이스의 개수만큼 반복
    {
        fibonacci(arr[i]); // 피보나치 함수 실행
        printf("%d %d\n", zero_count, one_count); // 0과 1이 출력된 횟수 출력
        zero_count = 0; // zero_count 초기화
        one_count = 0; // one_count 초기화
    }

    return 0; // 프로그램 종료
}