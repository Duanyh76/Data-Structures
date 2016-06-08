#ifndef _LIST_H
#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

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
ElementType Retrieve(Positon P);

#endif