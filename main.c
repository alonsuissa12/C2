//
// Created by alon on 11/23/22.
//
#include <stdio.h>
#include "my_mat.h"
int main(){
    char flag = 's';
    int i, j;
    while (flag != 'D') {
        scanf("%c", &flag);
        int m[10][10];

        if (flag == 'A') {
            scanMatrix(m);
        }
        if (flag == 'B') {
            int copy[10][10];
            for (int k = 0; k < 10; k++) {
                for (int t = 0; t < 10; t++) {
                    copy[k][t] = m[k][t];
                }
            }
            scanf("%d%d", &i, &j);
            int exist = pathExistence(copy, i, j);
            if (exist == 1) {
                printf("True");
            } else {
                printf("False");
            }
        }
        if (flag == 'C') {
            printf("a");
           //scanf("%d%d", &i, &j);
           i=1;
           j=3;
            int visited [] = {0,0,0,0,0,0,0,0,0,0,0};
            int pathLength [] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
            int previos [] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
            pathLength[i] = 0;
            printf("b");
            shortestPath(i , j , m , 1 , visited ,pathLength, previos);
            if(previos[j] == -1){
                return -1;
            }
            printf("the path is: ");
            char track [9];
            int node = j;
            int index = 0;
            while (node != i){
                track[index] = node + '0';
                index ++;
                node = previos[node];
            }
            index--;
            char c = i + '0';
            printf("%c" , c);
            for(;index >= 0; index--) {
                printf(" %c" , track[index]);
            }
        }

        if (flag == 'P') {
            for (int l = 0; l < 10; l++) {
                printf("\n");
                for (int r = 0; r < 10; r++) {
                    printf("%d ", m[l][r]);
                }
            }
        }
    }
    printf("\n");
}
