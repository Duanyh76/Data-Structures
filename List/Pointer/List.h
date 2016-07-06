#ifndef _LIST_H
#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct DoubleLinkdNode;
typedef struct DoubleLinkdNode *PtrToDoubleLinksNode;
typedef PtrToDoubleLinksNode DLPosition;
typedef PtrToDoubleLinksNode DLList;

struct PolyNode;
typedef struct PolyNode *PtrToPolyNode;
typedef PtrToPolyNode Term;
typedef PtrToPolyNode Polynomial;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Positon P, List L);
Position Find(ElementType X, List L);
void Delete(ELementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, Position P, List L);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Positon P, List L);
void PrintList(List L);
void PrintLots(List L, List M)
void Exchange(Position P, List L);
void DLExchange(DLPosition P,DLList L);
void CopyThenCreateNode(Position ExitP, Position CCP);
List Union(List L1, List L2);
List Intersection(List L1, List L2);
void CopyThenCreateTerm(Term ExitT, Term CCT);
Polynomial AddPolynomial(const Polynomial Poly1, const Polynomial Poly2);
Polynomial MultPolynomial(const Polynomial Poly1, const Polynomial Poly2);

#endif