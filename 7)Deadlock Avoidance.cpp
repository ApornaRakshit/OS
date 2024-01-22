#include <stdio.h>
#include<conio.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void input();
void show();
void cal();
int main()
{
    int i,j;
    printf("********** Banker's Algo ************\n");
    input();
    show();
    cal();
    getch();
    return 0;
}
void input()
{
    int i,j;
    printf("Enter the no of Processes: ");
    scanf("%d",&n);
    printf("Enter the no of resources instances: ");
    scanf("%d",&r);
    printf("Enter the Max Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<r; j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the Allocation Matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<r; j++)
        {
            scanf("%d",&alloc[i][j]);
        }

    }
    printf("Enter the available Resources: ");
    for(j=0; j<r; j++)
    {
        scanf("%d",&avail[j]);
    }
}
void show()
{
    int i,j;
    printf("\nProcess\t\tAllocation\tMax\t\tAvailable\t\t");
    for(i=0; i<n; i++)
    {
        printf("\nP%d\t\t",i+1);
        for(j=0; j<r; j++)
        {
            printf("%d ",alloc[i][j]);
        }
        printf("\t\t");
        for(j=0; j<r; j++)
        {
            printf("%d ",max[i][j]);
        }
        printf("\t\t");
        if(i==0)
        {
            for(j=0; j<r; j++)
                printf("%d ",avail[j]);
        }
    }
}
void cal()
{
    int finish[100],temp,need[100][100],flag=1,k,c1=0;
    int safe[100];
    int i,j;
    for(i=0; i<n; i++)
    {
        finish[i]=0;
    }
//find need matrix
    for(i=0; i<n; i++)
    {
        for(j=0; j<r; j++)

        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\n");
    while(flag)
    {
        flag=0;
        for(i=0; i<n; i++)
        {
            int c=0;
            for(j=0; j<r; j++)
            {
                if((finish[i]==0)&&(need[i][j]<=avail[j]))
                {
                    c++;
                    if(c==r)
                    {
                        for(k=0; k<r; k++)
                        {
                            avail[k]+=alloc[i][j];
                            finish[i]=1;
                            flag=1;
                        }
                        printf("P%d->",i);
                        if(finish[i]==1)
                        {
                            i=n;
                        }
                    }
                }
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(finish[i]==1)
        {
            c1++;
        }
        else
        {
            printf("P%d->",i);
        }

    }
    if(c1==n)
    {
        printf("\n\nThe system is in safe state");
    }
    else
    {
        printf("\n\nProcess are in dead lock");
        printf("\n\nSystem is in unsafe state");
    }
}

/*
********** Banker's Algo ************
Enter the no of Processes: 2
Enter the no of resources instances: 2
Enter the Max Matrix:
1
2
5
3
Enter the Allocation Matrix:
1
4
2
4
Enter the available Resources: 1
2

Process         Allocation      Max             Available
P1              1 4             1 2             1 2
P2              2 4             5 3
P0->P1->

The system is in safe state
*/