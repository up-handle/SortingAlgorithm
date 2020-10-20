//
//  ArraySomeTest.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/21.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "ArraySomeTest.h"

////for暴力
//plublic int findRepeatNumbar1 (int[] nums){
//    for (int i=0 ; i<num.length; i++) {
//        for (int j = j+1; j<nums.length; j++) {
//            if (num[i]==nums[j]) {
//                return nums[i];
//            }
//        }
//    }
//}
//
////哈希表
//plublic int findRepeatNumbar2 (int[] nums){
//
//    set<Integer> set = new HashSet<>();
//    for (int i =0; i<nums.length; i++) {
//        if (set.contains(num[i])) {
//            return num[i];
//        }
//        set.add(num[i]);
//    }
//}
//
////数组代替hashset
//plublic int findRepeatNumbar3 (int[] nums){
//    int[] bucket = new int[nums.length];
//    Arrays.fill(bucket,-1);
//    for (int i = 0; i<nums.length; i++) {
//        if (bucket[nums[i]] != -1) {
//            return nums[i];
//        }
//        bucket[num[i]] = i;
//    }
//    return -1;
//}
//
//
//plublic int findRepeatNumbar3 (int[] nums){
//
//    for (int i=0; i<nums.length; i++) {
//        while (i !=nums[i]) {
//
//            if (nums[i] == nums[nums[i]]) {
//                return nums[i];
//            }
//            int temp = nums[nums[i]];
//
//            nums[nums[i]] = nums[i];
//
//            nums[i] = temp;
//        }
//    }
//}


