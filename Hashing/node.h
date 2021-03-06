#ifndef NODE_CLASS
#define NODE_CLASS

template <class T>
class Node
{
    private:
		
    public:
        // next is the address of the following node
        Node<T> *next;
    	// the data is public
        T data;
    
		// constructor
        Node (const T& item, Node<T>* ptrnext);

        // get new node
        Node<T>* GetNode(const T& item, Node<T>* ptrNext=NULL);
        
        // list modification methods
        void InsertAfter(Node<T> *p);
        Node<T> *DeleteAfter(void);
        
        // obtain the address of the next node
        Node<T> *NextNode(void) const;

        Node<T>& operator = (const Node<T>& any_node);
};

// constructor. initialize data and pointer members
template <class T>
Node<T>::Node(const T& item, Node<T>* ptrnext) : 
		 data(item), next(ptrnext)
{}
  
// return value of private member next
template <class T>
Node<T> *Node<T>::NextNode(void) const
{
    return next;
} 

// insert a node p after the current one
template <class T>
void Node<T>::InsertAfter(Node<T> *p)
{
	// p points to successor of the current node, 
	// and current node  points to p.
    p->next = next;
    next = p;
}

// delete the node following current and return its address
template <class T>
Node<T> *Node<T>::DeleteAfter(void)
{
	// save address of node to be deleted
    Node<T> *tempPtr = next;

	// if there isn't a successor, return NULL
    if (next == NULL)
        return NULL;
        
	// current node points to successor of tempPtr.
    next = tempPtr->next;
    
	// return the pointer to the unlinked node
    return tempPtr;
}

//a method to create a new node
template <class T>
Node<T>* Node<T>::GetNode(const T& item,Node<T>* ptrNext)
{
   Node<T> *p;

   p = new Node<T>(item,ptrNext);
   if (p == NULL)
   {
      cout << "Memory allocation failure!\n";
      exit(1);
   }
   return p;
}

template<class T>
Node<T>& Node<T>::operator = (const Node<T>& any_node){
    data=any_node.data;
    next=any_node.next;
    return *this;
}
#endif  // NODE_CLASS