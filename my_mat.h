//
// Created by alon on 11/23/22.
//

#ifndef HW2_MY_MAT_H
#define HW2_MY_MAT_H

int pathExistence(int m[10][10] , int i, int j);
void scanMatrix(int m [10][10] );
void shortestPath(int i, int j, int m [10][10] ,int visitCounter, int *visited , int *pathLength, int  *previos);
void neighborsToVisit(int i , int m[10][10], int *visited, int *neighbors, int *pathLength, int *previos);
#endif //HW2_MY_MAT_H
