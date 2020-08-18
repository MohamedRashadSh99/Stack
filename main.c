#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

////////implementation of Stack
typedef struct
{
 int items[MAXSIZE];
 int top;
} Stack;
void initialize(Stack *s)
{
 s->top=0;
}

void push(Stack *s,int value)
{
 s->items[s->top]=value;
 s->top++;
}
int pop(Stack *s)
{
 int value;
 s->top--;
 value=s->items[s->top];
 return value;
}
 int isEmpty(Stack *s)
{
 if(s->top==0)
 return 1;
 else
 return 0;
}

int top( Stack *s)
{
 return s->items[s->top-1];
}
int isFull(Stack *s)
{
 if(s->top==MAXSIZE)
 return 1;
 else
 return 0;
}

// A function to display stack elements

void display(Stack *s)
{
 Stack copy;
 initialize(&copy);
 while (!isEmpty(s))
 {
 int x=pop(s);
 printf("%d ",x);
 push(&copy,x);
 }
 while (!isEmpty(&copy))
 push(s,pop(&copy));
  printf("\n");
}

/////////////////Implementation of Stack Using Linked_List

typedef struct
{
 int data;
 struct Node *next;
} Node;


typedef struct
{
 Node *top;
} Stack_Linked;



void initialize_Stack_Linked(Stack_Linked *s)
{
 s->top=NULL;
}
void push_Stack_Linked(Stack_Linked *s,int value)
{
 Node* p=malloc(sizeof(Node));
 p->data=value;
 p->next=s->top;
 //if(s->top!=NULL)
 //printf("vefore %d\n",isEmpty_Stack_Linked(s));
 s->top=p;
// if(s->top!=NULL)
// printf("After %d\n",s->top->data);

 //printf(" %d ",value);
}
int pop_Stack_Linked(Stack_Linked *s)
{
 Node *p=s->top;
 int data=p->data;
 s->top=p->next;
 free(p);

 return data;
 }
int isEmpty_Stack_Linked(Stack_Linked *s)
{
 if(s->top==NULL)
 return 1;
else
 return 0;
}
void display_Linked(Stack_Linked *s)
{
 Stack_Linked copy;
 initialize_Stack_Linked(&copy);
 while (!isEmpty_Stack_Linked(s))
 {
 int x=pop_Stack_Linked(s);
 printf("%d ",x);
 push_Stack_Linked(&copy,x);
 }
 while (!isEmpty_Stack_Linked(&copy))
 push_Stack_Linked(s,pop_Stack_Linked(&copy));
  printf("\n");
}

int main()
{
    Stack s1;
    initialize(&s1);
    push(&s1,5);
    push(&s1,6);
    push(&s1,7);
    pop(&s1);
    printf("Stack elements\n");
    display(&s1);
///////////////
Stack_Linked s2;
initialize_Stack_Linked(&s2);
push_Stack_Linked(&s2,1);push_Stack_Linked(&s2,2);push_Stack_Linked(&s2,3);
 printf("\nStack using LinkedList elements\n");
 display_Linked(&s2);
    return 0;
}
