#include <stdio.h>
void bestFit(int block[], int blockSIZE, int process[], int processSIZE)
{
    for (int i = 0; i < processSIZE; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < blockSIZE; j++)
        {
            if (block[j] >= process[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (block[bestIdx] > block[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {
            printf("Process %d (%dKB) allocated at %dKB Memory Space\n", i + 1, process[i], block[bestIdx]);
            block[bestIdx] -= process[i];
            printf("Remaining space is : %d\n", block[bestIdx]);
        }
        else
            printf("Process %d (%dKB) is not allocated\n", i + 1, process[i]);
    }
}

int main()
{
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 626};
    int m = sizeof(block) / sizeof(block[0]);
    int n = sizeof(process) / sizeof(process[0]);

    bestFit(block, m, process, n);
}