//
//  ShowSingleLinkToRevert.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/15.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "ShowSingleLinkToRevert.h"


int changeSingleLinkList(void){
   //创建链表
      Node* head = create_list_head();
      if(NULL == head)
      {
          printf("create_list_head failed!\n");
          return -1;
      }
      
      //填充数据（添加节点）
      int i;
      for(i=1; i<8; i++)
          add_node_head(head, create_new_node(i));
   
      //打印原来链表数据
      printf("befor ");
      display_list(head);
      
      //反转链表
      head = LinkRevert_list(head);
      printf("after ");
      display_list(head);
      
      //释放链表空间
      free_list(head);
      return 0;
}




//创建链表头部
Node* create_list_head(){
    Node *head = (Node *)malloc(sizeof(Node));
    if (NULL == head) {
        printf("创建头节点失败");
    }else{
        head->data = -1;
        head->pNext = NULL;
    }
    return head;
}

//创建新节点
Node* create_new_node(int node_data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (NULL != new_node) {
        new_node->data = node_data;
        new_node->pNext = NULL;
    }
    return new_node;
}

//头插法
int add_node_head(Node* head,Node *new_node){
    
    if (NULL ==head || NULL ==new_node) {
        return -1;
    }
    
    new_node->pNext = head->pNext;
    head->pNext = new_node;
    return 0;
}

//打印链表数据
void display_list(Node *head){
    if (NULL == head) {
        return;
    }
    Node *temp = head;
    printf("List data:\n");
    while (NULL!=(temp=temp->pNext)) {
        printf("%d ",temp->data);
    }
    printf("\n");
}

//释放链表
void free_list(Node* head)
{
    if(NULL == head)
        return;
    Node* p = head;
    while(NULL!= (p = p->pNext))
    {
        head->pNext = p->pNext;
        //printf("free:%d\n", p->data);
        free(p);
        p = head;
    }
    free(head);
}

//
//头插方式1-反转链表

Node *LinkRevert_list(Node *head){
    if (NULL == head) {
        return NULL;
    }

    Node *p = head->pNext;
    head->pNext = NULL;
    Node *tmp = NULL;

    while (p) {
        tmp = p->pNext;
        add_node_head(head, p);
        p = tmp;
    }
    return head;
}

////方法二
////新建链表方式-反转链表
//Node* LinkRevert_list(Node* head)
//{
//    if(NULL == head)
//        return NULL;
//
//    Node* p = head->pNext;
//    Node* q = NULL;
//    while((q = p->pNext))
//    {
//        p->pNext = q->pNext;//分离q
//        add_node_head(head, q);//将q插入到首元素位置
//    }
//
//    return head;
//}
