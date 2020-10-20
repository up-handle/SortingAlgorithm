//
//  CountSortingText.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/7.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "CountSortingText.h"

//参考：https://www.cnblogs.com/kyoner/p/10604781.html

//第一时间你可能会想使用快速排序，因为快排的时间复杂度只有O(nlogn)。但是这种方法还是不够快，有没有比O(nlogn)更快的排序方法呢？你可能会有疑问：O(nlogn)已经是最快的排序算法了，怎么可能还有更快的排序方法？

//让我们先来回顾一下经典的排序算法，无论是归并排序，冒泡排序还是快速排序等等，都是基于元素之间的比较来进行排序的。但是有一种特殊的排序算法叫计数排序，这种排序算法不是基于元素比较，而是利用数组下标来确定元素的正确位置。

//计数排序特征
/**

 当输入的元素是 n 个 0 到 k 之间的整数时，它的运行时间是 Θ(n + k)。计数排序不是比较排序，排序的速度快于任何比较排序算法。

 由于用来计数的数组C的长度取决于待排序数组中数据的范围（等于待排序数组的最大值与最小值的差加上1），这使得计数排序对于数据范围很大的数组，需要大量时间和内存。例如：计数排序是用来排序0到100之间的数字的最好的算法，但是它不适合按字母顺序排序人名。但是，计数排序可以用在基数排序中的算法来排序数据范围很大的数组。
 
 
 算法的步骤如下：
 （1）找出待排序的数组中最大和最小的元素
 （2）统计数组中每个值为i的元素出现的次数，存入数组C的第i项
 （3）对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
 （4）反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
 */


//有错误 未完待续 具体需要参考
//https://www.cnblogs.com/kyoner/p/10604781.html


void countSortingMethod(int arr[],int len){
    
    
//      int array[] = { 9, 3, 5, 4, 9, 1, 2, 7, 8,1,3,6,5,3,4,0,10,9,7,9};
    
    //1.找出当前元素的最大值
    int max = arr[0];
    for (int i = 0; i<len; i++) {
        if (max< arr[i]) {
            max = arr[i];
        }
    }
    //2.根据数列的最大值确定统计数组的长度
    //创建一个数组大小为 max减去min 加 1
    int *countArray = (int *) malloc(sizeof(int) * (max+1));
    
    //3.遍历数列，填充统计数组
    for (int i=0; i<len; i++) {
         printf("%d \n", arr[i]);
         countArray[arr[i]]++;
        
    }
    
    //遍历统计数组，输出结果
    int index = 0;
    
    int number = (int) sizeof(countArray)/sizeof(*countArray);
    
    int *sortedArray = (int *) malloc(sizeof(int) * number);
    
    for (int i = 0; i< number; i++) {
        
        for (int j = 0; j< countArray[i]; j++) {
//            printf("%d,%d\n",index,i);
            sortedArray[index++] = i;
        }
    }
    
    for (int i = 0; i < number; i++){
           printf("%d \n", sortedArray[i]);
    }

}



