#ifndef OUTPUTBYLINKLIST_H_INCLUDED
#define OUTPUTBYLINKLIST_H_INCLUDED
#include "LinkList.h"
void outputByLinklist(int m)
{
    queue<int> Q;
    int s,h,count=0;
    LinkList L;
    InitList_CL(L,m);
    //ListTraverse_CL(L,print);
    LinkList p=L,last;
    while(p->next!=p)
    {
        for(int i = 1; i < 5; i++)
        {
            last = p;
            p = p -> next;
        }
        Q.push(p->data);
        last -> next  = p -> next;
        free(p);
        p = last ->next;
    }
    s=p->data;
    if((m-s+2)%m==0)
    {
        printf("\nThe wanted order is %dth\n",m);
        h=m;
    }
    else
    {
        printf("\nThe wanted order is %dth\n",(m-s+2)%m);
        h=(m-s+2)%m;
    }
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        printf("%d ",((x+h-1)+m)%m==0?m:((x+h-1)+m)%m);
    }
    printf("%d\n",1);

    printf("Exit please input '0' Or Go on...\nPlease input the tatal of the team:\n");
}
#endif // OUTPUTBYLINKLIST_H_INCLUDED
