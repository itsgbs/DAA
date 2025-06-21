#include <stdio.h>

char id[10];
int deadline[10], profit[10], slot[10], dmax;

int jobsequence(int n) 
{
    int c = 0, i, sump = 0;
    int k;
    dmax = deadline[0];

    for (i = 1; i < n; i++) 
	{
        if (deadline[i] > dmax)
            dmax = deadline[i];
    }

    printf("max deadline : %d\n", dmax);

    for (i = 1; i <= dmax; i++) 
	{
        slot[i] = -1;
    }

    for (i = 0; i < n; i++) 
	{
        k = deadline[i];

        while (k > 0) {
            if (slot[k] == -1) 
			{
                slot[k] = i;
                sump += profit[i];
                c++;
                break;
            }
            k--;
            if (c == dmax)
                break;
        }
    }

    return sump;
}

int main() 
{
    int n, i, j, maxp,tempProfit,tempDeadline;
    char tempId;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter id, deadline and profits:\n");

    for (i = 0; i < n; i++) 
	{
        scanf(" %c %d %d", &id[i], &deadline[i], &profit[i]);
    }

    for (i = 0; i < n - 1; i++) 
	{
        for (j = 0; j < n - i - 1; j++) 
		{
            if (profit[j] < profit[j + 1]) 
			{
                tempId = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tempId;

                tempProfit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempProfit;

                tempDeadline = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = tempDeadline;
            }
        }
    }

    printf("id\t deadline\t profit\n");
    for (i = 0; i < n; i++)
        printf("%c\t %d\t %d\n", id[i], deadline[i], profit[i]);

    maxp = jobsequence(n);

    printf("max profit=%d\n", (int)maxp);
    printf("Solution vector: ");
    for (i = 1; i <= dmax; i++)
        if (slot[i] != -1)
            printf("[%c]", id[(int)slot[i]]);

    return 0;
}

