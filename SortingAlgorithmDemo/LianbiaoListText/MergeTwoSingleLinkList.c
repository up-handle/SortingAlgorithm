//
//  MergeTwoSingleLinkList.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/15.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "MergeTwoSingleLinkList.h"
#include "ShowSingleLinkToRevert.h"


//合并连个有序的链表
void mergeTwoSingleLinkMethod(){
    
    List L1, L2, L;
    L1 = Read();  //读取链表1
    L2 = Read_two();  //读取链表2
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    
}

List Merge( List L1, List L2 )
{
    List pa,pb,pc,L;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    pa=L1->Next;                              // 指向pa第一个元素
    pb=L2->Next;

    // 指向pb第一个元素
    pc = L;
    while(pa && pb)
    {
        if(pa->Data <= pb->Data)
        {
            pc->Next = pa;
            pc = pa;
            pa = pa->Next;
        }
        else
        {
            pc->Next = pb;
            pc = pb;
            pb = pb->Next;
        }
    }
    if(pa)
    {
      pc->Next = pa;
    }
    if(pb)
    {
      pc->Next = pb;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}

List Read(void)
{

    int n, i;
    List L, p, s;
//    scanf("%d",&n);
    n=10;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    p = L;
    for(i = 0;i < n; ++i){
        s = (List)malloc(sizeof(struct Node));
//        scanf("%d",&s->Data);
        s->Data = i;
        s->Next = p->Next;
        p->Next = s;
        p = s;
    }
    return L;
}


List Read_two(void)
{

    int n, i;
    List L, p, s;
//    scanf("%d",&n);
//    n=130;
    
    int arr[] = {3,6,8,10,11,16};
    int len = (int)sizeof(arr)/sizeof(*arr);
    
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    p = L;
    for(i = 0;i < len; i++){
        s = (List)malloc(sizeof(struct Node));
//        scanf("%d",&s->Data);
        s->Data = arr[i];
        s->Next = p->Next;
        p->Next = s;
        p = s;
    }
    return L;
}

void Print(List L){
  List p;
  p = L->Next;
  if (L->Next==NULL)
  {
    printf("NULL");
  }
  while(p)
  {
    printf("%d ", p->Data);
    p = p->Next;
  }
   printf("\n");
}
