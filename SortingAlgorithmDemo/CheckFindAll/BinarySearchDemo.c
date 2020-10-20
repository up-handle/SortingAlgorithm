//
//  BinarySearchDemo.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/8.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "BinarySearchDemo.h"


//顺序查找
int SequenceSearch(int a[], int value, int n)
{
    int i;
    for(i=0; i<n; i++)
        if(a[i]==value)
            return i;
    return -1;
}

//二分查找 == 折半查找

//说明：元素必须是有序的，如果是无序的则要先进行排序操作。

/**
 
 基本思想：也称折半查找，属于有序查找算法。
 用给定值k先与中间结点的关键字比较，中间结点把线形表分成两个子表，若相等则查找成功；
 若不相等，再根据k与该中间结点关键字的比较结果确定下一步查找哪个子表，
 这样递归进行，直到查找到或查找结束发现表中没有这样的结点。

 复杂度分析：最坏情况下，关键词比较次数为log2(n+1)，且期望时间复杂度为O(log2n)；
 
 注：折半查找的前提条件是需要有序表顺序存储，对于静态查找表，一次排序后不再变化，折半查找能得到不错的效率。
 但对于需要频繁执行插入或删除操作的数据集来说，维护有序的排序会带来不小的工作量，那就不建议使用。
 ——《大话数据结构》

 */
//arr 数组，value需要查找的值，n数组的个数
int BinarySearch1(int arr[], int value, int n){
 
    int low,high,mid;
    
    low = 0;
    
    high= n-1;
    
    while (low<=high) {
        
        mid = (low+high)/2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid]> value) {
            high = mid - 1;
        }
        if (arr[mid]< value) {
            low = mid + 1;
        }
    }
    return -1;
}

int BinarySearch2(int arr[], int value, int low, int high){
    
    int mid = low + (high -low)/2;
    
    if (arr[mid] == value) {
        return mid;
    }
    if (arr[mid]>value) {
        int index = BinarySearch2(arr, value, low, mid-1);
        return index;
    }
    if (arr[mid]<value) {
        int index = BinarySearch2(arr, value,  mid+1, high);
        return index;
    }
    return -1;
}

/**
    在介绍插值查找之前，首先考虑一个新问题，为什么上述算法一定要是折半，而不是折四分之一或者折更多呢？
 　　打个比方，在英文字典里面查“apple”，你下意识翻开字典是翻前面的书页还是后面的书页呢？如果再让你查“zoo”，你又怎么 查？很显然，这里你绝对不会是从中间开始查起，而是有一定目的的往前或往后翻。
 　　
    同样的，比如要在取值范围1 ~10000之间100个元素从小到大均匀分布的数组中查找5,我们自然会考虑从数组下标较小的开始查找。
 　　
 　　经过以上分析，折半查找这种查找方式，不是自适应的（也就是说是傻瓜式的）。二分查找中查找点计算如下：
 　　
 　　mid=(low+high)/2, 即mid=low+1/2*(high-low);
 　　通过类比，我们可以将查找的点改进为如下：
 　　mid=low+(key-a[low])/(a[high]-a[low])*(high-low)，
 　　
 　　也就是将上述的比例参数1/2改进为自适应的，根据关键字在整个有序表中所处的位置，让mid值的变化更靠近关键字key，这样也就间接地减少了比较次数。
 　　
 　　基本思想：基于二分查找算法，将查找点的选择改进为自适应选择，可以提高查找效率。当然，差值查找也属于有序查找。
 　　注：对于表长较大，而关键字分布又比较均匀的查找表来说，插值查找算法的平均性能比折半查找要好的多。反之，数组中如果分布非常不均匀，那么插值查找未必是很合适的选择
 　　
 　　复杂度分析：查找成功或者失败的时间复杂度均为O(log2(log2n))。

 */

//插值查找
int InsertionSearch(int a[], int value, int low, int high)
{
    int mid = low+(value-a[low])/(a[high]-a[low])*(high-low);
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return InsertionSearch(a, value, low, mid-1);
    if(a[mid]<value)
        return InsertionSearch(a, value, mid+1, high);
    
    return -1;
}


/**
 大家记不记得斐波那契数列：1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89…….（从第三个数开始，后边每一个数都是前两个数的和）。然后我们会发现，随着斐波那契数列的递增，前后两个数的比值会越来越接近0.618，利用这个特性，我们就可以将黄金比例运用到查找技术中
 //
 基本思想：也是二分查找的一种提升算法，通过运用黄金比例的概念在数列中选择查找点进行查找，提高查找效率。同样地，斐波那契查找也属于一种有序查找算法。
  
 */

/**
 
 斐波那契查找与折半查找很相似，他是根据斐波那契序列的特点对有序表进行分割的。他要求开始表中记录的个数为某个斐波那契数小1，及n=F(k)-1;

 开始将k值与第F(k-1)位置的记录进行比较(及mid=low+F(k-1)-1),比较结果也分为三种

 1）相等，mid位置的元素即为所求

 2）>，low=mid+1,k-=2;

 说明：low=mid+1说明待查找的元素在[mid+1,high]范围内，k-=2 说明范围[mid+1,high]内的元素个数为n-(F(k-1))= Fk-1-F(k-1)=Fk-F(k-1)-1=F(k-2)-1个，所以可以递归的应用斐波那契查找。

 3）<，high=mid-1,k-=1。

 说明：low=mid+1说明待查找的元素在[low,mid-1]范围内，k-=1 说明范围[low,mid-1]内的元素个数为F(k-1)-1个，所以可以递归 的应用斐波那契查找。

 复杂度分析：最坏情况下，时间复杂度为O(log2n)，且其期望复杂度也为O(log2n)。
 
 */


//斐波那契查找算法

const max_size = 20; //斐波那契数组的长度

//构造一个斐波那契数组
void Fibonacci(int * F){
    F[0] = 0;
    F[1] = 1;
    for (int i= 2; i<max_size; i++) {
        F[i] = F[i-1] + F[i-2];
    }
}

//定义菲波那切查找法

/**
 arr:为要查找的数组，
 n为要查找的数组的长度，
 key为要查找的关键字，
 */
int FibonacciSearch (int *arr,int n,int key){
    
    int low = 0;
    
    int high = n-1;
    
    
    int F[max_size];
    
    Fibonacci(F); //构造一个斐波那契数组F, 1，1，2，3，5，8，13，21.....
    
    
    int k=0;
    
    while (n > F[k]-1) { //计算n位于斐波那契的位置
        ++k;
    }
    
    int *temp = (int *) malloc(sizeof(int) * F[k]-1);
    memcpy( temp,arr,n*sizeof(int));
    
    
    for (int i = n; i<F[k]-1; i++) {
        temp[i] = arr[n-1];
    }
    
    
    while (low <= high) {
        
        
        int mid = low + F[k-1]-1;
        
        if (key < temp[mid]) {
            high = mid -1;
            k -=1;
        }
        else if (key>temp[mid]){
            low = mid +1;
            k-=2;
        }
        else {
            if (mid<n) {
                return mid;
            }else{
                return n-1;
            }
        }
    }
    
    return -1;

}



