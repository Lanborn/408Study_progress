#include <iostream>
using namespace std;
#define MaxSize 10
#define ElementType int
#define Status bool
#define OK true

typedef struct LinkNode
{
  /* data */
  ElementType data;
  LinkNode *next;
} LinkNode;

typedef struct
{
  /* data */
  LinkNode *front;
  LinkNode *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
  Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode)); // 带头结点
  // Q.front = Q.rear = NULL;                                 // 不带
  Q.front->next = NULL;
}

Status isEmpty(LinkQueue Q)
{
  // 带头结点
  if (Q.front == Q.rear)
    return OK;
  return false;
  // 不带
  // if (Q.front == NULL)
  //   return OK;
  // return false;
}

void testLinkQueue()
{
}