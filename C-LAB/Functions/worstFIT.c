#include <stdio.h>
void bestFit(int block[], int blockSIZE, int process[], int processSIZE)
{
    for (int i = 0; i < processSIZE; i++)
    {
        int worstFIT = -1;
        for (int j = 0; j < blockSIZE; j++)
        {
            if (block[j] >= process[i])
            {
                if (worstFIT == -1)
                    worstFIT = j;
                else if (block[worstFIT] < block[j])
                    worstFIT = j;
            }
        }

        if (worstFIT != -1)
        {
            printf("Process %d (%dKB) allocated at %dKB Memory Space\n", i + 1, process[i], block[worstFIT]);
            block[worstFIT] -= process[i];
            printf("Remaining space is : %d\n\n", block[worstFIT]);
        }
        else
            printf("Process %d (%dKB) is not allocated\n\n", i + 1, process[i]);
    }
}

int main()
{
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {400, 417, 112, 626};
    int m = sizeof(block) / sizeof(block[0]);
    int n = sizeof(process) / sizeof(process[0]);

    bestFit(block, m, process, n);
}