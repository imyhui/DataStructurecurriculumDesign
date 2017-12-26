#include "allheader.h"

int main()
{
    int m,kind=0;    /*声明变量*/
    printf("Please input the tatal of the team:");
    scanf("%d",&m);        /*输入敢死队员总数*/
    while(m!=0)/*当输入为0时退出程序*/
    {
        printf("Please choose the DataStructure:\n");
        printf("1.SqList 2、LinkList 3、数组 4、队列：");
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
          scanf("%d",&m);        /*输入敢死队员总数*/
    }
    return 0;
}
