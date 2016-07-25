#ifndef _AvlTree_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

static int Height( Positon P );
AvlTree MakeEmpty( AvlTree T );
Position Find( ElementType X, AvlTree T );
Position FindMin( AvlTree T );
Position FindMax( AvlTree T );
AvlTree Insert( ElementType X, AvlTree T );
AvlTree Delete( ELementType X, AvlTree T );
Position SingleRotateWithLeft( Position K2 );
Position  SingleRotateWithRight( Position K2 );
Position DoubleRotateWithLeft ( Position K );
Position DoubleRotateWithRight ( Position K );
ElementType Retrieve( Position P );