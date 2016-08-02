#include "HashSep.h"
#define MinTableSize 1

struct ListNode
{
    ElementType Element;
    Position Next;
};

struct HashTbl
{
    int TableSize;
    List *TheLists;
};

HashTable InitializeTable( int TableSize )
{
    HashTable H;
    int i;
    if( TableSize < MinTableSize )
    {
        Error( "Table size too small" );
        return NULL;
    }
    H = malloc( sizeof( struct HashTbl ) );
    if( H == NULL )
    {
        FatalError( "Out of space" );
    }
    H->TableSize = NextPrime( TableSize );
    H->TheLists = malloc( sizeof( List ) * H->TableSize );
    if( H->TheLists == NULL )
    {
        FatalError( "Out of space" );
    }
    H->TheLists = malloc( H->TableSize * sizeof( struct ListNode ) );
    for( i = 0; i< TableSize; i++ )
    {
        if( H->TheLists[i] == NULL )
        {
            FatalError( "Out of space" );
        }
        else
        {
            H->TheLists[i]->Next == NULL;
        }
    }
    return H;
}

Position Find( ElementType Key, HashTable H )
{
    Position P;
    List L;
    L = H->TheLists[ Hash( Key, H->TableSize ) ];
    P = L->Next;
    while( P != NULL && P->Element != Key )
    {
        P = P->Next;
    }
    return P;
}

void Insert( ElementType Key, HashTable H )
{
    Position Pos, NewCell;
    List L;
    Pos = Find( Key, H );
    if( Pos == NULL )
    {
        NewCell = malloc( sizeof( struct ListNode ) );
        if( NewCell == NULL )
        {
            FatalError( "Out of space" );
        }
        else
        {
            L = H->HashTable[ Hash( Key, H->TableSize ) ];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}