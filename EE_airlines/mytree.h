//decleration of TreeNode class
template<class T>
class TreeNode{
    private:
    public:
    TreeNode<T>* left;//contains two pointers for right and left sides of the node 
    TreeNode<T>* right;
    int state; // occupancy state (how many months is it under occupated)
    T data;//contains data of the node
    TreeNode(const T&item, TreeNode<T>* lptr=NULL, TreeNode<T>* rptr=NULL);//constructor
    TreeNode<T>* Left(void)const;//access methods to pointer fields
    TreeNode<T>* Right(void)const;//actually no need for them as pointers are public members

};
//decleration of Tree class
template<class T>
class Tree{     
    public:
    TreeNode<T>* root;//pointer to root nodeTree
    Tree();//constructor
    void addtflight(TreeNode<T>* root, int flight);//add flight number
    TreeNode<T>* removetflight(TreeNode<T>* node, int flight);//remove flight from the tree whose root is node
    TreeNode<T>* minValueNode(TreeNode<T>* node);//takes the root node and search for the min valued node
    TreeNode<T>* searchtflight(TreeNode<T>*, int flightNum);//search for flight and return the address of the node
    void listtflights(TreeNode<T>* root);//list all flights
};


//implementation of constructor
template<class T>
TreeNode<T>::TreeNode(const T & item, TreeNode<T> *lptr, TreeNode<T> *rptr):data(item), left(lptr), right(rptr), state(0){}

//a function dynamically allocate memory for a new object
template<class T>
TreeNode<T>* GetTreeNode(T item, TreeNode<T> *lptr=NULL, TreeNode<T> *rptr=NULL){
    TreeNode<T> *p;
    p=new TreeNode<T>(item,lptr,rptr);
    if(p==NULL){
        cerr<<"Memory allocation failure"<<endl; 
        exit(1);}
    return p;
}
//constructor implementation
template<class T>
Tree<T>::Tree(){

}
//implementation of addtflight method
template<class T>
void Tree<T>::addtflight(TreeNode<T>* root, int data) {//takes the adress of root node and the date to be inserted
    if (root == NULL) {
        TreeNode<T> *root = GetTreeNode(data);
    }
    else if (data <= root->data) {
        if (root -> left != NULL)
            addtflight(root->left, data);
        else
            root -> left = GetTreeNode(data);
    }
    else if (data > root->data) {
        if (root -> right != NULL)
            addtflight(root->right, data);
        else
            root -> right = GetTreeNode(data);
    }
  }

  template<class T>
  void Tree<T>::listtflights(TreeNode<T>* root){
      if(this->root==NULL){
          cout<<"root is null"<<endl;
          return;
      }
      if(root==NULL)
        return;
      else{
          listtflights(root->left);
          cout<<"EE";
          if(root->data<1e3 and root->data>=1e2)
            cout<<0;
          cout<<root->data<<" "<<endl;
          listtflights(root->right);
      }
  }

  template<class T>
  TreeNode<T>* Tree<T>::searchtflight(TreeNode<T>* root, int flightNum){
      if(this->root==NULL){
          cout<<"tree is empty";
          return this->root;
      }
      if(root==NULL){
          return root;
      }

      else if(flightNum>root->data){
          return searchtflight(root->right, flightNum);
      }
      else if(flightNum<root->data){
          return searchtflight(root->left, flightNum);
      }
      else if(root->data==flightNum)
       {
           return root;
       }
       return NULL;      

  }

/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
template<class T>
TreeNode<T>*  Tree<T>::minValueNode(TreeNode<T>* node)
{
    TreeNode<T>* current = node; 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
template<class T>
TreeNode<T>* Tree<T>::removetflight(TreeNode<T>* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is 
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->left = removetflight(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = removetflight(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            TreeNode<T>* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode<T>* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        TreeNode<T>* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = removetflight(root->right, temp->data);
    }
    return root;
}

// Function to concatenate 
// two integers into one 
int concat(int a, int b) 
{ 
  
    // Convert both the integers to string 
    string s1 = to_string(a); 
    string s2 = to_string(b); 
  
    // Concatenate both strings 
    string s = s1 + s2; 
  
    // Convert the concatenated string 
    // to integer 
    int c = stoi(s); 
  
    // return the formed integer 
    return c; 
}