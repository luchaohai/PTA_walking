// 函数题
// 错误集结——
// 1. null 需要大写
// 2. next 头字母需要大写，大小写很重要
// 情况分析——
// 1. 正常的整数数列
// 2. 只有一位的整数数列
// 3. 非整数的通常情况
// 4. 空数组的情况

List Reverse(List L)
{
  // 考虑到原链表尾指针的NULL到时候会摒弃
  List result = NULL;
  while (L)
  {
    List pos = L;
    L = L->Next;
    pos->Next = result;
    result = pos;
  }
  return result;
}