#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

#include "myvector.h"
#include "mypair.h"
#include "mygraph.h"
#include "mytree.h"
const double OT=80;
const int N=5;
int **newRoutes;
Graph g;
Tree<int> t; 
#include "usefulfunctions.h"
#include "globalfunctions.h"


int main(){
    freopen("output.txt","w",stdout);
    //part a
    initroutemap();
    cout<<"----------------Month 1---------------"<<endl;
    g.listgroute(),cout<<endl;
    //part b
    cout<<"Flights: "<<endl;
    initflightplan();
    t.listtflights(t.root);cout<<endl;
    //part c
    
    cout<<"----------------Month 2---------------"<<endl;
    setOccupancyState(t.root);
    addmonthlynewroutes();
    cout<<endl;
    addmonthlynewflights();
    cout<<endl;
    g.listgroute();
    cout<<endl;
    cout<<"Flights: "<<endl;
    t.listtflights(t.root);cout<<endl;
    
    cout<<"----------------Month 3---------------"<<endl;
    setOccupancyState(t.root);
    cancelUnpopularFlights(t.root);//calls discardUnpopularRoute and updatePrice functions
    cout<<endl;
    addmonthlynewroutes();
    cout<<endl;
    addmonthlynewflights();
    cout<<endl;
    g.listgroute();
    cout<<endl;
    cout<<"Flights: "<<endl;
    t.listtflights(t.root);cout<<endl;
    
    cout<<"----------------Month 4---------------"<<endl;
    setOccupancyState(t.root);
    cancelUnpopularFlights(t.root);//calls discardUnpopularRoute and updatePrice functions
    addmonthlynewroutes();
    cout<<endl;
    addmonthlynewflights();
    cout<<endl;
    g.listgroute();
    cout<<endl;
    cout<<"Flights: "<<endl;
    t.listtflights(t.root);cout<<endl;

    cout<<"----------------Month 5---------------"<<endl;
    setOccupancyState(t.root);
    cancelUnpopularFlights(t.root);//calls discardUnpopularRoute and updatePrice functions
    addmonthlynewroutes();
    cout<<endl;
    addmonthlynewflights();
    cout<<endl;
    g.listgroute();
    cout<<endl;
    cout<<"Flights: "<<endl;
    t.listtflights(t.root);cout<<endl;

    cout<<"----------------Month 6---------------"<<endl;
    setOccupancyState(t.root);
    cancelUnpopularFlights(t.root);//calls discardUnpopularRoute and updatePrice functions
    addmonthlynewroutes();
    cout<<endl;
    addmonthlynewflights();
    cout<<endl;
    g.listgroute();
    cout<<endl;
    cout<<"Flights: "<<endl;
    t.listtflights(t.root);cout<<endl;
    //part d
    cout<<"Missing Flights and Routes"<<endl;
    checkAndAddReturnsRoutes();
    cout<<endl;
    //part e
    flightOptions("Probia","North Kirchoff");
    cout<<endl;

    return 0;

}

