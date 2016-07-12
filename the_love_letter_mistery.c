/*
 * https://www.hackerrank.com/challenges/the-love-letter-mystery
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);
    for(;num > 0; num--) {
        int diff = 0;
        char str[10000];
        scanf("%s", str);
        int len = strlen(str);
        for(int i = 0; i < len / 2; i++) {
            int j = len - i - 1;
            if(str[i] != str[j]) {
                diff += abs(str[i] - str[j]);
            }
        }
        printf("%d\n", diff);
    }
    return 0;
}


