//
//  MergeTwoSingleLinkList.h
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/15.
//  Copyright © 2020 APPLE. All rights reserved.
//


//https://blog.csdn.net/Dr_S_/article/details/78638609
//https://blog.csdn.net/wwxy1995/article/details/83349654


#ifndef MergeTwoSingleLinkList_h
#define MergeTwoSingleLinkList_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read(void); /* 链表读取 */
List Read_two(void);
void Print( List L ); /*链表输出；空链表将输出NULL */
List Merge( List L1, List L2 );  /*链表合并*/

void mergeTwoSingleLinkMethod(void);

#endif /* MergeTwoSingleLinkList_h */
