#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *next;
}

struct llstack{
struct Node *top} llstack;

void popStack(struct llstack *stack)
{
    struct Node *var=stack->top;
    if(var->next!=NULL)
    {
        stack->top = stack->top->next;
        free(var);
    }
    else (var!=NULL&&var->next==NULL){
    	top=NULL;
    }
	
}

void push(int value, struct llstack *stack)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->Data=value;
    if (stack->top == NULL)
    {
         stack->top=temp;
         stack->top->next=NULL;
    }
    else
    {
        temp->next=stack->top;
        stack->top=temp;
    }
}


int top(struct llstack *stack)
{
     struct Node *var=stack->top;
     if(var!=NULL)
      return var->Data;
     else
      return -1;

}

void init_stack(struct llstack *stack)
{
	stack->top = NULL;
}
