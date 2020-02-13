//
// Created by SUN on 2019/8/13.
//

#ifndef STUDY_STACK_H
#define STUDY_STACK_H

#endif //STUDY_STACK_H

//初始化
void InitStack(SqStack *S) {
    S->top = -1;
}

//判断栈空
int StackEmpty(SqStack S) {
    if (S.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

//进栈
int Push(SqStack *S, BiTree x) {
    if (S->top == MaxSize - 1)
        return 0;
    S->data[++S->top] = x;
    return 1;
}

//出栈
int Pop(SqStack *S, BiTree *x) {
    if (S->top == -1) {
        return 0;
    }
    *x = S->data[S->top--];
    return 1;
}

//读取栈顶元素
int GetTop(SqStack S, BiTree x) {
    if (S.top == -1)
        return 0;
    x = S.data[S.top];
    return 1;
}

//判断单链表的n个字符是否中心对称.
//    算法思想:使用栈来判断
int dc(LinkList L, int n) {
    int i;
    char s[n / 2];
    LNode *p = L->next;
    for (i = 0; i < n / 2; i++) {
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 == 1)
        p = p->next;
    while (p && s[i] == p->data) {
        i--;
        p = p->next;
    }
    if (i == -1)
        return 1;
    else
        return 0;
}
//括号匹配
//int BracketsCheck(char *str){
//	SqStack S;
//	InitStack(&S);
//	int i = 0;
//	char e;
//	while(str[i]){
//		switch(str[i]){
//            case '(': Push(&S,'(');break;
//            case '[': Push(&S,'[');break;
//            case '{': Push(&S,'{');break;
//            case ')': Pop(&S,&e);
//                if(e!='(') return 0;
//                break;
//            case ']': Pop(&S,&e);
//                if(e!='[') return 0;
//                break;
//            case '}': Pop(&S,&e);
//                if(e!='{') return 0;
//                break;
//            default:
//                break;
//		}
//		i++;
//	}
//	if(!(StackEmpty(S))){
//        return 0;
//	} else{
//        return 1;
//	}
//}



























