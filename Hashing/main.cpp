//spent time 20 hours
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include<list>
using namespace std;
const int N=100;

#include "node.h"
#include "usefulfunctions.h"
#include "hashTable.h"
hashTable id;//our hash table object
#include "userfunctions.h"

int main(){
    cout<<"1.Initialize Hash Table"<<endl<<
    "2.Load T.C. IDNumbers from file"<<endl<<
    "3.Add new T.C. IDNumber"<<endl<<
    "4.Delete a T.C. IDNumber"<<endl<<
    "5.Search for a T.C. IDNumber"<<endl<<
    "6.Print out Hash Table"<<endl<<
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
        else if(x==0)
            cout<<"program is terminated"<<endl;
        else
            cout<<"write a valid number from 1 to 6"<<endl;
    }




    return 0;

}