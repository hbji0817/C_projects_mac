#include <stdio.h> // 표준 입출력 라이브러리 

int main() // 메인 함수 시작
{
    int arr[10]; // 입력받을 정수 10개 저장할 배열

    for(int i=0;i<10;i++) // 0부터 9까지 반복
    {
        scanf("%d", &arr[i]); // 배열에 값 입력 받음
    }

    int max = arr[0]; // 배열의 첫 번째 값을 최댓값으로 설정
    for (int i = 1; i < 10; i++) // 두 번째 원소부터 끝까지 반복
    {
        if (arr[i] > max) max = arr[i]; // 더 큰 값이 있으면 max 갱신
    }

    int count[max + 1]; // 각 숫자의 등장 횟수를 저장할 배열 (나온 모든 숫자를 세기 위해 최댓값까지)
    for (int i = 0; i <= max; i++) // count 배열 전부 바꾸기
    {
        count[i] = 0; // 세기 전이니 0으로 설정
    } 

    for (int i = 0; i < 10; i++) // 입력받은 값의 등장 횟수 세기
    {
        count[arr[i]]++; //나온 숫자 한개씩 추가
    }

    int check[max + 1]; // 이미 출력한 숫자인지 체크하는 배열(0~max까지) (이전에 출력했던 숫자가 또 출력되지 않게)
    for (int i = 0; i <= max; i++) // check 배열 바꾸기
    {
        check[i] = 0; //0으로 설정
    }

    for (int i = 0; i < 10; i++) { // 입력받은 배열을 순회
        if (check[arr[i]] == 0) { // 아직 출력하지 않은 숫자라면
            printf("%d %d\n", arr[i], count[arr[i]]); // 숫자와 등장 횟수 출력
            check[arr[i]] = 1; // 출력했음을 표시
        }
    }

    return 0; // 프로그램 종료
}