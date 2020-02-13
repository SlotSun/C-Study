//
// Created by SUN on 2019/7/17.
//

#ifndef STUDY_DS_H
#define STUDY_DS_H
#define MaxSize 50
#define ElemType int
#define InitSize 100
#endif //STUDY_DS_H
static int si;

//静态线性表
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;


//单链表的定义
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//双链表的定义
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

//二叉树的定义
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} *BiTree, BiTNode;

//栈的线性定义
typedef struct {
    BiTree data[MaxSize];
    int top;
} SqStack;


//栈的链式定义
typedef struct Linknode {
    ElemType data;
    struct Linknode *next;
} *LiStack;


//队列的定义
typedef struct {
    BiTree data[MaxSize];
    int front, rear;
} SqQueue;
typedef struct {
    LNode *front, *rear;
} LinkQueue;


//常用方法
void swap(int *a, int *b) {
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}





















