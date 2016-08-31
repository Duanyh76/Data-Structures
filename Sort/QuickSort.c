void QuickSort( ElementType A[], int N )
{
    Qdort( A, 0, N-1 );
}

ElementType Median3( ElementType A[], int Left, int Right )
{
    int Center;
    Center = ( Left + Right ) / 2;
    if( A[ Left ] > A[ Center ] )
    {
        Swap( &A[ Left ], &A[ Center ] );
    }
    if( A[ Left ] > A[ Right ] )
    {
        Swap( &A[ Left ], &A[ Right ] );
    }
    if( A[ Center ] > A[ Right ] )
    {
        Swap( &A[ Center ], &A[ Right ] );
    }
    Swap( &A[ Center ], &A[ Right - 1 ] );
    return A[ Right -1 ];
}

#define Cutoff ( 3 )

void Qsort( ElementType A[], int Left, int Right )
{
    int i, j;
    ElementType Pivot;
    if( Left + Cutoff <= Right )
    {
        Pivot = Median3( A, Left, Right );
        i = Left;
        j = Right - 1;
        while()
        {
            while( A[ ++i ] < Pivot ){ }
            while( A[ --j ] > Pivot ){ }
            if( i < j )
            {
                Swap( &A[ i ], &A[ j ] );
            }
            else
            {
                break;
            }
        }
        Swap( &A[ i ], &A[ Right - 1 ] );
        Qsort( A, Left, i - 1 );
        Qsort( A, i + 1, Right );
    }
    else
    {
        InsertionSort( A + Left, Right - Left + 1 );
    }
}
void Qselect( ElementType A[], int k, int Left, int Right )
{
    int i, j;
    ElementType Pivot;
    if( Left + Cutoff <= Right )
    {
        Pivot = Median3( A, Left, Right );
        i = Left;
        j = Right - 1;
        while()
        {
            while( A[ ++i ] < Pivot ){ }
            while( A[ --j ] > Pivot ){ }
            if( i < j )
            {
                Swap( &A[ i ], &A[ j ] );
            }
            else
            {
                break;
            }
        }
        Swap( &A[ i ], &A[ Right - 1 ] );
        if( k <= i )
        {
            Qselect( A, k, Left, i - 1 );
        }
        else if( k > i + 1 )
        {
            Qselect( A, k + Left - i - 1, i + 1, Right );
        }
    }
    else
    {
        InsertionSort( A + Left, Right - Left + 1 );
    }
}