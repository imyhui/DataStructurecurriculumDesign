#include "allheader.h"

int main()
{
    int m,kind=0;    /*��������*/
    printf("Please input the tatal of the team:");
    scanf("%d",&m);        /*���������Ա����*/
    while(m!=0)/*������Ϊ0ʱ�˳�����*/
    {
        printf("Please choose the DataStructure:\n");
        printf("1.SqList 2��LinkList 3������ 4�����У�");
        scanf("%d",&kind);
        while(kind>=4)
        {
            printf("The num out of range,Please input again:");
            scanf("%d",&kind);
        }
        switch(kind)
        {
            case 1:
                    outputBySqlist(m);
                    break;
            default:
                break;
        }
          scanf("%d",&m);        /*���������Ա����*/
    }
    return 0;
}
