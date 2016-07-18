struct DoubleLinkdNode;
typedef struct DoubleLinkdNode *PtrToDoubleLinksNode;
typedef PtrToDoubleLinksNode DLPosition;
typedef PtrToDoubleLinksNode DLList;

struct PolyNode;
typedef struct PolyNode *PtrToPolyNode;
typedef PtrToPolyNode Term;
typedef PtrToPolyNode Polynomial;

struct ArrayLinkedList;
typedef struct ArrayLinkedList *ALList;

struct LazyNode;
typedef struct LazyNode *LazyArray;
typedef struct LazyNode *LazyPosition;

struct SymNode;
typedef struct SymNode *SymStack;

Position FindNext(ElementType X, Position P, List L);
List Reverse(List L);
List CreateThenReverse(List L);
void PrintList(List L);
void PrintLots(List L, List M)
void Exchange(Position P, List L);
void DLExchange(DLPosition P,DLList L);
void CopyThenCreateNode(Position ExitP, Position CCP);
List Union(List L1, List L2);
List Intersection(List L1, List L2);
void CopyThenCreateTerm(Term ExitT, Term CCT);
void PolyExchange(Term T, Polynomial P);
Polynomial AddPolynomial(const Polynomial Poly1, const Polynomial Poly2);
Polynomial MultPolynomial(const Polynomial Poly1, const Polynomial Poly2);
Polynomial CreatePolynomial();
Polynomial PowerPolynomial(int power, Polynomial Poly);
List CreateJosephusList(const int people);
ElementType WinJosephus(const int times, const int people);
ElementType FindAndAdjust(ElementType X, ALList L);
void AddAndAdjust(ElementType X, ALList L);
ElementType FindAndAdjust(ElementType X, List L);
void AddAndAdjust(ElementType X, List L);
void RemoveMultipleElements(ALList L);
void Delete(int Position, ALList L);
void LazyDelete(ElementType X, List L);
struct Expression;
void CheckPair(char Input, SymStack S);
ElementType Calucate(Expression Array[]);