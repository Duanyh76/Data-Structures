#include "Queue.h"
#define MinQueueSize ( 5 )

struct Queue
{
    int Capacity;
    int Font;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty( Queue Q )
{
    return Q->Size == 0;
}

void MakeEmpty( Queue Q )
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ( int Value, Queue Q )
{
    if( ++Value == Q->Capacity )
    {
        Value = 0;
    }
    return Value;
}

void Enqueue( ElementType X, Queue Q )
{
    if( IsFull( Q ) )
    {
        Error( "Full queue" );
    }
    else
    {
        Q->Size++;
        Q->Rear = Succ( Q->Rear, Q );
        Q->Array[ Q->Rear ] = X;  
    }
}