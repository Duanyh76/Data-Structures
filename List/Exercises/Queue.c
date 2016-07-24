struct DequeNode
{
    ElementType Element;
    int Size;
    Deque Next;
};

typedef struct DequeNode *Deque;
typedef struct DequeNode *Next;
typedef struct DequeNode *Position;

void Push( ElementType X, Deque D )
{
    Positon P;
    P = malloc( sizeof ( struct DequeNode ) );
    P->Element = X;
    P->Next = D->Next;
    D->Next = P;
    D->Size++;
}

ElementType Pop( Deque D )
{
    ElementType Key;
    Position P;
    P = D->Next;
    Key = P->Element;
    D->Next = P->Next;
    free(P);
    D->Size--;
    return Key;
}

void Inject( ElementType X, Deque D )
{
    Positon P;
    P = D->Next;
    for( int i = 1; i < D->Size; i++)
    {
        P = P->Next;
    }
    P->Next = malloc( sizeof ( struct DequeNode ) );
    P->Next->Element = X;
    P->Next->Next = NULL;
    D->Size++; 
}

ElementType Eject( Deque D )
{
    Positon P;
    P = D->Next;
    ElementType Key;
    for( int i = 2; i < D->Size; i++)
    {
        P = P->Next;
    }
    Key = P->Next->Element;
    free( P->Next );
    P->Next = NULL;
    D->Size--;
    return Key;
}