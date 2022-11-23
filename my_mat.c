//
// Created by alon on 11/23/22.
//
#include <stdio.h>
#include "my_mat.h"
int pathExistence(int m[10][10] , int i, int j){
    if(i == j){
        return 1;
    }
    int ans;
    for( int lineI = 0; lineI < 10; lineI++){
        if(m[i][lineI] != 0) {
            m[lineI][i] = 0;
            m[i][lineI] = 0;
            ans = pathExistence(m ,lineI, j);
            if(ans == 1){
                return 1;
            }
        }
    }
    return 0;
}

void scanMatrix(int m [10][10] ) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
           scanf("%d", &m[i][j]);
        }
        printf("CHECK\n");
    }
    printf("DONE\n");

    return;
}
void shortestPath(int i, int j, int m [10][10] ,int visitCounter, int *visited , int *pathLength, int  *previos){

    if(visitCounter == 10){
        return;
    }

    pathLength[i] = 0;
    visited[i] = 1;
    int minIndex = 0;
    int check0 = -1;
    for(int k = 0; k < 10; k++ ) {
        if (m[i][k] != 0) {
                check0 = 1;
                if ( ( (m[i][k]) < m[i][minIndex] ) && (visited[k] == 0) ) {
                    minIndex = k;
                }
                if ((pathLength[i] + m[i][k] < pathLength[k]) || (pathLength[k] == -1)) {
                    pathLength[k] = pathLength[i] + m[i][k];
                    previos[k] = i;
                }
        }
    }
    if(check0 != -1) {
       return shortestPath( minIndex, j, m, visitCounter+1 , visited, pathLength , previos);
    }
    else{
        return;
    }
}
//int min(int a , int b){
//    if (a > b){
//        return b;
//    }
//    return a;
//}