//
//  SgLinkList.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/11.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "SgLinkList.h"

#include <stdio.h>
#include <stdlib.h>

/**
 第一个函数是创建单向链表，这里我首先创建了一个节点作为头节点，但是这个头节点不参与后面相关函数的运行，例如：头结点不参与链表数据的打印；只包含头节点不包含其他节点时，该链表判断为空；计算链表长度时，头结点不参与计数，删除和插入节点函数也都是从头节点后面的节点计数的。当然有一点，最后释放内存的时候，头节点是要跟着一起释放的，因为给头节点分配了内存所以也得释放，要不会造成内存泄露，这一点很容易忽视了。
 */

/**
  1.malloc创建头结点, 头结点值为0, next指针指向NULL
  2.创建新节点(替换)和 尾节点 值为NULL
  3.将头结点赋值给尾节点
  4.循环需要创建的个数，创建当前节点，把输入的值赋值为替换的p_new节点的data，并且p_new的next指针指向NULL，将pTail的next指向p_new， 将p_new总的赋值给pTail，然后进入下次循环。
 
 */
 

//创建单向链表
pNODE CreateSgLinkList(void){
    
    int i,length,data;
    
    pNODE p_new = NULL; //新节点
    pNODE pTail = NULL; //尾节点
    
    //创建头节点，头结点是第0个节点，后面的节点从1开始计数
    pNODE pHead = (pNODE)malloc(sizeof(NODE));
    if (NULL == pHead) {
        printf("内存分配失败\n");
        //退出 exit
    }
    //头节点值为0，指向的子节点为NULL
    pHead->data = 0;
    pHead->pNext = NULL;
    
    
    //把头节点赋值为尾节点
    pTail = pHead;
    
    printf("请输入链表的长度");
    scanf("%d",&length);
    
    for (i= 0; i<length+1; i++) {
        
        //（除头结点外）创建第一个节点
        p_new = (pNODE)malloc(sizeof(NODE));
        if (NULL == p_new) {
            printf("内存分配失败！\n");
            //退出 exit
        }
        printf("请输入第%d个节点的值:",i);
        scanf("%d",&data);
        
        p_new->data =data; //赋值当前节点的值
        p_new->pNext = NULL;//当前节点的指向NUll
        
        pTail->pNext = p_new;  //尾节点(第一次时间尾节点为头节点，大于1的时间,尾节点为当前循环的上个值创建的节点元素)
        pTail = p_new; //把当前的节点元素赋值给尾节点。
        
    }
    
    return pHead;
}


//打印单向链表函数
/**
 这个是打印单向链表函数，可以看到是从头结点的后面一个节点开始打印的，p=pHead->pNext。一直打印到最后一个
 */

void TraverseSgLinkList(pNODE pHead){
    
    pNODE pt = pHead ->pNext;
    printf("打印链表");
    
    while (pt != NULL) {
        printf("%d",pt->data);
        pt = pt->pNext;
    }
    putchar('\n');
    
}

//判断链表是否为空
/**
 判断链表是否为空的函数，通过检查头节点的后面一个节点来判断，所以这里头节点也不参与运算。
 */

int IsEmptySgLinkList(pNODE pHead){
    
    if (pHead->pNext == NULL) {
        return 1;
    }else{
        return 0;
    }
}

//计算链表的长度
/**
 计算链表长度的函数，也是从头节点后面的节点开始，找到节点就让length加1，直到找到最后一个节点为止。
 */
int GetLengthSgLinkList(pNODE pHead){
    int length = 0;
    pNODE pt = pHead->pNext;
    while (pt!=NULL) {
        length++;
        pt = pt->pNext;
    }
    return length;
}


//单向链表的插入
//向单向链表插入一个节点,位置从1开始，到链表长度加1结束。
/**
 pos 位置
 */
/**
 1.如果能插入，创建p_new节点，然后找到吧data的值赋值给新节点、
 2.然后
 */
int InsertEleSgLinkList(pNODE pHead,int pos,int data){
    
    pNODE pt= NULL;
    pNODE p_new = NULL;
    
    if (pos >0 && pos < GetLengthSgLinkList(pHead) +2) {
        
        p_new = (pNODE)malloc(sizeof(NODE));
        
        if (NULL == p_new) {
            printf("内存分配失败!\n");
            //退出 exit
            exit(0);
        }
        
        p_new->data = data;
        
        while (1) {
            pos--;
            if (0==pos) {
                break;
            }
            pHead = pHead->pNext;
        }
        //for
//        for (int i =pos; pos>0; pos--) {
//            pHead = pHead->pNext;
//        }
        
        // 将查找到的位置的下一个子节点的指针赋值给pt
        pt = pHead->pNext;
        // 将查找位置的的next节点- 指向 -将现有创建的p_new节点
        pHead->pNext = p_new;
        //然后将刚创建的new节点的next指针指向与pt的节点
        p_new->pNext = pt;
        
        return 1;
    }
    
    return 0;
}


//从单向链表中删除一个节点名，位置从1开始，到链表长度结束。

/**
 删除单向链表节点的函数，是从1到链表的长度
 里就说说在删除节点时要注意的地方，首先你要找到要删除的那个节点，然后把要删除节点的下一个节点的地址保存好（这里保存到pt），然后释放该节点的内存，让改指针指向NULL指针（这里因为马上要用到这个指针就没有让它指向NULL指针），接着让被删除节点的上一个的指针指向上面保存好的节点地址（也就是pt），这样节点被删除了，内存也释放了，链表也连接起来了。
 */


//从单向链表中删除一个节点，位置从1开始，到链表长度结束。

int DeleteEleSgLinkList(pNODE pHead,int pos){
    
    pNODE pt = NULL;
    
    if (pos > 0 && pos < GetLengthSgLinkList(pHead) +1 ) {
        
        while (1) {
            pos--;
            if (0==pos) {
                break;
            }
            pHead = pHead->pNext;
        }
        //找到需要删除节点的下一个子节点 赋值给pt
        pt = pHead->pNext->pNext;
        //删除需要删除节点的内存
        free(pHead->pNext);
        //把当前需要删除的 的下个子节点指针指向 删除节点的上个子节点
        pHead->pNext = pt;
        
        return 1;
    }
    return 0;
}


//删除整个单向链表，释放内存
void FreeMemoryNode(pNODE *pphead){

    pNODE pt = NULL;
    while (*pphead != NULL) {
        pt  = (*pphead)->pNext;
        free(pphead);
        *pphead = pt;
    }
}


