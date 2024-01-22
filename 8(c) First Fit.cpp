Dynamic Storage Allocation Problem
First Fit
*/

/*
Full Form-

bno = Number of Blocks
pno = Number of Processes
bsize = Size of Block
psize = Size of Process

*/

#include<stdio.h>
int main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;

    for(i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }

    printf("Enter No. of Blocks: ");
    scanf("%d", &bno);

    printf("\nEnter The Size of Each Block: ");

    for(i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("\nEnter No. of Processes: ");
    scanf("%d", &pno);

    printf("\nEnter Size of Each Process: ");

    for(i = 0; i < pno; i++)
        scanf("%d", &psize[i]);

    for(i = 0; i < pno; i++)
    {
        for(j = 0; j < bno; j++)
        {
            if(flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
        }
    }

    printf("\n Block No. \t Size \t\t Process No. \t\t Size");

    for(i = 0; i < bno; i++)
    {
        printf("\n %d \t\t %d \t\t ", i + 1, bsize[i]);

        if(flags[i] == 1)
            printf("%d \t\t\t %d ", allocation[i] + 1, psize[allocation[i]]);

        else
            printf("Not Allocated");
    }

    return 0;
}


/*

Sample Input/Output:

Enter No. of Blocks: 4

Enter The Size of Each Block: 16 5 15 30

Enter No. of Processes: 3

Enter Size of Each Process: 13 10 20

 Block No.       Size            Process No.             Size
 1               16              1                       13
 2               5               Not Allocated
 3               15              2                       10
 4               30              3                       20

*/