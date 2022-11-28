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
        int m[10][10]={
                {0, 9, 48, 20, 10, 39, 22, 49, 44, 33},
                       {9, 0, 38, 45, 26, 22, 2, 4 ,26, 42},
                       { 48, 38, 0, 47, 32, 5 ,5, 1, 5, 12},
                       { 20, 45, 47, 0, 19, 4, 36, 46, 36, 4},
                       {10, 26, 32, 19, 0, 46, 16, 3, 37, 27},
                       {39, 22, 5 ,4, 46, 0 ,46, 29, 16, 28},
                       {22, 2, 5, 36, 16, 46, 0, 4 ,46, 7},
                       {49, 4 ,1 ,46, 3, 29, 4 ,0, 10, 41},
                       {44, 26, 5 ,36, 37, 16, 46, 10, 0 ,19},
                       {33 ,42, 12 ,4 ,27, 28, 7, 41, 19, 0}
         };
        int copy[10][10];
        if (flag == 'A') {
            //scanMatrix(m);
        }
        if (flag == 'B') {
            for (int k = 0; k < 10; k++) {
                for (int t = 0; t < 10; t++) {
                    copy[k][t] = m[k][t];
                }
            }
            scanf("%d%d", &i, &j);
            int exist = pathExistence(copy, i, j);
            if (exist == 1) {
                printf("True\n");
            } else {
                printf("False\n");
            }
        }
        if (flag == 'C') {
           scanf("%d%d", &i, &j);
              for (int k = 0; k < 10; k++) {
                for (int t = 0; t < 10; t++) {
                    copy[k][t] = m[k][t];
                }
            }
           int exist = pathExistence(copy, i, j);
           if(exist == 0){
               printf("-1\n");
           }
           else {
               int visited[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
               int pathLength[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
               int previos[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
               pathLength[i] = 0;
               shortestPath(i, j, m, 1, visited, pathLength, previos);
//               if (previos[j] == -1) {
//                   printf("-1\n");
//               }
               char pathLengthChar = pathLength[j] + '0';
               printf("%c\n", pathLengthChar);
           }
        }

//        if (flag == 'P') {
//            for (int l = 0; l < 10; l++) {
//                printf("\n");
//                for (int r = 0; r < 10; r++) {
//                    printf("%d ", m[l][r]);
//                }
//            }
//        }
    }

    return 0;
}
