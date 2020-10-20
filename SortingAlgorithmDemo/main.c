//
//  main.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/2.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include <stdio.h>
//#include "bubbleSortingDemo.h"
//#include "SelectSortingDemo.h"
//#include "InsertSortingDemo.h"
//#include "XiErSortingText.h"
//#include "GuibingSorting.h"
//#include "FastSortingModule.h"

//#include "HeapSortingText.h"
#include "CountSortingText.h"
#include "ShowSingleLinkToRevert.h"
#include "MergeTwoSingleLinkList.h"



#pragma markm -排序的-
//冒泡
void bubble_sort_text3(int arr[],int len){
    for (int i = 0; i<len-1; i++) {
        for (int j = 0; j<len-1-i; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//选择
void selectSortingText3(int arr[],int len){
    int i ,j ,min;
    for (i = 0; i<len-1; i++) {
        min = i;
        for (j = i + 1; j<len-1; j++) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        //
        if (min != i) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

//插入

void insertSortingText3(int arr[],int len){
    
    int i,j,key;
    for (i = 1; i<len; i++) {
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}





int main(int argc, const char * argv[]) {
    printf("Hello, World!\n");

    int arr[] = { 22, 34, 3, 32, 82, 55,55, 89, 50, 37, 5, 64, 35, 9,9, 70 };
    //
    int len = (int) sizeof(arr) / sizeof(*arr);
//    bubble_sort_text3(arr, len);
//    selectSortingText3(arr,len);
    
//    selectSorting3(arr, len);
    
    insertSortingText3(arr ,len);
//    insertSortingText_for(arr,len);
  
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
