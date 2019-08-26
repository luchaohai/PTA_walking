// 函数题

ElementType FindKth(List L, int K)
{
  List pList = L;
  int pos = 0;
  while (pList)
  {
    // 说明第一个元素存在
    pos++;
    if (pos == K)
    {
      return pList->Data;
    }
    pList = pList->Next;
  }
  return ERROR;
}