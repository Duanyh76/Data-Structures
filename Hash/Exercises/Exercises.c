int CountConflict( ElementType Array[], int Length )
{
    int i, Count;
    Count = 0;
    HashTable H;
    Position P;
    H = InitializeTable( Length );
    for( i = 0; i < Length; i++ )
    {
        P = Hash( Array[ i ], H->TableSize );
        while( H->TheCells[ P ].Info != Empty )
        {
            P++;
            Count++;
        }
        /*
        int j = 0;
        while( H->TheCells[ i ].Info != Empty )
        {
            j++;
            P += j ^ j;
            Count++;
        }
        */
        /*
        int j = 0;
        while( H->TheCells[ i ].Info != Empty )
        {
            j++;           
            P = j * Hash2( Array[ i ], H->TableSize );
            Count++;
        }
        */
    }
    return Count;
}

