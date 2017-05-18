#include <stdio.h>
#include <stdlib.h>

struct stack_t
{
        int *arr;
        int top;
        int size;
};

struct stack_t stack_init(int size);
void stack_destroy(struct stack_t* st);
void push(struct stack_t *stack, int elem);
int size(struct stack_t stack);
int top(struct stack_t);
void pop(struct stack_t *stack);

int main()
{
        struct stack_t st = stack_init(5);
        stack_destroy(&st);
        return 0;
}

struct stack_t stack_init(int size)
{
        struct stack_t st;
        st.size = size;
        st.top = 0;
        st.arr = malloc(sizeof(int)*size);
        return st;
}
void stack_destroy(struct stack_t* st)
{
        free(st->arr);
        st->arr = NULL;
        st->size = 0;
        st->top = -1;
}
void push(struct stack_t *stack, int elem)
{
        stack->arr[stack->top++] = elem; //top is going to be saved (that's why it is a pointer)
}
int size(struct stack_t stack)
{
        return stack.top;
}
int top(struct stack_t st)
{
        if(size(st)!=0) return st.arr[st.top-1];
        return -1;
}
void pop(struct stack_t *stack)
{
        if(size(*stack) != 0) //size requires a non-pointer
        stack->top--; //We don't delete it entirely, just logically by showing the previous element
}


