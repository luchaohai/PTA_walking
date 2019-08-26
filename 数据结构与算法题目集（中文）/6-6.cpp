// 函数题
// 错误集结——

List MakeEmpty()
{
  // 思路问题
  // 这里的空是一定要返回一个空结点？不看题目，带头结点…… 如果不能对于Data一定要赋值么？
  List newNode = (List)malloc(sizeof(List));
  // 不需要考虑Data
  // newList->Data = -1;
  newNode->Next = NULL;
  return newNode;
}

Position Find(List L, ElementType X)
{
  while (L)
  {
    if (L->Data == X)
    {
      return L;
    }
    L = L->Next;
  }
  return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
  while (L)
  {
    if (L->Next == P)
    {
      List newNode = (List)malloc(sizeof(List));
      newNode->Data = X;
      newNode->Next = P;
      L->Next = newNode;
      return true;
    }
    L = L->Next;
  }
  printf("Wrong Position for Insertion\n");
  return false;
}

bool Delete(List L, Position P)
{
  while (L)
  {
    if (L->Next == P)
    {
      L->Next = L->Next->Next;
      return true;
    }
    L = L->Next;
  }
  printf("Wrong Position for Deletion\n");
  return false;
}