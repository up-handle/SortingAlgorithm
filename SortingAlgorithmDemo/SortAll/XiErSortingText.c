//
//  XiErSortingText.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/3.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "XiErSortingText.h"

//参考图解
///https://blog.csdn.net/qq_39207948/article/details/80006224


/**
 希尔排序，也称递减增量排序算法，是插入排序的一种更高效的改进版本。但希尔排序是非稳定排序算法。
 希尔排序是基于插入排序的以下两点性质而提出改进方法的：
    1.插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率；
    2. 但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位；
 希尔排序的基本思想是：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序。
 */

//希尔排序就是对插入排序的一种优化，内部的核心就是使用插入算法。
//希尔排序，就是比插入排序，在外层多加了一个控制增量（gap）的循环罢了。


//时间复杂度 O(nlog²n)

///////////////////////////////////////////

/**
 
将arr[i] 插入到所在分组中正确的位置上
 arr[i]所在的分组为
   .....arr[i-2*gap]、arr[i-gap]、arr[i]、arr[i+gap]、arr[i+2*gap]......
 */

//类似插入排序
void inertGapSortOne(int arr[],int gap,int i){

    int key = arr[i];
    int j;
    for (j = i-gap; j>=0 && arr[j]>key; j -= gap) {
        arr[j+gap] = arr[j];
    }
    arr[j +gap] = key;
}

//希尔排序
void xierSorting (int arr[],int len){
    int gap, i;
    //进行分组，开始时的增量gap为数组的长度的一半
    for (gap = len/2; gap>0; gap/=2) {
        
        //对每个分组进行插入排序 （此处以下类似插入排序，不过间隔gap）
        for (i = gap; i < len; i++) {
            //将arr[i]插入到所在分组中正确的位置上(核心插入排序)
            inertGapSortOne(arr, gap, i);
        }
    }
    
}



////希尔排序-整体版本
void xierSorting_all (int arr[],int len){
    int gap, i;
    //进行分组，开始时的增量gap为数组的长度的一半
    for (gap = len/2; gap>0; gap/=2) {

        //对每个分组进行插入排序 （此处以下类似插入排序，不过间隔gap）
        for (i = gap; i< len; i++) {
            //将arr[i]插入到所在分组中正确的位置上(核心插入排序)
            int key = arr[i];
            int j;
            
            for (j = i - gap; j>=0 && arr[j]>key ; j = j-gap) {
                arr[j +gap] = arr[j];
            }
            
            arr[j +gap] = key;
        }
    }
    
}

