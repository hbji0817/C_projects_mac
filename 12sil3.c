#include <stdio.h>

int main() {
    char num[10];  

    while (1) {
        gets(num); 

        if (num[0] == '0' && num[1] == '\0') {
            break;
        }

        int i = 0;
        while (num[i] != '\0') {
            i++;
        }

        int correct = 1;
        for (int j = 0; j < i / 2; j++) {
            if (num[j] != num[i - 1 - j]) {
                correct = 0;
                break;
            }
        }

        // 출력
        if (correct) {
            puts("yes");
        } else {
            puts("no");
        }
    }

    return 0;
}