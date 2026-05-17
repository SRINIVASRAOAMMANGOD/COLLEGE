#include<stdio.h>
#include<ctype.h>
#include<math.h>
char stack1[1000];
int stack2[1000];
int t1=-1,t2=-1;

char push1(char c){
    stack1[++t1]=c;
}

int push1(int i){
    stack2[++t2]=i;
}
char pop1(){
if(t1==-1){
return 0;
}
else{ return stack1[t1--];
}}
int pop2(){
if(t2==-1){
return 0;
}
else{ return stack2[t2--];
}}
int prioprity(char c){
if(c=='(') return 0;
else if(c=='+' || c=='-') return 1;
else if(c=='*' || c=='/') return 2;
else if(c=='^') return 3;}
char operator(char a,char b,char x){
if (x=='+') return a+b;
else if (x=='-') return a-b;
else if (x=='*') return a*b;
else if (x=='/') return a/b;
else if (x=='%') return a%b;
else if (x=='^') return pow(a,b);
}
int main(){
char exp[1000],c,w,x,y;
printf("enter choice:");
int i,ch;
scanf("%d",&ch);
switch(ch){
case 1:
printf("enter expression: ");
scanf("%s",exp);
i=0;
while(exp[i]!='\0'){
if(isalpha(exp[i]||isalnum(exp[i])){
printf("%d",exp[i]);
}
else if(exp[i]=='('){
    push1('(');
}
else if(exp[i]==')'){
while((c=pop1())!='('){
printf("%c",c);
}
}
else {
while(prioprity(stack1[t1])>=prioprity(exp[i])){
printf("%c",pop1);
push1(exp[i]);
}}
i++;
}
while(t1!=-1){
c=pop1();
print1("%c",c);
}
break;
}}