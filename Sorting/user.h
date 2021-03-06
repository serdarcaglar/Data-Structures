void one(){//initialize a random array with size N
    cout<<"Please enter size of the array"<<endl;
    string N;
    cin>>N;
    int x = stringToNumber<int>(N);
    mySet.array = initializeRandomArray(x);
    mySet.size = x;

}

void two(){//load array from a txt file
    int cnt;
    mySet.array = loadRandomNumbers(cnt);
    mySet.size = cnt;
}

void three(){//perform bubble sort
    int comparisons = 0;
    int moves = 0;
    BubbleSort(mySet.array, mySet.size, comparisons, moves);
    printArray(mySet.array, mySet.size);
}

void four(){//perform quick sort with four different possible types
    cout<<"Please enter how will the pivot be chosen?"<<endl<<
    "1. select first element as pivot"<<endl<<
    "2. select middle element as pivot"<<endl<<
    "3. select randomly chosen element of the array"<<endl<<
    "4. select the median of 3 randomly chosen elements of the array as pivot"<<endl;
    string N;
    cin>>N;
    int x = stringToNumber<int>(N);
    int comparisons = 0;
    int moves = 0;
    QuickSort(mySet.array, 0, mySet.size - 1, x, comparisons, moves);
    printArray(mySet.array, mySet.size);

}

void five(){//perform selection sort
    int comparisons = 0;
    int moves = 0;
    SelectionSort(mySet.array, mySet.size, comparisons, moves);
    printArray(mySet.array, mySet.size);
    
}


void six(){//perform my sort
    int comparisons = 0;
    int moves = 0;
    mySort(mySet.array, 0, mySet.size - 1, 1, comparisons, moves);
    printArray(mySet.array, mySet.size);
}


void seven(){//perform testing algorithms
    testSet.size = mySet.size;
    testSet.array = new int[mySet.size];
    copyArray(mySet.array, testSet.array, mySet.size);
    cout<<"Array size: "<<mySet.size<<" numbers"<<endl;
    printf("%20s%20s%20s%20s\n","Algorithm","#Comparisons","#Moves","Time(msec)");
   
    double start; int comparisons; int moves; double finish; double elapsed_time;
    for(int i=0; i<7; i++){//perform for 7 different algorithms
        start = double(clock());
        comparisons = 0;
        moves = 0;
        if(i==0){//selection sort
            for(int i=0; i < 10; i++){//iterate 10 times to measure
                SelectionSort(testSet.array, testSet.size, comparisons, moves);
                copyArray(mySet.array, testSet.array, mySet.size);//apply sorting to the same copied array
            }
            finish = double(clock()); 
            elapsed_time = (finish-start)/CLOCKS_PER_SEC;//measure elapsed time in terms of second
            printf("%20s%20.2lf%20.2lf%20.2lf \n","Selection Sort",comparisons/10.0, moves/10.0, elapsed_time*1000/10);//convert elapsed time to milisec
        }

        else if(i==1){//bubble sort
            for(int i=0; i < 10; i++){
                BubbleSort(testSet.array, testSet.size, comparisons, moves);
                copyArray(mySet.array, testSet.array, mySet.size);
            }
            finish = double(clock()); 
            elapsed_time = (finish-start)/CLOCKS_PER_SEC;
            printf("%20s%20.2lf%20.2lf%20.2lf \n","Bubble Sort",comparisons/10.0, moves/10.0, elapsed_time*1000/10);
        }

        else if(i==2){//quick sort 1
            for(int i=0; i < 10; i++){
                QuickSort(testSet.array,0, testSet.size-1,1, comparisons, moves);
                copyArray(mySet.array, testSet.array, mySet.size);
            }
            finish = double(clock()); 
            elapsed_time = (finish-start)/CLOCKS_PER_SEC;
            printf("%20s%20.2lf%20.2lf%20.2lf \n","Quick Sort-1",comparisons/10.0, moves/10.0, elapsed_time*1000/10);
        }

        else if(i==3){//quick sort 2
            for(int i=0; i < 10; i++){
                QuickSort(testSet.array,0, testSet.size-1,2, comparisons, moves);
                copyArray(mySet.array, testSet.array, mySet.size);
            }
            finish = double(clock()); 
            elapsed_time = (finish-start)/CLOCKS_PER_SEC;
            printf("%20s%20.2lf%20.2lf%20.2lf \n","Quick Sort-2",comparisons/10.0, moves/10.0, elapsed_time*1000/10);
        }

        else if(i==4){//quick sort 3
            for(int i=0; i < 10; i++){
                QuickSort(testSet.array,0, testSet.size-1,3, comparisons, moves);
                copyArray(mySet.array, testSet.array, mySet.size);
            }
            finish = double(clock()); 
            elapsed_time = (finish-start)/CLOCKS_PER_SEC;
            printf("%20s%20.2lf%20.2lf%20.2lf \n","Quick Sort-3",comparisons/10.0, moves/10.0, elapsed_time*1000/10);

        }

        else if(i==5){//quick sort 4
            for(int i=0; i < 10; i++){
                QuickSort(testSet.array,0, testSet.size-1,4, comparisons, moves);
                copyArray(mySet.array, testSet.array, mySet.size);
            }
            finish = double(clock()); 
            elapsed_time = (finish-start)/CLOCKS_PER_SEC;
            printf("%20s%20.2lf%20.2lf%20.2lf \n","Quick Sort-4",comparisons/10.0, moves/10.0, elapsed_time*1000/10);

        }

        else if(i==6){//quick sort 4
            for(int i=0; i < 10; i++){
                mySort(testSet.array,0, testSet.size-1, 2 , comparisons, moves);
                copyArray(mySet.array, testSet.array, mySet.size);
            }
            finish = double(clock()); 
            elapsed_time = (finish-start)/CLOCKS_PER_SEC;
            printf("%20s%20.2lf%20.2lf%20.2lf \n","My Sort",comparisons/10.0, moves/10.0, elapsed_time*1000/10);

        }
    
    }
    cout<<endl;
}