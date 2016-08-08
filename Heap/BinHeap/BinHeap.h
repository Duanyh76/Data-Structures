#ifndef _BinHeap_H

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int Position;

PriorityQueue Initialize( int MaxElements );
void Destory( PriorityQueue H );
void MakeEmpty( PriorityQueue H );
void Insert( ElementType X, PriorityQueue H );
ElementType DeleteMin( PriorityQueue H );
ElementType FindMin( PriorityQueue H );
int IsEmpty( PriorityQueue H );
int IsFull( PriorityQueue H );
void DecreaseKey( Position P, ElementType X, PriorityQueue H );
void IncreaseKey( Position P, Elementtype X, PriorityQueue H );
void Delete( Position P, PriorityQueue H );
PriorityQueue BuildHeapByInsert( ElementType Array[], int Length );
PriorityQueue BuildHeap( ElementType Array[], int Length );
void PercolateDown( Position P, PriorityQueue H );

#endif