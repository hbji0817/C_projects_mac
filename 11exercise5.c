#include <stdio.h> // 표준 입출력 라이브러리 포함

int main() // 메인 함수 시작
{
    int n; // 입력받을 숫자의 개수를 저장할 변수
    scanf("%d", &n); // 숫자의 개수 입력 받기
    int arr[n]; // 입력받은 숫자를 저장할 배열 선언

    for(int i = 0; i < n; i++) // 0부터 n-1까지 반복
    {
        scanf("%d", &arr[i]); // 배열에 값 입력 받음
    }

    for(int i = 0; i < n - 1; i++) // 배열을 오름차순 정렬하기 위한 반복문
    {
        for(int j = 0; j < n - i - 1; j++) // 한 원소를 뒤의 원소와 비교해서 뒤의 원소가 더 작으면 위치 바꾸기
        {
            if(arr[j] > arr[j + 1]) // 앞의 값이 더 크면
            {
                int t = arr[j]; // 두 값을 교환
                arr[j] = arr[j + 1]; // 하는
                arr[j + 1] = t; // 코드
            } 
        }
    }

    int time = 0; // 결과를 저장할 변수
    for(int i = 0; i < n; i++) // 0부터 n-1까지 반복
    {
        time += (n - i) * arr[i]; // 각 사람이 기다린 시간의 합 계산
    }

    printf("%d\n", time); // 결과 출력

    return 0; // 프로그램 종료
}