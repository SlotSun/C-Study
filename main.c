//
// Created by SUN on 2019/8/8.
//
#include "hFile/include.h"


void printD(int a[], int n);

void test(int *e);

void printSqList(SqList L);

void printLinkList(LinkList L);

int main() {
    int bool;
    int a[] = {11, 7, 5, 8, 9, 2, 1, 6, 77};
    int Test1[] = {1, 3, 5, 6, 9, 11, 13, 17, 22, 77};
    int Test2[] = {1, 2, 3, 0, 0, 4, 0, 0, 5, 6, 7, 0, 0, 8, 0, 0, 9, 10, 0, 0, 0};
    int L1[] = {7,9};
    int L2[] = {0,0,1};
    int b[] = {1, 1, 1, 2, 3, 3, 5, 7, 9, 11, 66};
    char str[] = "hello";

//    printf("%s",intToRoman(6));
//    printf("%d",(int)*(str+0) );
//    reverseString(str,5);
//    printf("%s",str);
//    LinkList La;
//    LinkList Lb;
//    LNode *p;
//    bubbleSort(a, 9);
//    printD(a, 9);
//    SqList Sa;
//    CreatSq(&Sa,a);
//    deTriangle(3,4,5);
//    La = CreatListRear(La, a, 5);//尾插法创建单链表
//    printLinkList(La);
//    Lb = CreatListRear(Lb, L2, 3);
//    printLinkList(Lb);
//    La = addTwoNumbers(La->next,Lb->next);
//    cirArrLShift(L1,5,3);
//    printD(L1,5);
//    InsertSort2(a,9);
//    printD(a,9);
//    love();
    BiTree T;
    T = PreCreatBiTree(Test2);
    printf("%d\n", BTreeLeafCount(T));
//    printf("%d\n", Btdepth2(T));
//    printf("%d", balanceBiTree(T));
//    LevelOrder(T);
//    printf("\n");
//    SwapLRB(T);
//    LevelOrder(T);
//    printf("%d\n",Btdepth2(T));
//    InOrder2(T);
//    PreOrder(T);
//    PreOrder2(T);
//    PostOrder2(T);
//    LevelOrder(T);
//    LevelOrder2(T);

//    Lb = CreatListRear(Lb, LB, 6);
//    printLinkList(La);
//     printLinkList(Lb);
//    La = p38q15LLgetCommon(La, Lb);
//    printLinkList(La);
//     Lc = p38q14LLGetCommon(La,Lb);
//     printLinkList(Lc);




//    Lc = p37q13LLMergeSortD(La,Lb);
//    LLdeleteX(LL,q);
//    printLinkList(LL);
//    LL = p37q7LLDeleteAoB(LL,4,10);
//    p37q10LLDivideA(LL,LLB);
//    printLinkList(LL);
//    LL = p37q6LLSortI(LL);
//    LL = p37q5LLInversion(LL);
//    La = p37q5LLInversion(La);
//    printLinkList(La);
//        printLinkList(LL);
//    p37q4LLDeleteMin(LL);
//    int a = 5,b = 9;
//    TempSwap1(&a,&b);
//    printf("%d %d\n",a,b);
//    if(Dinsert(a,9,5))
//        printf("yes\n");
//    Narcissus();
//    printD(a,9);
//    SqList L = {{7, 8, 10, 11}, 4};
//    SqList L1 = {{4, 5, 6}, 3};
//    int A[] = {3, 8, 10, 11, 4, 5, 6};
//    LinkList LL;
//    LL = CreatListHead(LL);
//    LNode s = {6,};
//    LLinsert(LL,2,&s);

//    printLinkList(LL);
//    printLinkList(LL);
//    int e;
//    if(MinDelete(&L,&e)==0)
//        printf("error!\n");
//    else
//        for (int i = 0; i < L.length ; ++i) {
//            printf("%d  ",L.data[i]);
//        }

//    SqDeleteSt(&L,5,7);
//    SqDeleteRe(&L);
//    SqMerge(&L,&L1);
//    SqExchange(A, L, L1);
//    for (int i = 0; i < L.length+L1.length; ++i) {
//       printf("%d  ", A[i]);
//  }
    // printSqList(L);
    return 0;
}

void test(int *e) {
    int i = 5;
    *e = i;
}

void printSqList(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%d  ", L.data[i]);
    }
}

void printLinkList(LinkList L) {
    LNode *s = L;
    s = s->next;
    while (s) {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}


void printD(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d  ", a[i]);
    }
}
