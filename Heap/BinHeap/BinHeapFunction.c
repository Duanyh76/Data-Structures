#include "BinHeap.h"
#define MinPQSize 1
#define MinData 1

struct HeapStruct 
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

PriorityQueue Initialize( int MaxElements )
{
    PriorityQueue H;
    if( MaxElement < MinPQSize )
    {
        Error( "Priority queue size is too small" );
    }
    H = malloc( sizeof( struct HeapStruct ) );
    if( H == NULL )
    {
        FatalError( "Out of space" );
    }
    H->Elements = malloc( ( MaxElements + 1 ) * sizeof( ElementType ) );
    if( H->Elements == NULL )
    {
        FatalError( "Out of space" );
    }
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[ 0 ] = MinData;
}

void Insert( ElementType X, PriorityQueue H )
{
    int i;
    if( IsFull( H ) )
    {
        Error( "Priority queue is full" );
        return;
    }
    for( i = ++H->Size; H->Element[ i / 2 ] > X; i /= 2 )
    {
        H->Elements[ i ] = H->Elements[ i / 2 ];
    }
    H->Elements[ i ] = X;
}

ElementType DeleteMin( PriorityQueue H )
{
    int i, Child;
    ElementType MinElement, LastElement;
    if( IsEmpty( H ) )
    {
        Error( "Priority queue is empty" );
        return H->Elements[ 0 ]; 
    }
    MinElement = H->Elements[ 1 ];
    LastElement = H->Elements[ H->Size-- ];
    for( i = 1; i * 2 < H->Size || i * 2 == H->Size; i = Child )
    {
        Child = i * 2;
        if( Child != H->Size && H->Elements[ Child + 1 ] < H->Elements[ Child ] )
        {
            Child++;
        }
        if( LastElement > H->Elements[ Child ] )
        {
            H->Elements[ i ] = H->Elements[ Child ];
        }
        else
        {
            break;
        }
    }
    H->Elements[ i ] = LastElement;
    return MinElement;
}

void Destory( PriorityQueue H )
{
    free( H->Elements );
    free( H );
}

void MakeEmpty( PriorityQueue H )
{
    for( int i = 0; H->Elements[ i ] != NULL; i++ )
    {
        H->Elements[ i ] = NULL;
    }
}

ElementType FindMin( PriorityQueue H )
{
    return H->Elements[ 1 ];
}

int IsEmpty( PriorityQueue H )
{
    return H->Elements[ 1 ] == NULL;
}

int IsFull( PriorityQueue H )
{
    return H->Size == H->CapaCity;
}

void DecreaseKey( Position P, ElementType X, PriorityQueue H )
{
    H->Elements[ P ] -= X;
    ElementType Key;
    Key = H->Elements[ P ];
    Position Parent;
    Parent = P / 2;
    while( H->Elements[ Parent ] > H->Elements[ P ] && Parent != 0 )
    {
        H->Elements[ P ] = H->Elements[ Parent ];
        P = Parent;
        Parent /= 2;
    }
    H->Elements[ P ] = Key;
}

void IncreaseKey( Position P, ElementType X, PriorityQueue H )
{
    H->Elements[ P ] += X;
    ElementType Key;
    Key = H->Elements[ P ];
    Position Child;
    Child = P * 2;
    if( H->Elements[ Child ] > H->Elements[ Child + 1 ] )
    {
        Child++;
    }
    while( H->Elements[ P ] > H->Elements[ Child ] && Child < H->Size + 1 )
    {
        H->Elements[ P ] = H->Elements[ Child ];
        P = Child;
        Child = P * 2;
        if( H->Elements[ Child ] > H->Elements[ Child + 1 ] )
        {
            Child++;
        }
    }
    H->Elements[ P ] = Key;
}

Delete( Position P, PriorityQueue H )
{
    ElementType Num, Tmp;
    Num = H->Elements[ P ] - H->Elements[ 1 ] + 1;
    Tmp = H->Elements[ P ];
    DecreaseKey( P, Num, H );
    Num = DeleteMin( H );
    return Tmp;
}

PriorityQueue BuildHeapByInsert( ElementType Array[], int Length )
{
    int i;
    PriorityQueue H;
    H = Initialize( Length );
    for( i = 0; i < Length; i++ )
    {
        Insert( Array[ i ], H );
        H->Size++; 
    }
    return H;
}

PriorityQueue BuildHeap( ElementType Array[], int Length )
{
    PriorityQueue H;
    H = Initialize( Length );
    int i;
    for( i = 0; i < Length; i++ )
    {
        H->Elements[ i + 1 ] = Array[ i ];
        H->Size++;
    }
    for( i = H->Size / 2; i > 0; i--)
    {
        if( H->Elements[ i ] > H->Elements[ i * 2 ] || H->Elements[ i ] > H->Elements[ i * 2 + 1 ] )
        {
            PercolateDown( i, H );
        }
    }
    return H;
}

void PercolateDown( Position P, PriorityQueue H )
{
    ElementType Key;
    Key = H->Elements[ P ];
    Position Child;
    Child = P * 2;
    if( H->Elements[ Child ] > H->Elements[ Child + 1 ] )
    {
        Child++;
    }
    while( Child < H->Size + 1 && H->Elements[ P ] > H->Elements[ Child ] )
    {
        H->Elements[ P ] = H->Elements[ Child ];
        P = Child;
        Child = P * 2;
        if( H->Elements[ Child ] > H->Elements[ Child + 1 ] )
        {
            Child++;
        } 
    }
}