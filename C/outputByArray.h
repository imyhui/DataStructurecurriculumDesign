#ifndef OUTPUTBYARRAY_H_INCLUDED
#define OUTPUTBYARRAY_H_INCLUDED
#define ARREY_INIT_SIZE 100
void outputByArray(int m)
{
    queue<int> Q;
    int s,i,e,count=0;
    int A[ARREY_INIT_SIZE];
    for(i=0; i<m; i++)         A[i]=i+1;  /*Ϊ��Ա��ֵ*/
        s=m;
        i=0;
        while(s>1)             /*����ʣ������Ա����Ϊ1ʱ,��ѭ������*/
        {
            for(i=0; i<m; i++)
            {
                e = A[i];
                if(e!=0)
                {
                    count++;
                    if(count==5)         /*����ѭ��*/
                    {
                        Q.push(e);
                        A[i]=0; /*��ʾ��Ա����*/
                        count=0;     /*����������*/
                        s--;         /*������Ա��-1*/
                    }
                }
            }
        }
        int h;
        for(i=0; i<m; i++) /*���*/
            if( A[i]!=0)
                if((m- A[i]+2)%m==0)
                {
                    /**/
                    printf("\nThe wanted order is %dth\n",m);
                    h=m;
                    break;
                }
                else
                {
                    printf("\nThe wanted order is %dth\n",(m- A[i]+2)%m);
                    h=(m- A[i]+2)%m;
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

}



#endif // OUTPUTBYARRAY_H_INCLUDED
