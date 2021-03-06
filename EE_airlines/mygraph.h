const int cityNumber=20;//total number of cities is constant
//constructor for the Graph class
class Graph{
    public:
        Graph();//constructor
        ~Graph();//destructor
        void addgcity(string s);//add city to the names array
        void removegcity(string s);//remove city from the graph
        int searchgcity(string s);//searches the city in the names array and returns its index
        void addgroute(string departure, string arrival, double fare);//creates route between departure and arrival cities
        void removegroute(string departure, string arrival);//remove the route from departure city to arrival city
        double searchgroute(string departure, string arrival);//returns fare between the cities
        void listgroute(void);//prints the existing routes
       
        void updategroute(string departure,string arrival);

        myvector<mypair> v[cityNumber];//v is an array of myvector type(type for myvector is mypair) and the array dimension is cityNumber
        string names[cityNumber];//an array of string to hold the city names
        int vertex, edge;//vertex and edge number
};

Graph::Graph(){
    vertex=edge=0;
}
Graph::~Graph(){
    
}
void Graph::addgcity(string s){
    names[vertex++]=s;//put string s into the names array
}
void Graph::removegcity(string s){
    int ind=searchgcity(s);//find the index of city
    names[ind]="\0";//remove it
    
}
int Graph::searchgcity(string s){
    for(int i=0; i<vertex;i++)
        if(names[i]==s)//search string s and return its index
            return i;
    return -1;        
}
void Graph::addgroute(string departure, string arrival, double fare){
    int a=searchgcity(departure);//index of departure city
    int b=searchgcity(arrival);//index of arrival city
    mypair tmp(b,fare);//hold the arrival city and the fare from departure city
    v[a].push(tmp);//insert tmp to the vector for departure city with index a
}
void Graph::removegroute(string departure, string arrival){
    int a=searchgcity(departure);//index of departure city
    int b=searchgcity(arrival);//index of arrival city
    myvector<mypair> &adj=v[a];//keep the vector for departure city as reference adj
    for(int i=0;i<adj.size;i++)
        if(adj.ar[i].first==b)//search adj[i] and remove it if it is found
            adj.remove(i);
}
double Graph::searchgroute(string departure, string arrival){//returns fare between the cities
    int a=searchgcity(departure);
    int b=searchgcity(arrival);
    myvector<mypair> &adj=v[a];//keep the vector for departure city as reference
    for(int i=0;i<adj.size;i++)
        if(adj.ar[i].first==b)//search for the arrival city
            return adj.ar[i].second;//return the fare from departure city to arrival city
    return -1;        
}
void Graph::listgroute(void){
    cout<<"Routes:"<<endl;
    for(int i=0;i<vertex;i++){//loop for scanning departure cities
        myvector<mypair> &adj=v[i];//keep the vector for departure city as reference
        for(int j=0;j<adj.size;j++)//loop for scanning arrival cities
            cout<<names[i]<<"---> "<<names[ adj.ar[j].first ]<<", "<<adj.ar[j].second<<endl; 
            //print departureCity-->fare-->arrivalCİty
    }
}
void Graph::updategroute(string departure,string arrival){
    int a=searchgcity(departure);
    int b=searchgcity(arrival);
    myvector<mypair> &adj=v[a];//keep the vector for departure city as reference
    for(int i=0;i<adj.size;i++)
        if(adj.ar[i].first==b)//search for the arrival city
            adj.ar[i].second/=2;//return the fare from departure city to arrival city
}