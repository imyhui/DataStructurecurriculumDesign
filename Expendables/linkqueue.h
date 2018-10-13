#ifndef LINKQUEUE_H
#define LINKQUEUE_H
typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue &Q)
{
    Q.front  = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.front) exit(OVERFLOW);
    Q.front ->next = NULL;
    return OK;
}
Status EnQueue(LinkQueue &Q,ElemType e)
{
    QueuePtr p  = (QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p ->data = e; p ->next = NULL;
    Q.rear ->next = p;
    Q.rear = p;
    return OK;
}
Status DeQueue(LinkQueue &Q,ElemType &e)
{
    if(Q.front == Q.rear) return ERROR;
    QueuePtr p  = Q.front->next;
    e = p ->data;
    Q.front ->next = p ->next;
    if(Q.rear == p) Q.rear = Q.front;
    free(p);
    return OK;
}
Status GetHead(LinkQueue Q,ElemType &e)
{
    if(Q.front == Q.rear)
    return ERROR;
    QueuePtr p = Q.front->next;
    e = p->data;
    return OK;
}
bool QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
    return true;
    else
    return false;
}
Status QueueTraverse(LinkQueue Q,void(*vi)(ElemType))
{
  QueuePtr p;
  p=Q.front->next;
  while(p)
  {
    vi(p->data);
    p=p->next;
  }
  printf("\n");
  return OK;
}
#endif // LINKQUEUE_H
