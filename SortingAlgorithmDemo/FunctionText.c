//
//  FunctionText.c
//  SortingAlgorithmDemo
//
//  Created by apple on 2020/9/2.
//  Copyright © 2020 APPLE. All rights reserved.
//

#include "FunctionText.h"


//结构体的赋值
void getvect(vect *v){
    scanf("%d,%d",&(v->x),&(v->y));
}
void showvect(vect v){
    printf("%d,%d",v.x,v.y);
}
