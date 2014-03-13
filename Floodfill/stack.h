#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *next;
}Node;

struct llstack{
struct Node *top;}llstack;

void popStack(struct llstack *stack);

void push(int value, struct llstack *stack);


int top(struct llstack *stack);
int stackIsEmpty(struct llstack *stack);
void init_stack(struct llstack *stack);

