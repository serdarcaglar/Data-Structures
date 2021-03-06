template<class T>//a function to swap to elements
void Swap(T &x, T &y){
    T temp;
    temp = x;
    x = y;
    y = temp;
}

template<class T>// selection sort implementation
void SelectionSort(T *A, int n, int &comparisons, int &moves){
    int smallindex;
    int i,j;
    for(i = 0; i<n-1; i++){
        smallindex = i;
        for(int j = i+1; j<n; j++){//search for the rest of the array
            if(A[j] < A[smallindex])//if a smaller item is found swap current item and smaller item
                smallindex = j;
            comparisons++;    
            
       }
     Swap(A[i], A[smallindex]);
     if(i!=smallindex)
        moves++;
    }
}

template<class T>//bubble sort implementation, same as in the lecture notes
void BubbleSort(T *A, int n, int &comparisons, int &moves){
    int i, j;
    int lastExchangeIndex;
    i = n-1;
    while(i>0){//continue the process until no exchanges are made
        lastExchangeIndex = 0;//start last exchanged index at 0
        for(j = 0; j<i; j++){//scan the sublist from A[0] to A[i]
            if(A[j+1] < A[j]){
                Swap(A[j],A[j+1]);
                moves++;
                lastExchangeIndex = j;
            }
        comparisons++;    
        }
        i = lastExchangeIndex;//set i to index of the last exchange
        //continue sorting the sublist A[0] to A[i]
    }
}

int choosePivot(int l, int r, int type){//choose pivot based on quick sport type
    if(type == 1)//return low
        return l;
    if(type == 2){//return median
        return (l+r)/2;
    }
    if(type == 3){//return random index between low and high
        return rand()%(r-l+1)+l;
    }
    if(type == 4){
        int a,b,c;
        a = rand()%(r-l+1)+l;
        b = rand()%(r-l+1)+l;
        c = rand()%(r-l+1)+l;
        //sort a b and c then return b which is the median
        if(a>b)
            Swap(a,b);
        if(a>c)
            Swap(a,c);
        if(b>c)
            Swap(b,c);
        return b;   
             
    }
    return 5;
}

template<class T>
void QuickSort(T* A, int low, int high, int type, int &comparisons, int &moves){
    T pivot;
    if(comparisons++, low<high){
        int ScanUp =  low + 1;
        int ScanDown = high;
        Swap(A[low], A[choosePivot(low, high, type)]);
        moves++;
        pivot = A[low];
        while(true){
            while(comparisons++, A[ScanUp] <= pivot)
                ScanUp++;//increment scanup until pivot
            while(comparisons++, A[ScanDown] > pivot)
                ScanDown--;//decrement scandown until pivot
            if(comparisons++, ScanUp < ScanDown)
                Swap(A[ScanDown], A[ScanUp]);    
            else
                break;
        }
        Swap(A[ScanDown], A[low]);
        moves++;
        //recursive calls
        QuickSort(A, low, ScanDown-1, type, comparisons, moves);
        QuickSort(A, ScanDown+1, high, type, comparisons, moves);
    }
    
}

template<class T>
void mySort(T* A, int low, int high, int type, int &comparisons, int &moves){
    if(low<high and high-low<15){
        BubbleSort(A, high-low+1, comparisons, moves);
        return;
    }
    T pivot;
    if(comparisons++, low<high){
        int ScanUp =  low + 1;
        int ScanDown = high;
        Swap(A[low], A[choosePivot(low, high, type)]);//bring asked element to low(type of the quickSort)
        moves++;
        pivot = A[low];
        while(true){
            while(comparisons++, A[ScanUp] <= pivot)
                ScanUp++;
            while(comparisons++, A[ScanDown] > pivot)
                ScanDown--;
            if(comparisons++, ScanUp < ScanDown)
                Swap(A[ScanDown], A[ScanUp]);    
            else
                break;
        }
        Swap(A[ScanDown], A[low]);
        moves++;
        QuickSort(A, low, ScanDown-1, type, comparisons, moves);
        QuickSort(A, ScanDown+1, high, type, comparisons, moves);
    }
    // else{
    //     BubbleSort(A, high-low+1, comparisons, moves);
    // }
}
