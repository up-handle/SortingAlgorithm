//
//  CSingleLinkListStudy.h
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/14.
//  Copyright © 2020 APPLE. All rights reserved.
//

#ifndef CSingleLinkListStudy_h
#define CSingleLinkListStudy_h

//study
//https://www.cnblogs.com/usingnamespace-caoliu/p/9049035.html

#include <stdio.h>

//用 typedef 定义数据类型能有效提高代码的实用性
typedef int T;

typedef struct ZXZNode{
    T data;
    struct ZXZNode *next;
}ZXZNode,ZXZLink;

//zxzNode定义节点
//zxzLink 定义链表


#endif /* CSingleLinkListStudy_h */
