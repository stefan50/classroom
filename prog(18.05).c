#include <stdio.h>
#include <stdlib.h>

struct stack_t
{
        int *arr;
        int top;
        int size;
}stack;

struct stack_t stack_init(int size);
void stack_destroy(struct stack_t* st);
void push(struct stack_t *stack, int elem);
int size(struct stack_t stack);
int top(struct stack_t);
void pop(struct stack_t *stack);
int is_full(struct stack_t);
int is_empty(struct stack_t);
void stack_resize(struct stack_t*);
struct stack_t stack_copy(struct stack_t);
float rpn_solve(char* rpn_exp);

int main()
{
	int i;
	char* rpn_exp;
	for(i=0;i<2;i++)
	{
		push(&stack,'2');
	}
	push(&stack,'+');
	printf("%f",rpn_solve(rpn_exp));
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
int is_full(struct stack_t stack)
{
	if(stack.top == stack.size) return 1;
	else return 0;
}
int is_empty(struct stack_t stack)
{
	if(stack.top == 0) return 1;
	else return 0;
}
void stack_resize(struct stack_t* stack)
{
	stack->size*=2;
	stack->arr=realloc(stack->arr,sizeof(int)*(stack->size));
}
struct stack_t stack_copy(struct stack_t stack)
{
	int i;
	struct stack_t stack_cpy;
	stack_cpy.size = stack.size;
	stack_cpy.top = stack.top;
	stack_cpy.arr = malloc(sizeof(int)*stack.size);
	for(i=0;i<stack_cpy.top;i++)
	{
		*(stack_cpy.arr+i)=*(stack.arr+i);
	}
	return stack_cpy;
}
void rpn_push(struct stack_t* stack,char* rpn_exp)
{
	int i,size = stack->size;
	for(i=0;i<size;i++)
	{
		if(*(rpn_exp+i)!=' ') push(stack,*(rpn_exp+i));
	}
}
float rpn_solve(char* rpn_exp)
{
	int el,i;
	struct stack_t rpn = stack_init(10);
	float num,result=0;
	for(i=0;i<6;i++)
	{
		if(*(rpn_exp+i)>=0 && *(rpn_exp+i)<=9)
		{
			push(&rpn,*(rpn_exp+i));
		}
		else if(*(rpn_exp+i) == '+')
		{
			el=top(rpn);
			pop(&rpn);
			result+=el;
			el=top(rpn);
			pop(&rpn);
		}
	}
	stack_destroy(&rpn);
	return result;
}
