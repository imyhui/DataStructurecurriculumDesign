#include "allheader.h"

int main()
{
    queue<int> Q;
    SqList L;
    int s,i,m,count=0;    /*声明变量*/
    InitList_Sq(L);
    printf("Please input the tatal of the team:");
    scanf("%d",&m);        /*输入敢死队员总数*/
    while(m!=0)/*当输入为0时退出程序*/
    {
        //if(m>L.length)   /*当顺序表当前分配的存储空间大小不足时进行再分配*/
        //   L=ListInsert_Sq(L);
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
                        Q.push(L.elem[i]);
                        L.elem[i]=0; /*表示队员出列*/
                        count=0;     /*计数器清零*/
                        s--;         /*敢死队员数-1*/
                    }
                }
        }
        int h;
        for(i=0; i<m; i++) /*输出*/
            if(L.elem[i]!=0)
                if((m-L.elem[i]+2)%m==0)
                {
                    /**/
                    printf("\nThe wanted order is %dth\n",m);
                    h=m;
                    break;
                }
                else
                {
                    printf("\nThe wanted order is %dth\n",(m-L.elem[i]+2)%m);
                    h=(m-L.elem[i]+2)%m;
                    break;
                }
        while(!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            printf("%d ",((x+h-1)+m)%m==0?m:((x+h-1)+m)%m);
        }
        printf("%d\n",1);
        printf("Exit please input '0' Or Go on...\nPlease input the tatal of the team:\n");
        scanf("%d",&m);        /*输入敢死队员总数*/
    }
    return 0;
}
