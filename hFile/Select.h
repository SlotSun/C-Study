//
// Created by SUN on 2019/10/26.
//

#ifndef STUDY_SELECT_H
#define STUDY_SELECT_H

#endif //STUDY_SELECT_H


//顺序查找
int Search_Sq(SqList Sa, int key) {
    Sa.data[0] = key;
    int i;
    for (i = Sa.length; Sa.data[i] != key; --i);
    return i;
}

//折半查找：要求顺序表有序
int Binary_Search(SqList Sa, int key) {
    int low, high = Sa.length, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (Sa.data[mid] == key)
            return mid;
        else if (Sa.data[mid] > key)
            high = mid - 1;   //向左
        else
            low = mid + 1;  //向右
    }
    return -1; //无
}
//如何计算ASL
//B+ 和 B的插入删除
//kmp算法 和 next数组
//hash：开放定址  拉链法
