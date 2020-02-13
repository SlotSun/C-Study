//
// Created by SUN on 2019/7/17.
//


#ifndef STUDY_SEQLIST_H
#define STUDY_SEQLIST_H

#endif //STUDY_SEQLIST_H
//创建一个线性表
void CreatSq(SqList *L,int *a){
    while(a[L->length]){
        L->data[L->length] = a[L->length];
        L->length++;
    }
}
//线性表的插入操作
int ListInsert(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1)
        return 0;
    if (L->length >= MaxSize)
        return 0;
    for (int j = L->length; j < i; --j) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return 1;
}

//线性表的删除操作
int ListDelete(SqList *L, int i, int *e) {
    if (i < 1 || i > L->length + 1)
        return 0;
    *e = L->data[i - 1];
    for (int j = 0; j < L->length; ++j) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return 1;
}
//不设置数值的改变均是地址的改变

//线性表按值查找,不涉及地址改变
int SqLocateElem(SqList L, ElemType e) {
    int i;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

//综合应用题

//  p18 1:从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值。空出的位置由最后一个元素填补，
//  若顺序表为空显示出错信息并退出运行

int MinDelete(SqList *L, int *e) {
    int temp = 0, i = 0;
    if (L->length == 0)
        return 0;
    for (i = 0; i < L->length - 1; ++i) {
        if (L->data[temp] > L->data[i])
            temp = i;
    }
    *e = L->data[temp];
    L->data[temp] = L->data[L->length - 1];
    L->data[L->length - 1] = 0;
    L->length--;
    return 1;
}


//p18 2:设计一个高效算法，将顺序表的所有元素转置，要求算法的空间复杂度为0（1）
void SqReverse(SqList *L) {
    int temp = 0;
    for (int i = 0; i < L->length / 2; ++i) {
        temp = L->data[i];
        L->data[i] = L->data[L->length - i - 1];
        L->data[L->length - i - 1] = temp;
    }
}

//p18 3：长度为n的顺序表L,编写一个时间复杂度为O(n),空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素
void SqDeleteX(SqList *L, int x) {
    int k = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] != x) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

//p18 4:从有序顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素 ，如果s或t不合理或者顺序表为空则显示
// 错误信息并推出运行。
int SqDeleteSt(SqList *L, int s, int t) {
    int k = 0;
    if (s >= t || L->length == 0)
        return 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] < s || L->data[i] > t) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
    return 1;
}

//p18 6:从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
void SqDeleteRe(SqList *L) {
    int k = 0;
    for (int i = 1; i < L->length;) {
        if (L->data[k] == L->data[i]) {
            i++;
        } else {
            k++;
            L->data[k] = L->data[i];
        }
    }
    L->length = k + 1;
}


//p18 7: 将两个有序顺序表合并成一个新的有序顺序表，并由函数返回结果顺序表
void SqMerge(SqList *a, SqList *b) {
    int i = a->length - 1, j = b->length - 1;
    int temp = a->length + b->length - 1;
    for (; i >= 0 && j >= 0;) {
        if (a->data[i] >= b->data[j]) {
            a->data[temp--] = a->data[i--];
        } else {
            a->data[temp--] = b->data[j--];
        }
    }
    if (j >= 0) {
        for (; j >= 0; j--) {
            a->data[j] = b->data[j];
        }
    }
    a->length = a->length + b->length;

}

//p18 已知数组A[m+n]中依次存放着两线性表（a）(b) 试着写一个函数，将数组中两个顺序表的位置互换。
void SqExchange(ElemType *A,SqList a,SqList b){
    int B[MaxSize] = {};
    int temp = 0;
    for (int i = a.length; i <a.length+b.length ; ++i) {
        B[temp++] = A[i];
    }
    for (int j = a.length-1; j >=0 ; j--) {
        A[b.length+j] = A[j];
    }
    for (int k = 0; k <b.length ; ++k) {
        A[k] = B[k];
    }
}

//循环数组左移
void cirArrLShift(int *a,int n,int p){
    for (int i=0;  i<p/2 ; i++) {
        swap(&a[i],&a[p-i-1]);
    }
    for (int i=0;  i<(n-p)/2 ; i++) {
        swap(&a[p+i],&a[n-i-1]);
    }
    for (int i=0;  i<n/2 ; i++) {
        swap(&a[i],&a[n-i-1]);
    }
}












