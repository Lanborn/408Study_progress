#include <iostream>
using namespace std;
#define MaxSize 50
#define ElementType int
#define Status bool
#define OK true

typedef struct
{
  /* data */
  ElementType data[MaxSize];
  int top;
} SqStack;

Status isFairOperato(char *A)
{
  int j = 0;
  int i = 0;
  int k = 0;
  int len = sizeof(A) / sizeof(char);
  while (A[i] != '\0')
  {
    if (A[i] == 'I')
      j++;
    if (A[i] == 'O')
      k++;
    if (k > j)
    {
      cout << "非法序列" << endl;
      return false;
    }
    i++;
  }
  if (j != k)
    cout << "非法序列" << endl;
  else
    cout << "合法序列" << endl;
  return OK;
}

int main()
{
  char test[9] = "IOOIOIIO";
  isFairOperato(test);
  system("pause");
  return 0;
}