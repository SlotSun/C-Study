//
// Created by SUN on 2019/9/6.
//

#ifndef STUDY_QUEUE_H
#define STUDY_QUEUE_H

#endif //STUDY_QUEUE_H
//初始化队
void InitQueue(SqQueue *Q){
    Q->front = Q->rear = 0;
}

//判断队空
int QueueEmpty(SqQueue Q){
    if(Q.rear == Q.front){
        return 1;
    } else{
        return 0;
    }
}
//进队
void EnQueue(SqQueue *Q, BiTree T)
{
    Q->data[Q->rear++] = T;
}
//出队
void DeQueue(SqQueue *Q, BiTree *T)
{
    *T = Q->data[Q->front++];
}