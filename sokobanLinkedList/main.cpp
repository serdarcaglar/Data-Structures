#include <iostream>
#include<stdlib.h>
#include"source_code.h"
using namespace std;

//declaration of Node Class
template<class T>
class Node{
private:

public:
    Node <T>* next;//next part is a pointer to nodes of this type
    Node <T>* prev;//prev part is a pointer to nodes of this type
    T data;//data of the node

    Node(const T& item, Node<T>* ptrNext, Node<T>* ptrPrev);//constructor
    Node<T>* GetNode(const T&item, Node<T>*ptrNext, Node<T>*ptrPrev);//dynamically allocates a node and initializes it
    void InsertAfter(Node<T>*p);//unused
    Node<T>*DeleteAfter(void);//unused
    //get address of next node
    Node<T>*NextNode(void)const;//unused

};

//declaration of class doublyLinkedList
template<class T>
class doublyLinkedList{
private:
    //pointers to access front and rear
    Node<T> *rear;
    Node<T> *head;
    Node<T> *current;
    //relative position of current(unused)
    int position;
public:
    Node<T> *front;
    doublyLinkedList();
    //count of elements
    int size=0;
    void insertRear(const T& item);//insert an item to the linked list
    T popRear(void);//pop item from rear
    T popFront(void);//pop item from front
    T peekRear(void);//peek item from rear but not pop
    void printList(void)const;//prints the whole list;

};

template<class T>
class StackQueue
{
private:
    //int front, rear, count;
    //DataType list[MaxSQsize];
public:
    doublyLinkedList<T> list;
    StackQueue(void);//constructor
    void push_front(const T &item);//push front of the stackqueue////////caution!!!!//////
    T pop_front(void);//pop from front of the stackqueue///the rear of the linked list corresponds to front of the StackQueue/////
    T pop_rear(void);//pop from rear of the stackqueue
    T peek_front(void);//peek from front
    void print_movements(void);//print all movements
    //DataType peek_front(void);
    int length(void)const;//get the length of the stackqueue


};

int main()
{

    Sokoban soko;//instantiate a Sokoban class
    StackQueue<Sokoban> movements;//instantiate a StackQueue class with template Sokoban
    char a='s';//just a dummy character to get inside the while loop
    soko.print_puzzle();//print initial state
    movements.push_front(soko);//save initial state push to stackqueue
    while(a!='x'){//character'x' terminates the game
        cin>>a;
        if(a=='w'){
            if(soko.move_up())
            soko.print_puzzle();//print the new state and save to the stackqueue
            movements.push_front(soko);
            }
        else if(a=='a'){
            if(soko.move_left())
            soko.print_puzzle();
            movements.push_front(soko);}
        else if(a=='s'){
            if(soko.move_down())
                soko.print_puzzle();
            movements.push_front(soko);}
        else if(a=='d'){
            if(soko.move_right())
            soko.print_puzzle();
            movements.push_front(soko);
            }
        else if(a=='r'){//to replay all the moves, there are two option. In the comment code I used pop_rear so that it can replay only once as it deletes the movements, or the uncommented code allows replaying again and again
            /*int length=movements.length();        //this code as comment can performs replay operation once
            for(int i=0; i<length; i++)             //as it uses pop method
                (movements.pop_rear()).print_puzzle();
            cout<<"Thank for playing!"<<endl; return 0;*/
            movements.print_movements();            //this code may provide replay operation more than once
        }
        else if(a=='z'){//undoes the last movement
            movements.pop_front();
            movements.peek_front().print_puzzle();
        }
        else if(a=='f'){//check if the puzzle is solved or not
            if(movements.peek_front().is_solved())
                cout<<"Congratulations!!!"<<endl;
            else
                cout<<"Keep trying!"<<endl;
        }

    }






    return 0;
}

//Node class implementation
//constructor
template<class T>
Node<T>::Node(const T& item, Node<T>*ptrNext, Node<T>*ptrPrev):data(item), next(ptrNext), prev(ptrPrev){}

template<class T>
Node<T>* Node<T>::GetNode(const T&item, Node<T>*ptrNext, Node<T>*ptrPrev){
    Node<T>*newNode;//declare pointer;
    newNode=new Node<T>(item, ptrNext, ptrPrev);//allocate memory and create object of a node with these parameters
    if(newNode==NULL){
        cerr<<"Memory allocation failed"<<endl; exit(1);}
    return newNode;
    }

//doubly linked list constructor
template<class T>
doublyLinkedList<T>::doublyLinkedList(){};

template<class T>
void doublyLinkedList<T>::insertRear(const T& item){//a method for inserting items to the list from rear
    if(size==0){
        T soko2;
        head = head->GetNode(soko2,NULL,NULL);//head is a pointer that points to a head node which does not have data, it just has next pointer.
        head->next=head->GetNode(item, NULL, head);//put new node's address to head->next, and put the item inside new node
        rear=front=head->next;//update rear and front pointers so that they point the new node
        size++;//increase list size by 1
    }
    else{
        rear->next=head->GetNode(item, NULL, rear);//create new node and put its address to rear->next
        rear=rear->next;//update rear
        front=head->next;//front does not change
        size++;//increase size by 1
    }
}

template<class T>
T doublyLinkedList<T>::popFront(void){
    if(size>1){
        Node<T>* temp=front;//create a temp Node*
        T tempData=temp->data;//keep the item to return
        Node<T>* posterior=front->next;//find posterior node*
        /*front->prev=NULL;//unnecessary
        front->next=NULL;*/
        head->next=posterior;//connect posterior to head doubly
        posterior->prev=head;
        front=head->next;//update front
        size--;//decrease size of the list
        return tempData;}//return the item in the front
    else if(size==1){
        Node<T>* temp=front;
        T tempData=temp->data;
        head->next=NULL;//if size is one directly make head->next null
        //cout<<"stack will be empty"<<endl;
        size--;//decrease size
        return tempData;
    }
    else if(size==0){
        cout<<"stack is empty.";

    }
}

template<class T>
T doublyLinkedList<T>::popRear(void){
    if(size>=1){
    Node<T>* temp=rear;
    T tempData=temp->data;//keep tempData to return
    Node<T>* former=rear->prev;//keep former
    former->next=NULL;//make former node the last node
    rear=former;//update rear
    size--;
    return tempData;
    }
    else if(size==0){
        cout<<"no previous movement"<<endl;
    }
}

template<class T>
T doublyLinkedList<T>::peekRear(void){
    return rear->data;//return the data at the rear
}

template<class T>
void doublyLinkedList<T>::printList(void)const{//this is a method just to check linked list, here is nothing with sokoban
    Node<T>*temp=front;//displays all the items in the list
    for(int i=0;i<size;i++){
    cout<<temp->data<<" ";
    temp=temp->next;
    }

}

//constructor for class StackQueue
template<class T>
StackQueue<T>::StackQueue(void){}

//this might be confusing but push_front method of StackQueue class corresponds to insertRear method of the dooublyLinkedList Class
template<class T>
void StackQueue<T>::push_front(const T &item){
    list.insertRear(item);
}
//similarly pop_front corresponds to pop_rear
template<class T>
T StackQueue<T>::pop_front(void){
    return list.popRear();
}
//pop_rear corresponds to popFront
template<class T>
T StackQueue<T>::pop_rear(void){
    return list.popFront();
}
//peek_front corresponds to peekRear
template<class T>
T StackQueue<T>::peek_front(void){
    return list.peekRear();
}

//print all the movements included by StackQueue
template<class T>
void StackQueue<T>::print_movements(void){
    Node<T>*cur=list.front;
    for(int i =0; i<list.size;i++){
        cur->data.print_puzzle();
        cur=cur->next;}
}

//a method for returning list.size
template<class T>
int StackQueue<T>::length(void)const{
    return list.size;
}
