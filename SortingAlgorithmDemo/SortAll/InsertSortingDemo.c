//
//  InsertSortingDemo.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/2.
//  Copyright © 2020 APPLE. All rights reserved.
//

//https://www.runoob.com/w3cnote/ten-sorting-algorithm.html

/**
 插入排序是一种最简单直观的排序算法，它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
 插入排序和冒泡排序一样，也有一种优化算法，叫做拆半插入。
 */

/**
 算法步骤
 1、将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
 2、从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。（如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
 */


//while 循环方法
void insertSortingText(int arr[],int len){
    
    int i,j,key;
    
    for (i = 1; i<len; i++) { //外层控制元素个数循环
        
        key = arr[i]; //找出排序序列中的未排序开始的下标对应的元素（最初初始化的时间第二个元素）
    
        j = i - 1; //找到已经排序有序序列的下标（开始时下标为0,默认第一个是有序序列）
    
        while ( (j>=0) && (arr[j] > key) ){ // 查找有序序列,扫描有序序列的每个元素，让插入元素找到合适的位置插入。
            
            arr[j+1] = arr[j]; //大于当前key元素的向后移动一位，
            j-- ;   //key值得元素的下标向前进1
            
        } //找到不大于当前元素的标位置为j ，跳出while循环
        
        arr[j+1] = key; //找到合适的位置了(当前不大于自己的元素的下一个位置，进行赋值),然后插入元素，待下次循环。
    
    }
}


////for循环的方法
void insertSortingText_for(int arr[],int len){
    int i,j;
    int key;
    
    for (i = 1; i<len; i++) {
        
        key = arr[i];
        
        for (j = i-1; (j>=0) && (arr[j]>key); j--) {
            arr[j+1] = arr[j];
        }
        arr[j +1] = key;
    }

}
