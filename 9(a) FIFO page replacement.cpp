/*
Page Replacement Algorithm
FIFO
*/

#include <stdio.h>
int main()
{
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;

    printf("Enter The Length of The Reference String: ");
    scanf("%d", &n);

    printf("Enter The Reference String: ");

    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    printf("Enter the number of Frames: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1;

    j = 0;

    printf("Ref String\t Page Frames\n");

    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;

        for (k = 0; k < no; k++)
        {
            if (frame[k] == a[i])
                avail = 1;
        }

        if (avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;

            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }

        printf("\n\n");
    }

    printf("Page Fault is: %d\n", count);
    return 0;
}


/*

20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3

Sample Input/Output-1:

Enter The Length of The Reference String: 10       
Enter The Reference String: 7 0 1 2 0 3 0 4 2 3    
Enter the number of Frames: 3

Ref String       Page Frames
7               7       -1      -1

0               7       0       -1

1               7       0       1

2               2       0       1

0

3               2       3       1

0               2       3       0

4               4       3       0

2               4       2       0

3               4       2       3

Page Fault is: 9



Sample Input/Output-2:

Enter The Length of The Reference String: 20
Enter The Reference String: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter the number of Frames: 3

Ref String       Page Frames
7               7       -1      -1

0               7       0       -1

1               7       0       1

2               2       0       1

0

3               2       3       1

0               2       3       0

4               4       3       0

2               4       2       0

3               4       2       3

0               0       2       3

3

2

1               0       1       3

2               0       1       2

0

1

7               7       1       2

0               7       0       2

1               7       0       1

Page Fault is: 15

*/