//
//  FastSortingModule.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/3.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "FastSortingModule.h"

//参考
//https://blog.csdn.net/nrsc272420199/article/details/82587933
//https://www.sohu.com/a/246785807_684445



//快速排序相当于对 冒泡排序演变过来的，比冒泡排序要搞笑很多

//同冒泡排序一样快速排序也属于交换排序，通过元素之间的比较和交换位置来达到排序的目的。

/**
 冒泡排序在每一轮只把一个元素冒泡到数列的一端，
 而快速排序在每一轮挑选一个基准元素，并让其他比它大的元素移动到数列一边，比它小的元素移动到数列的另一边，从而把数列拆解成了两个部分。
 */


//注意：当交换1和2的位置时间会发生排序错误

static int getIndex(int arr[],int start,int end){

    //基准数据
    int temp = arr[start];
    
    while (start<end) {
        //1.
        // 当队尾的元素大于等于基准数据时,向前挪动end指针
        while (start<end && arr[end] >= temp) {
            end--;
        }
        // 如果队尾元素小于tmp了,需要将其赋值给start
        arr[start] = arr[end];
        //2
        // 当队首元素小于等于tmp时,向前挪动start指针
        while (start < end && arr[start] <=temp) {
            start++;
        }
        // 当队首元素大于tmp时,需要将其赋值给end
        arr[end] = arr[start];
        
    }
    // 跳出循环时low和high相等,此时的low或high就是tmp的正确索引位置
    // 由原理部分可以很清楚的知道low位置的值并不是tmp,所以需要将tmp赋值给arr[low]
    arr[start] = temp;
     // 返回tmp的正确位置
    return start;
    
}


void quick_sort(int arr[],int start ,int  end){
  
    if (start >= end) {
        return;
    }
    
    //寻找基准数据的正确索引
    int index = getIndex(arr, start, end);
    // 进行迭代对index之前和之后的数组进行相同的操作使整个数组变成有序
    //quickSort(arr, 0, index - 1); 之前的版本，这种姿势有很大的性能问题，谢谢大家的建议
    quick_sort(arr, start, index-1);
    quick_sort(arr, index+1, end);
    
}


void fastSortingText(int arr[],int len){
        
    quick_sort(arr, 0, len-1);
    
}

