/*Dynamic Storage Allocation Problem
Best Fit
*/


#include<stdio.h>
int main()
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowst = 9999;
    static int barry[20], parray[20];

    printf("\n\t\tMemory Mangement Scheme - Best Fit\n\n");

    printf("ENter The Number of Blocks: ");
    scanf("%d", &nb);

    printf("Enter The Number of Process: ");
    scanf("%d", &np);

    printf("\nEnter The Size of The Blocks-\n");
    for(i = 1; i <= nb; i++)
    {
        printf("Block No. %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter The Size of The Processes-\n");
    for(i = 1; i <= np; i++)
    {
        printf("Process No %d: ", i);
        scanf("%d", &p[i]);
    }

    for(i = 1; i <= np; i++)
    {
        for(j = 1; j <= nb; j++)
        {
            if(barry[j] != 1)
            {
                temp = b[j] - p[i];

                if(temp >= 0)
                {
                    if(lowst > temp)
                    {
                        parray[i] = j;
                        lowst = temp;
                    }
                }
            }
        }

        fragment[i] = lowst;
        barry[parray[i]] = 1;
        lowst = 10000;
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\tFragment");

    for(i = 1; i <= np && parray[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parray[i], b[parray[i]], fragment[i]);

    return 0;
}


/*
Sample Input/Output:


                Memory Mangement Scheme - Best Fit
                
ENter The Number of Blocks: 4
Enter The Number of Process: 4

Enter The Size of The Blocks-
Block No. 1: 5
Block No. 2: 14
Block No. 3: 16
Block No. 4: 30

Enter The Size of The Processes-
Process No 1: 10
Process No 2: 14
Process No 3: 16
Process No 4: 20

Process No.     Process Size    Block No.       Block Size      Fragment
1               10              2               14              4       
2               14              3               16              2       
3               16              4               30              14      

*/