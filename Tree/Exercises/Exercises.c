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

