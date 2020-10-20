//
//  bubbleSortingDemo.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/2.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "bubbleSortingDemo.h"

//https://www.runoob.com/w3cnote/ten-sorting-algorithm.html

/**
 
 比较相邻的元素。如果第一个比第二个大，就交换他们两个。

 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。

 针对所有的元素重复以上的步骤，除了最后一个。

 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
 
 */


/*
 理解
 1、最外层的for是控制执行的次数、每次执行一次之后都确保了最后一个元素是最大的值。
 2、内层的for 是控制执行到数组需要排序的位置, 因为之前for循环i 的时间执行的时间已经对后面的元素排序好了，没有必要在进行比对了。
    所以for循环的判断条件是 len - 1 - i （数组的下标 在减除已经循环好的元素，就是剩余需要排序的元素）。
 3、最内层的for循环，是对 比对元素的比较，进项数据的交互。
 */

//i 个数      // 0  1  2  3  4  5   6   7   8
//j 判断最大数 // 9  8  7  6  5  4   3   2   1





void bubble_sort_text(int arr[], int len){
    
    int i,j,temp;
    
    for (i = 0; i < len - 1; i++) { //最外层控制循环的总次数/圈数，len -1
        
        for (j = 0; j < len - 1 - i; j++) {  //内层控制一圈 需要交换的次数
           
            if (arr[j] > arr[j + 1]) {  //判断相邻的两个值的大小，然后进行比较交换。如果前一个大于后一个 就把大的交换到后面
        
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;
            }
            
        }
    }
}


//什么时候最快
//当输入的数据已经是正序时（都已经是正序了，我还要你冒泡排序有何用啊）。

//什么时候最慢
//当输入的数据是反序时（写一个 for 循环反序输出数据不就行了，干嘛要用你冒泡排序呢，我是闲的吗）。
