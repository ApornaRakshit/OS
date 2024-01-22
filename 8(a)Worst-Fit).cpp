#include<stdio.h>
#define max 25

main()
{
    int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
    static int bf[max],ff[max];

    printf("\n\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d",&nb);
    printf("Enter the number of files:");
    scanf("%d",&nf);
    printf("\nEnter the size of the blocks:-\n");
    for(i=1; i<=nb; i++)
    {
        printf("Block %d:",i);
        scanf("%d",&b[i]);
    }
    printf("Enter the size of the files :-\n");
    for(i=1; i<=nf; i++)
    {
        printf("File %d:",i);
        scanf("%d",&f[i]);
    }
    for(i=1; i<=nf; i++)
    {
        for(j=1; j<=nb; j++)
        {
            if(bf[j]!=1) //if bf[j] is not allocated
            {
                temp=b[j]-f[i];
                if(temp>=0)
                {
                    if(highest<temp)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
                }
            }
        }
        frag[i]=highest;
        bf[ff[i]]=1;
        highest=0;
    }
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragement");
    for(i=1; i<=nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);

}
/*

        Memory Management Scheme - Worst Fit
Enter the number of blocks:4
Enter the number of files:3

Enter the size of the blocks:-
Block 1:60
Block 2:50
Block 3:20
Block 4:10
Enter the size of the files :-
File 1:5
File 2:10
File 3:15

File_no:        File_size:      Block_no:       Block_size:     Fragement
1               5               1               60              55
2               10              2               50              40
3               15              3               20              5
Process returned 0 (0x0)   execution time : 32.006 s
Press any key to continue.


*/
