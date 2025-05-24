#include <stdio.h>  // 표준 입출력 라이브러리

int arr[100];  // 섬 방문 여부를 저장하는 배열 (0: 미방문, 1: 방문)
void stamp(int curr_island, int n);  // stamp 재귀 함수 선언

int main()
{
    int num;  // 섬의 개수를 저장할 변수
    scanf("%d", &num);  // 섬의 개수 입력 받기

    
    for (int i = 1; i <= num; i++)  // 1번 섬부터 num번 섬까지 순차적으로 확인
    {
        
        if (arr[i-1] != 1) // 현재 섬이 아직 방문되지 않았다면
        { 
            arr[i-1] = 1;  // 현재 섬 방문 표시
            stamp(i, num);  // 현재 섬에서 재귀적으로 다른 섬 방문 시작
            printf("연세%d섬 방문!\n", i );  // 현재 섬 방문 출력
        }
    }
}


void stamp(int curr_island, int n) // 규칙에 따라 섬을 방문하는 함수
{
    
    if(2 * curr_island <= n) // 현재 섬의 아래 번호가 n 안에 있으면
    {
        curr_island *= 2;  // 아래 섬으로 이동
        arr[curr_island - 1] = 1;  // 해당 섬 방문 표시

        
        if(2 * curr_island < n) // 아래 섬의 아래 섬도 범위 내에 있다면 재귀 호출
        {
            stamp(curr_island, n);  // 재귀적으로 아래 섬 방문
        }

        printf("연세%d섬 방문!\n", curr_island);  // 현재 섬 방문 출력
    }

    
    if((2 * curr_island) + 1 <= n)  // 오른쪽 아래 섬이 n안에 있으면
    {
        curr_island = (2 * curr_island) + 1;  // 오른쪽 아래 섬으로 이동
        arr[curr_island - 1] = 1;  // 해당 섬 방문 표시
        printf("연세%d섬 방문!\n", curr_island);  // 섬 방문 출력
        //오른쪽 아래섬의 아래섬이 있었으면 위 if문에서 이미 넘어갔기 때문에 재귀함수를 넣지 않음
    }

    
    if(arr[curr_island] != 1) // 다음 번호의 섬이 아직 방문되지 않았으면
    {
        curr_island += 1;  // 다음 섬 번호로 이동
        if(curr_island <= n) stamp(curr_island, n);  // 범위 내에 있으면 재귀적으로 방문 시도

        return;  // 함수 종료
    }

    
    if(curr_island == n) // 현재 섬이 마지막 섬이면
    {
        return; // 함수 종료
    }
}
