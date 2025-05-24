#include <stdio.h> // 표준 입출력 라이브러리

int arr[100]; // 섬 방문 여부를 저장하는 배열 (0: 미방문, 1: 방문)
void stamp(int curr_island, int n); // stamp 함수 선언

int main() // main 함수 시작
{
    int num; // 섬의 개수를 저장할 변수
    scanf("%d", &num); // 섬의 개수를 입력받음

    for (int i = 1; i <= num; i++) // 1번 섬부터 num번 섬까지 반복
    {
        if (arr[i - 1] != 1) // 현재 섬이 아직 방문되지 않았다면
        {
            arr[i - 1] = 1; // 현재 섬 방문 표시
            stamp(i, num); // 현재 섬에서 재귀적으로 다른 섬 방문 시작
        }
    }

    return 0; // 프로그램 종료
}

void stamp(int curr_island, int n) // 규칙에 따라 섬을 방문하는 함수
{
    if (2 * curr_island <= n && arr[(2 * curr_island) - 1] != 1) // 왼쪽 아래 섬이 존재하고 방문되지 않았다면
    {
        arr[(2 * curr_island) - 1] = 1; // 왼쪽 아래 섬 방문 표시
        stamp(2 * curr_island, n); // 왼쪽 아래 섬으로 이동하여 재귀 호출
    }

    if ((2 * curr_island) + 1 <= n && arr[(2 * curr_island)] != 1) // 오른쪽 아래 섬이 존재하고 방문되지 않았다면
    {
        arr[(2 * curr_island)] = 1; // 오른쪽 아래 섬 방문 표시
        stamp((2 * curr_island) + 1, n); // 오른쪽 아래 섬으로 이동하여 재귀 호출
    }

    printf("연세%d섬 방문!\n", curr_island); // 현재 섬 방문 출력
}