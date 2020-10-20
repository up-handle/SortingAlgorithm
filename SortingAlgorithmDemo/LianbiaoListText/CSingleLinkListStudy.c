//
//  CSingleLinkListStudy.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/14.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "CSingleLinkListStudy.h"

#include <stdlib.h>
#include <stdbool.h>

//创建一个链表 1、为申请头结点内存，2、使pNext指向下一节点（NULL）。3、返回头地址。

ZXZLink *creata_ZXZLink(){
    //创建一个节点，表示头节点，该节点并不保存数据
    ZXZLink *head = (ZXZLink*)malloc(sizeof(ZXZNode));
     //让头节点的next置NULL，表示链表为空
    head->next = NULL;
    //返回头的地址
    return head;
}

//单项链表的清空与销毁主要包含两个步骤：①依次释放存储数据的节点内存。②释放头结点的内存，变量置空。

//清空链表

void clear_ZXZLink(ZXZLink *link){
    
    ZXZNode *node = link->next;
    while (node !=NULL) {
        ZXZNode *temp = node;
        node = node->next;
        free(temp);
    }
    link->next = NULL;
}

//销毁链表
void destroy_ZXZLink(ZXZLink *link){
    clear_ZXZLink(link);
    free(link);
    link = NULL;
}

//单向链表的判空
bool empty_ZXZLink(ZXZLink *link){
    return !link->next;
}


//单向链表的个数查询
/**　获取单向链表中数据的个数主要包含三个步骤：
 　①创建变量存储数据个数、创建node记录头节点的下一节位置点用于遍历链表。
 　②循环遍历，当当前节点的pNext指向NULL时代表已达链表末尾，结束循环。
 　③返回数据个数。
 */
size_t size_ZXZLink(ZXZLink *link){
    size_t i= 0;
    ZXZNode *node = link->next;
    //只要node不为NULL,表示该节点存在
    while (node != NULL) {
        //让node继续指向下一个节点
        node = node->next;
        i++;
    }
    return i;
}

//获取指定节点的前一个节点
/**
 获取指定下标节点的前一个节点主要包含三个步骤： ①创建node记录头节点位置用于遍历链表。
 ②循环遍历，当当前节点的pNext指向NULL时代表已达链表末尾，结束循环。
 ③返回指定下标的前一个节点。
 */

//返回下标为index的前一个节点
ZXZNode *getNode_ZXZLink(ZXZLink *link ,int index){
    
    ZXZNode *node = link;
     //如果index=0 其前一个节点就为link ,并不会进入下面循环
    for (int i = 0; node !=NULL && i<index; i++) {
        node = node->next;
    }
    return node;
}

//查找指定数据的下标（第一个）

/**
 　　查找指定数据的下标主要包含主要包含三个步骤：
 　　①创建node记录头节点的下一节位置点用于遍历链表。
 　　②循环遍历，当当前节点的pNext指向NULL时代表已达链表末尾，结束循环。
 　　③成功返回数据下标，失败则返回 -1 。
 */

int indexOf_ZXZLink(ZXZLink *link,T value){
    
    ZXZNode *node = link->next;
    for (int i=0 ; node !=NULL; i++) {
        if (node->data == value) {
            return i;
        }
        node = node->next;
    }
    return -1;
}

//遍历显示链表
/**
 　遍历显示链表主要包含主要包含三个步骤：
 　①创建node记录头节点的下一节位置点用于遍历链表。
 　②循环遍历，顺序输出每一个节点中储存的数据，当当前节点的pNext指向NULL时代表已达链表末尾，结束循环。
 */

void travel_ZXZLink(ZXZLink *link){
    ZXZNode *node = link->next;
    while (node!=NULL) {
        printf("%d",node->data);
        node = node -> next;
    }
    printf(" ");
}

//5.单项链表的节点插入

//5.1将一个节点插入指定的下标
/**
 　将一个节点插入指定下标（index）主要包含三个步骤：
 　①获取指定下标节点的上一个节点位置。
 　②创建node节点存储需要插入的数据。
 　③让插入节点的下一个节点指向index前一个节点的后节点，让index的前节点的下一个节点指向当前插入的节点。
 */

//插入一个元素到指定的元素 index取值范围（0，size_ZXZLink(ZXZLink *link)）
//0-失败  1-成功
bool insert_ZXZLink(ZXZLink *link,int index,T value){

    if (index<0 || index> size_ZXZLink(link)) {
        return false;
    }
    
    //得到下标为index位置的前一个节点
    ZXZNode *prevZXZNode = getNode_ZXZLink(link, index);
    //申请内存、用于保存需要插入的数据
    ZXZNode *node = (ZXZNode *)malloc(sizeof(ZXZNode));
    node->data = value;
    //
    node->next = prevZXZNode->next;
    //
    prevZXZNode->next = node;
    
    return true;
}

//插入一个元素到链表的末尾
bool insertBack_ZXZLink(ZXZLink *link,T value){
    return insert_ZXZLink(link, size_ZXZLink(link), value);
}

//插入一个元素到链表首部
bool insertFront_ZXZLink(ZXZLink *link,T value){
    return insert_ZXZLink(link, 0, value);
}


//
//5.2 将一个节点替换指定下标节点

/**
 　将一个节点替换指定下标（index）节点只包含一个步骤：创建node节点获取指定下标节点的位置并存储需要插入的数据。
 */

 //更新链表下标为index的节点的值

bool update_ZXZLink(ZXZLink *link ,int index ,T value){

    if (index<0 || index>size_ZXZLink(link)-1) {
        return false;
    }
    ZXZNode *node = getNode_ZXZLink(link, index+1);
    node->data = value;
    return true;

}


//6、单项链表的数据删除

//6.1 将一个指定下标的节点删除

/**
 　将一个指定下标的节点（index）删除主要包含四个步骤：
 　①获取指定下标节点的上一个节点位置。
 　②保存要删除的节点，用于释放内存。
 　③让要删除节点的前一个节点指向要删除节点的后一个节点。
 　④释放内存。
 */
//删除指定下标的元素
bool delete_ZXZLink(ZXZLink *link ,int index){

    if (index<0 || index>size_ZXZLink(link)-1) {
        return false;
    }
    //获得需要删除节点的前一个节点
    ZXZNode *prevZXZNode = getNode_ZXZLink(link, index);
    //保存要删除的节点，用于释放内存
    ZXZNode *node = prevZXZNode->next;
    //让要删除节点的前一个节点指向要删除节点的后一个节点
    prevZXZNode->next = prevZXZNode->next->next;
    free(node);
    return true;
}

//6.2 删除链表中所有包含指定数据的节点

/**
 　　删除链表中所有包含指定数据（value）的节点主要包含三个步骤：
 　　①设置标志变量（flag）表示该链表的数据是否发生变化。
 　　②循环遍历，顺序删除每一个包含指定数据的节点并将标志变量置位置为1，当当前节点的pNext指向NULL时代表已达链表末尾，结束循环。③返回标志变量。
 */

////删除元素为value的所有节点，返回值表示该链表的数据是否发生变化
bool deleteDatas_ZXZLink(ZXZLink* link, T value){
    //作为是否删除成功的一个标志
    bool flag = false;

    ZXZNode *prevNode = link; //头指针

    ZXZNode *currNodel = link->next; //遍历开始的头节点->next

    while (currNodel !=NULL) {

        if (currNodel->data ==value) {

            ZXZNode *temp = currNodel; //把当前的节点赋值给temp
            prevNode->next = currNodel->next; //把当前的节点赋值给上个节点的next指向

            currNodel = currNodel->next; //继续寻找下个current

            free(temp);
            flag = true;

        }else{
            prevNode = prevNode->next; //如果没有就继续往下走
            currNodel= currNodel->next;
        }
    }
    return flag;

}


 //删除元素为value的第一个元素
 bool deleteData_SLLink(ZXZLink* link, T value)
 {
    ZXZLink* prevNode = link;
    ZXZLink* currNode = link->next;
    while(currNode != NULL)
    {
         if(currNode->data == value)
        {
            ZXZNode* tmp = currNode;
            prevNode->next = currNode->next;
            currNode = currNode->next;
            free(tmp);
            return true;
        }
        else
        {
            prevNode = prevNode->next;
            currNode = currNode->next;
        }
     }
     return false;
 }

/////拓展应用

//单向链表整体翻转
//链表逆序

void reverse(ZXZLink *link){
    if (link == NULL || link->next ==NULL) {
        return;
    }
    //0、记录前一个节点与当前节点
    ZXZNode *prevNode = link->next;
    ZXZNode *node = prevNode->next; //NULL

    //只要当前节点存在
    while (node!=NULL) {
        //1、先记录当前节点的后一个节点
         ZXZNode* nextNode = node->next;
        //2、让当前节点(node)的下一个节点(node->next)指向(=)前一个节点(prev)
        node->next = prevNode;
         //3、让前一个节点指向当前节点、当前节点指向原先记录的下一个节点
        prevNode = node;
    }
     link->next->next = NULL;
    //5、让链表的头节点指向原来的尾元素
    link->next = prevNode;
    
}

