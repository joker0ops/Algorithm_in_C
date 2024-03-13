/****************************************************************************
    线性表基本操作：
    InitList(&L);
    Length(L);
    LocateElem(L,e);
    GetElem(L,i);
    ListInsert(&L,i,e)
    ListDelete(&L,i,&e)
    PrintList(L)
    Empty(L)
    DestroyList(&L)
    在线性表的基本操作中i代表位序，在插入操作中需要将第i个元素及其后元素后移

    C语言初始动态分配语句：L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
    C++初始动态分配语句：L.data = new ElemType[InitSize];

    单链表判空：L->next==NULL
    双链表判空：L->next==NULL(L->prior==NULL)
    循环单链表判空：L->next==L
    循环双链表判空：L->next==L&&L->prior==L
****************************************************************************/