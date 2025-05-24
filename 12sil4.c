#include <stdio.h>

int main(){
    char input[1000000];
    int count=0;
    for (int i = 0;; i++){
        scanf("%c",&input[i]);
        if (i==0 && input[i]==' '){
            continue;
        }
        if (input[i-1]!=' ' && input[i]==' '){
            count++;
        }
        if (input[i]=='\n' && input[i-1]==' '){
            break;
        }
        if (input[i]=='\n'){
            count++;
            break;
        }
    }
    printf("%d\n",count);
    return 0;
}