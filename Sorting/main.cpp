#define fname "test1"
#include <iostream>
#include<cstdlib>
#include<ctime>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;
const int size = 200;
#include "someFunctions.h"
set mySet;//my set is a struct including integer poiner and size of the array
set testSet;//this is a test set which can be used by copying mySet
#include "sort.h"
#include "user.h"
#include "performance_evaluation.h"

int main(){
    srand(time(0));
    // freopen(&*((string)fname+".in").begin(),"r",stdin);
    // freopen(&*((string)fname+".out").begin(),"w",stdout);

    cout<<"1.Initialize input array randomly"<<endl<<
    "2.Load input array from a file"<<endl<<
    "3.Perform Bubble Sort"<<endl<<
    "4.Perform Quick Sort"<<endl<<
    "5.Perform Selection Sort"<<endl<<
    "6.Perform Your Own Sort"<<endl<<
    "7. Compare sorting algorithms"<<endl<<
    "0.Terminate Program"<<endl;
    
    int x=1;
    while(x){
        cin>>x;
        if(x==1)
            one();
        else if(x==2)
            two();
        else if(x==3)
            three();
        else if(x==4)
            four();
        else if(x==5)
            five();
        else if(x==6)
            six();
        else if(x==7)
            seven();
        else if(x==0){
            cout<<"program is terminated"<<endl;
            exit(1);
        }
        else
            cout<<"write a valid number from 1 to 7"<<endl;
    }
    //performance_evaluation();

    return 0;
}