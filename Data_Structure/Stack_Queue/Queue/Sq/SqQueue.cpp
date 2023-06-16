#include <iostream>
using namespace std;
#define MaxSize 10
#define ElementType int
#define Status bool
#define OK true

// typedef struct
// {
//   /* data */
//   ElementType *base; // �洢�ռ�Ļ���ַ
//   int front;         // ͷָ��
//   int rear;          // βָ��
// } SqQueue;

// typedef struct
// {
//   /* data */
//   ElementType *base; // �洢�ռ�Ļ���ַ
//   int front;         // ͷָ��
//   int rear;          // βָ��
//   int size;          // ��ǰ���г���
// } SqQueue;

typedef struct
{
  /* data */
  ElementType *base; // �洢�ռ�Ļ���ַ
  int front;         // ͷָ��
  int rear;          // βָ��
  int tag;
} SqQueue;

Status InitQueue(SqQueue &Q)
{
  Q.base = new ElementType[MaxSize];
  if (!Q.base)
    exit(0);
  Q.front = Q.rear = 0; //����Ϊ��
  return OK;
}

Status isEmpty(SqQueue &Q)
{
  if (Q.rear == Q.front && Q.tag == 0)
    return OK;
  return false;
}

// ��ȡ���г���
ElementType getLength(SqQueue Q)
{
  return (MaxSize + Q.rear - Q.front) % MaxSize;
}

Status EnQueue(SqQueue &Q, ElementType e)
{
  // if ((Q.rear + 1) % MaxSize == Q.front) // �ж϶���

  if (Q.tag == 1 && Q.rear == Q.front) // �ж϶���
    return false;
  Q.base[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MaxSize;
  Q.tag = 1;
  return OK;
}

Status PopQueue(SqQueue &Q, ElementType &e)
{
  // if (Q.rear == Q.front)
  if (Q.tag == 0 && Q.rear == Q.front) // �ж϶ӿ�
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
      cout << "��ӳɹ�" << i << endl;
    else
      cout << "���ʧ��" << endl;
  }
  Q.rear = (Q.rear + MaxSize - 1) % MaxSize;
  cout << "-------------------------------" << endl;

  cout << "���г���" << getLength(Q) << endl;

  cout << "����˳��" << endl;
  while (!isEmpty(Q))
  {
    int x = 0;
    PopQueue(Q, x);
    cout << "�Ӷ�Ԫ�أ�" << getQueueTop(Q) << endl;
    cout << x << endl;
  }
  system("pause");
  return 0;
}