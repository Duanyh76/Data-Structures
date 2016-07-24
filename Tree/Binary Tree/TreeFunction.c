#include "Tree.h"

struct TreeNode
{
    ElementType Element;
    Position Left;
    Position Right;
};

SearchTree MakeEmpty( SearchTree T )
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
}

Position Find( ElementType X, SearchTree T )
{
    if( T == NULL)
    {
        return NULL;
    }
    if( T->Element > X )
    {
        return  Find( X, T->Left );
    }
    else if( T->Element < X )
    {
        return Find( X, T->Right );
    }
    else
    {
        return T;
    }
}

Position FindMin( SearchTree T )
{
    if( T == NULL )
    {
        return NULL;
    }
    else if( T->Left == NULL )
    {
        return T;
    }
    else
    {
        return FindMin( T->Left );
    }
}

Position FindMax( SearchTree T )
{
    if( T != NULL )
    {
        while( T->Right != NULL )
        {
            T = T->Right;
        }
    }
    return T;
}

SearchTree Insert( ElementType X, SearchTree T )
{
    if( T == NULL )
    {
        T = malloc( sizeof( struct TreeNode ) );
        if( T == NULL )
        {
            FatalError( "Out of space");
        }
        else
        {
            T->Element = X;
            T->Left = NULL;
            T->Right = NULL;
        }
    }
    else if( T->Element > X )
    {
        T->Left = Insert( X, T->Left );
    }
    else if( T->Element < X )
    {
        T->Right = Insert( X, T->Right );
    }
    return T;
}

SearchTree Delete( ElementType X, SearchTree T )
{
    Position TmpCell;
    if( T == NULL )
    {
        Error( "Element not found" );
    }
    else if( T->Element > X )
    {
        T->Left = Delete( X, T->Left );
    }
    else if( T->Element < X)
    {
        T->Right = Delete( X, T->Right );
    }
    else if( T->Left && T->Right )
    {
        TmpCell = FindMin( T->Left );
        T->Element = TmpCell->Element;
        T->Right = Delete( TmpCell->Element, T->Right );
    }
    else
    {
        TmpCell = T;
        if( T->Left == NULL )
        {
            T = T->Left;
        }
        else if( T->Right == NULL )
        {
            T = T->Left;
        }
    }
    return T;
}