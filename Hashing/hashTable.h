class hashTable{
    private:    
    public:
    hashTable();//constructor
    ~hashTable();//destructor
    Node<string>* table;//pointer to a node
    void initializeHashTable(int N, string user_function);//initialize hash table with provided N and hashing method
    string hash_function;
    void loadNumbers(void);
    void addNewNumber(string number);
    void deleteNumber(string number);
    bool searchNumber(string number);
    void printOut(void);

};

//constructor
hashTable::hashTable() {}

//destructor
hashTable::~hashTable(){
    free(table);
}

void hashTable::initializeHashTable(int N, string user_function){
    table = (Node<string>*) calloc (N, sizeof(Node<string>));//get an array of Node<string> with dimension N
    for (int i=0;i<N;i++){
        table[i].data="E";//initialize all nodes with empty
        table[i].next=NULL;//every nodes shows null
    }
    hash_function = user_function;

}

void hashTable::loadNumbers(void){//function to load numbers from a txt file to our hash table
ifstream myfile("hash_table_init200.txt");
    string line;
    int i=0;
    string data[200];
    if (myfile.is_open()){
        while (getline(myfile, line)){
            data[i]=line;
            i++;}
        myfile.close();
    }
    else
        cout << "Unable to open file";

for(int i=0;i<200;i++){
    addNewNumber(data[i]);
}

}

void hashTable::addNewNumber(string number){//add new number based on hashing functiın
    if(!ifIdValid(number)){
        cout<<"ID is not valid"<<endl;
        return;
    }
    int adress;
    if(hash_function=="folding"){
        adress = folding(number);
    }
    
    else if(hash_function=="middleSquaring"){
        adress = middleSquaring(number);
    }
    else if(hash_function=="truncation"){
        adress = truncation(number);
    }

if(table[adress].data=="E"){//if data is empty insert id number to the node
    table[adress].data=number;
}
else{
    Node<string>* tmp = table[adress].next;
    if(tmp==NULL){//if next item is null insert a node after current node
        table[adress].InsertAfter(GetNode<string>(number, NULL));
    }
        while(tmp!=NULL){//move tmp until it reaches null
            if(tmp->next==NULL){//if reached insertafter a node with data of number
            tmp->InsertAfter(GetNode<string>(number,NULL));
            break;
            }
            tmp=tmp->next;
        }
    }
}

void hashTable::printOut(void){//print the table ingredients
    for(int i=0;i<N;i++){
        cout<<i+1<<". ";
        cout<<table[i].data<<" ";
        Node<string>* tmp = table[i].next;
        while(tmp!=NULL){
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
}

bool hashTable::searchNumber(string number){//search number return one if found, zero otherwise
    for(int i = 0; i<N; i++){
        Node<string>* list = & table[i];
        Node<string>* tmp = list;
        if(list->data=="E"){}
        else{    
            while(tmp!=NULL){
                if(tmp->data==number)
                    return 1;
            tmp=tmp->next;        
            }
        }
    }
    return 0;
}

void hashTable::deleteNumber(string number){//delet a number from table

    for(int i = 0; i<N; i++){
        Node<string>* list = & table[i];
        Node<string>* tmp = list;
        Node<string>* prev;
        if(list->data=="E"){}//if data is empty ther eis nothing to delete
        else{    
            while(tmp!=NULL){//move tmp 
                if(tmp->data==number){//if number is found
                    if(tmp==list){//if it is the first element of the table[i]
                        if(list->next==NULL){//if next is null insert E instead of data
                            list->data="E";
                            }
                        else{
                            table[i] = *list->next;//if next is not null connect node to the next node
                            }
                    }
                    else{
                        prev->next=tmp->next; 
                    }                    
                }
            prev=tmp; //previous is one back of the tmp pointer   
            tmp=tmp->next;   //move tmp to right     
            }
        }
    }
}