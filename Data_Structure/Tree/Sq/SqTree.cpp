#include <iostream>
using namespace std;
#define MaxSize 10
#define ElementType int
#define Status bool
#define OK true

typedef struct Binary_Tree
{
  /* data */
  ElementType data[MaxSize];
  bool isEmpty;
} * Tree;

Status init_BinaryTree(Tree &T)
{
  for (int i = 0; i < MaxSize; i++)
  {
    /* code */
    T->isEmpty = true;
    T->data[i] = i;
  }
}

int main()
{
  Binary_Tree *T;
  // 初始化一个顺序存储结构的树
  init_BinaryTree(T);
}