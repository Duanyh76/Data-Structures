struct SymNode;
typedef struct SymNode *SymStack;

struct Expression;
void CheckPair(char Input, SymStack S);
ElementType Calucate(Expression Array[]);
Expression InfixToPostfix