#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
//모든 동물 쌍을 찾으면 게임 종료
//총 실패 횟수 알려주기

int arrayAnimal[4][5]; // 카드 지도 (20장)
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인
char * strAnimal[10];
int foundAllAnimals();

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();

int main()
{
    srand(time(NULL));

    initAnimalArray(); // 수정된 함수 이름
    initAnimalName();
    shuffleAnimal();

    int failCount = 0;

    while (1)
    {
        int select1 = 0; // 사용자가 선택한 첫 번째 수
        int select2 = 0; // 두 번째 수

        printAnimals(); // 동물 위치 출력
        printQuestion(); // 문제 출력
        printf("뒤집을 카드를 2개 고르세요 : ");
        scanf("%d %d", &select1, &select2);

        if (select1 == select2) // 같은 카드 선택 시 무효
            continue;

        // 좌표에 해당하는 카드를 뒤집어보고 같은지 확인
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        // 같은 동물인 경우
        if (checkAnimal[firstSelect_x][firstSelect_y] == 0 
            && checkAnimal[secondSelect_x][secondSelect_y] == 0 // 카드가 뒤집히지 않았는지
            && arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]) // 둘이 같은지
        {
            printf("\n\n빙고! : %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y] = 1;
            checkAnimal[secondSelect_x][secondSelect_y] = 1;
        }
        else
        {
            printf("\n\n틀렸거나 이미 뒤집힌 카드입니다\n\n");
            printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            printf("\n\n");

            failCount++;
        }

        // 모든 동물을 찾았을 때
        if (foundAllAnimals() == 1)
        {
            printf("\n\n축하합니다! 성공하셨습니다\n");
            printf("총 실수는 %d회입니다", failCount);
            break;
        }
    }

    return 0;
}

void initAnimalArray()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalName()
{
    strAnimal[0] = "  원숭이";
    strAnimal[1] = "    하마";
    strAnimal[2] = "  강아지";
    strAnimal[3] = "  고양이";
    strAnimal[4] = "    돼지";

    strAnimal[5] = "  코끼리";
    strAnimal[6] = "    기린";
    strAnimal[7] = "    낙타";
    strAnimal[8] = "    타조";
    strAnimal[9] = "  호랑이";
}

void shuffleAnimal()
{
    //ㅁㅁㅁㅁㅁ
    //ㅁㅁㅁㅁㅁ
    //ㅁㅁㅁㅁㅁ
    //ㅁㅁㅁㅁㅁ

    for( int i = 0 ; i < 10; i++)
    {
        for(int j=0;j<2;j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition()
{
    while(1)
    {
        int randPos = rand() % 20;
        // 19 -> [3][4]
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if(arrayAnimal[x][y] == -1)
        {
            return randPos;
        }

    }
    return 0;
}

int conv_pos_x(int x)
{
    //19 -> [3][4]
    return x / 5;
}
int conv_pos_y(int y)
{
    return y % 5;
}

void printAnimals()
{
    printf("\n 답임 \n");
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0; j < 5 ; j++)
        {
            printf("%8s",strAnimal[arrayAnimal[i][j]]);

        }
        printf("\n");
    }
    printf("\n===============================\n\n");
}
void printQuestion()
{
    printf("\n\n(문제)\n");
    int seq = 0;
                   //seq                   checkAnimal
    //ㅁㅁㅁㅁㅁ   0  1  2  3  4            0  0  0  0  0
    //ㅁㅁㅁㅁㅁ 하마  6  7  8  9            1  0  0  0  0 
    //ㅁㅁㅁㅁㅁ  10 11 하마 13 14           0  0  1  0  0
    //ㅁㅁㅁㅁㅁ  15 16 17 18 19            0  0  0  0  0

    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0; j < 5 ; j++)
        {
            if(checkAnimal[i][j] != 0)
            {
                printf("%8s",strAnimal[arrayAnimal[i][j]]);
            }

            else
            {
                printf("%8d", seq);
            }
            seq++;
        }
        printf("\n");
    }
}

int foundAllAnimals()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0; j < 5 ; j++)
        {
            if(checkAnimal[i][j] == 0)
            {
                return 0;
            }
            
        }
    }
    return 1;
}