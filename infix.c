#include <stdio.h>
#include<ctype.h>

#define SIZE 50

char stack[SIZE];
int top=-1;

 void Push(char elem)
{
       stack[++top]=elem;
}
char Pop()
{
    return(stack[top--]);
}
int pr(char symbol)
{
    if(symbol=='^')
    {
        return(3);
    }
    else if(symbol == '*' ||symbol == '/')
    {
        return(2);
    }
    else if(symbol == '+'|| symbol =='-')
    {
        return(1);
    }
    else 
    {
        return(0);
        
    }
}
    int main()
    {
        char infix[50],Postfix[50],ch,elem;
        int i=0,k=0;
        printf("Enter Infix Exression :");
        scanf("%s",infix);
        Push('#');
        while ( (ch=infix[i++]) != '\0')
        {
            if( ch == '(') Push(ch);
            else
            if(isalnum(ch)) Postfix[k++]=ch;
            else
            if (ch ==')')
            {
                while(stack [top] !='(')
                 Postfix[k++]=Pop();
                 elem=Pop();
            }
            else 
            {
                while(pr(stack[top]) >= pr(ch))
                Postfix[k++]=Pop();
                Push(ch);
            }
            }
            while(stack [top] !='#')
            Postfix[k++]=Pop();
            Postfix[k]='\0' ;
            printf("\n Postfix Expression = %s \n",Postfix);
            
        }