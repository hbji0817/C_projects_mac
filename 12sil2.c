#include <stdio.h>

int main()
{
    char arr[101];
    int a[26];
    for(int i = 0; i < 26; i++)
    {
        a[i] = -1;
    }
    
    scanf("%s",arr);
    for(int i = 0; arr[i] != '\0'; i++) {
        int index = arr[i] - 'a';  
        if(a[index] == -1) { 
            a[index] = i;
        }
    }

    for(int i = 0; i < 26; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
