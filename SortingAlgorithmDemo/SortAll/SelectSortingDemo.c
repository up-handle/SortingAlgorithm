//
//  SelectSortingDemo.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/2.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "SelectSortingDemo.h"

//https://www.runoob.com/w3cnote/ten-sorting-algorithm.html

//选择排序是一种简单直观的排序算法，无论什么数据进去都是 O(n²) 的时间复杂度。所以用到它的时候，数据规模越小越好。唯一的好处可能就是不占用额外的内存空间了吧。
//时间复杂度为O（n²）
/**
 算法步骤
   1.首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
   2.再从剩余的未排序元素中继续寻找最小（大）的元素，然后放到已排序序列的末尾。
   3.重复第二步，知道所有的元素均排列完毕
 */


//交换指针
void swap(int *a,int *b){
    int temp =  *a;
        *a   =  *b;
        *b   =  temp;
}


void selectSorting (int arr[], int len){
    
    //i   有序区的末尾位置
    //j   无序区的起始位置
    //min 无序区中最小元素位置
    
    int i , j ;
    
    for (i = 0; i < len - 1; i++ ) {
        
        int min = i; //初始定义最小值为第一个元素
        
        for (j = i + 1; j < len; j++) {//走访未排序的元素
            
            if (arr[j] < arr[min]) { //找到目前的最小值
                
                min = j; //记录最小值
            }
        }
        
        if (min != i) {
            swap(&arr[min],&arr[i]); //交换，把值排序到最前面
        }
    }
}



//
//void selectSorting1 (int arr[],int len){
//    int i , j;
//    for (i = 0; i < len-1; i++) {
//        int min = i;
//        for (j = i+1; j < len; j++) {
//            if (arr[min]>arr[j] ) {
//                min = j;
//            }
//        }
//        if (min != i) {
//            int temp = arr[min];
//            arr[min] = arr[i];
//            arr[i] = temp;
//        }
//    }
//}


