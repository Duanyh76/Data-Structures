#include "Queue.h"

struct QueueNode
{
    ElementType Element;
    Queue Next;
};

int IsEmpty( Queue Q )
{
    return Q->Next == NULL;
}

void MakeEmpty( Queue Q )
{
    Q->Next = NULL;
}

void Enqueue( ElementType X, Queue Q )
{
    Position P;
    P = Q->Next;
    while( P->Next != NULL )
    {
        P = P->Next;
    }
    P->Next = malloc( sizeof( struct QueueNode) );
    P = P->Next;
    P->Element = X;
    P->Next = NULL;
}

void Dequeue( Queue Q )
{
    Position P;
    P = Q->Next;
    Q->Next = P->Next;
    free(P);
}