#include <stdio.h>
#include<stdlib.h>
typedef struct stack{
    int size;
    int top;
    int *arr;

}stack;

int isEmpty(stack *s){
    if (s->top==-1) {
        return 1;
    }else{
        return 0;
    }  
}
int isFull(stack *s){
    if (s->top==s->size) {
        return 1;
    }else{
        return 0;
    }  
}

//push
void push(stack * s,int value){
if (isFull(s)){
    printf("Stak is full you cannot push element:\n");
}else{
    s->top++;
    s->arr[s->top]=value;
}
}

int main(){
     stack *s;
    s = ( stack *) malloc(sizeof(stack));
    s->size = 8;
    s->top=-1;
    s->arr = (int*) malloc(s->size* sizeof(int));
 while(!isEmpty(s)) {
      int data = pop();
      printf("%d\n",data);
   }
    return 0;
}