//
//  HeapSortingText.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/7.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "HeapSortingText.h"

//参考网址
//https://www.cnblogs.com/chengxiao/p/6129630.html
/**
 大顶堆（最大堆）：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]

 小顶堆（最小堆）：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]
 
 arr[i] 的父位置为  arr[（i-1)/2 ]的位置
 
 一个父位置的两个子节点的位置分别是 2*i+1 和2*i+2
 
 */


static void swapTwoNum(int arr[],int i,int j){
    int temp =arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

static void adjustHeap(int arr[],int i,int length){
    
    int temp = arr[i]; //先取出当前的元素i
    
   
    for (int k = i*2+1; k<length; k= k*2+1) {
        //从i结点的左子结点开始，也就是2i+1处开始
        
        if (k+1<length && arr[k]<arr[k+1]) {
            //如果左子结点小于右子结点，k指向右子结点
            k++;
        }
        
        if (arr[k] > temp) {
            //如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
            arr[i] = arr[k];
            i = k;
            
        }else{
            break;
        }
    }
    
    arr[i] = temp; //将temp值放到最终的位置
}

void heapSortingMethody(int arr[],int length){
    
    //1.首先需要将数据构建成 大顶堆
    //len/2-1 可以算出最后一个子节点
    for (int i = length/2-1; i>=0; i--) {
        //从第一个非叶子节点从下到上，从右到左进行调整结构
        adjustHeap(arr, i, length);
    }
    //2.调整堆结构+交换堆顶元素与末尾元素
    for (int j = length -1; j>0; j--) {
        
        swapTwoNum(arr,0, j); //将堆顶元素与末尾元素进行交换
        adjustHeap(arr, 0, j); //重新对堆进行调整
        
    }

}

