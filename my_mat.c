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
    visited[i] = 1;
    int minIndex = 0;
    int nextOptions = 0;

    int counter = 0;
    for(int j = 0; j < 10 ; j++){
        if( (m[i][j] != 0) && (visited[j] == 0) ){
            counter ++ ;
        }
    }
    if(counter == 0) {
        return;
    }
    int neighbors [counter];
    neighborsToVisit(i, m, visited, neighbors , pathLength, previos);
    for(int k = 0; k < counter; k++ ) {
        int neighbor = neighbors[k];
            if ( ( (m[i][neighbor]) < m[i][minIndex] ) ) {
                minIndex = neighbor;
            }
            if ((pathLength[i] + m[i][neighbor] < pathLength[neighbor]) || (pathLength[neighbor] == -1)) {
                pathLength[neighbor] = pathLength[i] + m[i][neighbor];
                previos[neighbor] = i;
            }
    }
    return shortestPath( minIndex, j, m, visitCounter+1 , visited, pathLength , previos);
}

void neighborsToVisit(int i , int m[10][10], int *visited, int *neighbors, int *pathLength, int *previos){
    int counter = 0;
    for(int j = 0; j < 10 ; j++) {
        if (m[i][j] != 0) {
            if(visited[j] == 0) {
                neighbors[counter] = j;
                counter ++;
            }
            else{
                if (pathLength[i] + m[i][j] < pathLength[j] ) {
                    pathLength[j] = pathLength[i] + m[i][j];
                    previos[j] = i;
                }
            }
        }
    }
}

//int min(int a , int b){
//    if (a > b){
//        return b;
//    }
//    return a;
//}