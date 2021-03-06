struct set{//structure including  an integer pointer
    int* array;
    int size; //size
};


template <class T>//convert string to the template number data type
long stringToNumber(string s){
    T n=0;
    stringstream semih (s) ;
    semih >> n;
  return n;
}

int* initializeRandomArray(int N){//initialize random array with size N and return its pointer
    int *p;
    p=new int[N];
    for(int i=0; i<N; i++){
        p[i]=(rand()%(2*N))+1;
    }
    return p;
}

void printArray(int *x, int size){
    for(int i=0; i<size; i++){
        cout<<x[i]<<" "<<endl;
    }
}
void randomTextFile(int N){//generate random text file
    ofstream myfile;
    myfile.open ("input_array.txt");
    int* x;
    x=initializeRandomArray(N);
    for(int i=0; i<N; i++){
        myfile<<x[i]<<endl;
    }
    myfile.close();
}

int* loadRandomNumbers(int &cnt){//load random numbers from a text file
    ifstream myfile("input_array.txt");
    string line;
    cnt=0;
    string data[200];
    if (myfile.is_open()){
        while (getline(myfile, line)){
            data[cnt]=line;
            cnt++;}
        myfile.close();
    }
    else
        cout << "Unable to open file";
    int* x = new int[cnt];
    for(int i=0; i<cnt; i++){
        x[i]=stringToNumber<int>(data[i]);
    }
    return x;
}

void copyArray(int* ar1, int* ar2, int size){//copy ar1 to ar2
    for(int i=0; i<size; i++){
        ar2[i] = ar1[i];
    }
}