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
            T->Element = X;
            T->Height = 0;
            T->Right = NULL;
            T->Left = NULL;
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