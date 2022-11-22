#include <stdio.h>
#include <stdlib.h>

//This practical tackles the Tower of Hanoi puzzle game using a recursive function. 

void hanoi (int n, int source, int destination, int inter)
{
    //base case when the number of discs is only 1
    if (n==1)
    {
        printf("Move disc from %d to %d\n", source, destination);
    }
    else
    {
        // Applying the function recursively for (n-1) discs from the source rod  to intermediary rod
        hanoi(n-1,source,inter,destination);
        printf("Move disc from %d to %d\n", source, destination);
        // applying the function recursively for (n-1) discs from the intermediary rod to destination rod
        hanoi(n-1,inter,destination,source);
    }
}

int main(void)
{
    //Set the number of discs used in this hanoi game
    int h = 2;
    printf("Solution for %d discs: \n", h);
    //We send the function the number of discs, the source rod, the destination rod and the intermediary rod
    hanoi(h, 1, 3, 2);
    return 0;
}
