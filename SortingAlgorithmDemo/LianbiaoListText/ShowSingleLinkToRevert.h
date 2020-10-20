//
//  ShowSingleLinkToRevert.h
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/15.
//  Copyright © 2020 APPLE. All rights reserved.
//

//https://blog.csdn.net/nanfeibuyi/article/details/90116419

#ifndef ShowSingleLinkToRevert_h
#define ShowSingleLinkToRevert_h

#include <stdio.h>
#include <stdlib.h>

//链表节点定义
typedef struct s_node
{
    int data;
    struct s_node* pNext;
}Node;


Node* create_list_head(void);
Node* create_new_node(int node_data);
int add_node_head(Node* head, Node* new_node);
void display_list(Node* head);
void free_list(Node* head);

//翻转链表 方法一
Node* LinkRevert_list(Node* head);


//调用
int changeSingleLinkList(void);



#endif /* ShowSingleLinkToRevert_h */
