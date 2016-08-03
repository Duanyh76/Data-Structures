#ifndef _HashQuad_H
#define ElementType int

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

struct HashEntry;
typedef struct HashEntry Cell;

HashTable InitializeTable( int TableSize );
void DestoryTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, HashTable H );
ElementType Retrieve( Position P );
HashTable Rehash( HashTable H );

#endif