// 函数题
// 知识累积——
// 返回类型只看它的本质，重命名的数据类型不会对格式有任何影响，因为本质内容是一样的。
// 指针传递，只是复制了一个指针（对其操作不会有什么副作用）
// 段错误是访问了不可访问的内存导致 `本题目的段错误：List next = pos->Next`;
// 下面是一些典型的段错误的原因 :
// 非关联化空指针——这是特殊情况由内存管理硬件
// 试图访问一个不存在的内存地址(在进程的地址空间)（死循环也会导致这样的问题）
// 试图访问内存的程序没有权利(如内核结构流程上下文)
// 试图写入只读存储器(如代码段)
// 错误集结——
// bool值需要注入头文件
// 这道题最危险的地方就是会忽略P为NULL，而在while循环里，无法处理到判断条件为NULL的情况

Position Find(List L, ElementType X)
{
  // 根据数据结构，这里返回的位置即指针
  // 类型声明一定要正确
  // 尝试所谓的格式错误与 Position或是List无关
  Position pos = L;
  while (pos)
  {
    if (pos->Data == X)
    {
      return pos;
    }
    pos = pos->Next;
  }
  return ERROR;
}

List Insert(List L, ElementType X, Position P)
{
  // 这里注意P的非法可能性？我目前只能考虑到NULL的情况……
  // 换句话说，便利L，看看P是否在L上，来确保它的合法地位
  List pos = L;
  // 考虑开头结点这种特殊情况
  if (pos == P)
  {
    // 如何新建一个结点？分配空间
    List newP = (List)malloc(sizeof(List));
    newP->Data = X;
    newP->Next = pos;
    return newP;
  }
  // 需要记录前一个结点（可以用Next进行判断，从而减少变量）
  // 如果pos就是空表呢？
  if (!pos)
  {
    printf("Wrong Position for Insertion\n");
    return ERROR;
  }
  List next = pos->Next;
  // 也就是说flag额外的内存导致的错误？
  // 这里的答案错误是没有考虑到如果next是NULL的情况……以及P是NULL的情况
  // 这里的某一次循环next为NULL，但是P就是为NULL的情况
  while (next)
  {
    if (next == P)
    {
      List newP = (List)malloc(sizeof(List));
      newP->Data = X;
      newP->Next = next;
      pos->Next = newP;
      return L;
    }
    pos = next;
    next = next->Next;
  }
  // 可以在最后加一次为NULL的判断
  if (P == next)
  {
    List newP = (List)malloc(sizeof(List));
    newP->Data = X;
    newP->Next = next;
    pos->Next = newP;
    return L;
  }
  // 没有加\n可能会导致格式错误
  printf("Wrong Position for Insertion\n");
  return ERROR;
}

List Delete(List L, Position P)
{
  List pos = L;
  // 考虑开头
  // 未考虑最开始pos就是NULL
  if (pos == P)
  {
    return L->Next;
  }
  if (!pos)
  {
    printf("Wrong Position for Deletion\n");
    return ERROR;
  }
  List next = pos->Next;
  while (next)
  {
    if (next == P)
    {
      // 需要知道前一项
      pos->Next = next->Next;
      return L;
    }
    pos = next;
    // 之前少了这一句，导致死循环了……
    next = next->Next;
  }
  printf("Wrong Position for Deletion\n");
  return ERROR;
}

// 这里有更优的写法，以delete举例
List Delete(List L, Position P)
{
  if (L == P)
  {
    return L->Next;
  }
  List pos = L;
  while (pos)
  {
    if (pos->Next == P)
    {
      pos->Next = pos->Next->Next;
      return L;
    }
    pos = pos->Next;
  }
  printf("Wrong Position for Deletion\n");
  return ERROR;
}