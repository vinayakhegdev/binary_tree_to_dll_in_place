#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void 
print_elem(int (*v)[100], int a[], int i, int sum) {
    int x = 0;
    if((sum == 0) || (i == 0)) {
        return;
    }
    x = a[i - 1];
    i = i - 1;
    if(v[i][sum]) {
        print_elem(v, a, i, (sum - x));
        printf("%d\n", x);
    } else {       
        print_elem(v, a, i, sum);
    }
}    

int
main(int argc, char **argv) {
    int a[5] = {1, 2, 4, 8};
    int sum = 0;
    int len = 4;
    int i = 0, j = 0;
    int m[5][100];
    int v[5][100] = {0};

    printf("Enter the sum\n");
    scanf("%d", &sum);
    printf("Sum entered is %d\n", sum);        

    for(i = 0; i < len; i++) {
        m[i][0] = 1;
    }
   
    for(j = 1; j <= sum; j++) {
        if(a[0] == j) {
            m[0][j] = 1;
            v[0][j] = 1;
        } else {
            m[0][j] = 0;
        }      
    }      
    for(i = 1; i < len; i++) {
        for(j = 1; j <= sum; j++) {
            m[i][j] = 0;
            if((m[i - 1][j]) ||
                (m[i - 1][j - a[i]])) {
                if(m[i - 1][j]) {
                    v[i][j] = 0;
                } else {
                    v[i][j] = 1;
                }     
                m[i][j] = 1;
            }     
        }
    }
    if(m[len - 1][sum]) {
        printf("Subset sum found\nElements are\n");
        print_elem(v, a, 4, sum);
    } else {
        printf("No subset sum found\n");
    }
    printf("===========================m-Table==========================\n");
    for(i = 0; i < len; i++) {
        for(j = 0; j <= sum; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }      

    printf("===========================v-Table==========================\n");
    for(i = 0; i < len; i++) {
        for(j = 0; j <= sum; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }       
    return 0;
}    

