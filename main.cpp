#include "allheader.h"

int main()
{
    queue<int> Q;
    SqList L;
    int s,i,m,count=0;    /*��������*/
    InitList_Sq(L);
    printf("Please input the tatal of the team:");
    scanf("%d",&m);        /*���������Ա����*/
    while(m!=0)/*������Ϊ0ʱ�˳�����*/
    {
        //if(m>L.length)   /*��˳���ǰ����Ĵ洢�ռ��С����ʱ�����ٷ���*/
        //   L=ListInsert_Sq(L);
        for(i=0; i<m; i++) L.elem[i]=i+1;         /*Ϊ��Ա��ֵ*/
        s=m;
        i=0;
        while(s>1)             /*����ʣ������Ա����Ϊ1ʱ,��ѭ������*/
        {
            for(i=0; i<m; i++)
                if(L.elem[i]!=0)
                {
                    count++;
                    if(count==5)         /*����ѭ��*/
                    {
                        Q.push(L.elem[i]);
                        L.elem[i]=0; /*��ʾ��Ա����*/
                        count=0;     /*����������*/
                        s--;         /*������Ա��-1*/
                    }
                }
        }
        int h;
        for(i=0; i<m; i++) /*���*/
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
        scanf("%d",&m);        /*���������Ա����*/
    }
    return 0;
}
