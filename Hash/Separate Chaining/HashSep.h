#ifndef _HashSep_H
#define ElementType int

struct ListNode;
typedef struct ListNode *Position;
typedef Position List;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestoryTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, HashTable H );
ElementType Retrieve( Position P );

#endif