#include <stdio.h>

int arr[100]; // 방문 여부를 저장하는 배열 (0 = 방문 안 함, 1 = 방문함)
void stamp(int curr_island, int n); // stamp 함수 선언

int main() //메인 함수 시작
{
    int num; // 섬의 개수를 저장할 변수 num
    scanf("%d", &num); // 섬의 개수를 입력받음

    for (int i = 1; i <= num; i++) { // 1부터 num까지 섬 방문
        if (arr[i-1] != 1) { // 해당 섬이 방문되지 않았을 경우
            printf("연세%d섬 방문!\n", i ); // 섬 방문 출력
            arr[i-1] = 1; // 섬 방문 표시
            stamp(i, num); // stamp 함수 호출
        }
    }

    return 0; //프로그램 죵료
}

void stamp(int curr_island, int n) //규칙에 따라 섬을 방문하는 stamp 함수 
{
    if(2 * curr_island <= n) { // 현재 섬의 왼쪽 아래 섬이 존재할 경우
        printf("연세%d섬 방문!\n", 2 * curr_island); // 왼쪽 아래 섬 방문 출력
        curr_island *= 2; // 현재 섬을 왼쪽 아래 섬으로 변경
        arr[curr_island - 1] = 1; // 왼쪽 아래 섬 방문 표시
        if(2 * curr_island < n) { // 왼쪽 아래 섬의 왼쪽 아래 섬이 존재할 경우
            stamp(curr_island, n); // 재귀 호출로 왼쪽 아래 섬 방문
        }
    }

    if((2 * curr_island) + 1 <= n) { // 현재 섬의 오른쪽 아래 섬이 존재할 경우
        printf("연세%d섬 방문!\n", (2 * curr_island) + 1); // 오른쪽 아래 섬 방문 출력
        curr_island = (2 * curr_island) + 1; // 현재 섬을 오른쪽 아래 섬으로 변경
        arr[curr_island - 1] = 1; // 오른쪽 아래 섬 방문 표시
    }

    if(arr[curr_island] != 1) { // 바로 다음 숫자의 섬이 방문되지 않았을 경우
        curr_island += 1; // 다음 섬으로 이동
        if(curr_island <= n) stamp(curr_island, n); // 다음 섬 방문
        return; // n을 넘었으면 함수 종료
    }

    if(curr_island == n) { // 마지막 섬에 도달한 경우
        return; // 함수 종료
    }
}