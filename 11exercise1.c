#include <stdio.h> // 표준 입출력 라이브러리

int main() // 메인 함수 시작
{
    int num; // 입력받을 숫자의 개수를 저장할 변수
    scanf("%d", &num); // 숫자의 개수 입력 받기

    int arr[num]; // 입력받은 숫자를 저장할 배열 선언

    for(int i  = 0;i < num ; i++) // 0부터 num-1까지 반복
    {
        scanf("%d", &arr[i]); // 배열에 값 입력 받음
        if(arr[i] < 0 || arr[i] > 100) { // 입력 범위가 100을 넘으면
            printf("ERROR\n"); // ERROR 출력
            return 0; // 프로그램 종료
        }
    }

    while (num > 1) { // 배열 크기가 1보다 클 때까지 반복
        for (int i = 0; i < num; i += 2) { // 2개씩 묶어서 반복
            if(arr[i] > arr[i + 1]) printf("%d ", arr[i]); // 앞의 값이 더 크면 출력
            else                    printf("%d ", arr[i + 1]); // 뒤의 값이 더 크거나 같으면 출력
        }
        printf("\n"); // 한 줄 출력 후 줄바꿈
        num /= 2; // 배열 크기를 절반으로 줄임
    }
}