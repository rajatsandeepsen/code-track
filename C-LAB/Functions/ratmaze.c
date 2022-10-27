// write c program to implement rat in a maze problem using stack
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 4
struct stack
{
    int x;
    int y;
    struct stack *next;
};
struct stack *top = NULL;
void push(int x, int y)
{
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    temp->x = x;
    temp->y = y;
    temp->next = top;
    top = temp;
}
void pop()
{
    struct stack *temp;
    temp = top;
    top = top->next;
    free(temp);
}
void display()
{
    struct stack *temp;
    temp = top;
    while (temp != NULL)
    {
        printf("%d %d", temp->x, temp->y);
        temp = temp->next;
    }
}
bool isSafe(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};
    int x = 0, y = 0;
    while (x != N - 1 || y != N - 1)
    {
        if (isSafe(maze, x, y))
        {
            sol[x][y] = 1;
            push(x, y);
            if (isSafe(maze, x + 1, y))
                x++;
            else if (isSafe(maze, x, y + 1))
                y++;
            else
            {
                sol[x][y] = 0;
                pop();
                if (top->x == x)
                    y--;
                else
                    x--;
            }
        }
        else
        {
            sol[x][y] = 0;
            pop();
            if (top->x == x)
                y--;
            else
                x--;
        }
    }
    sol[x][y] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
    return true;
}
int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};
    solveMaze(maze);
    return 0;
}
