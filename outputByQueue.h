#ifndef OUTPUTBYQUEUE_H_INCLUDED
#define OUTPUTBYQUEUE_H_INCLUDED

#include "LinkQueue.h"
void outputByQueue(int m)
{
    queue<int> Q;
    int s,i,e,count=0;
    LinkQueue L;
    InitQueue(L);
    //if(m>L.length)   /*��˳���ǰ����Ĵ洢�ռ��С����ʱ�����ٷ���*/
    //   L=ListInsert_Sq(L);
    for(i=0; i<m; i++) EnQueue(L,i+1);         /*Ϊ��Ա��ֵ*/
    //QueueTraverse(L,print);
    i=0;
    while(!QueueEmpty(L))             /*����ʣ������Ա����Ϊ1ʱ,��ѭ������*/
    {
        DeQueue(L,e);
        count++;
        if(count==5)         /*����ѭ��*/
        {
            Q.push(e);
            count=0;     /*����������*/
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
