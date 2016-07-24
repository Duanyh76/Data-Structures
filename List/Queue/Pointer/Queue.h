#ifndef _Queue_h

#define ElementType int

struct QueueNode;
typedef struct QueueNode *Position;
typedef struct QueueNode *Queue;

int IsEmpty( Queue Q );
void MakeEmpty( Queue Q );
void Enqueue( ElementType X, Queue Q );
void Dequeue( Queue Q );

#endif