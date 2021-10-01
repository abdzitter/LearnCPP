#include<iostream>
#include<string>
#include<bits/stdc++.h> 
using namespace std;
struct stack1
{
    int Size;
    int Top;
    char *p;
};
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
void pusH(stack1 *st,char x)
{ 
    if(st->Top<st->Size)
    {
        st->Top=st->Top+1;
        st->p[st->Top]=x;  
    }
}
char poP(stack1 *st)
{
    char c='0';
    if(st->Top==-1)
    return c;
    else
    {
        c=st->p[st->Top];
        st->Top=st->Top-1;
    }
    return c;
}
void infixTopostfix(char *infi )
{
    stack1 st;
    st.Size=strlen(infi);
    st.p=new char[st.Size];
    st.Top=-1;
    pusH(&st,'N');
    char *post=new char[strlen(infi)];
    int z=0;
    for(int i=0;infi[i];i++)
    {
           if(infi[i] >= 'a' && infi[i] <= 'z')
           {
                post[z]=infi[i];
                z++;
           }
          else if(infi[i] == '(') 
          {
                pusH(&st,'('); 
          }
          else if(infi[i]==')')
          {
                while(st.p[st.Top]!='N'&&st.p[st.Top]!='(')
                {
                    char c=poP(&st);
                    post[z]=c;
                    z++;
                }
                if(st.p[st.Top]== '(') 
                { 
                    poP(&st);
                } 
          }
          else
          {  
                while(st.p[st.Top]!='N'&&prec(infi[i])<=prec(st.p[st.Top]))
                {
                    char c=poP(&st);
                    post[z]=c;
                    z++;
                }
            pusH(&st,infi[i]);
          }  
    }    
            while(st.p[st.Top] != 'N') 
            { 
                        char c=poP(&st);
                        post[z]=c; 
                        z++;
            } 
            for(int j=0;post[j];j++)
            {
                cout << post[j];
            }
}
int main()
{
     char exp1[] = "a+b*(c^d-e)^(f+g*h)-i"; 
     infixTopostfix(exp1); 
    return 0;
}