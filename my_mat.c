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
        //printf("CHECK\n");
    }
   // printf("DONE\n");

    return;
}
void shortestPath(int i, int j, int m [10][10] ,int visitCounter, int *visited , int *pathLength, int  *previos){ //need to fix case that there is no path from i to j.
    if(visitCounter == 10){
        return;
    }
    visited[i] = 1;
    int counter = 0;
    for(int k = 0; k < 10 ; k++){
        if( (m[i][k] != 0) && (visited[k] == 0) ){
            counter ++ ;
        }
    }
    int neighbors [counter];
    neighborsToVisit(i, m, visited, neighbors);
    updateLengthAndPrev( i , m, pathLength, previos);
    int next = nextNode(neighbors, pathLength,  counter);
    if(next == -1){
        return;
    }
    return shortestPath( next, j, m, visitCounter+1 , visited, pathLength , previos);
}

void neighborsToVisit(int i , int m[10][10], int *visited, int *neighbors){
    int counter = 0;
    for(int j = 0; j < 10 ; j++) {
        if (m[i][j] != 0) {
            if(visited[j] == 0) {
                neighbors[counter] = j;
                counter++;
            }
        }
    }
}

void updateLengthAndPrev(int i , int m[10][10], int *pathLength, int *previos){
    for(int j = 0; j < 10; j++) {
        if (m[i][j] != 0) {
            int neighbor = j;
            if ((pathLength[neighbor] == -1) || (pathLength[i] + m[i][neighbor] < pathLength[neighbor])) {
                pathLength[neighbor] = pathLength[i] + m[i][neighbor];
                previos[neighbor] = i;
            }
        }
    }
}
int nextNode(int *neighbors, int *pathLength, int neighborsLength){
    if(neighborsLength == 0){
        return -1;
    }
    int next = neighbors[0];
    for(int i = 1; i < neighborsLength; i++ ){
        int neighbor = neighbors[i];
        if(pathLength[neighbor] < pathLength[next] ){
            next = neighbor;
        }
    }
    return next;
}
