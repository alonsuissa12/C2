//
// Created by alon on 11/23/22.
//
#include <stdio.h>
#include "my_mat.h"
int main(){
    char flag = 's';
    int i, j;
    int m[10][10]= {0};
    int copy[10][10] ={0};
    while (flag != 'D') {
        scanf("%c", &flag);
        if (flag == 'A') {
            scanMatrix(m);
        }
        if (flag == 'B') {
            for (int k = 0; k < 10; k++) {
                for (int t = 0; t < 10; t++) {
                    copy[k][t] = m[k][t];
                }
            }
            scanf("%d%d", &i, &j);
            if(i == j){
                printf("False\n");
            }
            else {
                int exist = pathExistence(copy, i, j);
                if (exist == 1) {
                    printf("True\n");
                } else {
                    printf("False\n");
                }
            }
        }
        if (flag == 'C') {
            scanf("%d%d", &i, &j);
            if (i == j) {
                printf("%d\n", -1);
            }
            else
            {
                for (int k = 0; k < 10; k++) {
                    for (int t = 0; t < 10; t++) {
                        copy[k][t] = m[k][t];
                    }
                }
                int exist = pathExistence(copy, i, j);
                if (exist == 0) {
                    printf("%d\n", -1);
                } else {
                    int visited[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    int pathLength[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
                    pathLength[i] = 0;
                    shortestPath(i, j, m, 1, visited, pathLength);
                    //char pathLengthChar = pathLength[j] + '0';
                    printf("%d\n", pathLength[j]);
                }
            }
        }

    }

    return 0;
}
