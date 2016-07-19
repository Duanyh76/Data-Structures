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
        if(sizeof(Array) == sizeof(ElementType))
        {
            Push(Array[i], S)
        }
        else if(sizeof(Array) == sizeof(char) && !IsEmpty(S) )
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

