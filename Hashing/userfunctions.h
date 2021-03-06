void one(){
    cout<<"Please enter N then press enter than enter hashing method(truncation or middleSquaring or folding)"<<endl;
    string N;
    cin>>N;
    string method;
    cin>>method;
    id.initializeHashTable(stringToNumber<int>(N), method);//initialize hash table with entered N and method
}

void two(){
    id.loadNumbers();//load numbers from txt file
}

void three(){
    cout<<"please enter id number to be added"<<endl;
    string s;
    cin>>s;
    id.addNewNumber(s);
}

void four(){
    cout<<"please enter id number to be deleted"<<endl;
    string s;
    cin>>s;
    id.deleteNumber(s);
}

void five(){
    cout<<"please enter id number to be searched"<<endl;
    string s;
    cin>>s;
    if(id.searchNumber(s)){
        cout<<"id exists in database"<<endl;
    }
    else
    {
        cout<<"id could not found"<<endl;
    }
    
}


void six(){
    id.printOut();
}

