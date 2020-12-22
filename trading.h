#include<stdint.h>
#ifndef TRADING_H_INCLUDED
#define TRADING_H_INCLUDED
#include "appconst.h"

typedef struct _Trading_Q_ TradingQ;

struct _Trading_Q_{

    int32_t         data;
    _Trading_Q_     *next;
    char            share_name[SHARE_NAME];
    char            date[32];
    uint8_t         quantity;
    uint32_t        price;
};

typedef struct _queue_ Queue;

struct _queue_ {
    uint32_t    size;
    uint32_t    count;
    TradingQ    *rear;
    TradingQ    *front;

};

typedef struct _queue_result QueueResult;

struct _queue_result{
    int32_t data;
    uint32_t    status;
};

Queue   queue_new();
uint8_t queue_full(Queue *q);
Queue* queue_add(Queue *q, int32_t ele, QueueResult *res);
Queue* queue_del(Queue *q, QueueResult *res);
uint32_t    queue_length(Queue *q);


#endif // TRADING_H_INCLUDED
