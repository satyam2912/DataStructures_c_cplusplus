#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//PUSH
void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow:\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
//POP
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow:\n");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

//stack top
int stackTop(struct stack *s)
{
    return s->arr[s->top];
}
///
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
        return 0;
}
///
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
////
char *infixToPostfix(char *infix)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    int infix_len = strlen(infix) + 1;
    char *postfix = (char *)malloc(infix_len * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
    free(s);
}
int main()
{
char *infix = "x-y/z-k*d";
printf("The infix to postfix is %s:\n",infixToPostfix(infix));
    return 0;
}
