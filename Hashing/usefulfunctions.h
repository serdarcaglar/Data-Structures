template <class T>//convert string to the template number data type
T stringToNumber(string s){
    T n=0;
    stringstream geek;
    geek<<s;
    geek >> n;
  return n;
}

template <class T>//convert any number of data type T to string
string numberToString(T n){
    string s;
    s = to_string(n);
    return s;
}

int folding(string str){//takes string(id number) and returns integer value of folding function
    int result;
    string part1 = str.substr(0, 3);
    string part2 = str.substr(3, 3);
    string part3 = str.substr(6, 3);
    string part4 = str.substr(9, 2);
    result = (stringToNumber<int>(part1) + stringToNumber<int>(part2) + stringToNumber<int>(part3) + stringToNumber<int>(part4))%N;
    return result;
}

int middleSquaring(string str){//takes string and returns integer value for the middle squaring function
    int result;
    string part = str.substr(4, 3);
    int num = stringToNumber<int>(part);
    result = (num*num)%N;
    return result;

}

int truncation(string str){//takes string and returns integer value for truncation function
    int result;
    string part = str.substr(9, 2);
    int num = stringToNumber<int>(part);
    result = num%N;
    return result;
}

//a global function to create a new node
template<class T>
Node<T>* GetNode(const T& item, Node<T>* nextPtr=NULL){
    Node<T>* newNode;
    newNode=new Node<T>(item, nextPtr);
    if(newNode==NULL){
        cerr<<"Memory allocation failed"<<endl; exit(1);
    }
    return newNode;
}

bool ifIdValid(string s){
    long long num = stringToNumber<long long>(s);
    if( num>=1e10 and num < 1e11)
        return 1;
    else
        return 0;
}