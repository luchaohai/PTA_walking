// 函数题
// 知识累积——
// typedef 是重命名的意思
// malloc 分配一个内存空间：前面是说明这个空间的用途；后面是说明这个空间的大小。
// C语言 指针和变量的区别？ (*a).b = a->b【这里的a是指针】
// 错误集结——
// 格式分号漏写是个大问题……
// 输出要求没有看仔细也是一个大问题
// ERROR 如何返回？ 嗯…… 直接大小返回 return ERROR
// 情况分析——
// 1. 取值的边界情况
// 2. 空表操作

List MakeEmpty()
{
  List newList = (List)malloc(sizeof(struct LNode));
  // 注意看List的声明，可以得到List类型是指针类型
  newList->Last = -1;
  return newList;
}

Position Find(List L, ElementType X)
{

  // 没有初始化的int是一个随机数……
  Position i = 0;
  while (i <= L->Last && L->Data[i] != X)
    i++;

  if (i > L->Last)
    // 思路问题
    // 1. ERROR 如何返回？
    return ERROR;
  else
    return i;
}

bool Insert(List L, ElementType X, Position P)
{
  if (L->Last + 1 == MAXSIZE)
  {
    printf("FULL");
    return false;
  }
  // 这里缺少对于P另一半边界的判断（gg）, 以及MAXSIZE的判断也极其不合理……
  if (P < 0 || P > L->Last + 1)
  {
    printf("ILLEGAL POSITION");
    return false;
  }
  L->Last++;
  Position i = L->Last;

  while (i > P)
  {
    L->Data[i] = L->Data[i - 1];
    i--;
  }
  L->Data[P] = X;
  return true;
}

bool Delete(List L, Position P)
{
  if (P < 0 || P > L->Last)
  {
    // 输出写错了，读题不仔细……
    printf("POSITION %d EMPTY", P);
    return false;
  }

  Position i = P;
  while (i < L->Last)
  {
    L->Data[i] = L->Data[i + 1];
    i++;
  }
  L->Last--;
  return true;
}