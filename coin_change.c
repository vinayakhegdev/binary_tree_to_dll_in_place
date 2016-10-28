#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int
main(int argc, char **argv) {
    int coin[5] = {1, 2, 4, 8};
    int sum = 0;
    int len = 4;
    int i = 0, j = 0;
    int m[5][100];

    printf("Enter the sum\n");
    scanf("%d", &sum);
    printf("Sum entered is %d\n", sum);        

    for(i = 0; i < len; i++) {
        m[i][0] = 1;
    }
   
    for(j = 1; j <= sum; j++) {
        if((j % coin[0]) == 0) {
            m[0][j] = 1;
        } else {
            m[0][j] = 0;
        }      
    }      
    for(i = 1; i < len; i++) {
        for(j = 1; j <= sum; j++) {
            if(j >= coin[i]) {
                m[i][j] = m[i - 1][j] + m[i][j - coin[i]];
            } else {
                m[i][j] = m[i - 1][j];
            }     
        }
    }
    printf("Number of ways %d\n", m[len - 1][sum]); 
    printf("===========================m-Table==========================\n");
    for(i = 0; i < len; i++) {
        for(j = 0; j <= sum; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }      

    return 0;
}    

