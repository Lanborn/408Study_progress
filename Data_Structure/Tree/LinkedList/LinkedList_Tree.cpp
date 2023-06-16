#include <iostream>
#include "..\..\Stack\LinkList\LinkList_Stack.cpp"
using namespace std;
#define MaxSize 10
#define ElementType int
#define Status bool
#define OK true

typedef struct LinkNode
{
  /* data */
  ElementType data;
  struct LinkNode *LNode, *RNode;
} LinkNode, *LinkTree;

void InitTree(LinkTree &T)
{
}

// 递归
void InOrderTraverse(LinkTree T)
{
  // 中序遍历
  if (T != NULL)
  {
    InOrderTraverse(T->LNode);
    cout << T->data;
    InOrderTraverse(T->RNode);
  }
}

void NotRecInOrderTraverse(LinkTree T)
{
  LinkStack S;
  initStack(S);
  LinkTree p = T;
  LinkNode *q = new LinkNode;
  if (p || isEmptyStack(S))
  {
    if (p)
    {
      // PushStack(S, p);
      p = p->LNode;
    }
    else
    {
      // PopStack(S, q);
      cout << q->data;
      p = q->RNode;
    }
  }
}

void preOrderTraversal(LinkTree T)
{

  if (T != NULL)
  {
    cout << T->data;
    preOrderTraversal(T->LNode);
    preOrderTraversal(T->RNode);
  }
}

int main()
{
  LinkTree T;
  InitTree(T);
  return 0;
}