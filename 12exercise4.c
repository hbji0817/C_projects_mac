#include <stdio.h> // 표준 입출력 라이브러리 사용

int main() // 메인 함수 시작
{
    char input[51]; // 문자열 입력받을 배열
    int a[26]; // 알파벳의 개수를 셀 배열
    char result[51]; // 결과를 저장할 배열

    for(int i = 0; i < 26; i++) // 알파벳 개수 배열 전부
        a[i] = 0; // 0으로 초기화
    for(int i = 0; i < 51; i++) // 결과 배열 전부
        result[i] = 0; // 0으로 초기화

    gets(input); // 문자열 입력 받기

    int num = 0; // 입력 문자열 길이 저장 변수
    while (input[num] != '\0') // 문자열 전체의 알파벳 종류랑 개수 세기
    {
        a[input[num] - 'A'] += 1; // 해당 알파벳 개수 증가
        num++; // 문자열 길이 증가
    }

    // 홀수 개수 알파벳 개수 세기
    int odd_count = 0; // 홀수 개수
    int odd_index = -1; // 홀수에 해당하는 알파벳
    for (int i = 0; i < 26; i++) //알파벳 전체에서 
    {
        if (a[i] % 2 == 1) // 홀수 개인 알파벳 발견시
        {
            odd_count++; // 개수 +1
            odd_index = i; // 알파벳 저장
        }
    }

    if (odd_count > 1) // 홀수 개수 알파벳이 2개 이상이면
    {
        printf("Cannot Convert\n"); // 불가
        return 0; //프로그램 종료
    }

    int left = 0; // 왼쪽 반쪽
    int right = num - 1; //오른쪽 반쪽
    // 앞/뒤 절반 채우기
    for (int i = 0; i < 26; i++) 
    {
        int half = a[i] / 2; // 해당 알파벳의 절반 개수
        for (int t = 0; t < half; t++) // 절반 개수만큼 반복
        {
            result[left++] = i + 'A'; // 앞쪽에 알파벳 저장
            result[right--] = i + 'A'; // 뒤쪽에 알파벳 저장
        }
    }

    if (odd_count == 1) // 홀수 개수 알파벳이 있으면
    {
        result[left] = odd_index + 'A'; //가운데 배치
    }
    result[num] = '\0'; //문자열 끝 표시

    printf("%s\n", result); //문자열 출력

    return 0; //프로그램 종료
}


// #include <stdio.h> // 표준 입출력 라이브러리 사용

// int main() // 메인 함수 시작
// {
//     char input[51]; // 문자열 입력받을 배열
//     int a[26]; //알파벳의 개수를 셀 배열
//     int check = 0; // 
//     char result[51]; //마지막에 출력할 배열

//     for(int i = 0;i<26;i++)
//     {
//         a[i] = 0;
//     }
//     for(int i = 0;i<51;i++)
//     {
//         result[i] = 0;
//     }

//     gets(input);     // 문자열 입력 받기

//     int i = 0;
//     for (; input[i] != '\0'; i++) // 문자열 전체의 알파벳 종류랑 개수 세기
//     {
//         char c = input[i]; // 현재 문자 c에 저장 
//         a[c - 'A'] += 1;
//     }

//     int k;

//     for (k = 0; k < i/2; k++)
//     {
//         for (int j = 0; j < 26; j++) 
//         {
//             int t = a[j]; // 반복문 시작 시 a[j]의 값을 t에 저장 (이후 t는 고정)
//             while (a[j] >= t / 2 + 1) // t는 반복 내내 변하지 않음
//             {
//                 result[k] = j + 65;
//                 k += 1;
//                 a[j] -= 1;
//             }
//         }

//     }

//     for (int j = 0; j < 26; j++) 
//     {
//         if(a[j] % 2 == 0 && a[j] != 0)
//         {
//             result[k] = j + 'A';
//         }
//     }

//     for(; k <= i; k++)
//     {
//         result[k] = result[i - k];
//     }
    
//     for(int l = 0 ; l <= i ; l++)
//     {
//         printf("%c", result[l]);
//     }

//     return 0;
// }