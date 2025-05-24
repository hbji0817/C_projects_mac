#include <stdio.h> // 표준 입출력 라이브러리 사용

int main() { // 메인 함수 시작
    char input[101]; // 문자열 입력받을 배열
    int n; // 숫자 입력 받을 변수

    gets(input);     // 문자열 입력 받기
    scanf("%d", &n); // 숫자 입력 받기

    for (int i = 0; input[i] != '\0'; i++) // 문자열 끝까지 반복
    {
        char c = input[i]; // 현재 문자 c에 저장

        if ('A' <= c && c <= 'Z') // 대문자일 때
        {
            printf("%c", c + n); // n만큼 아스키코드 증가시켜 출력
        } 
        else if ('a' <= c && c <= 'z') // 소문자일 때
        {
            printf("%c", c - n); // n만큼 아스키코드 감소시켜 출력
        } 
        else if ('0' <= c && c <= '9') // 숫자일 때
        {
            int num = c - '0'; // 한 자리 숫자
            
            if ('0' <= input[i + 1] && input[i + 1] <= '9') // 두 자리 숫자 처리 (27 이하만 두 자리로)
            {
                int next_num = input[i + 1]; //다음 숫자 저장
                int two_num = num * 10 + next_num; //현재 숫자랑 다음 숫자를 합쳐 두자리 숫자로 만들기
                if (two_num <= 26) // 1~26까지만 두 자리로 처리
                {
                    num = two_num; //num에 숫자 저장
                    i++; // 두 자리 처리했으니 한 칸 더 증가
                }
            }
            
            for (int j = 0; j < n; j++) // n번 반복
            {
                printf("%c", 'A' + num - 1); // num번째 대문자 알파벳을 출력
            }
            
        } 
        else { // 그 외(공백, 특수문자 등)
            printf(" "); // 공백 출력
        }
    }

    return 0; // 프로그램 종료
}