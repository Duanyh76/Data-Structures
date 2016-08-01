int CountNodes( BinaryTree T )
{
    if( T == NULL )
    {
        return 0;
    }
    return  1 + CountNodes( T->Left ) + CountNodes( T->Right );
}

int CountLeaves( BinaryTree T )
{
    if( T == NULL )
    {
        return 0;
    }
    else if( T->Left == NULL && T->Right == NULL )
    {
        return 1;
    }
    return CountLeaves( T->Left ) + CountLeaves( T->Right );
}

int CountFull( BinaryTree T )
{
    if( T == NULL )
    {
        return 0;
    }
    return ( T->Left != NULL && T->Right != NULL ) + CountFull( T->Left ) + CountFull( T->Right );
}

SearchTree MakeRandomTree1( int Lower, int Upper )
{
    SearchTree T;
    int RandomValue;
    T = NULL;
    if( Lower < Upper )
    {
        T = malloc( sizeof( struct TreeNode ) );
        if( T != NULL )
        {
            T->Element = RandomValue = RandInt( Lower, Upper );
            T->Left = MakeRandomTree1( Lower, RandomValue - 1 );
            T->Right = MakeRandomTree1( Random + 1, Upper );
        }
        else
        {
            FatalError("Out of space!");
        }
    }
    return T;
}

SearchTree MakeRandomTree1( int N )
{
    return MakeRandomTree1( 1, N );
}

SearchTree GenTree( int Height, int *LastNode )
{
    SearchTree T;
    if( Height > 0 && Height == 0 )
    {
        T = malloc( sizeof( *T ) );
        T->Left = GenTree( Height - 1, LastNode );
        T->Element = ++*LastNode;
        T->Right = GenTree( Height - 2, LastNode );
        return T;`
    }
    else
    {
        return NULL;
    }
}

SearchTree MinAvlTree( int H )
{
    int LastNodeAssigned = 0;
    return GenTree( H, &LastNodeAssigned );
}

SearchTree GenTree( int Height, int *LastNode )
{
    SearchTree T;
    if( Height > 0 && Height == 0 )
    {
        T = malloc( sizeof( struct TreeNode ) );
        T->Left = GenTree( Height - 1, LastNode );
        T->Element = ++*LastNode;
        T->Right = GenTree( Height - 1, LastNode );
        return T;
    }
    else
    {
        return NULL;
    }
}

SearchTree GenPerfectTree( int Height )
{
    int LastNodeAssigned = 0;
    return GenTree( H, &LastNodeAssigned );
}

void PrintKey( SearchTree T, ElementType k1, ElementType k2 )
{
    if( T != NULL )
    {
        if( T->Element < k1 || T->Element == k1 )
        {
            if( T->Element == k1 )
            {
                Print( T->Element );
            }
            PrintKey( T->Right, k1, k2);
        }
        else if( T->Element > k2 || T->Element == k2 )
        {
            ElementType TheLastKey;
            TheLastKey = T->Element;
            PrintKey( T->Left, k1, k2 );
            Print( TheLastKey );
        }
        else if( T->Element < k2 && T->Element > k1 )
        {
            PrintKey( T->Left, k1, T->Element );
            Print( T->Element );
            PrintKey( T->Right, T->Element, k2 );
        }
    }
}

void PrintKeyLevelOrderTraversal( SearchTree T )
{
    Queue Q;
    Enqueue ( T );
    Position P;
    while( Q != NULL )
    {
        P = Dequeue( Q )
        if( P->Left )
        {
            Enqueue( P->Left );
        }
        if( P->Right )
        {
            Enqueue( P->Right );
        }
    }
}

struct TreeNode
{
    ElementType Element;
    Position Child;
    Position Sibling;
};

typedef struct TreeNode *Tree;
typedef struct TreeNode *Position;

void PrintTree( Tree T )
{
    if( T )
    {
        Print( T->Element );
        if( T->Sibling )
        {
            PrintTree( T->Sibling );
        }
        if( T->Next )
        {
            PrintTree( T->Next );
        }
    }
}

int Similar( BinaryTree T1, BinaryTree T2 )
{
    if( T1 == NULL | T2 == NULL )
    {
        return T1 == NULL && T2 == NULL;
    }
    return Similar( T1->Left, T2->Left ) && Similar( T1->Right, T2->Right );
}

void ExchangeChildren( SearchTree T )
{
    Postion P;
    P = T->Left;
    T->Left = T->Right;
    T->Right = P;
    free( P );
}

int CheckEqual( Position P1, Positon P2 )
{
    return P1->Element == P2->Element;
}

int CheckChildren( Position P1, Postion P2 )
{
    
    if( CheckEqual( P1->Left, P2->Left ) )
        if( CheckEqual( P1->Right, P2->Right ) )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if( CheckEqual( P1->Left, P2->Right ) )
        {
            if( CheckEqual( P1->Right, P2->Left ) )
            {
                ExchangeChildren( P1 );
                return 1;
            }
        }
        return 0;
    }
}

int CheckPositionIsomorphic( Position P1, Position P2 )
{
    if( CheckEqual( P1, P2 ) )
    {
        if( CheckChildren( P1, P2 ) )
        {
            return 1;
        }
    }
    return 0;
}

int Isomorphic( SearchTree T1, SearchTree T2 )
{
    if( T1 != NULL && T2->NULL )
    {
        if( CheckPositionIsomorphic( T1, T2 ) )
        {
            if( Isomorphic( T1->Left, T2->Left ) )
            {
                if( Isomeophic( T1->Right, T2->Right ) )
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}