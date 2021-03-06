#include <iostream>
#include <fstream>
using namespace std;
const int row_number = 6;
const int column_number=8;
const int MaxSQsize=400;


//decleration of the class Sokoban
class Sokoban{
    private:

    public:
        char** my_map;//two d array for the map
        int* cursor;//1d array which keeps to integer to represent the position of the player e.g. 2,1
        //char invisible;//the character that is covered by player(unneccessary)
        int row;    //refers to the column and row
        int column; //that player stays
        Sokoban(char**given_map);//initializes class from a character array
        Sokoban(const Sokoban&);//copy constructor
        Sokoban& operator = (const Sokoban& any_soko);//overloading assignment operator for copying
        Sokoban(void);//a constructor that initializes the class from a text file
        ~Sokoban(void);//destructor for my_mapp
        void print_puzzle(void) const;
        bool move_up(void);//methods for movements, returns 1 if the move is valid and performs the movement
        bool move_down(void);//
        bool move_left(void);//
        bool move_right(void);//
        bool is_solved(void)const;//method checks if it is solved

};

void printPuzzle(const Sokoban & my_soko){//the function for debugging
    for(int i=0; i<row_number; i++){
        for(int j=0; j<column_number; j++)
            cout<<my_soko.my_map[i][j];
    cout<<endl;
    }
}

//implementation of the class Sokoban
Sokoban::Sokoban(char ** given_map){//constructor that initializes the class from a char array
    //allocate memory for our two dimensional array my_map
    my_map = new char*[row_number];
    for(int i = 0; i < row_number; i++){
    my_map[i] = new char[column_number];
    }
    //initialize our class from a char array
    for(int i=0; i<row_number; i++)
        for(int j=0; j<column_number; j++)
            my_map[i][j]=given_map[i][j];
}
//implementation of the copy constructor
Sokoban::Sokoban(const Sokoban& copy_soko){
    //allocate memory for our two dimensional array my_map
    my_map = new char*[row_number];
    for(int i = 0; i < row_number; i++){
    my_map[i] = new char[column_number];
    }
    //initialize our class from a char array
    for(int i=0; i<row_number; i++)
        for(int j=0; j<column_number; j++)
            my_map[i][j]=copy_soko.my_map[i][j];
    column=copy_soko.column;
    row=copy_soko.row;

}
Sokoban& Sokoban::operator = (const Sokoban& any_soko){
    //allocate memory for our two dimensional array my_map
    my_map = new char*[row_number];
    for(int i = 0; i < row_number; i++){
    my_map[i] = new char[column_number];
    }
    //initialize our class from a char array
    for(int i=0; i<row_number; i++)
        for(int j=0; j<column_number; j++)
            my_map[i][j]=any_soko.my_map[i][j];
    column=copy_soko.column;
    row=copy_soko.row;
    return *this;
}
//implementation of destructor
Sokoban::~Sokoban(void){
    delete my_map;
}
//implementation of the constructor that initializes the class from a text file
Sokoban::Sokoban(void){
/////////////provided code////////////////////
/* code segment to read the */ /* sample file into a char array */
/* file path */ /* you can use relative path if */ /* the file is in project folder */
string path = "sample_puzzle.txt";
/* contents of the file will be */ /* stored in this array */
char data[row_number][column_number]; /* newline character will be */ /* read in dummy */
char dummy; /* input file stream */
ifstream file;
file.open(path);
for(int i=0; i<row_number; ++i){
    for(int j=0; j<column_number; ++j){
        /* read a character like cin */ /* noskipws is required for */ /* reading whitespaces */
        file >> noskipws >> data[i][j]; }
/* read the newline character */ /* at the end of each line */
file >> noskipws >> dummy; }
file.close();
    // dynamically create array of pointers of size row_number
	my_map  = new char*[row_number];

	// dynamically allocate memory of size column_number for each row
	for (int i = 0; i < row_number; i++)
		my_map[i] = new char[column_number];
for(int i = 0; i<row_number; i++)
    for(int j=0; j<column_number; j++)
        my_map[i][j]=data[i][j];
cursor=new int[2];
for(int i = 0; i<row_number; i++){//detect where the player is
    for(int j=0; j<column_number; j++){
        if (my_map[i][j]=='@'){
            cursor[0]=i; cursor[1]=j;}
    }
}
row=cursor[0];//insert inside those variables row and column
column=cursor[1];
//invisible=' ';//unneccessary
}

void Sokoban::print_puzzle(void) const{//method for printing the map
    for(int i=0; i<row_number; i++){
        for(int j=0; j<column_number; j++)
            cout<<my_map[i][j];
    cout<<endl;
    }

}
bool Sokoban::move_up(){
    if (my_map[row-1][column]=='#'){///if there is block above
        return 0;}
    else if (my_map[row-1][column]==' '){////if there is space above
        if(my_map[row][column]=='+'){       ///check if player on target
            my_map[row][column]='.';            ///will leave target
            row=row-1;                          ///update place of the player
            my_map[row][column]='@';            ///will be on space
            return 1;
            }
        else if(my_map[row][column]=='@'){  ///or not on target
            my_map[row][column]=' ';            ///will leave space
            row=row-1;                          ///update place of the player
            my_map[row][column]='@';            ///will be on space
            return 1;
            }

        }
    else if (my_map[row-1][column]=='.'){////if there is target above
        if(my_map[row][column]=='+'){       ///check if player on target
            my_map[row][column]='.';        ///it will leave target
            row=row-1;
            my_map[row][column]='+';        ///and will be on target
        }
        else if(my_map[row][column]=='@'){    ///or player not on target
            my_map[row][column]=' ';        ///it will leave empty space
            row=row-1;
            my_map[row][column]='+';        ///after movement it will be on target
        }
        return 1;
    }

    if (my_map[row-1][column]=='$'){////if there is movable box above (not at target location)
        if(my_map[row-2][column]=='#'||my_map[row-2][column]=='$'){///if there is wall or another box next the box it is invalid movement
            return 0;
        }
        else if(my_map[row-2][column]==' '){///1111 if there is empty cell next to the box 1111
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';        ///it will leave target
                my_map[row-1][column]='@';      ///player will go to the old place of the movable box
                my_map[row-2][column]='$';      ///movable box moved to empty cell
                row=row-1;
                return 1;
        }
            else if(my_map[row][column]=='@'){   ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row-1][column]='@';
                my_map[row-2][column]='$';      ///movable box moved to empty cell
                row=row-1;
                return 1;                     ///after movement it will be on target
        }
        }

        else if(my_map[row-2][column]=='.'){///2222 if there is target cell next to the box 2222
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';          ///it will leave target
                my_map[row-1][column]='@';        ///player will go to the old place of the movable box
                my_map[row-2][column]='*';        ///movable box moved to target cell
                row=row-1;
                return 1;
        }
            else if(my_map[row][column]=='@'){       ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row-1][column]='@';
                my_map[row-2][column]='*';      ///movable box moved to target cell
                row=row-1;
                return 1;                     ///after movement it will be on target
        }
        }
    }

    else if (my_map[row-1][column]=='*'){////if there is a box above that is at target location)
        if(my_map[row-2][column]=='#'||my_map[row-2][column]=='$'){///if there is wall or another box next the box it is invalid movement
            return 0;
        }
        else if(my_map[row-2][column]==' '){///1111 if there is empty cell next to the box 1111
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';        ///it will leave target
                my_map[row-1][column]='+';      ///player will go to the old place of the movable box that was at target
                my_map[row-2][column]='$';      ///movable box moved to empty cell
                row=row-1;
                return 1;
        }
            else if(my_map[row][column]=='@'){   ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row-1][column]='+';      ///player will go to the old place of the movable box that was at target
                my_map[row-2][column]='$';      ///movable box moved to empty cell
                row=row-1;
                return 1;
        }
        }

        else if(my_map[row-2][column]=='.'){///2222 if there is target cell next to the box 2222
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='+';          ///it will leave target
                my_map[row-1][column]='+';        ///player will go to the old place of the box that was at target
                my_map[row-2][column]='*';        ///movable box moved to target cell
                row=row-1;
                return 1;
        }
            else if(my_map[row][column]=='@'){       ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row-1][column]='+';      ///after movement it will be on target
                my_map[row-2][column]='*';      ///movable box moved to target cell
                row=row-1;
                return 1;
        }
        }
    }


return 0;
}

bool Sokoban::move_right(){
    if (my_map[row][column+1]=='#'){///if there is block right
        return 0;}
    else if (my_map[row][column+1]==' '){////if there is space right
        if(my_map[row][column]=='+'){   ///check if player on target
            my_map[row][column]='.';        ///will leave target
            column=column+1;
            my_map[row][column]='@';        ///will be on space
            }
        else if(my_map[row][column]=='@'){   ///or not on target
            my_map[row][column]=' ';        ///will leave space
            column=column+1;
            my_map[row][column]='@';        ///will be on space
            }
        return 1;
        }
    else if (my_map[row][column+1]=='.'){////if there is target right
        if(my_map[row][column]=='+'){   ///check if player on target
            my_map[row][column]='.';    ///it will leave target
            column=column+1;
            my_map[row][column]='+';    ///and will be on target
        }
        else if(my_map[row][column]=='@'){    ///or player not on target
            my_map[row][column]=' ';    ///it will leave empty space
            column=column+1;
            my_map[row][column]='+';    ///after movement it will be on target
        }
        return 1;
    }

    else if (my_map[row][column+1]=='$'){////if there is movable box right (not at target location)
        if(my_map[row][column+2]=='#'||my_map[row][column+2]=='$'){///if there is wall or another box next the box it is invalid movement
            return 0;
        }
        else if(my_map[row][column+2]==' '){///1111 if there is empty cell next to the box 1111
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';        ///it will leave target
                my_map[row][column+1]='@';      ///player will go to the old place of the movable box
                my_map[row][column+2]='$';      ///movable box moved to empty cell
                column=column+1;
                return 1;
        }
            else if(my_map[row][column]=='@'){   ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row][column+1]='@';
                my_map[row][column+2]='$';      ///movable box moved to empty cell
                column=column+1;                 ///after movement it will be on target
                return 1;
        }
        }

        else if(my_map[row][column+2]=='.'){///2222 if there is target cell next to the box 2222
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';          ///it will leave target
                my_map[row][column+1]='@';        ///player will go to the old place of the movable box
                my_map[row][column+2]='*';        ///movable box moved to target cell
                column=column+1;
                return 1;
        }
            else if(my_map[row][column]=='@'){       ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row][column+1]='@';
                my_map[row][column+2]='*';      ///movable box moved to target cell
                column=column+1;                ///after movement it will be on target
                return 1;
        }
        }
    }

    else if (my_map[row][column+1]=='*'){////if there is a box right that is at target location)
        if(my_map[row][column+2]=='#'||my_map[row+2][column]=='$'){///if there is wall or another box next the box it is invalid movement
            return 0;
        }
        else if(my_map[row][column+2]==' '){///1111 if there is empty cell next to the box 1111
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';        ///it will leave target
                my_map[row][column+1]='+';      ///player will go to the old place of the movable box that was at target
                my_map[row][column+2]='$';      ///movable box moved to empty cell
                column=column+1;
                return 1;
        }
            else if(my_map[row][column]=='@'){   ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row][column+1]='+';      ///player will go to the old place of the movable box that was at target
                my_map[row][column+2]='$';      ///movable box moved to empty cell
                column=column+1;
                return 1;
        }
        }

        else if(my_map[row][column+2]=='.'){///2222 if there is target cell next to the box 2222
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='+';          ///it will leave target
                my_map[row][column+1]='+';        ///player will go to the old place of the box that was at target
                my_map[row][column+2]='*';        ///movable box moved to target cell
                column=column+1;
                return 1;
        }
            else if(my_map[row][column]=='@'){       ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row][column+1]='+';      ///after movement it will be on target
                my_map[row][column+2]='*';      ///movable box moved to target cell
                column=column+1;
                return 1;
        }
        }
    }

return 0;
}

bool Sokoban::move_down(){
    if (my_map[row+1][column]=='#'){///if there is block down
        return 0;}
    else if (my_map[row+1][column]==' '){////if there is space down
        if(my_map[row][column]=='+'){   ///check if player on target
            my_map[row][column]='.';        ///will leave target
            row=row+1;
            my_map[row][column]='@';        ///will be on space
            return 1;
            }
        else if(my_map[row][column]=='@'){   ///or not on target
            my_map[row][column]=' ';        ///will leave space
            row=row+1;
            my_map[row][column]='@';        ///will be on space
            return 1;
            }

        }
    else if (my_map[row+1][column]=='.'){////if there is target down
        if(my_map[row][column]=='+'){   ///check if player on target
            my_map[row][column]='.';    ///it will leave target
            row=row+1;
            my_map[row][column]='+';    ///and will be on target
            return 1;
        }
        else if(my_map[row][column]=='@'){    ///or player not on target
            my_map[row][column]=' ';    ///it will leave empty space
            row=row+1;
            my_map[row][column]='+';    ///after movement it will be on target
            return 1;
        }
        return 1;
    }

    else if (my_map[row+1][column]=='$'){////if there is movable box right (not at target location)
        if(my_map[row+2][column]=='#'||my_map[row+2][column]=='$'){///if there is wall or another box next the box it is invalid movement
            return 0;
        }
        else if(my_map[row+2][column]==' '){///1111 if there is empty cell next to the box 1111
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';        ///it will leave target
                my_map[row+1][column]='@';      ///player will go to the old place of the movable box
                my_map[row+2][column]='$';      ///movable box moved to empty cell
                row=row+1;
                return 1;
        }
            else if(my_map[row][column]=='@'){   ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row+1][column]='@';
                my_map[row+2][column]='$';      ///movable box moved to empty cell
                row=row+1;                      ///after movement it will be on target
                return 1;
        }
        }

        else if(my_map[row+2][column]=='.'){///2222 if there is target cell next to the box 2222
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';          ///it will leave target
                my_map[row+1][column]='@';        ///player will go to the old place of the movable box
                my_map[row+2][column]='*';        ///movable box moved to target cell
                row=row+1;
                return 1;
        }
            else if(my_map[row][column]=='@'){       ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row+1][column]='@';
                my_map[row+2][column]='*';      ///movable box moved to target cell
                row=row+1;                      ///after movement it will be on target
                return 1;
        }
        }
    }

    else if (my_map[row+1][column]=='*'){////if there is a box right that is at target location)
        if(my_map[row+2][column]=='#'||my_map[row+2][column]=='$'){///if there is wall or another box next the box it is invalid movement
            return 0;
        }
        else if(my_map[row+2][column]==' '){///1111 if there is empty cell next to the box 1111
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';        ///it will leave target
                my_map[row+1][column]='+';      ///player will go to the old place of the movable box that was at target
                my_map[row+2][column]='$';      ///movable box moved to empty cell
                row=row+1; return 1;
                }
            else if(my_map[row][column]=='@'){   ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row+1][column]='+';      ///player will go to the old place of the movable box that was at target
                my_map[row+2][column]='$';      ///movable box moved to empty cell
                row=row+1; return 1;
                }
        }

        else if(my_map[row+2][column]=='.'){///2222 if there is target cell next to the box 2222
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='+';          ///it will leave target
                my_map[row+1][column]='+';        ///player will go to the old place of the box that was at target
                my_map[row+2][column]='*';        ///movable box moved to target cell
                row=row+1;
                return 1;
        }
            else if(my_map[row][column]=='@'){       ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row+1][column]='+';      ///after movement it will be on target
                my_map[row+2][column]='*';      ///movable box moved to target cell
                row=row+1;
                return 1;
        }
        return 1;
        }
    }

return 0;
}

bool Sokoban::move_left(){
    if (my_map[row][column-1]=='#'){///if there is block left
        return 0;}
    else if (my_map[row][column-1]==' '){////if there is space left
        if(my_map[row][column]=='+'){   ///check if player on target
            my_map[row][column]='.';        ///will leave target
            column=column-1;
            my_map[row][column]='@';        ///will be on space
            return 1;
            }
        else if(my_map[row][column]=='@'){   ///or not on target
            my_map[row][column]=' ';        ///will leave space
            column=column-1;
            my_map[row][column]='@';        ///will be on space
            return 1;
            }
        return 1;
        }
    else if (my_map[row][column-1]=='.'){////if there is target left
        if(my_map[row][column]=='+'){   ///check if player on target
            my_map[row][column]='.';    ///it will leave target
            column=column-1;
            my_map[row][column]='+';    ///and will be on target
            return 1;
        }
        else if(my_map[row][column]=='@'){    ///or player not on target
            my_map[row][column]=' ';    ///it will leave empty space
            column=column-1;
            my_map[row][column]='+';    ///after movement it will be on target
            return 1;
        }
        return 1;
    }

    else if (my_map[row][column-1]=='$'){////if there is movable box left (not at target location)
        if(my_map[row][column-2]=='#'||my_map[row][column-2]=='$'){///if there is wall or another box next the box it is invalid movement
            return 0;
        }
        else if(my_map[row][column-2]==' '){///1111 if there is empty cell next to the box 1111
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';        ///it will leave target
                my_map[row][column-1]='@';      ///player will go to the old place of the movable box
                my_map[row][column-2]='$';      ///movable box moved to empty cell
                column=column-1;return 1;
        }
            else if(my_map[row][column]=='@'){   ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row][column-1]='@';
                my_map[row][column-2]='$';      ///movable box moved to empty cell
                column=column-1;                     ///after movement it will be on target
                return 1;
        }
        }

        else if(my_map[row][column-2]=='.'){///2222 if there is target cell next to the box 2222
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';          ///it will leave target
                my_map[row][column-1]='@';        ///player will go to the old place of the movable box
                my_map[row][column-2]='*';        ///movable box moved to target cell
                column=column-1;
                return 1;
        }
            else if(my_map[row][column]=='@'){       ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row][column-1]='@';
                my_map[row][column-2]='*';      ///movable box moved to target cell
                column=column-1;                     ///after movement it will be on target
                return 1;
        }
        }
    }

    else if (my_map[row][column-1]=='*'){////if there is a box left that is at target location)
        if(my_map[row][column-2]=='#'||my_map[row+2][column]=='$'){///if there is wall or another box next the box it is invalid movement
            return 0;
        }
        else if(my_map[row][column-2]==' '){///1111 if there is empty cell next to the box 1111
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='.';        ///it will leave target
                my_map[row][column-1]='+';      ///player will go to the old place of the movable box that was at target
                my_map[row][column-2]='$';      ///movable box moved to empty cell
                column=column-1;
                return 1;
        }
            else if(my_map[row][column]=='@'){   ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row][column-1]='+';      ///player will go to the old place of the movable box that was at target
                my_map[row][column-2]='$';      ///movable box moved to empty cell
                column=column-1;
                return 1;
        }
        }

        else if(my_map[row][column-2]=='.'){///2222 if there is target cell next to the box 2222
            if(my_map[row][column]=='+'){   ///check if player on target
                my_map[row][column]='+';          ///it will leave target
                my_map[row][column-1]='+';        ///player will go to the old place of the box that was at target
                my_map[row][column-2]='*';        ///movable box moved to target cell
                column=column-1;
                return 1;
        }
            else if(my_map[row][column]=='@'){       ///or player not on target
                my_map[row][column]=' ';        ///it will leave empty space
                my_map[row][column-1]='+';      ///after movement it will be on target
                my_map[row][column-2]='*';      ///movable box moved to target cell
                column=column-1;
                return 1;
        }
        }
    }

return 0;
}

bool Sokoban::is_solved()const{
for(int i=0; i<row_number; i++){
    for(int j=0; j<column_number;j++){
        if (my_map[i][j]=='+'||my_map[i][j]=='.')//if there is any + or . that means that puzzle is not solved
            return 0;
    }
}
return 1;//else puzzle is solved
}
