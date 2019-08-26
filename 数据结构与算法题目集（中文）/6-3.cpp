// 函数题

int Length(List L)
{
  List pos = L;
  int len = 0;
  while (pos)
  {
    len++;
    pos = pos->Next;
  }
  return len;
}