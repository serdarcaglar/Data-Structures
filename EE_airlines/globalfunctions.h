void initroutemap(){
    cout << "Hello world!" << endl;
    ifstream myfile("citylist.txt");
    string line;

    if (myfile.is_open()){
        while (getline(myfile, line))
            g.addgcity(line);
        myfile.close();
    }
    else
        cout << "Unable to open file";

    g.addgroute("Gulf of Archi","Logicheim",8);
    g.addgroute("Probia","Logicheim",3);
    g.addgroute("Logicheim","Probia",3);
    g.addgroute("Probia","Gulf of Archi",7);
    g.addgroute("Signale","Probia",12);
    g.addgroute("Probia","Las Datas",20);


}

void initflightplan(){
    TreeNode<int>* root=GetTreeNode(111);//just to initialize the tree
    t.root = root;
    for(int i=0;i<g.vertex;i++){//loop for scanning departure cities
        myvector<mypair> &adj=g.v[i];//keep the vector for departure city as reference
        for(int j=0;j<adj.size;j++){//loop for scanning arrival cities
            int departure = i+1;
            int arrival=adj.ar[j].first+1;
            int flight;
            if(arrival)
                flight=concat(departure*10+arrival/10, arrival%10);
            t.addtflight(t.root, flight);
        }
    }
    t.removetflight(t.root, 111);//delete the number for initialization
}
void addmonthlynewroutes(){
    //int ** newRoutes;//array of new routes in the form (12,4,8),(3,8,6),1,5,2) where(departure,arrival,fare)
    newRoutes = new int*[N];//
    for(int i = 0; i < N; i++){//and allocate memory for that
    newRoutes[i] = new int[3];//
    }
    //check if route exists

    for(int i=0;i<N;i++){//look for every route that is newly added
        newRoutes[i]=threeRand();//array elements consist of arrays of size 3. they represents departure city, arrival cit and fare between them
        string departureCity=g.names[newRoutes[i][0]-1];//get string of departureCity
        string arrivalCity=g.names[newRoutes[i][1]-1];//get string of arrivaltureCity
        int fare = newRoutes[i][2];//get fare
        int isValid=g.searchgroute(departureCity, arrivalCity);
        if(isValid){
            printNewRoutesInfo(newRoutes[i]);
            g.addgroute(departureCity, arrivalCity, fare);
        }

    }
}

void addmonthlynewflights(){
    for(int i=0; i<N; i++){
        int departure=newRoutes[i][0];//get string of departureCity
        int arrival=newRoutes[i][1];//get string of arrivaltureCity
        int fare = newRoutes[i][2];//get fare
        int flightNum=concat(departure*10+arrival/10, arrival%10);
        TreeNode<int>* isValid=t.searchtflight(t.root, flightNum);
        if(isValid==NULL){
            printNewFlightsInfo(newRoutes[i]);
            t.addtflight(t.root, flightNum);
        }
    }
}
/*************************** part d ***********************************************/
template <class T>
void setOccupancyState(TreeNode<T>* root){
      if(root==NULL){
          return;
      }
      bool tmp=rand()%101>=OT?false:true;
    //   assert(root->state<2);
      root->state=root->state==1 and tmp==0 ? 0 : root->state+tmp;
      setOccupancyState(root->left);
      setOccupancyState(root->right);
}

void discardUnpopularRoutes(int departure,int arrival){
    cout<<"("<<g.names[departure]<<"---> "<<g.names[arrival]<<") Route Discarded\n";
    g.removegroute(g.names[departure],g.names[arrival]);
}

void updatePrices(int departure,int arrival){
    cout<<"("<<g.names[departure]<<"---> "<<g.names[arrival]<<", "<<g.searchgroute(g.names[departure],g.names[arrival])<< ") is %%50 off\n";
    g.updategroute(g.names[departure],g.names[arrival]);
}

template <class T>
void cancelUnpopularFlights(TreeNode<T>* root){
    if (root == NULL){
        return;
    }
    if (root->state == 2){
        int departure, arrival;
        departure = root->data / 100;
        arrival = root->data % 100;
        cout<<"Flight EE";
        if(root->data<1e3 and root->data>=1e2)
            cout<<0;
        cout<<root->data<<" Cancelled\n";
        discardUnpopularRoutes(departure - 1, arrival - 1);
        t.removetflight(t.root, root->data);
        root=t.root;
    }
    else if(root->state == 1){
        int departure, arrival;
        departure = root->data / 100;
        arrival = root->data % 100;
        updatePrices(departure-1,arrival-1);
    }
    cancelUnpopularFlights(root->left);
    cancelUnpopularFlights(root->right);
}

/*************************************** part e ***************************/

void addReturnFlights(int num){
    cout << "Flight EE";
    if (num < 1e3 and num >= 1e2)
        cout << 0;
    cout << num << " Added\n";
    t.addtflight(t.root,num);
}

void  checkAndAddReturnsRoutes(){
    for(int i=0;i<g.vertex;++i){
        myvector<mypair> &adj=g.v[i];
        for(int j=0;j<adj.size;++j){
            int departure=i,arrival=adj.ar[j].first;
            if(g.searchgroute(g.names[arrival],g.names[departure])==-1){
                cout<<"("<<g.names[arrival]<<"---> "<<g.names[departure]<<", "<<adj.ar[j].second<< ") Return Route Added\n";
                g.addgroute(g.names[arrival],g.names[departure],adj.ar[j].second);
                departure++,arrival++;
                addReturnFlights(concat(arrival*10+departure/10, departure%10));
            }
        }
    }
}

void inttoflight(int departure,int arrival){
    int num=concat(departure*10+arrival/10, arrival%10);
    if (num < 1e3 and num >= 1e2)
        cout << 0;
    cout << num;
}

void flightOptions(string departureCity, string destinationCity){
    int departure=g.searchgcity(departureCity);
    int arrival=g.searchgcity(destinationCity);

    cout<<"One-way Trip Options for "<< g.names[departure] <<"--->"<< g.names[arrival]<<endl;
    bool flag=true;
{
    int tmp=g.searchgroute(g.names[departure],g.names[arrival]);
    if(tmp!=-1){
        cout<<"Direct Option: "<<g.names[departure] <<" ---> ";
        inttoflight(departure+1,arrival+1);
        cout<<" ---> "<< g.names[arrival]<< " for "<<tmp<<endl;
        flag=false;
    }
}
    int firstStop;
    myvector<mypair> &adj = g.v[departure];
    for (int i = 0; i < adj.size; i++)
    {
            firstStop = adj.ar[i].first;
            if(firstStop==departure or firstStop==arrival)
                continue;
            int tmp=g.searchgroute(g.names[firstStop], g.names[arrival]);
            if(tmp==-1)
                continue;
            cout<<"1-Stop Option: "<<g.names[departure]<<" ---> ";
            inttoflight(departure+1,firstStop+1);
            cout<<" ---> "<< g.names[firstStop]<< " ---> ";
            inttoflight(firstStop+1,arrival+1);
            cout<<" ---> "<<g.names[arrival]<< " for "<< adj.ar[i].second <<" + "<< tmp <<endl;
            flag=false;
    }
{

}

{    int firstStop, secondStop;
    myvector<mypair> &adj = g.v[departure];
    for (int i = 0; i < adj.size; i++)
    {
            firstStop = adj.ar[i].first;
            if(firstStop==departure or firstStop==arrival)
                continue;
            myvector<mypair> &adjStop1 = g.v[firstStop];
            for(int j=0;j<adjStop1.size;j++){
                secondStop=adjStop1.ar[j].first;
                if(secondStop==firstStop or secondStop==departure or secondStop==arrival)
                    continue;
                int tmp=g.searchgroute(g.names[secondStop], g.names[arrival]);
                if(tmp==-1)
                    continue;

                cout<<"2-Stop Option: "<< g.names[departure]<<" ---> ";
                inttoflight(departure+1,firstStop+1);
                cout<<" ---> "<< g.names[firstStop]<< " ---> ";
                inttoflight(firstStop+1,secondStop+1);
                cout<<" ---> "<<g.names[secondStop]<< " ---> ";
                inttoflight(secondStop+1,arrival+1);
                cout<<" ---> "<<g.names[arrival]<< " for "<< adj.ar[i].second<<" + "<<adjStop1.ar[j].second<<" + "<<tmp<<endl;
                flag=false;
            }
    }
}
         if(flag)
            cout<<"No Trip Options"<<endl;
}
