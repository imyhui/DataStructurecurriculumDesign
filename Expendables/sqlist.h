#ifndef SQLIST_H
#define SQLIST_H
//线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量
struct SqList
{
    ElemType *elem; // 存储空间基址
    int length; // 当前长度
    int listsize; // 当前分配的存储容量(以sizeof(ElemType)为单位)
};

//顺序表示的线性表)的基本操作(12个)
Status InitList_Sq(SqList &L)
{
    // 操作结果：构造一个空的顺序线性表
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(OVERFLOW); // 存储分配失败
    L.length=0; // 空表长度为0
    L.listsize=LIST_INIT_SIZE; // 初始存储容量
    return OK;
}

Status DestroyList_Sq(SqList &L)
{
    // 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L
    free(L.elem);
    L.elem=NULL;
    L.length=0;
    L.listsize=0;
    return OK;
}

Status ClearList_Sq(SqList &L)
{
    // 初始条件：顺序线性表L已存在。操作结果：将L重置为空表
    L.length=0;
    return OK;
}

Status ListEmpty_Sq(SqList L)
{
    // 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}

int ListLength_Sq(SqList L)
{
    // 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数
    return L.length;
}

Status GetElem_Sq(SqList L,int i,ElemType &e)
{
    // 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)
    // 操作结果：用e返回L中第i个数据元素的值
    if(i<1||i>L.length)
        exit(ERROR);
    e=*(L.elem+i-1);
    return OK;
}

int LocateElem_Sq(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    // 初始条件：顺序线性表L已存在，compare()是数据元素判定函数(满足为1,否则为0)
    // 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
    //           若这样的数据元素不存在，则返回值为0。算法2.6
    ElemType *p;
    int i=1; // i的初值为第1个元素的位序
    p=L.elem; // p的初值为第1个元素的存储位置
    while(i<=L.length&&!compare(*p++,e))
        ++i;
    if(i<=L.length)
        return i;
    else
        return 0;
}

Status PriorElem_Sq(SqList L,ElemType cur_e,ElemType &pre_e)
{
    // 初始条件：顺序线性表L已存在
    // 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
    //           否则操作失败，pre_e无定义
    int i=2;
    ElemType *p=L.elem+1;
    while(i<=L.length&&*p!=cur_e)
    {
        p++;
        i++;
    }
    if(i>L.length)
        return INFEASIBLE;
    else
    {
        pre_e=*--p;
        return OK;
    }
}

Status NextElem_Sq(SqList L,ElemType cur_e,ElemType &next_e)
{
    // 初始条件：顺序线性表L已存在
    // 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
    //           否则操作失败，next_e无定义
    int i=1;
    ElemType *p=L.elem;
    while(i<L.length&&*p!=cur_e)
    {
        i++;
        p++;
    }
    if(i==L.length)
        return INFEASIBLE;
    else
    {
        next_e=*++p;
        return OK;
    }
}

Status ListInsert_Sq(SqList &L,int i,ElemType e) // 算法2.4
{
    // 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1
    // 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
    ElemType *newbase,*q,*p;
    if(i<1||i>L.length+1) // i值不合法
        return ERROR;
    if(L.length>=L.listsize) // 当前存储空间已满,增加分配
    {
        if(!(newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(OVERFLOW); // 存储分配失败
        L.elem=newbase; // 新基址
        L.listsize+=LISTINCREMENT; // 增加存储容量
    }
    q=L.elem+i-1; // q为插入位置
    for(p=L.elem+L.length-1; p>=q; --p) // 插入位置及之后的元素右移
        *(p+1)=*p;
    *q=e; // 插入e
    ++L.length; // 表长增1
    return OK;
}

Status ListDelete_Sq(SqList &L,int i,ElemType &e) // 算法2.5
{
    // 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)
    // 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
    ElemType *p,*q;
    if(i<1||i>L.length) // i值不合法
        return ERROR;
    p=L.elem+i-1; // p为被删除元素的位置
    e=*p; // 被删除元素的值赋给e
    q=L.elem+L.length-1; // 表尾元素的位置
    for(++p; p<=q; ++p) // 被删除元素之后的元素左移
        *(p-1)=*p;
    L.length--; // 表长减1
    return OK;
}

Status ListTraverse_Sq(SqList L,void(*vi)(ElemType&))
{
    // 初始条件：顺序线性表L已存在
    // 操作结果：依次对L的每个数据元素调用函数vi()。一旦vi()失败，则操作失败
    //           vi()的形参加'&'，表明可通过调用vi()改变元素的值
    ElemType *p;
    int i;
    p=L.elem;
    for(i=1; i<=L.length; i++)
        vi(*p++);
    cout<<endl;
    return OK;
}
#endif // SQLIST_H
