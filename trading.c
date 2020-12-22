#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "trading.h"

//creating a new queue
Queue   queue_new(){
    Queue q={NULL, NULL, 0};
    return q;
}

static TradingQ*  _get_new_node_(int32_t ele) {
    Node *newnode = (TradingQ*)malloc(sizeof(TradingQ));
    newnode->data=ele;
    newnode->next=NULL;

    return newnode;
}

Queue*  queue_add(Queue *q, int32_t ele, QueueResult *res) {
    assert(q!=NULL);
    TradingQ *newnode = _get_new_node_(ele);

    if (q->rear != NULL) {
        q->rear->next=newnode;
        q->rear=newnode;
    }
    else{
        q->rear=q->front=newnode;
    }
    ++q->count;
    res->status=SHARE_OK;
    return  Q;
}

