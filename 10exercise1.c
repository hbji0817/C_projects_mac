#include <stdio.h> //표준 입출력 라이브러리 사용

void give_friend(int length, int m); //함수 먼저 선언
void eat(int length, int m); //함수 먼저 선언

int main() { // 메인함수 선언
    int n,m; // 과자의 길이 n, 친구 수 m 선언
    scanf("%d %d", &n, &m); // n, m 입력 받기

    if (n % m == 0)  eat(n, m); //나누어 떨어지면 연세가 먹고
    else     give_friend(n, m); //아니면 친구가 먹음

    return 0; //프로그램 종료
}

void eat(int length, int m) { //김연세가 먹는 함수
    if(length <= 0) return; // 길이가 0이면 멈추기

    length = length / m; // 연세는 남은 것의 1/m만 남김
    printf("먹은 사람: 김연세, 먹은 후 남은 길이: %d\n", length);  // 출력

    if (length % m == 0) // 나눠떨어지면
        eat(length, m);  // 김연세 다시 -> eat() 재귀 호출
    else 
        give_friend(length, m);  // 아니면 친구에게 넘김 -> give_friend() 호출 
}

void give_friend(int length, int m) { //친구가 먹는 함수
    if (length <= 0) return; //과자가 없으면 종료

    length -= 1; //친구가 1센치 먹음

    printf("먹은 사람: %d번째 친구, 먹은 후 남은 길이 %d\n", (length % m) + 1, length); //출력

    if(length > 0) //길이가 0보다 클때만 
    {
        if (length % m == 0) //나누어 떨어지면
            eat(length, m); // 김연세에게 넘김 -> eat() 호출
        else {
            give_friend(length, m); // 다음 친구 차례 -> give_friend() 호출
        }
    }
}