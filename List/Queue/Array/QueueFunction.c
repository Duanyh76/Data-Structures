#include "Queue.h"
#define MinQueueSize ( 5 )

struct QueueRecord
{
    int Capacity;
    int Front;
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

int IsFull( Queue Q )
{
    return Q->Capacity == Q->Size;
}

Queue CreateQueue( int MaxElements )
{
    Queue Q;
    if( MaxElements < MinQueueSize )
    {
        Error( "Queue size is too small" );
    }
    Q = malloc( sizeof( struct QueueRecord ) );
    if( Q == NULL )
    {
        FatalError( "Out of space" );
    }
    Q->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( Q->Array == NULL )
    {
        FatalError( "Out of space" );
    }
    Q->Capacity = MaxElements;
    MakeEmpty( Q );
    return Q;
}

void DisposeQueue( Queue Q )
{
    if( Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}

ElementType Front( Queue Q )
{
    if( !IsEmpty( Q ) )
    {
        return Q->Array[ Q->Front ];
    }
    Error( "Empty space" );
    return 0;
}

void Dequeue( Queue Q )
{
    if( IsEmpty( Q ) )
    {
        Error( "Empty space" );
    }
    else
    {
        Q->Front++;
    }
} 

ElementType FrontAndDequeue( Queue Q )
{
    if( !IsEmpty( Q ) )
    {
        return Q->Array[ Q->Front-- ];
    }
    Error( "Empty queue" );
    return 0;
}