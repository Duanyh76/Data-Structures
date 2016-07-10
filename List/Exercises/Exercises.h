struct DoubleLinkdNode;
typedef struct DoubleLinkdNode *PtrToDoubleLinksNode;
typedef PtrToDoubleLinksNode DLPosition;
typedef PtrToDoubleLinksNode DLList;

struct PolyNode;
typedef struct PolyNode *PtrToPolyNode;
typedef PtrToPolyNode Term;
typedef PtrToPolyNode Polynomial;

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