template<class T>
class myvector{
    public:
        myvector();//constructot
        ~myvector();//destructor
        void push(T x);//push an element of type T to the vector
        int search(T element);//search an element for the vector and return its index
        void remove(int ind);//remove an element from the vector with index ind
        T* ar;//the address of the first element of the vector
        int size;//size of the vector
};

template<class T>
myvector<T>::myvector(){
    size=0;//initially size is zero
    ar=(T*)malloc(0);//initialize ar
};
template<class T>
myvector<T>::~myvector(){
    free(ar);//free ar when the object is destructed
}

template<class T>
void myvector<T>::push(T x){
    ar=(T*)realloc(ar,(size+1)*sizeof(T));//when an element is pushed to the vector increment size by 1
    ar[size++]=x;//put new element to the end of the vector and increment size
};

template<class T>
int myvector<T>::search(T element){
    for(int i=0;i<size;++i)
        if(ar[i]==element)//search for the element, if found return its index
            return i;
    return -1;
}

template<class T>
void  myvector<T>::remove(int ind){
    ar[ind]=ar[size-1];//put last element and insert it to the place of element removed
    ar=(T*)realloc(ar, (size-1)*sizeof(T)); //decrease the size of array ar
    size--;
}