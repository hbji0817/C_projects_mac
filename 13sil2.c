#include <stdio.h>

typedef struct {
    int x;
    int y;
} locate;

int main()
{
    locate t;
    printf("사분면을 검색할 좌표를 입력하시오: ");
    scanf("%d %d", &t.x, &t.y);

    if(t.x > 0)
    {
        if(t.y > 0)
        {
            printf("1사분면 입니다.");
        }
        else if(t.y < 0)
        {
            printf("4사분면 입니다.");
        }
        else
        {
            printf("y축에 있습니다.");
        }
    }
    else if(t.x < 0)
    {
        if(t.y > 0)
        {
            printf("2사분면 입니다.");
        }
        else if(t.y < 0)
        {
            printf("3사분면 입니다.");
        }
        else
        {
            printf("y축에 있습니다.");
        }
    }
    else
    {
        printf("x축에 있습니다.");
    }

    return 0;
}
