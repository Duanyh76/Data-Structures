#include "List.h"
#include <stdlib.h>
#define MinElement -32767

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
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
    {
        FatalError("Out of space.");
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position P, TmpCell;
    P = L->Next;
    L->Next = NULL;
    while(P != NULL)
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    if(P != NULL)
    {
        return P->Next;
    }
    else
    {
        return P;
    }
}

ElementType Retrieve(Position P, List L)
{
    if(P != NULL)
    {
        return P->Element;
    }
    else
    {
        return MinElement;
    }
}