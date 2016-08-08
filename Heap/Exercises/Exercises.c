/* Min-Max Heap*/
void DeleteMin( PriorityQueue H )
{

}

void DeleteMax( PriorityQueue H )
{
    
}

void Insert( ElemmentType X, PriorityQueue H )
{
    Position P, Parent, GrandParent;
    P = ++H->Size;
    Parent = P / 2;
    GrandParent = Parent / 2;
    int Level;
    Level = log( P ) / log( 2 );
    if( Level % 2 ) //MinSubHeap
    {
        if( X < H->Elements[ Parent ] )
        {      
            if( X > H->Elements[ GrandParent ] )
            {
                H->Elements[ P ] = X;
            }
            else if( X < H->Elements[ GrandParent ] )
            {
                while( GrandParent && X < H->Elements[ GrandParent ] )
                {
                    H->Elements[ P ] = H->Elements[ GrandParent ];
                    P = GrandParent;
                    GrandParent /= 4;
                }
                H->Element[ P ] = X;
            }
            else if( X == H->Elemnents[ GrandParent ] )
            {
                H->Size--;
            }
        }
        else( X > H->Elements[ Parent ] )
        {
            H->Elements[ P ] = H->Elements[ Parent ];
            P = Parent;
            GrandParent = P / 4;
            while( GrandParent && X > H->Elements[ GrandParent ] )
            {
                H->Elements[ P ] = H->Elements[ GrandParent ];
                P = GrandParent;
                GrandParent = P / 4;
            }
        }
    }
    else    //MaxSubHeap
    {
        if( X > Elements[ Parent ] )
        {
            if( GrandParent )
            {
                if( X < H->Elements[ GrandParent ] )
                {
                    H->Elements[ P ] = X;
                }
                else if( X > Elements[ GrandParent ] )
                {
                    while( GrandParent && X > H->Elements[ GrandParent ] )
                    {
                        H->Elements[ P ] = H->Elements[ GrandParent ];
                        P = GrandParent;
                        GrandParent = P / 4;
                    }
                }
            }
            else
            {
                H->Elements[ P ] = X;
            }
        }
        else if( X == Elements[ Parent ] )
        {
            H->Size--;
        }
        else
        {
            H->Elements[ P ] = H->Elements[ Parent ];
            P = Parent;
            GrandParent = P / 4;
            while( GrandParent && X < H->Elements[ GrandParent ] )
            {
                H->Elements[ P ] = H->Elements[ GrandParent ];
                P = GrandParent;
                GrandParent = P / 4;
            }
        }
    }
}

void BuildHeap
void Merge
