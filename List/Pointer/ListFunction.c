#include "List.h"
#include <stdlib.h>
#define MinElement -32767

struct Node
{
    ElementType Element;
    Position Next;
};

struct DoubleLinksNode
{
    ElementType Element;
    DLPosition Before;
    DLPosition Next;
};

struct PolyNode
{
    int Coefficient;
    int Exponent;
    PtrToPolyNode Next;
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
    P = L->Next;
    while(P != NULL && P->Element != X)
    {
        P = P->Next;
    }
    return P;
}

Position FindNext(ElementType X, Positon P,List L)
{
    if(P->Element == X || P == NULL)
    {
        return P;
    }
    else
    {
        return FindNext(X, P->Next, L);
    }
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

List Reverse(List L)
{
    Position PBefore ,P ,PNext;
    PBefore = L->Next;
    P = PBefore->Next;
    PNext = P->Next;
    PBefore->Next = NULL;
    while(TNext != NULL)
    {
        T->Next = TBefore;
        TBefore = T;
        T = TNext;
        TNext = T->Next;
    }
    T->Next = TBefore;
    L->Next = T;
    return L;
}

List CreateThenReverse(List L)
{
    int num = 0;
    Position P, NewP;
    List NewL;
    NewL = malloc(sizeof(struct Node));
    NewP = malloc(sizeof(struct Node));
    NewP = NewL->Next;
    P = L->Next;
    while(P != NULL)
    {
        num++;
        P = P->Next;
    }
    ElementType a[num];
    for(int i = 0, P = L->Next; P != NULL; i++)
    {
        a[i] = P->Element;
        P = P->Next;
    }
    for(int i = num - 1; i > -1; i--)
    {
        NewP->Element = a[i];
        NewP->Next = malloc(sizeof(struct Node));
        NewP = NewP->Next;
    }
    return NewL;
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

void PrintList(List L)
{
    Position P;
    P = L->Next;
    while(P != NULL)
    {
        printf("%d\t",P->Element);
        P = P->Next;
    }
}

void PrintLots(List L, List M)
{
    Position Pl, Pm;
    int i;
    Pm = M->Next;
    while(Pm != NULL)
    {   
        Pl = L->Next;
        for(i = Pm->Element; i >1; i--)
        {
            if(Pl != NULL)
            {
                Pl = Pl->Next;
            }
        }
        if(Pl != NULL)
        {
            printf("%d\t",Pl->Element);
        }
        else
        {
            printf("%d\t",MinElement);
        }
        Pm = Pm->Next;
    }
}

void Exchange(Position P, List L)
{
    Position PBefore, PNext;
    if(IsLast(P, L))
    {
        return;
    }
    PBefore = FindPrevious(P->Element, L);
    PNext = P->Next;
    P->Next = PNext->Next;
    PBefore->Next = PNext;
    PNext->Next = P;
}

void DLExchange(DLPosition P, DLList L)
{
    if(P->Next == NULL)
    {
        return;
    }
    Position BeforeP, ExchangeP, NextP;
    BeforeP = P->Before;
    ExchangeP = P->Next;
    BeforeP->Next = ExchangeP;
    ExchangeP->Before = BeforeP;
    P->Before = ExchangeP;
    P->Next = ExchangeP->Next;
    Exchange->Next = P;
    if(P->Next != NULL)
    {
        NextP = P->Next;
        NextP->Before = P;
    }
}

void CopyThenCreateNode(Position ExitP, Position CCP)
{
     CCP->Element = ExitP->Element;
     ExitP = ExitP->Next;
     CCP->Next = malloc(sizeof(struct Node));
     CCP = CCP->Next;
}

List Union(List L1, List L2)
{
    List UnionList;
    UnionList = malloc(sizeof(struct Node));
    Positon P1, P2, P;
    P1 = L1->Next;
    P2 = L2->Next;
    P = malloc(sizeof(struct Node));
    P = UnionList->Next;
    while(P1 != NULL && P2 != NULL)
    {
        if(P1->Element == P2->Element)
        {
            P2 = P2->Next;
            CopyThenCreateNode(P1, P);
        }
        else if(P1->Element > P2->Element)
        {
            CopyThenCreateNode(P2, P);
        }
        else
        {
            CopyThenCreateNode(P1, P);
        }
    }
    if(P1 == NULL)
    {
        while(P2 != NULL)
        {
            CopyThenCreateNode(P2, P);
        }
    }
    if(P2 == NULL)
    {
        while(P1 != NULL)
        {
            CopyThenCreateNode(P1, P);
        }
    }
    P == NULL;
    return UnionList;
}

List Intersection(List L1, List L2)
{
    List InterList;
    InterList = malloc(sizeof(struct Node));
    Position P1, P2, P;
    P1 = L1->Next;
    P2 = L2->Next;
    P = malloc(sizeof(struct Node));
    P = InterList->Next;
    While(P1 != NULL && P2 != NULL)
    {
        if(P1->Element == P2->Element)
        {
            P->Element = P1->Element;
            P1 = P1->Next;
            P2 = P2->Next;
            P->Next = malloc(sizeof(struct Node));
            P = P->Next;
        }
        else if(P1->Element > P2->Element)
        {
            P2 = P2->Next;
        }
        else
        {
            P1 = P1->Next;
        }
    }
    P == NULL;
    return InterList;
}

void CopyThenCreateTerm(Term ExitT, Term CCT)
{
    CCT->Coefficient = ExitT->Coefficient;
    CCT->Exponent = Exit->Exponent;
    ExitT = ExitT->Next;
    CCT->Next = malloc(sizeof(struct PolyNode));
    CCT = CCT->Next;
}

Polynomial AddPolynomial(const Polynomial Poly1, const Polynomial Poly2)
{
    Polynomial SumPoly;
    SumPloy = malloc(sizeof(struct PolyNode));
    Term T1, T2, T;
    T1 = Poly1->Next;
    T2 = Poly2->Next;
    T = malloc(sizeof(struct PolyNode));
    T = SumPoly->Next;
    while(T1 != NULL && T2 != NULL)
    {
        if(T1->Coefficient == T2->Coefficient)
        {
            T->Exponent = T1->Exponent;
            T->Coefficient = T1->Coefficient + T2->Coefficient;
            T1 = T1->Next;
            T2 = T2->Next;
            T->Next = malloc(sizeof(struct PolyNode));
            T = T->Next;
        }
        else if(T1->Coefficient > T2->Coefficient)
        {
            CopyThenCreateTerm(T1, T);
        }
        else
        {
            CopyThenCreateTerm(T2, T);
        }
    }
    if(T1 == NULL)
    {
        while(T2 != NULL)
        {
            CopyThenCreateTerm(T2, T);
        }
    }
    if(T2 == NULL)
    {
        while(T1 != NULL)
        {
            CopyThenCreateTerm(T1, T);
        }
    }
    T = NULL;
    return SumPoly;
}

Polynomial MultPolynomial(const Polynomial Poly1, const Polynomial Poly2)
{
    Polynomial MultPoly;
    MultPoly = malloc(sizeof(struct PolyNode));
    Term T1, T2, T, Tmp, TmpNext;
    T1 = Poly1->Next;
    T2 = Poly2->Next;
    T = malloc(sizeof(struct PolyNode));
    T = MultPoly->Next;
    while(T1 != NULL)
    {
        while(T2 != NULL)
        {
            T->Coefficient = T1->Coefficient + T2->Coefficient;
            T->Exponent = T1->Exponent +T2->Exponent;
            T2 = T2->Next;
            T->Next = malloc(sizeof(struct PolyNode));
            T = T->Next;
        }
        T2 = Poly2->Next;
        T1 = T1->Next;
    }
    T = MultPoly->Next;
    Tmp = T;
    TmpNext = Tmp->Next;
    while(T->Next != NULL)
    {
        while(TmpNext != NULL)
        {
            if(Tmp->Exponent = TmpNext->Exponent)
            {
                Tmp->Coefficient = Tmp->Coefficient + TmpNext->Coefficient;
                Tmp->Next = TmpNext->Next;
                free(TmpNext);
            }
            else if(Tmp->Exponent > TmpNext->Exponent)
            {
                PolyExchange(Tmp, MultPloy);
            }
            else
            {
                break;
            }
            TmpNext = Tmp->Next;
        }
        T = T->Next;
        TmpNext = T->Next;
    }
    return MultPoly;
}

void PolyExchange(Term T, Polynomial P)
{
    Term TBefore, TNext;
    TBefore = P->Next;
    TNext = T->Next;
    while(TBefore->Next != NULL && TBefore->Next->Exponent != T->Exponent)
    {
        TBefore = TBefore->Next;
    }
    TBefore->Next = T->Next;
    T->Next = TNext->Next;
    TNext->Next = T;
}

Polynomial CreatePolynomial();
{
    Polynomial Poly;
    Term T;
    Poly = malloc(sizeof(struct PolyNode));
    T = malloc(sizeof(struct PolyNode));
    T = Poly->Next;
    scanf("%d,%d",&coe,&exp);
    while(exp != 0 && coe != 0)
    {
        T->Coefficient = coe;
        T->Exponent = exp;
        T->Next = malloc(sizeof(struct PolyNode));
        T = T->Next;
        scanf("%d,%d",&coe,&exp);
    }
    T = NULL;
    return Poly;
}

Polynomial PowerPolynomial(int power, Polynomial Poly)
{
    Polynomial P;
    P = MultPolynomial(Poly, Poly);
    for(int i = 3; i < power + 1; i++)
    {
        P = MultPolynomial(P, Poly);
    }
    return P;
}

List CreateJosephusList(int people)
{
    List JosephusList;
    JosephusList = malloc(sizeof(struct Node));
    Positon P;
    P = JosephusList;
    for(int i = 0;i < people; i++)
    {
        P->Element = i + 1;
        P->Next = malloc(sizeof(struct Node));
        P = P->Next;
    }
    P->Next = JosephusList;
    return JosephusList;
}

ElementType WinJosephus(int times, int people)
{
    List JosephusList = CreateJosephusList(people);
    Position P;
    P = JosephusList;
    while(P != P->Next)
    {
        time = times % people;
        for(int i = 0; i < time; i++)
        {
            P = P->Next;
        }
        Delete(P->Element, JosephusList);
    }
    return P->Element;
}