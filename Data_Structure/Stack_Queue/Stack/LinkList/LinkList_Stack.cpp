#include <iostream>
using namespace std;
#define ElementType int
#define Status bool
#define OK true

typedef struct LinkList_Stack
{
  /* data */
  ElementType data;
  struct LinkList_Stack *next;
} * LinkStack;
Status initStack(LinkStack &S)
{
  S = NULL;
  return OK;
}

Status isEmptyStack(LinkStack &S)
{
  // ��ջ
  if (S == NULL)
    return OK;
  return false;
}
Status PushStack(LinkStack &S, ElementType e)
{
  // LinkStack p;
  LinkList_Stack *p = new LinkList_Stack;
  p->data = e;
  p->next = S;
  S = p;
  return OK;
}
Status PopStack(LinkStack &S, ElementType &e)
{
  if (S == NULL)
    return false;
  LinkStack p = S;
  e = p->data;
  S = S->next;
  delete p;
  return OK;
}
ElementType getStackTop(LinkStack &S)
{
  if (S != NULL)
  {
    return S->data;
  }
}

Status CoreE(LinkStack &S)
{
  if (S == NULL)
    return false;
  return OK;
}

int main()
{
  LinkStack S;
  initStack(S);
  for (int i = 0; i < 10; i++)
  {
    if (PushStack(S, i))
      cout << "��ջSuccess��" << i << endl;
    else
      cout << "��ջʧ�� " << endl;
  }
  cout << "-------------------------------" << endl;

  cout << "��ջ˳��" << endl;
  while (!isEmptyStack(S))
  {
    int x = 0;
    PopStack(S, x);
    cout << "ջ��Ԫ�أ�" << getStackTop(S) << endl;
    cout << x << endl;
  }
  system("pause");
  return 0;
}