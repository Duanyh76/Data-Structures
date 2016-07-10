#ifndef _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
static int Succ( int Value, Queue Q );
void Enqueue( ElementType X, Queue Q );
ElementType FrontAndQueue( Queue Q );

#endif