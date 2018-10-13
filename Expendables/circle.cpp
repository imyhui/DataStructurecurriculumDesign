#include "circle.h"
#include "public.h"
#include "sqlist.h"
#include "LinkQueue.h"
#include "LinkList.h"

void Circle::doSomething(int m,int n)
{
    switch (n) {
    case 1:outputByArray(m);
        break;
    case 2:outputBySqlist(m);
        break;
    case 3:outputByQueue(m);
        break;
    case 4:outputByLinklist(m);
        break;
    default:
        break;
    }

}
void Circle::outputByArray(int m)
{
        len = 0;
        int s,i,e,count=0;
        int A[ARREY_INIT_SIZE];
        for(i=0; i<m; i++)         A[i]=i+1;  /*为队员赋值*/
            s=m;
            i=0;
            while(s>1)             /*当所剩敢死队员总数为1时,总循环结束*/
            {
                for(i=0; i<m; i++)
                {
                    e = A[i];
                    if(e!=0)
                    {
                        count++;
                        if(count==5)         /*报数循环*/
                        {
                            //qDebug()<<e<<" ";
                            num[len++]=e;
                            //Q.push(e);
                            A[i]=0; /*表示队员出列*/
                            count=0;     /*计数器清零*/
                            s--;         /*敢死队员数-1*/
                        }
                    }
                }
            }
            int h;
            for(i=0; i<m; i++) /*输出*/
                if( A[i]!=0)
                {
                    if((m- A[i]+2)%m==0)
                    {
                        /**/
                        //qDebug()<<"\nThe wanted order is "<<m<<"th\n";
                        h=m;
                        break;
                    }
                    else
                    {
                        //qDebug()<<"\nThe wanted order is "<<(m- A[i]+2)%m<<"th\n";
                        h=(m- A[i]+2)%m;
                        break;
                    }
                }
              for(i=0; i<len; i++)
              {
                  int x= num[i];
                   num[i]=((x+h-1)+m)%m==0?m:((x+h-1)+m)%m;
              }
              num[len++]=1;
//              for(int i = 0;i < len; i++)
//              {
//                    qDebug()<<num[i]<<" ";
//              }
               thef=h;
//             qDebug() <<"Exit please input '0' Or Go on...\nPlease input the tatal of the team:\n";
//        qDebug() << h;
    }
void Circle::outputBySqlist(int m)
{
    len=0;
    int s,i,count=0;
    SqList L;
    InitList_Sq(L);
    for(i=0; i<m; i++) L.elem[i]=i+1;         /*为队员赋值*/
        s=m;
        i=0;
        while(s>1)             /*当所剩敢死队员总数为1时,总循环结束*/
        {
            for(i=0; i<m; i++)
                if(L.elem[i]!=0)
                {
                    count++;
                    if(count==5)         /*报数循环*/
                    {
                        num[len++]=i;
                        L.elem[i]=0; /*表示队员出列*/
                        count=0;     /*计数器清零*/
                        s--;         /*敢死队员数-1*/
                    }
                }
        }
        int h;
        for(i=0; i<m; i++) /*输出*/
            if(L.elem[i]!=0)
            {
                if((m-L.elem[i]+2)%m==0)
                {
                    /**/
//                    printf("\nThe wanted order is %dth\n",m);
                    h=m;
                    break;
                }
                else
                {
//                    printf("\nThe wanted order is %dth\n",(m-L.elem[i]+2)%m);
                    h=(m-L.elem[i]+2)%m;
                    break;
                }
            }
        for(i=0; i<len; i++)
        {
            int x= num[i];
             num[i]=((x+h-1)+m)%m==0?m:((x+h-1)+m)%m+1;
        }
        num[len++]=1;
//              for(int i = 0;i < len; i++)
//              {
//                    qDebug()<<num[i]<<" ";
//              }
         thef=h;
//        while(!Q.empty())
//        {
//            int x=Q.front();
//            Q.pop();
//            printf("%d ",((x+h-1)+m)%m==0?m:((x+h-1)+m)%m);
//        }
//        printf("%d\n",1);
//        printf("Exit please input '0' Or Go on...\nPlease input the tatal of the team:\n");

}
void Circle::outputByQueue(int m)
{
//    queue<int> Q;
    len = 0;
    int i,e,count=0;
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
            num[len++]=e;
//            Q.push(e);
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
    for(i=0; i<len; i++)
    {
        int x= num[i];
         num[i]=((x+h-1)+m)%m==0?m:((x+h-1)+m)%m;
    }
//              for(int i = 0;i < len; i++)
//              {
//                    qDebug()<<num[i]<<" ";
//              }
     thef=h;
}
void Circle::outputByLinklist(int m)
{
    len = 0;
    int s,h,i;
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
        num[len++]=p->data;
        last -> next  = p -> next;
        free(p);
        p = last ->next;
    }
    s=p->data;
    if((m-s+2)%m==0)
    {
//        printf("\nThe wanted order is %dth\n",m);
        h=m;
    }
    else
    {
//        printf("\nThe wanted order is %dth\n",(m-s+2)%m);
        h=(m-s+2)%m;
    }
    for(i=0; i<len; i++)
    {
        int x= num[i];
         num[i]=((x+h-1)+m)%m==0?m:((x+h-1)+m)%m;
    }
    num[len++]=1;
     thef=h;

}
