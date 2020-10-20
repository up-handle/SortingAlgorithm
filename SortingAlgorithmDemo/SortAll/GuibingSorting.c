//
//  GuibingSorting.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/3.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "GuibingSorting.h"

//参考图解
//https://www.cnblogs.com/chengxiao/p/6194356.html
//https://blog.csdn.net/assiduous_me/article/details/89414914
//https://www.runoob.com/w3cnote/merge-sort.html

//归并排序
/**
基本思想：  归并排序
利用归并的思想实现的排序算法，该算法采用经典的分治策略。
分治法分为两个阶段，首先是分阶段，分阶段将问题分成一系列小的问题然后进行递归求解。
然后是治阶段，治阶段将分阶段得到的各个答案“修补”在一起，这就是分而治之。
 */

//   1234567890
//   12345  67890
// 12 3 45  67 8 90
// 1 2 3 4 5 6 7 8 9 0

//12 34 56 78 90
//1234 56 7890
//1234567890


//递归实现的排序
void merge(int arr[],int start, int mid, int end){
    
    int result[end+1];
    
    int k = 0;
    
    int i = start;
    
    int j = mid+1;
    
    //进行比对，然后进行赋值到result数据中
    while (i<=mid && j<=end) {
        
        if (arr[i] < arr[j]) {
            
            result[k++] = arr[i++];
        }else{
            
            result[k++] = arr[j++];
        }
    }
    
    
    //将 前半部分 剩下的有序数据存入result数组中
    if (j == end + 1) {
        while (i<= mid) {
            result[k++] = arr[i++];
        }
    }
    
    //将 后半部分 剩下的有序数据存入到result数组中
    if (i == mid + 1) {
        while(j<=end){
            result[k++] = arr[j++];
        }
    }
    
    //将result数据中的元素考本到原数组中
    k = 0;
    while (start<=end) {
        arr[start++] = result[k++];
    }

//    for (j = 0, i = start; j<k ;j++,i++) {
//        arr[i] = result[j];
//    }
    
    
}

//
void margeSort(int arr[], int start, int end){
    
    if (start >= end) {
       return;
    }
    int mid = (start + end) /2;
    
    margeSort(arr, start, mid); //递归/分/前部分
    margeSort(arr, mid+1, end); //递归/分/后部分
    merge(arr, start, mid, end); //合
}


//开始---分治策略
void guibingSortingText(int arr[],int len){
    margeSort(arr, 0, len-1);
}
