void Msort( ElementType A[], ElementType TmpArray[], int Left, int Right )
{
    int Center;
    if( Left < Right )
    {
        Center = ( Left + Right ) / 2;
        Msort( A, TmpArray, Left, Center );
        Msort( A, TmpArray, Center + 1, Right );
        Merge( A, TmpArray, Left, Center + 1, Right );
    }
}

void MergeSort( ElementType A[], int N )
{
    ElementType *TmpArray;
    TmpArray = malloc( N * sizeof( ElementType ) );
    if( TmpArray != NULL)
    {
        Msort( A, TmpArray, 0, N - 1 );
        free( TmpArray );
    }
    else
    {
        FatalError( " No Space for tmp array " );
    }
}

void Merge( ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd )
{
    int i, LeftEnd, NumElements, TmpPos;
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;
    while( Lpos <= LeftEnd && Rpos <= RightEnd )
    {
        if( A[ Lpos ] <= A[ Rpos ] )
        {
            TmpArray[ TmpPos++ ] = A[ Lpos++ ];
        }
        else
        {
            TmpArray[ TmpPos++ ] = A[ Rpos++ ];
        }
    }
    while( Lpos <= LeftEnd )
    {
        TmpArray[ TmpPos++ ] = A[ Lpos++ ];
    }
    while( Rpos <= RightEnd )
    {
        TmpArray[ TmpPos++ ] = A[ Rpos++ ];
    }
    for( i = 0; i < NumElements; i++, RightEnd-- )
    {
        A[ RightEnd ] = TmpArray[ RightEnd ];
    }
}

void MergeSort( ElementType A[], int N )
{
    ElementType *TmpArray;
    int SubListSize, Part1Start, Part2Start, Part2End;
    TmpArray = malloc( sizeof( ElementType ) * N );
    for( SubListSize = 1; SubListSize < N; SubListSize *= 2 )
    {
        Part1Start = 0;
        while( Part1Start + SubListSize < N - 1 )
        {
            Part2Start = Part1Start + SubListSize;
            Part2End = min( N, Part1Start + SubListSize - 1 );
            Merge( A, TmpArray, Part1Start, Part2Start, Part2End );
            Part1Start = Part2End + 1;
        }
    }
}