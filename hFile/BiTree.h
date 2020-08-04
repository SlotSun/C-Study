//
// Created by SUN on 2019/8/13.
//

#ifndef STUDY_BITREE_H
#define STUDY_BITREE_H

#endif //STUDY_BITREE_H

//先序遍历
void PreOrder(BiTree T) {
    if (T) {
        printf("%d ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序遍历
void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        printf("%d ", T->data);
        InOrder(T->rchild);
    }
}

//后序遍历
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%d ", T->data);
    }
}

//先序创建二叉树
BiTree PreCreatBiTree(int *a) {
    BiTree T;
    int temp;
    temp = a[si++];
    if (temp == 0)
        T = NULL;
    else {
        T = (BiTree) malloc(sizeof(BiTNode));
        T->data = temp;
        T->lchild = PreCreatBiTree(a);
        T->rchild = PreCreatBiTree(a);
    }
    return T;
}

//中序遍历非递归:这里有一个让人无法接受的地方,如何实现P元素的入栈指针定义,多重定义还是手动修改,极大消耗人的精力和操作.
void InOrder2(BiTree T) {
    SqStack S;
    InitStack(&S);
    BiTree p = T;
    while (p || !StackEmpty(S)) {
        if (p) {
            Push(&S, p);
            p = p->lchild;
        } else {
            Pop(&S, &p);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

//先序遍历非递归：
void PreOrder2(BiTree T) {
    SqStack S;
    InitStack(&S);
    Push(&S, T);
    BiTree p;
    while (!StackEmpty(S)) {
        Pop(&S, &p);
        printf("%d ", p->data);
        if (p->rchild) Push(&S, p->rchild);
        if (p->lchild) Push(&S, p->lchild);

    }
}

//后序遍历非递归
void PostOrder2(BiTree T) {
    SqStack S;
    InitStack(&S);
    SqStack O;
    InitStack(&O);
    BiTree p = T;
    while (p || !StackEmpty(S)) {
        if (p) {
            Push(&S, p);
            Push(&O, p); //栈O是最后的输出栈
            p = p->rchild;
        } else {
            Pop(&S, &p);
            p = p->lchild;
        }
    }
    while (!StackEmpty(O)) {
        Pop(&O, &p);
        printf("%d ", p->data);
    }
}

//p122 q5:设计一个非递归算法求二叉树的高度
int Btdepth(BiTree T) {
    if (!T)
        return 0;
    int front = -1, rear = -1;
    int last = 0, level = 0;
    BiTree Q[MaxSize];
    Q[++rear] = T;
    BiTree p;
    while (front < rear) {
        p = Q[++front];
        if (p->lchild)
            Q[++rear] = p->lchild;
        if (p->rchild)
            Q[++rear] = p->rchild;
        if (front == last) {   //处理该层最右边的节点：把数组分成多段！
            level++;
            last = rear;
        }
    }
    return level;
}

//求二叉树高度递归算法
int Btdepth2(BiTree T) {
    if (!T) {
        return 0;
    }
    int Ldep = Btdepth2(T->lchild);
    int Rdep = Btdepth2(T->rchild);
    if (Ldep > Rdep) {
        return Ldep + 1;
    } else {
        return Rdep + 1;
    }
}

//从上而下 从左到右的层次遍历
void LevelOrder(BiTree T) {
    SqQueue Q;
    InitQueue(&Q);
    BiTree p;
    EnQueue(&Q, T);
//    printf("%d ",Q.data[Q.front]->data);
//    DeQueue(&Q, p);
//    printf("%d ", p->data);
//    EnQueue(&Q, p->rchild);
//    printf("%d ",Q.data[Q.front]->data);
    while (!QueueEmpty(Q)) {
        DeQueue(&Q, &p);
        printf("%d ", p->data);
        if (p->lchild != NULL) {
            EnQueue(&Q, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(&Q, p->rchild);
        }
    }
}

//从下而上 从右而左的层次遍历
void LevelOrder2(BiTree T) {
    SqStack S;
    InitStack(&S);
    SqQueue Q;
    InitQueue(&Q);
    BiTree p;
    EnQueue(&Q, T);
    while (!QueueEmpty(Q)) {
        DeQueue(&Q, &p);
        Push(&S, p);
        if (p->lchild != NULL) {
            EnQueue(&Q, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(&Q, p->rchild);
        }
    }
    while (!StackEmpty(S)) {
        Pop(&S, &p);
        printf("%d ", p->data);
    }
}

//由先序和中序确定一棵二叉树
BiTree PreInCreat(ElemType *A, ElemType *B, int l1, int h1, int l2, int h2) {
    //l1,h1为先序的第一和最后一个节点的下标，l2,h2为中序的第一和最后一个节点下标
    //初始调用的时候，l1=l2=1,h1=h2=n
    BiTree T;
    int i;
    T = (BiTree) malloc(sizeof(BiTree));
    T->data = A[l1];
    for (i = l2; B[i] != T->data; i++);
    int llen = i - l2;
    int rlen = h2 - i;
    if (llen) {
        T->lchild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    } else {
        T->lchild = NULL;
    }
    if (rlen) {
        T->rchild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    } else {
        T->rchild = NULL;
    }
    return T;
}

//判断二叉树是否是完全二叉树
int IsComplete(BiTree T) {
    SqQueue Q;
    BiTNode *p;
    InitQueue(&Q);
    if (!T)
        return 1;
    EnQueue(&Q, T);
    while (!QueueEmpty(Q)) {
        DeQueue(&Q, &p);
        if (p) {
            EnQueue(&Q, p->lchild);
            EnQueue(&Q, p->rchild);
        } else {
            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &p);
                if (p)
                    return 0;
            }
        }
    }
    return 1;
}

//计算二叉树度为二的节点的个数
int DsonNodes(BiTree T) {
    if (T == NULL)
        return 0;
    else if (T->lchild != NULL && T->rchild != NULL)
        return DsonNodes(T->lchild) + DsonNodes(T->rchild) + 1;
    else
        return DsonNodes(T->lchild) + DsonNodes(T->rchild);
}

//计算二叉树中的叶节点个数
int BTreeLeafCount(BiTree T) {
    if (T == NULL) {
        return 0;
    } else if (T->lchild == NULL && T->rchild == NULL) {
        return BTreeLeafCount(T->lchild) + BTreeLeafCount(T->rchild) + 1;
    } else {
        return BTreeLeafCount(T->lchild) + BTreeLeafCount(T->rchild);
    }
}

//交换左右子树
void SwapLRB(BiTree T) {
    if (T) {
        SwapLRB(T->lchild);
        SwapLRB(T->rchild);
        BiTNode *temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}

//判断是否是平衡二叉树
int balanceBiTree(BiTree T) {
    if (!T) {
        return 0;
    }
    int ldeep = balanceBiTree(T->lchild);
    int rdeep = balanceBiTree(T->rchild);
    if (ldeep == -1 || rdeep == -1) {
        return -1;
    }
    return abs(ldeep - rdeep) > 1 ? -1 : ldeep > rdeep ? ldeep + 1 : rdeep + 1;
}














