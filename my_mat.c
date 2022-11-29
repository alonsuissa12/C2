//
// Created by alon on 11/23/22.
//
#include <stdio.h>
#include "my_mat.h"
#ifndef ARRAY_LENGTH_AND_WIDTH
#define ARRAY_LENGTH_AND_WIDTH 10
#endif

/*
* The function is checking if there is a path from i to j.
*@param  m : The matrix
*@param i , j : indexes
*/
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
/*
*that function read the matrix from the user.
*@param  m : The matrix
*/
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
/*
*The function checks what is the shortest path from i to j, 
* it's upgrades the "neighbors" array and "pathLength" arrays
*
*@param  m : The matrix
*@param i , j : indexes
*@param visitCounter : 
*@param *visited: array which told us if we have checked this index or not yet 
*@param *pathLength:  the path length until now.
* 
*/
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
/*
*this function upgrades the "neighbors" array.
*such that every index we want to check will be in "neighbors" and in his place 
*in the mat will be zero.
*
*@param i : the index we wanted a path from him to j
*@param m : the matrix 
*@param *visited: array which told us if we have checked this index or not yet  
*@param *neighbors : the neighbors array include all the indexes we can arrive to them from i 
*/
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

/*
*This function upgrades the length of the path.
*
*@param i : the index we wanted a path from him to j.
*@param m : the matrix .
*@param *pathLength : the path length until now.
*/
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
/*
*this function return the next node we should go for the shortest way from i to j
*
*param *neighbors : the "neighbors" array include all the indexes we can arrive to them from i 
*@param *pathLength : the length until now.
*@param neighborsLength:
*/
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
