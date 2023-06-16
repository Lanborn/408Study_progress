#include <iostream>
using namespace std;
#define MaxSize 10
#define ElementType int
#define Status bool
#define OK true

// typedef struct
// {
//   /* data */
//   ElementType *base; // 存储空间的基地址
//   int front;         // 头指针
//   int rear;          // 尾指针
// } SqQueue;

// typedef struct
// {
//   /* data */
//   ElementType *base; // 存储空间的基地址
//   int front;         // 头指针
//   int rear;          // 尾指针
//   int size;          // 当前队列长度
// } SqQueue;

typedef struct
{
  /* data */
  ElementType *base; // 存储空间的基地址
  int front;         // 头指针
  int rear;          // 尾指针
  int tag;
} SqQueue;

Status InitQueue(SqQueue &Q)
{
  Q.base = new ElementType[MaxSize];
  if (!Q.base)
    exit(0);
  Q.front = Q.rear = 0; //队列为空
  return OK;
}

Status isEmpty(SqQueue &Q)
{
  if (Q.rear == Q.front && Q.tag == 0)
    return OK;
  return false;
}

// 获取队列长度
ElementType getLength(SqQueue Q)
{
  return (MaxSize + Q.rear - Q.front) % MaxSize;
}

Status EnQueue(SqQueue &Q, ElementType e)
{
  // if ((Q.rear + 1) % MaxSize == Q.front) // 判断队满

  if (Q.tag == 1 && Q.rear == Q.front) // 判断队满
    return false;
  Q.base[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MaxSize;
  Q.tag = 1;
  return OK;
}

Status PopQueue(SqQueue &Q, ElementType &e)
{
  // if (Q.rear == Q.front)
  if (Q.tag == 0 && Q.rear == Q.front) // 判断队空
    return false;
  e = Q.base[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  Q.tag = 0;
  return OK;
}

ElementType getQueueTop(SqQueue &Q)
{
  if (Q.front != Q.rear)
    return Q.base[Q.front];
}
int main()
{
  SqQueue Q;
  InitQueue(Q);
  for (int i = 0; i < 10; i++)
  {
    if (EnQueue(Q, i))
      cout << "入队成功" << i << endl;
    else
      cout << "入队失败" << endl;
  }
  Q.rear = (Q.rear + MaxSize - 1) % MaxSize;
  cout << "-------------------------------" << endl;

  cout << "队列长度" << getLength(Q) << endl;

  cout << "出队顺序：" << endl;
  while (!isEmpty(Q))
  {
    int x = 0;
    PopQueue(Q, x);
    cout << "队顶元素：" << getQueueTop(Q) << endl;
    cout << x << endl;
  }
  system("pause");
  return 0;
}