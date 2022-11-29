//
// Created by alon on 11/23/22.
//
#include <stdio.h>
#include "my_mat.h"
#ifndef ARRAY_LENGTH_AND_WIDTH
#define ARRAY_LENGTH_AND_WIDTH 10
#endif
int pathExistence(int m[ARRAY_LENGTH_AND_WIDTH][ARRAY_LENGTH_AND_WIDTH] , int i, int j){
    if(i == j){
        return 1;
    }
    int ans;
    for( int lineI = 0; lineI < ARRAY_LENGTH_AND_WIDTH; lineI++){
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

void scanMatrix(int m [ARRAY_LENGTH_AND_WIDTH][ARRAY_LENGTH_AND_WIDTH] ) {
    for (int i = 0; i < ARRAY_LENGTH_AND_WIDTH; i++) {
        for (int j = 0; j < ARRAY_LENGTH_AND_WIDTH; j++) {
           scanf("%d", &m[i][j]);
        }
        //printf("CHECK\n");
    }
   // printf("DONE\n");

    return;
}
void shortestPath(int i, int j, int m [ARRAY_LENGTH_AND_WIDTH][ARRAY_LENGTH_AND_WIDTH] ,int visitCounter, int *visited , int *pathLength){
    if(visitCounter == ARRAY_LENGTH_AND_WIDTH){
        return;
    }
    visited[i] = 1;
    int counter = 0;
    for(int k = 0; k < ARRAY_LENGTH_AND_WIDTH ; k++){
        if( (m[i][k] != 0) && (visited[k] == 0) ){
            counter ++ ;
        }
    }
    int neighbors [counter];
    neighborsToVisit(i, m, visited, neighbors);
    updateLength( i , m, pathLength);
    int next = nextNode(neighbors, pathLength,  counter);
    if(next == -1){
        return;
    }
    return shortestPath( next, j, m, visitCounter+1 , visited, pathLength );
}

void neighborsToVisit(int i , int m[ARRAY_LENGTH_AND_WIDTH][ARRAY_LENGTH_AND_WIDTH], int *visited, int *neighbors){
    int counter = 0;
    for(int j = 0; j < ARRAY_LENGTH_AND_WIDTH ; j++) {
        if (m[i][j] != 0) {
            if(visited[j] == 0) {
                neighbors[counter] = j;
                counter++;
            }
        }
    }
}

void updateLength(int i , int m[ARRAY_LENGTH_AND_WIDTH][ARRAY_LENGTH_AND_WIDTH], int *pathLength){
    for(int j = 0; j < ARRAY_LENGTH_AND_WIDTH; j++) {
        if (m[i][j] != 0) {
            int neighbor = j;
            if ((pathLength[neighbor] == -1) || (pathLength[i] + m[i][neighbor] < pathLength[neighbor])) {
                pathLength[neighbor] = pathLength[i] + m[i][neighbor];
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
