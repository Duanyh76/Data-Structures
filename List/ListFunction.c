#include "List.h"
#include <stdlib.h>

struct Node
{
    ElementType Element;
    Position Next;
};

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
    Position P;
    while(P != NULL && P->Element != X)
    {
        P = P->Next;
    }
    return P;
}

List MakeEmpty(List L)
{
    L->Next == NULL;
    return L;
}

void Delete(ElementType X,List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if(!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L)
{   
    Position P;
    P = L;
    while(P->Next != NULL && P->Next->Element != NULL)
    {
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, Position P, List L)
{
    Position
}