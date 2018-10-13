#ifndef OUTPUTBYQUEUE_H_INCLUDED
#define OUTPUTBYQUEUE_H_INCLUDED

#include "LinkQueue.h"
void outputByQueue(int m)
{
    queue<int> Q;
    int s,i,e,count=0;
    LinkQueue L;
    InitQueue(L);
    //if(m>L.length)   /*当顺序表当前分配的存储空间大小不足时进行再分配*/
    //   L=ListInsert_Sq(L);
    for(i=0; i<m; i++) EnQueue(L,i+1);         /*为队员赋值*/
    //QueueTraverse(L,print);
    i=0;
    while(!QueueEmpty(L))             /*当所剩敢死队员总数为1时,总循环结束*/
    {
        DeQueue(L,e);
        count++;
        if(count==5)         /*报数循环*/
        {
            Q.push(e);
            count=0;     /*计数器清零*/
        }
        else
            EnQueue(L,e);
    }
    int h;
    if((m-e+2)%m==0)
    {
        /**/
        printf("\nThe wanted order is %dth\n",m);
        h=m;
    }
    else
    {
        printf("\nThe wanted order is %dth\n",(m-e+2)%m);
        h=(m-e+2)%m;
    }
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        printf("%d ",((x+h-1)+m)%m==0?m:((x+h-1)+m)%m);
    }
    printf("\n");
    printf("Exit please input '0' Or Go on...\nPlease input the tatal of the team:\n");

}




#endif // OUTPUTBYQUEUE_H_INCLUDED
