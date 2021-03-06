int * threeRand(){//generates three integer between 1 and 20 and return array of this three integers
    int * ar = new int[3];
    for(int i = 0; i<3; i++){
        ar[i]=rand()%20+1;}
    if(ar[1]==ar[0]) ar[1]=rand()%20+1;
    return ar;    
}

void printNewRoutesInfo(int *newRoute){//prints root for the input array e.g.[4,5,3]
    cout<<g.names[newRoute[0]-1]<<"---> "<<g.names[ newRoute[1]-1 ]<<", "<<newRoute[2]<<"  Route added"<<endl; 
}

void printNewFlightsInfo(int *newRoute){//prints root for the input array e.g.[4,5,3]
    int departure=newRoute[0];//get string of departureCity
    int arrival=newRoute[1];//get string of arrivaltureCity
    int fare = newRoute[2];//get fare
    int flightNum=concat(departure*10+arrival/10, arrival%10);
    cout<<"Flight "<<flightNum<<" is added"<<endl; 
}
