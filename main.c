#include <stdio.h>
#include <stdlib.h>
#define Len sizeof (struct cacu)
struct cacu
{
    float num;
    struct cacu *next;
}*fi,*ch;
struct cacu *create()
{
    struct cacu *head;
    head=NULL;
    return head;
}
struct cacu * push(struct cacu *head,float num)
{
    struct cacu *p;
    p=(struct cacu *)malloc(Len);
    p->num=num;
    p->next = head;
    head=p;
    return head;
}
struct cacu * pop(struct cacu *head,float *num)
{
    struct cacu *p;
    *num=head->num;
    p=head;
    head=head->next;
    free(p);
    return head;
}
int juge(int jia,float ho)
{
    switch(jia)
    {
        case 1 : ;
        case 2 : if (ho == 3 || ho == 4 || ho == 5) return -1;
                   return 1;
        case 3 : ;
        case 4 : if (ho == 5) return -1;
                 return 1;
        case 5 : if (ho == 6) return 0;
                 return -1;
        case 6 : return 1;
        case 7 : if(ho == 7) return 0;
                return -1;
    }
}
int change(char ch)
{
    switch(ch)
    {
        case '+' : return 1;
        case '-' : return 2;
        case '*' : return 3;
        case '/' : return 4;
        case '(' : return 5;
        case ')' : return 6;
        case '#' : return 7;
    }
}
float gettop(struct cacu * p)
{
    return p->num;
}
float cau(float a,int si, float b)
{
    switch(si)
    {
        case 1 : return a+b;
        case 2 : return a-b;
        case 3 : return a*b;
        case 4 : return a/b;
    }
}
int main()
{
    char ar='.';
    float a,b,si,q,num;
    int p,ju,su,num1;
    ch=create();
    fi=create();
    ch=push(ch,7);
    do
    {
        num1=-1;
        if (ar != '#') loop : scanf ("%c",&ar);
        if (ar>='0' && ar<='9')
        {
            if (num1 == -1) num1++;
            num1*=10;
            su=ar-'0';
            num1+=su;
            goto loop;
        }
        else
        {
              p=change(ar);
              num=(float)num1;
              if (num1 != -1) fi=push(fi,num);
              ji:ju=(int)gettop(ch);
               switch (juge(ju,p))
              {
                  case -1:
                           ch=push(ch,p);
                           break;
                  case 1:
                           ch=pop(ch,&si);
                           fi=pop(fi,&a);
                           fi=pop(fi,&b);
                           si=(int)si;
                           fi=push(fi,cau(b,si,a));
                           goto ji;
                           break;
                  case 0:
                           ch=pop(ch,&q);
                           break;
              }
        }
    }while (ch != NULL);
    printf("%f\n",fi->num);
    return 0;
}/*1+(2*3)#*/
