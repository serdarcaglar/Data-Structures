void performance_evaluation(){
    for(int a=0;a<7; a++){//iterate for seven different algorithms
        if(a==0)
            cout<<"Selection Sort"<<endl;
        else if(a==1)
            cout<<"Bubble Sort"<<endl;
        else if(a==2)
            cout<<"Quick Sort-1"<<endl;
        else if(a==3)
            cout<<"Quick Sort-2"<<endl;
        else if(a==4)
            cout<<"Quick Sort-3"<<endl;
        else if(a==5)
            cout<<"Quick Sort-4"<<endl;
        else if(a==6)
            cout<<"My Sort"<<endl;
                
        
        printf("%20s%20s%20s%20s\n","Size","#Comparisons","#Moves","Time(msec)");
        double start; int comparisons; int moves; double finish; double elapsed_time;
        for(int k=0; k<5; k++){ //iterate for 5 randomly generated arrays
            int size;
            if(k==0)
                size=100;
            else if(k==1)
                size = 1000; 
            else if(k==2)
                size = 5000; 
            else if(k==3)
                size = 10000; 
            else if(k==4)
                size = 25000; 
            int sum_comp = 0; int sum_moves=0; int sum_time=0;
            for(int i=0;i<5;i++) {
                int randArray[size]; 
                for(int j=0; j<size; j++) 
                randArray[j]=rand()%(10*size); //Generate numbers between 0 to (10*size) 

                start = double(clock());
                comparisons = 0;
                moves = 0;
                
                if(a==0)
                    SelectionSort(randArray, size, comparisons, moves);
                else if(a==1)
                    BubbleSort(randArray, size, comparisons, moves);
                else if(a==2)
                    QuickSort(randArray, 0, size - 1, 1, comparisons, moves);
                else if(a==3)
                    QuickSort(randArray, 0, size - 1, 2, comparisons, moves);
                else if(a==4)
                    QuickSort(randArray, 0, size - 1, 3, comparisons, moves);
                else if(a==5)
                    QuickSort(randArray, 0, size - 1, 4, comparisons, moves);
                else if(a==6)
                    mySort(randArray, 0, size - 1, 2, comparisons, moves);      
                                                                          
                finish = double(clock()); 
                elapsed_time = (finish-start)/CLOCKS_PER_SEC*1000;
                sum_comp+=comparisons; sum_moves+=moves; sum_time+=elapsed_time;
                // collect statistics 
                i++; 
            }
            printf("%20d%20.2lf%20.2lf%20.2lf \n",size,sum_comp/5.0, sum_moves/5.0, sum_time/5.0);

        }


    }

}