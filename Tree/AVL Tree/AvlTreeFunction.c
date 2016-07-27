#include "AvlTree.h"

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

static int Height( Position P )
{
    if( P == NULL )
    {
        return -1;
    }
    else
    {
        return P->Height;
    }
}

AvlTree Insert( ElementType X, AvlTree T )
{
    if( T == NULL )
    {
        T = malloc( sizeof( struct AvlNode ) );
        if( T == NULL)
        {
            FatalError("Out of space");
        }
        else
        {
            T = CreateAvlNode( X, T );
        }
    }
    else if( T->Element < X )
    {
        T->Left = Insert( X, T->Left );
        if( Height( T->Left ) - Height( T->Right ) == 2 )
        {
            T = SingleRotateWithLeft( T );
        }
        else
        {
            T = DoubleRotateWithLeft( T );
        }
    }
    else if( T->Element > X )
    {
        T->Right = Insert( X, T->Right );
        if( Height( T->Right ) - Height( T->Left ) == 2 )
        {
            T = SingleRotateWithRight( T );
        }
        else
        {
            T = DoubleRotateWithRight( T );
        }
    }
    T->Height = Max( Height( T->Left ), Height( T->Right ) ) + 1;
    return T;
}

Position Insert( ElementType X, AvlTree T )
{
    Position P, Parent, GrandParent;
    Stack S, LeftOrRight;
    int Key;
    S = CreateStack( void );
    LeftOrRight = CreateStack( void );
    P = T;
    while( P != NULL );
    {   
        Push( P, S);
        if( P->Element > X )
        {
            P = P->Left;
            Key = 0;
        }
        else if( P->Element < X )
        {
            P = P->Right;
            Key = 1;
        }
        else if( P->Element = X )
        {
            return P;
        }
        Push( Key, LeftOrRight);
    }
    P = malloc( sizeof( struct AvlNode ) );
    if( P == NULL)
    {
        FatalError("Out of space");
    }
    else
    {
        P = CreateAvlNode( X, P );
    }
    Parent = TopAndPop( S );
    Parent->Height = Max( Height( Parent->Left ), Height( Parent->Right ) ) + 1;
    GrandParent = TopAndPop( S );
    if( abs( GrandParent->Left->Height - GrandParent->Right->Height == 2) )
    {   
        if( Top( LeftOrRight ) == 0 )
        {
            Pop( LeftOrRight );
            if( Top( LeftOrRight ) == 0 )
            {
                GrandParent = SingleRotateWithLeft( GrandParent );
            }
            else if( Top( LeftOrRight ) == 1 )
            {
                GrandParent = DoubleRotateWithLeft( GrandParent );
            }
        }
        else if( Top( LeftOrRight ) == 1 )
        {
            Pop( LeftOrRight );
            if( Top( LeftOrRight ) == 0 )
            {
                GrandParent = DoubleRotateWithRight( GrandParent );
            }
            else if( Top( LeftOrRight ) == 1 )
            {
                GrandParent = SingleRotateWithRight( GrandParent );
            }
        }
    }    
    return P;
}

Positon CreateAvlNode( ElementType X, Position P )
{
    P->Element = X;
    P->Height = 0;
    P->Right = NULL;
    P->Left = NULL;
    return P;
}

Position SingleRotateWithLeft( Position K2 )
{
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->Height = Max( Height( K2->Left ), Height( K2->Right ) ) + 1;
    K1->Height = Max( Height( K1->Left ), Height( K2 ) ) + 1;
    return K1;
}

Position SingleRotateWithRight( Postion K2 )
{
    Position K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    K2->Height = Max( Height( K2->Left ), Height( K2->Right ) ) + 1;
    K1->Height = Max( Height( K2 ), Height( K1->Right ) ) + 1;
    return K1;
}

Position DoubleRotateWithLeft( Position K );
{
    K->Left = SingleRotateWithRight( K->Left );
    return SingleRotateWithLeft( K );
}

Position DoubleRotateWithRight( Position K )
{
    K->Right = SingleRotateWithLeft( K->Right );
    return SingleRotateWithRight( K );
}

Position DoubleRotateWithLeft ( Postion P );
{
    Position Child, GrandChild;
    Child = P->Left;
    GrandChild = Child->Right;
    P->Left = GrandChild->Right;
    Child->Right = GrandChild->Left;
    GrandChild->Left = Child;
    GrandChild->Right = P;
    Child->Height = Max( Height( Child->Left ), Height( Child->Right ) ) + 1;
    P->Height = Max( Height( P->Left ), Height( P->Right ) ) + 1;
    GrandChild->Height = Max( Height( Child ), Height( P ) ) + 1;
    return GrandChild;
}

Position DoubleRotateWithRight ( Postion P );
{
    Position Child, GrandChild;
    Child = P->Right;
    GrandChild = Child->Left;
    P->Right = GrandChild->Left;
    Child->Left = GrandChild->Right;
    GrandChild->Right = Child;
    GrandChild->Left = P;
    Child->Height = Max( Height( Child->Left ), Height( Child->Right ) ) + 1;
    P->Height = Max( Height( P->Left ), Height( P->Right ) ) + 1;
    GrandChild->Height = Max( Height( Child ), Height( P ) ) + 1;
    return GrandChild;
}