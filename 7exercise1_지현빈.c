#include <stdio.h> // 표준 입출력 라이브러리 포함


void swmenu(int t) // 소웨 할인 가격을 출력하는 함수
{
    switch (t) // 입력된 메뉴 번호에 따라 실행
    {
        case 1: // 메뉴 번호가 1인 경우
            printf("피자 가격: 13500원"); // 할인된 피자 가격 출력
            break; // switch문 종료
        case 2: // 메뉴 번호가 2인 경우
            printf("파스타 가격: 10800원"); // 할인된 파스타 가격 출력
            break; // switch문 종료
        case 3: // 메뉴 번호가 3인 경우
            printf("햄버거 가격: 7200원"); // 할인된 햄버거 가격 출력
            break; // switch문 종료
        case 4: // 메뉴 번호가 4인 경우
            printf("샐러드 가격: 6300원"); // 할인된 샐러드 가격 출력
            break; // switch문 종료
        case 5: // 메뉴 번호가 5인 경우
            printf("밥버거 가격: 5400원"); // 할인된 밥버거 가격 출력
            break; // switch문 종료
        default: // 메뉴 번호가 유효하지 않은 경우
            printf("잘못된 입력입니다."); // 오류 메시지 출력
            break; // switch문 종료
    }
}

void menu(int t) // 메뉴 번호에 따라 가격을 출력하거나 특별 할인 처리하는 함수
{
    switch (t) // 입력된 메뉴 번호에 따라 실행
    {
        case 1: // 메뉴 번호가 1인 경우
            printf("피자 가격: 15000원"); // 피자 가격 출력
            break; // switch문 종료
        case 2: // 메뉴 번호가 2인 경우
            printf("파스타 가격: 12000원"); // 파스타 가격 출력
            break; // switch문 종료
        case 3: // 메뉴 번호가 3인 경우
            printf("햄버거 가격: 8000원"); // 햄버거 가격 출력
            break; // switch문 종료
        case 4: // 메뉴 번호가 4인 경우
            printf("샐러드 가격: 7000원"); // 샐러드 가격 출력
            break; // switch문 종료
        case 5: // 메뉴 번호가 5인 경우
            printf("밥버거 가격: 6000원"); // 밥버거 가격 출력
            break; // switch문 종료
        case 245: // 특별 할인 코드가 입력된 경우
            printf("특별 할인이 적용되었습니다. 주문을 계속 진행해 주세요. 다시 메뉴를 선택하세요.\n"); // 할인 메시지 출력
            scanf("%d", &t); // 새로운 메뉴 번호 입력받기
            swmenu(t); // swmenu 함수 호출
            break; // switch문 종료
        default: // 메뉴 번호가 유효하지 않은 경우
            printf("잘못된 입력입니다."); // 오류 메시지 출력
            break; // switch문 종료
    }
}

// 프로그램의 시작점
int main()
{
    int t; // 메뉴 번호를 저장할 변수 선언
    scanf("%d", &t); // 사용자로부터 메뉴 번호 입력받기
    menu(t); // 입력받은 메뉴 번호로 menu 함수 호출
    return 0; // 프로그램 정상 종료
}