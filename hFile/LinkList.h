//
// Created by Slot on 2019/7/23.
//
#ifndef STUDY_LINKLIST_H
#define STUDY_LINKLIST_H
#endif //STUDY_LINKLIST_H

//单链表 双链表
//头插法建立单链表：可以根据这个方法进行一些数据操作
LinkList CreatListHead(LinkList L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//尾插法建立单链表
LinkList CreatListRear(LinkList L, int *a, int n) {
    int x, i = 0;
    L = (LinkList) malloc(sizeof(LNode));
    LNode *s, *r = L;
    while (i < n) {
        x = a[i++];
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;                              //r = r.next;
    }
    r->next = NULL;
    return L;
}


//对链表的增删查改
//按正序号查找节点值
LNode *LLGetElem(LinkList L, int i) {
    int j = 1;
    LNode *p = L->next;
    if (!i) {
        return L;
    }
    if (i < 1) {
        return NULL;
    }
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//按逆序号查找节点
LNode *LLGetElemBack(LinkList L, int k) {
    if (k < 1)
        return NULL;
    LNode *p = L->next;
    LNode *q = L->next;
    while (k--) {
        p = p->next;
    }
    while (p) {
        p = p->next;
        q = q->next;
    }
    return q;
}

//按值查找表节点
LNode *LLLocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p && p->data != e) //这里
        p = p->next;
    return p;
}

//单链表插入节点
int LLinsert(LinkList L, int i, LNode *s) {           //i是位置，s为待插入节点
    LNode *p = LLGetElem(L, i - 1);
    s->next = p->next;
    p->next = s;
    return 1;
}

//单链表删除节点
int LLdeleteI(LinkList L, int i) {
    LNode *p = LLGetElem(L, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}


//单链表删除节点
int LLdeleteX(LinkList L, LNode *q) {
    LNode *p = L->next;
    LNode *pre = L;
    while (p) {
        if (p == q) {
            pre->next = p->next;
            free(q);
            return 1;
        } else {
            p = p->next;
            pre = pre->next;
        }
    }
    return 0;
}


//单链表的长度
int LLLength(LinkList L) {
    LNode *p = L->next;
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

//双链表的各种操作
//双链表查找节点
DNode *DLLGetElem(DLinklist L, int i) {
    int j = 1;
    DNode *p = L->next;
    if (!i) {
        return L;
    }
    if (i < 1) {
        return NULL;
    }
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 双链表的插入操作
int DLLinsert(DLinklist L, int i, DNode *s) {       //i为插入节点位置，s为待插入节点
    DNode *p = DLLGetElem(L, i);
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return 1;
}

// 双链表的删除操作
int DLLdelete(DLinklist L, int i) {
    DNode *p = DLLGetElem(L, i);
    p->prior->next = p->next;
    p->next->prior = p->prior;
    return 1;
}

//p37 q1:设计一个递归算法，删除不带头结点的单链表L中的所有值为x的节点
void p37q1NhLDeleteX(LinkList L, int x) {
    if (L) {
        if (L->data == x)
            LLdeleteI(L, x);
        p37q1NhLDeleteX(L->next, x);
    }
}

//p37 q2:在带头节点的单链表L中，删除所有值为x节点，并释放其空间为x的节点
//p37 q3:设L为带头结点的单链表，编写算法实现从未到头反向输出每个节点的值
void p37q3PrintLL(LinkList L) {
    if (L) {
        p37q3PrintLL(L->next);
        printf("%d ", L->data);
    }
}

//p37 q4:在带头结点的单链表L中删除一个最小值节点的算法
void p37q4LLDeleteMin(LinkList L) {
    LNode *t, *s, *r = L;  //t存放最小节点，s往后遍历单链表，r尾插法辅助构建L（）
    s = L->next->next;
    t = L->next;
    while (s) {
        if (t->data > s->data) {
            r->next = t;
            r = t;
            t = s;
        } else {
            r->next = s;
            r = s;
        }
        s = s->next;
    }
    r->next = NULL;
}

//p37 q5：编写算法将带头结点的单链表就地逆置，空间复杂度为o（1）
LinkList p37q5LLInversion(LinkList L) {
    LNode *s = L->next;
    L->next = NULL;
    LNode *r;
    while (s) {
        r = s;
        s = s->next;                                            //原因：指针会直接改动目标地址内存上的数据
        r->next = L->next;
        L->next = r;
//        s = s->next;
    }
    return L;
}

//p37 q6:在一个带头结点的单链表L，设计一个算法使其元素递增有序
LinkList p37q6LLSortI(LinkList L) {
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while (p) {
        r = p->next;
        pre = L;
//        printf("%d ", pre->next->data);
        while (pre->next && (pre->next->data < p->data)) {

            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
    return L;
}

//p37 q7:设在一个带头节点的单链表中所有元素节点无序，试着编写一个函数，删除表中所有介于给定两个值之间的元素的元素（若存在）

LinkList p37q7LLDeleteAoB(LinkList L, int a, int b) {
    LNode *p = L->next, *pre = L;
    while (p) {
        if (p->data > a && p->data < b) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            p = p->next;
            pre = pre->next;
        }
    }
    return L;
}

//p37 q8:给定两个单链表，编写算法找出两个链表的公共节点。
LinkList p37q8LLSelectSim(LinkList LA, LinkList LB) {
    int dist = 0, LALenth = 0, LBLenth = 0;
    LALenth = LLLength(LA);
    LBLenth = LLLength(LB);
    LinkList P, R;
    if (LALenth > LBLenth) {
        P = LA->next;
        R = LB->next;
    } else {
        P = LB->next;
        R = LA->next;
    }
    dist = fabs(LALenth - LBLenth);
    while (dist--)
        P = P->next;
    while (P) {
        if (P->data == R->data)
            return P;
        else {
            P = P->next;
            R = R->next;
        }
    }
    return NULL;
}

//p37 q9:给定一个带头结点的单链表,设Head为头指针，试写出算法：按照递增次序输出单链表中的各结点的数据元素，并释放结点所占的存储空间（要求：不允许使用数组作为辅助空间）
void p37q9LLPrintUp(LinkList L) {
    LNode *p = L->next, *pre = L, *u;
    while (L->next) {                               //是一种反向头插法的解法：
        p = L->next;                                //
        pre = L;                                    //
        while (p->next) {
            if (p->next->data < pre->next->data)
                pre = p;
            p = p->next;
        }
        printf("%d ", pre->next->data);
        u = pre->next;
        pre->next = u->next;
        free(u);
    }
    free(L);
}

//p37 q10:讲一个带头结点的单链表A分解为两个带头结点的单链表A和B，使得A表中含有原表中序号为奇数的元素，B表中含有原表中序号为偶数的元素，且保持其相对位置不变。
void p37q10LLDivideA(LinkList LA, LinkList LB) {
    LNode *p = LA->next;
    LNode *q = LB;
    while (p) {
        q->next = p->next;
        q = q->next;
        if (p->next)
            p->next = p->next->next;
        p = p->next;
    }
}

//p37 q12:递增有序的单链表中，设计算法去掉数值想通的元素
void p37q12LLDeleteSimilar(LinkList L) {
    LNode *p = L->next, *q;
    while (p && p->next) {
        if (p->data != p->next->data)
            p = p->next;
        else {
            q = p->next;
            p->next = p->next->next;
            free(q);
        }
    }
}

//p37 q13:假设有两个按元素值递增次序排列的单链表，将两个单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的节点存储归并后的单链表
LinkList p37q13LLMergeSortD(LinkList LA, LinkList LB) {
    LNode *p = LA->next, *q = LB->next, *pA = LA->next, *qB = LB->next;
    LA->next = NULL;
    while (p && q) {
        if (p->data >= q->data) {
            qB = qB->next;
            q->next = LA->next;
            LA->next = q;
            q = qB;
        } else {
            pA = pA->next;
            p->next = LA->next;
            LA->next = p;
            p = pA;
        }
    }
    while (p) {
        pA = pA->next;
        p->next = LA->next;
        LA->next = p;
        p = pA;
    }
    while (q) {
        qB = qB->next;
        q->next = LA->next;
        LA->next = q;
        q = qB;
    }
    return LA;
}

//p38 q14:设A和B是两个单链表（带头结点），其中元素递增有序。要求从A和B中公共元素产生单链表C,要求不破坏A、B的节点
LinkList p38q14LLGetCommon(LinkList LA, LinkList LB) {
    LNode *p = LA->next, *q = LB->next;
    LNode *s;
    LinkList LC;
    LC = (LinkList) malloc(sizeof(LNode));
    LC->next = NULL;
    while (p && q) {
        if (p->data < q->data)
            p = p->next;
        else if (p->data > q->data) {
            q = q->next;
        } else {
            s = (LNode *) malloc(sizeof(LNode));
            s->data = p->data;
            s->next = LC->next;
            LC->next = s;
            p = p->next;
            q = q->next;
        }
    }
    return LC;
}

//p38 q15:已知A和B分别表示两个集合，其元素递增有序。求A和B的交集，并存入A链表中。
LinkList p38q15LLgetCommon(LinkList La, LinkList Lb) {
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    LNode *pc = La;
    pc = La;
    LNode *u;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        } else {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(Lb);
    return La;
}


















