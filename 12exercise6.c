#include <stdio.h>

int main()
{
    char input[101];
    char word[11];
    char word1[] = "ATTACK";
    char word2[] = "MALWARE";
    char word3[] = "VIRUS";
    int word1_count = 0;
    int word2_count = 0;
    int word3_count = 0;
    int word1_loc[11];
    int word2_loc[11];
    int word3_loc[11];

    gets(input);

    int i = 0;

    while (1)
    {
        int w = 0;
        int start = i; // 단어 시작 위치 저장

        while (input[i] != ' ' && input[i] != '.' && input[i] != '!' && input[i] != '?' && input[i] != '\0') // 단어 하나 추출 
        {
            word[w] = input[i];
            w++;
            i++;
        }
        word[w] = '\0'; // 단어 끝에 널 문자 추가

        int j = 0;
        while (word[j] == word1[j] && word[j] != '\0' && word1[j] != '\0') j++;
        if (word[j] == '\0' && word1[j] == '\0') {
            word1_loc[word1_count++] = start;
        }

        j = 0;
        while (word[j] == word2[j] && word[j] != '\0' && word2[j] != '\0') j++;
        if (word[j] == '\0' && word2[j] == '\0') {
            word2_loc[word2_count++] = start;
        }

        j = 0;
        while (word[j] == word3[j] && word[j] != '\0' && word3[j] != '\0') j++;
        if (word[j] == '\0' && word3[j] == '\0') {
            word3_loc[word3_count++] = start;
        }

        if (input[i] == '\0') break;
        if (input[i] == ' ' || input[i] == '.' || input[i] == '!' || input[i] == '?') i++;
    }

    if(word1_count == 0 && word2_count == 0 && word3_count == 0)
    {
        printf("탐지된 패턴 없음.");
        return 0;
    }

    printf("ATTACK: %d번 등장(위치: ", word1_count);
    for (int i = 0; i < word1_count; i++)
    {
        printf("%d", word1_loc[i]);
        if (i < word1_count - 1) printf(", ");
        else printf(")\n");
    }
    printf("MALWARE: %d번 등장(위치: ", word2_count);
    for (int i = 0; i < word2_count; i++)
    {
        printf("%d", word2_loc[i]);
        if (i < word2_count - 1) printf(", ");
        else printf(")\n");
    }
    printf("VIRUS: %d번 등장(위치: ", word3_count);
    for (int i = 0; i < word3_count; i++)
    {
        printf("%d", word3_loc[i]);
        if (i < word3_count - 1) printf(", ");
        else printf(")\n");
    }

    return 0;
}

// #include <stdio.h>

// int main()
// {
//     char input[101];
//     char word[11];
//     char word1[] = "ATTACK";
//     char word2[] = "MALWARE";
//     char word3[] = "VIRUS";
//     int word1_count = 0;
//     int word2_count = 0;
//     int word3_count = 0;
//     int word1_loc[11];
//     int word2_loc[11];
//     int word3_loc[11];

//     gets(input);

//     int i = 0;

//     while (1)
//     {
//         int w = 0;

//         while (input[i] != ' ' && input[i] != '.' && input[i] != '!' && input[i] != '?' && input[i] != '\0') // 단어 하나 추출 
//         {
//             word[w] = input[i]; // 단어 배열에 문자 저장
//             w = w + 1;      // 단어 배열 인덱스 증가
//             i = i + 1;      // 문자열 A 인덱스 증가
//         }
//         word[w] = '\0'; // 단어 끝에 널 문자 추가

//         int j = 0;

//         while (word[j] == word1[j] && word[j] != '\0' && word1[j] != '\0') 
//         {
//             word1_count++;
//             j++;
//         }
//         j = 0;
//         while (word[j] == word2[j] && word[j] != '\0' && word2[j] != '\0') 
//         {
//             word2_count++;
//             j++;
//         }
//         j = 0;
//         while (word[j] == word3[j] && word[j] != '\0' && word3[j] != '\0') 
//         {
//             word3_count++;
//             j++;
//         }
//         if (input[i] == '\0') break;
//     }



//     if(word1_count == 0 && word2_count == 0 && word3_count == 0)
//     {
//         printf("탐지된 패턴 없음.");
//         return 0;
//     }

//     printf("ATTACK: %d번 등장(위치: ", word1_count);
//     for (int i = 0; i < word1_count; i++)
//     {
//         printf("%d", word1_loc[i]);
//         if (word1_loc[i+1] != '\0') printf(", ");
//         else printf(")\n");
//     }
//     printf("MALWARE: %d번 등장(위치: ", word2_count);
//     for (int i = 0; i < word2_count; i++)
//     {
//         printf("%d", word2_loc[i]);
//         if (word2_loc[i+1] != '\0') printf(", ");
//         else printf(")\n");
//     }
//     printf("VIRUS: %d번 등장(위치: ", word3_count);
//     for (int i = 0; i < word3_count; i++)
//     {
//         printf("%d", word3_loc[i]);
//         if (word3_loc[i+1] != '\0') printf(", ");
//         else printf(")\n");
//     }

//     return 0;
// }