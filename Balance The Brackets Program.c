// This code is not optimized please check it before use.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global stack for better access in all functions
int top = -1;
char *stack;
int length = 0;
char stackelement = ' ';

// Function to get closing bracket
char closing(char i){
    if (i=='('){
        return ')';
    }
    if(i=='{'){
        return '}';
    }
    if(i=='['){
        return ']';
    }
}

// To insert any character in the start but not used
void insert(char *arr,int pos,int value,int size){
    for(int i=size-1;i>=pos-1;i--)
    arr[i+1]=arr[i];
    arr[pos-1]= value;
}

// Create a array for l bytes of data
void createstack(int l){
    length = l;
    stack = malloc(l);
}

//Push the element in the stack
char push(char element){
    if (top<length-1){
        top+=1;
        stack[top] = element;
    }else{
        printf("Stack is full");
        return '1';
    }
}

//Pop the element in the stack
char pop(){
    if (top!=-1){
        top-=1;
        printf("\nPoped %c",stack[top+1]);
        return stack[top+1];
    }else{
        printf("\nUnderflow");
        return '1';
    }
}

int main(){
    int length;
    printf("Enter the length of the input : ");
    scanf("%d",&length);
    char brackets[length+1];
    printf("Enter the brackets without spaces : ");
    scanf("%s",brackets);
    createstack(length);
    int flag =0;
    char ans[length*2];

    // Loop to traverse through the brackets and push the opening brackets
    // in the stack. If we get any closing bracket we just check if it's 
    // equal to the current bracket in stack top, if its equal then it will 
    // pop the stack and then continue, this whole events are recorded from
    // ans array which will hold the final array of paranthesis,
    // If stack is empty and there is a closing bracket it will be skipped.
    // If stack is not empty even after traversing through the brackets then
    // the elements in the stack will be automatically closed.


    for(int i =0;i<=length;i++){
        if (brackets[i] == '[' || brackets[i] == '{' || brackets[i] == '('){
            push(brackets[i]);
            ans[i] = brackets[i];
            printf("\nPushed %c",brackets[i]);
        }else{
            if (brackets[i]==')'){
            stackelement = pop();
            if(stackelement == '1'){
                continue;
            }
             
            if ('(' != stackelement){
                ans[i] = closing(stackelement);
            }else{
                ans[i] = ')';
            }
        }
        if (brackets[i]==']'){
            stackelement = pop();
            if(stackelement == '1'){
                continue;
            }
            if ('[' != stackelement){
                ans[i] = closing(stackelement);
            }else{
                ans[i] = ']';
            }
        }
        if (brackets[i]=='}'){
            stackelement = pop();
            if(stackelement == '1'){
                continue;
            }
            if ('{' != stackelement){
                ans[i] = closing(stackelement);
            }else{
                ans[i] = '}';
            }
        }
        }
        // Must needed to end the string so that random characters don't
        // form inside the string and better arrangement of the string.
        ans[i+1] = '\0';
    }
    int i = strlen(ans);
    
    if(top!=-1){
        // This loop here takes all the remaining elements from that stack
        // and append them to the ans.
        // These are basically ending brackets that needs to be closed.
        while(top!=-1){
            stackelement = pop();
            if (stackelement == '('){
                stackelement = ')';
            }
            
            if (stackelement == '{'){
                stackelement = '}';
            }
            
            if (stackelement == '['){
                stackelement = ']';
            }
            ans[i] = stackelement;
            i++;
        }
    }
    // Don't delete this in worst case there will be random things on the string
    ans[i+1] = '\0';
    
    printf("\n\nThe final unbalanced array will be : %s",ans);
}
