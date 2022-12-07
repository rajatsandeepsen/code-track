#include <stdio.h>
void bestFit(int block[], int blockSIZE, int process[], int processSIZE)
{
    for (int i = 0; i < processSIZE; i++)
    {
        int flag = 0;
        for (int j = 0; j < blockSIZE; j++)
        {
            if (block[j] >= process[i])
            {
                printf("Process %d (%dKB) allocated at %dKB Memory Space\n", i + 1, process[i], block[j]);
                block[j] -= process[i];
                printf("Remaining space is : %d\n\n", block[j]);
                flag = 1;
                break;
            }
        }

        if (flag != 1)
        {
            printf("Process %d (%dKB) is not allocated\n\n", i + 1, process[i]);
        }
    }
}

int main()
{
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 600};
    int m = sizeof(block) / sizeof(block[0]);
    int n = sizeof(process) / sizeof(process[0]);

    bestFit(block, m, process, n);
}