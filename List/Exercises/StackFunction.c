struct SymNode
{
    char Sym;
    SymStack Next;
};

struct Expression
{
    ElementType Sym;
    char Sym;
};

void CheckPair(Expression Input, SymStack S)
{
    if(Input == 'begin' || Input == '(' || Input == '[' || Input == '{')
    {
        Push(Input, S);
    }
    else if(Top(S) != NULL)
    {
        switch (Input)
        {
            case 'end':
                if(Top(S) == 'begin')
                {
                    Pop(S);
                }
                else
                {
                    FatalError("Not match");
                }
                break;
            case ')':
                if(Top(S) == '(')
                {
                    Pop(S);
                }
                else
                {
                    FatalError("Not match");
                }
                break;
            case ']':
                if(Top(S) == '[')
                {
                    Pop(S);
                }
                else
                {
                    FatalError("Not match");
                }
                break;
            case '}':
                if(Top(S) == '{')
                {
                    Pop(S);
                }
                else
                {
                    FatalError("Not match");
                }
                break;
        }
    }
    else
    {
        FatalError("Empty stack");
    }
}

ElementType Calucate(Expression Array[])
{
    int n, check;
    n = length(Array);
    check = 0; 
    ElementType Tmp, FirstNum, SecondNum;
    Stack S;
    S = CreateStack();
    for(int i = 0; i < n; i++)
    {
        if(sizeof(Array[i]) == sizeof(ElementType))
        {
            Push(Array[i], S)
        }
        else if(sizeof(Array[i]) == sizeof(char) && !IsEmpty(S) )
        {
            FirstNum = TopAndPop(S);
            if(IsEmpty(S))
            {
                return 0;
            }
            SecondNum = TopAndPop(S);
            switch (Array[i])
            {
                case '+':
                    Tmp = FirstNum + SecondNum;
                    break;
                case '*':
                    Tmp = FirstNum * SecondNum;
                    break;
                case '-':
                    Tmp =  SecondNum - FirstNum;
                    break;
                case '/':
                    Tmp = Second / FirstNum;
                    break;
            }
            Push(Tmp, S);
        }
    }
    return Top(S);
}

Expression InfixToPostfix(Expression InfixArray)
{
    Stack S;
    S = CreateStack;
    int n;
    n = length(InfixArray);
    Expression PostfixArray[n];
    int Position = 0;
    Expression Sym;
    for(int i = 0; i < n; i++)
    {
        if(sizeof(InfixArray[i]) == sizeof(ElementType))
        {
            PostfixArray[Position++] = InfixArray[i];
        }
        else
        {
            if(InfixArray[i] == '(')
            {
                Push(InfixArray[i], S; 
            }
            else if(InfixArray[i] == ')')
            {
                while(Top(S) != '(')
                {
                    Sym = TopAndPop(S);
                    PostfixArray[Position++] = Sym;
                }
                Pop(S);
            }
            else if(InfixArray[i] == '+' || InfixArray[i] == '-')
            {
                while(Top(S) == '(' || Top(S) == NULL)
                {
                    Sym = TopAndPop(S);
                    PostfixArray[Position++] = Sym;
                }
                Push(InfixArray[i], S);
            }
            else if(InfixArray[i] == '*' || InfixArray[i] == '/')
            {
                if(Top(S) == '*' || Top(S) == '/')
                {
                    Sym = TopAndPop(S);
                    PostfixArray[Position++] = Sym;
                }
                Push(InfixArray[i], S);
            }
        }
    }
    while(Top(S) != NULL)
    {
        Sym = TopAndPop(S);
        PostfixArray[Position++] = Sym;
    }
    return PostfixArray;
}

Expression InfixToPostfixWithIndex(Expression InfixArray[])
{
    Stack S;
    S = CreateStack;
    int n;
    n = length(InfixArray);
    Expression PostfixArray[n];
    int Position = 0;
    Expression Sym;
    for(int i = 0; i < n; i++)
    {
        if(sizeof(InfixArray[i]) == sizeof(ElementType))
        {
            PostfixArray[Position++] = InfixArray[i];
        }
        else
        {
            if(InfixArray[i] == '(')
            {
                Push(InfixArray[i], S; 
            }
            else if(InfixArray[i] == ')')
            {
                while(Top(S) != '(')
                {
                    Sym = TopAndPop(S);
                    PostfixArray[Position++] = Sym;
                }
                Pop(S);
            }
            else if(InfixArray[i] == '+' || InfixArray[i] == '-')
            {
                while(Top(S) == '(' || Top(S) == NULL)
                {
                    Sym = TopAndPop(S);
                    PostfixArray[Position++] = Sym;
                }
                Push(InfixArray[i], S);
            }
            else if(InfixArray[i] == '*' || InfixArray[i] == '/')
            {
                if(Top(S) == '*' || Top(S) == '/')
                {
                    Sym = TopAndPop(S);
                    PostfixArray[Position++] = Sym;
                }
                Push(InfixArray[i], S);
            }
            else if(InfixArray[i] == '^')
            {
                if(Top(S) == '^')
                {
                    Sym = TopAndPop(S);
                    PostfixArray[Position++] = Sym;
                }
                Push(InfixArray[i], S);
            }
        }
    }
    while(Top(S) != NULL)
    {
        Sym = TopAndPop(S);
        PostfixArray[Position++] = Sym;
    }
    return PostfixArray;
}

Expression PostfixToInfix(Expression PostfixArray[])//unfinished
{
    Stack S;
    S = CreateStack;
    int n;
    n = length(PostfixArray)
    Expression InfixArray[n];
    int Position = 0;
    ElementType FirstNum;
    ElementType SecondNum;
    for(int i = 0; i < n; i++)
    {
        if(sizeof(PostfixArray[i]) == sizeof(ElementType))
        {
            Push(PostfixArray[i], S);
        }
        else
        {
            SecondNum = TopAndPop(S);
            FirstNum = TopAndPop(S);
            InfixArray[Position++] = FirstNum;
            InfixArray[Position++] = PostfixArray[i];
            InfixArray[Position++] = SecondNum;
        }
    }
}

struct TwoStacksShareArray
{
    int Capacity;
    Stack A;
    Stack B;
    ElementType *Array;
}

TwoStacks CreateTwoStack(int Size)
{
    TwoStacks TS;
    TS = malloc(sizeof(struct TwoStacksShareArray));
    TS->Capacity = Size;
    TS->A->TopPosition = 0;
    TS->B->TopPosition = Size - 1;
    TS->Array = malloc(sizeof(ElementType) * size);
    return TS;
}
void PopB(TwoStacks TS)
{
    if(TS->B->TopPosition > TS->A->Size)
    {
        TS->B->TopPosition--;
        TS->B->Size--;
    }
}

void PushB(ElememtType X, TwoStack TS)
{
    if(TS->B->TopPosition != Capacity - 1)
    {
        TS->B->TopPosition++;
        TS->Array[TS->B->TopPosition] = X;
        TS->B->Size++;
    }
}
