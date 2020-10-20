//
//  main.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/2.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include <stdio.h>
#include "bubbleSortingDemo.h"
#include "SelectSortingDemo.h"
#include "InsertSortingDemo.h"
#include "XiErSortingText.h"
#include "GuibingSorting.h"
#include "FastSortingModule.h"

#include "HeapSortingText.h"
#include "CountSortingText.h"
#include "ShowSingleLinkToRevert.h"
#include "MergeTwoSingleLinkList.h"



#pragma markm -排序的-


int main(int argc, const char * argv[]) {
    printf("Hello, World!\n");

    int arr[] = { 22, 34, 3, 32, 82, 55,55, 89, 50, 37, 5, 64, 35, 9,9, 70 };
    //
    int len = (int) sizeof(arr) / sizeof(*arr);
//    bubble_sort_text3(arr, len);
//    selectSortingText3(arr,len);
    
//    selectSorting3(arr, len);
    
    insertSortingText_for(arr,len);
  
//    xierSorting3(arr,len);
//    guibingSortingText(arr,len);
    
//    guibingSortingText(arr,len);
    
//    fastSortingText(arr,len);
    
    
//    heapSortheapSort(arr,len);
//    FastFastFastSortSort(arr,0,len-1);
    
    for (int i = 0; i < len; i++){
        printf("%d \n", arr[i]);
    }

    return 0;
    
//    int nunber= changeSingleLinkList();
//    return nunber;

}

//冒泡、选择、插入、希尔、归并、快速
//堆排、计数、桶、基数

//链表 合并、倒序、创建
