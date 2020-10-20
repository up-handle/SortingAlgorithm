//
//  MethodTextTextFun.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/9.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "MethodTextTextFun.h"

int binarySearch3(int arr[],int value,int low,int high){
    
    int mid = low + (high -low)/2;
    
    if (mid ==value) {
        return mid;
    }
    if (mid>value)
    {
        int index = binarySearch3(arr,value,low,mid-1);
        return index;
    }
    if (mid<value){
        int index = binarySearch3(arr, value, mid+1, high);
        return index;
    }
    
    return -1;
}





