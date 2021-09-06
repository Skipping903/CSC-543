#include<stdio.h>
#include <iostream>
using namespace std;

int main()
{
    //The parameters for all of the matrices
    const int oldRows = 4, oldColumns = 5, newRows = 3, newColumns = 6;

    //Had to figure out how exactly to create a 2d array, since I haven't used them before.
    //Sample set
    int badMatrix[oldRows][oldColumns] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };

    //Originally I tried to avoid hardcoding the values here but I gave up after about an hour
    //because I couldn't find a way around c++'s requirement of a constant being needed for arrays.
    int goodMatrix[newRows][newColumns];

    int count = 0;
    for (int i = 0; i < oldRows; i++) 
    {
        for (int j = 0; j < oldColumns; j++) 
        {
            if (badMatrix[i][j] != 0)//Excluding all zeros from new array
            {
                goodMatrix[0][count] = i;//Swapping between the rows of the new matrix wasn't as difficult as I thought it was gonna be originally.
                goodMatrix[1][count] = j;
                goodMatrix[2][count] = badMatrix[i][j];
                count++;
            }
        }   
    }
        

    for (int i = 0; i < newRows; i++)
    {
        for (int j = 0; j < newColumns; j++) 
        {
            cout << goodMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}