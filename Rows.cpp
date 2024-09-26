#include "Rows.h"

/* Constructor for a Rows class
// purpose: populates a row with zeros
// inputs - None
// ouputs - populated row */ 

Rows::Rows(){
    for (int i = 0; i < 9; i++){
        rowArray[i] = 0;
    }
}

Rows::Rows(int* myPopArray) { 
     for (int i = 0; i < 9; i++){
        rowArray[i] =  myPopArray[i];
     }
}


/* Function: selectDiff(). 
// purpose: get a user choice for the game's difficulty
// inputs: None
// outputs: an integer between 1-3 indicating the game's difficulty level
// where 1 is easy, 2 is medium, 3 is hard. */ 


int selectDiff() {
    int diffLevel = 0;
    cout << "Select difficulty level. For easy press 1, for medium press 2, and for hard press 3: ";
    cin >> diffLevel;
    while (!cin || diffLevel > 3 || diffLevel < 1) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid entry: For easy press 1, for medium press 2, and for hard press 3: ";
        cin >> diffLevel;
    }
    return diffLevel;
}




/* Grid constructor - 
// creates a grid of 9x9 soduku game correlates to the difficulty level chosen
// by the user 
// inputs - diffLevel - difficulty level chosen by the user
// output - populated grid */ 

Grid :: Grid (int diffLevel) {
    if (diffLevel == 1) { 
        int inputRow0[9] = {3, 8, 0, 0, 0, 1, 0, 0, 4};
        int inputRow1[9] = {0, 0, 2, 6, 0, 0, 0, 7, 0};
        int inputRow2[9] = {0, 0, 0, 4, 8, 7, 0, 0, 3};
        int inputRow3[9] = {0, 0, 0, 0, 4, 0, 2, 3, 9};
        int inputRow4[9] = {2, 0, 1, 0, 0, 0, 4, 0, 6};
        int inputRow5[9] = {4, 9, 5, 0, 6, 0, 0, 0, 0};
        int inputRow6[9] = {6, 0, 0, 8, 5, 4, 0, 0, 0};
        int inputRow7[9] = {0, 7, 0, 0, 0, 6, 8, 0, 0};
        int inputRow8[9] = {8, 0, 0, 7, 0, 0, 0, 9, 2};
        myGrid[0] = Rows(inputRow0);
        myGrid[1] = Rows(inputRow1);
        myGrid[2] = Rows(inputRow2);
        myGrid[3] = Rows(inputRow3);
        myGrid[4] = Rows(inputRow4);
        myGrid[5] = Rows(inputRow5);
        myGrid[6] = Rows(inputRow6);
        myGrid[7] = Rows(inputRow7);
        myGrid[8] = Rows(inputRow8);
    } else if (diffLevel == 2) { 
        int inputRow0[9] = {0, 4, 0, 0, 0, 1, 0, 0, 3};
        int inputRow1[9] = {0, 0, 0, 0, 5, 0, 0, 7, 9};
        int inputRow2[9] = {5, 6, 0, 0, 0, 2, 8, 0, 4};
        int inputRow3[9] = {1, 0, 0, 2, 7, 0, 0, 8, 0};
        int inputRow4[9] = {0, 8, 2, 0, 0, 0, 9, 6, 0};
        int inputRow5[9] = {0, 3, 0, 0, 1, 8, 0, 0, 7};
        int inputRow6[9] = {3, 0, 6, 1, 0, 0, 0, 9, 8};
        int inputRow7[9] = {4, 7, 0, 0, 8, 0, 0, 0, 0};
        int inputRow8[9] = {8, 0, 0, 5, 0, 0, 0, 4, 0};
        myGrid[0] = Rows(inputRow0);
        myGrid[1] = Rows(inputRow1);
        myGrid[2] = Rows(inputRow2);
        myGrid[3] = Rows(inputRow3);
        myGrid[4] = Rows(inputRow4);
        myGrid[5] = Rows(inputRow5);
        myGrid[6] = Rows(inputRow6);
        myGrid[7] = Rows(inputRow7);
        myGrid[8] = Rows(inputRow8);
        
    } else {
        int inputRow0[9] = {0, 6, 0, 0, 0, 1, 9, 0, 7};
        int inputRow1[9] = {1, 0, 0, 0, 0, 7, 2, 3, 0};
        int inputRow2[9] = {0, 8, 0, 0, 0, 0, 4, 0, 6};
        int inputRow3[9] = {0, 1, 8, 0, 0, 2, 0, 0, 4};
        int inputRow4[9] = {0, 7, 0, 0, 4, 0, 0, 9, 0};
        int inputRow5[9] = {9, 0, 0, 1, 0, 0, 7, 8, 0};
        int inputRow6[9] = {6, 0, 7, 0, 0, 0, 0, 4, 0};
        int inputRow7[9] = {0, 5, 1, 6, 0, 0, 0, 0, 9};
        int inputRow8[9] = {8, 0, 9, 3, 0, 0, 0, 2, 0};
        myGrid[0] = Rows(inputRow0);
        myGrid[1] = Rows(inputRow1);
        myGrid[2] = Rows(inputRow2);
        myGrid[3] = Rows(inputRow3);
        myGrid[4] = Rows(inputRow4);
        myGrid[5] = Rows(inputRow5);
        myGrid[6] = Rows(inputRow6);
        myGrid[7] = Rows(inputRow7);
        myGrid[8] = Rows(inputRow8);
    }
}


/* Function: operator <<  
// Purpose : Overloading the << operator to print a grid object
// Inputs: ouptut stream reference, grid reference
// outputs: output stream reference
// notes: N/A                                         */


ostream& operator<<(ostream &os, Grid &g){
    os << "   1 2 3  4 5 6  7 8 9 " << endl;
    os << "   - - -  - - -  - - - " << endl;
    int j = 0;
    for (int i = 0; i < 9; i++) {
        os << i+1 << "| ";
        g.myGrid[i].displayRow();
        cout << endl;
        j++;
        if (j % 3 == 0) 
            os << endl;
    }
    return os;
}


/* Grid constructor  
// Purpose : creating a grid 
// Inputs: 9 rows objects
// outputs: a Grid object
// notes: N/A                                         */


Grid :: Grid(Rows a,Rows b,Rows c,Rows d,Rows e,Rows f,Rows g,Rows h,Rows i) {
    myGrid[0] = a;
    myGrid[1] = b;
    myGrid[2] = c;
    myGrid[3] = d;
    myGrid[4] = e;
    myGrid[5] = f;
    myGrid[6] = g;
    myGrid[7] = h;
    myGrid[8] = i;
}

    
/* Functions: member function: displayRow()
// purpose: display the values stored in a row object (Array of integers)
// inputs - None
// ouputs - none.                                    */

void Rows::displayRow() { 
    for (int i = 0; i < 9; i++) {
         cout << rowArray[i] << " ";
      if (i == 2 || i == 5 || i == 8){
        cout << " ";
      }
    }
}


/* Function: createAnswerGrid() 
// Purpose : Creating an answer grid corresponding to the user's chosen difficulty level 
// Inputs: integer indicating difficulty level 
// outputs: A populated grid 
// notes: N/A                                         */

Grid createAnswerGrid(int diffLevel) { 
    Grid answerGrid(1);
    if (diffLevel == 1) {
        int inputRow0[9] = {3, 8, 7, 5, 2, 1, 9, 6, 4};
        int inputRow1[9] = {5, 4, 2, 6, 3, 9, 1, 7, 8};
        int inputRow2[9] = {9, 1, 6, 4, 8, 7, 5, 2, 3};
        int inputRow3[9] = {7, 6, 8, 1, 4, 5, 2, 3, 9};
        int inputRow4[9] = {2, 3, 1, 9, 7, 8, 4, 5, 6};
        int inputRow5[9] = {4, 9, 5, 3, 6, 2, 7, 8, 1};
        int inputRow6[9] = {6, 2, 9, 8, 5, 4, 3, 1, 7};
        int inputRow7[9] = {1, 7, 3, 2, 9, 6, 8, 4, 5};
        int inputRow8[9] = {8, 5, 4, 7, 1, 3, 6, 9, 2};


        Grid easy(inputRow0,inputRow1,inputRow2, inputRow3, inputRow4, inputRow5, inputRow6, inputRow7, inputRow8);
        answerGrid = easy;
        
    } else if (diffLevel == 2) { 
        int inputRow0[9] = {9, 4, 7, 8, 6, 1, 2, 5, 3};
        int inputRow1[9] = {2, 1, 8, 4, 5, 3, 6, 7, 9};
        int inputRow2[9] = {5, 6, 3, 7, 9, 2, 8, 1, 4};
        int inputRow3[9] = {1, 9, 4, 2, 7, 6, 3, 8, 5};
        int inputRow4[9] = {7, 8, 2, 3, 4, 5, 9, 6, 1};
        int inputRow5[9] = {6, 3, 5, 9, 1, 8, 4, 2, 7};
        int inputRow6[9] = {3, 5, 6, 1, 2, 4, 7, 9, 8};
        int inputRow7[9] = {4, 7, 1, 6, 8, 9, 5, 3, 2};
        int inputRow8[9] = {8, 2, 9, 5, 3, 7, 1, 4, 6};
        
        Grid medium(inputRow0,inputRow1,inputRow2, inputRow3, inputRow4, inputRow5, inputRow6, inputRow7, inputRow8);
        answerGrid = medium;
        
    } else if (diffLevel == 3) {
        int inputRow0[9] = {4, 6, 3, 2, 8, 1, 9, 5, 7};
        int inputRow1[9] = {1, 9, 5, 4, 6, 7, 2, 3, 8};
        int inputRow2[9] = {7, 8, 2, 5, 3, 9, 4, 1, 6};
        int inputRow3[9] = {5, 1, 8, 7, 9, 2, 3, 6, 4};
        int inputRow4[9] = {2, 7, 6, 8, 4, 3, 1, 9, 5};
        int inputRow5[9] = {9, 3, 4, 1, 5, 6, 7, 8, 2};
        int inputRow6[9] = {6, 2, 7, 9, 1, 8, 5, 4, 3};
        int inputRow7[9] = {3, 5, 1, 6, 2, 4, 8, 7, 9};
        int inputRow8[9] = {8, 4, 9, 3, 7, 5, 6, 2, 1};
        
        Grid hard(inputRow0,inputRow1,inputRow2, inputRow3, inputRow4, inputRow5, inputRow6, inputRow7, inputRow8);
        answerGrid = hard;
        
    }
    
    
    
    
    return answerGrid;
}

/* Function: setCorrect() 
// Purpose : sets a correct guess value in the grid
// Inputs: row number, column number, user's guess
// outputs: N/A
// notes: N/A                                         */



void Grid :: setCorrect(int row, int column, int guess){
        myGrid[row].rowArray[column] = guess;
}

/* Function: exitFunction() 
// Purpose : prints a message at the end of the game
// Inputs: N/A 
// outputs: N/A
// notes: N/A                                         */

void exitFunction(void){
    cout << "You have now exited the game"<< endl;
}

/* Function: getRowPositionChoice() 
// Purpose : gets users choice for row number which they would like to place their guess in 
// Inputs: N/A 
// outputs: row number to place guess
// notes: N/A                                         */

int getRowPositionChoice() { 
    int userChoice = 0;
    char test = '.';
    cout << "Hit q if you want to quit or any other key if you would like to continue " << endl;
    cin >> test;
    if (test == 'q'){
        exitFunction();
        exit(0);
    } 
    cout << "Choose the row number you would like to place your guess in: " << endl;
    cin >> userChoice;
    while (!cin || userChoice > 9 || userChoice < 1) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid entry: Pick a location between 1 to 9 " << endl;
        cin >> userChoice;
    }
    return userChoice;
    
}
/* Function: getColumnPositionChoice() 
// Purpose : gets users choice for column number which they would like to place their guess in 
// Inputs: N/A 
// outputs: column number to place guess
// notes: N/A                                         */


int getColumnPositionChoice() { 
    int userChoice = 0;
    cout << "Choose the column you would like to place you guess in: " << endl;
    cin >> userChoice; 
    while (!cin || userChoice > 9 || userChoice < 1) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid entry: Pick a location between 1 to 9 " << endl;
        cin >> userChoice;
    }
    return userChoice;
}

/* Function: guessValue() 
// Purpose : Getting an input for the number the user wants to guess (1-9)
// Inputs:N/A
// outputs: The user's guess
// notes: N/A                                         */


int getGuessValue () { 
    int userChoice = 0;
    cout << "Choose the number would like to place in the chosen position " << endl;
    cin >> userChoice; 
    while (!cin || userChoice > 9 || userChoice < 1) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid entry: Pick a number 1 to 9 " << endl;
        cin >> userChoice;
    }
    return userChoice;
}


/* Function: ifCorrect() 
// Purpose : checks for a correct / incorrect answer
// Inputs: a grid reference 
// outputs: boolean expression
// notes: N/A                                         */

bool Grid :: ifCorrect(Grid& playingGrid) { 
    bool returnStatement = false; 
    int row = getRowPositionChoice()-1;
    if (row == -1) { 
        exit(0);
    }
    int column = getColumnPositionChoice()-1;
    if (column == -1) { 
        exit(0);
    }
    int guessValue = 0;
    while (playingGrid.myGrid[row].rowArray[column] != 0) {
           cout << "You cannot change an existing value ://" << endl;
           cout << "Try to pick an empty spot" << endl;
           cout << playingGrid;
           row = getRowPositionChoice()-1;
           column = getColumnPositionChoice()-1;
    }
    if (playingGrid.myGrid[row].rowArray[column] == 0) {
        guessValue = getGuessValue();
        if (guessValue == myGrid[row].rowArray[column]) {
            returnStatement = true;
            playingGrid.setCorrect(row,column,guessValue);
        }
    } 
   return returnStatement;
}

/* Function: printFeedback() 
// Purpose : Displaying a message correlated to a correct / incorrect answer
// Inputs: a boolean value for correct/incorrect answer - to come from the ifCorrect() function 
// outputs: N/A
// notes: N/A                                         */

void printFeedback(bool correctOutput){
    string msg = "Incorrect, try again!";
    try {
        if(correctOutput == false) {
            throw msg;
        } else {
            cout << "Your choice is correct ";
            cout << "\342\230\272" << "\t" << endl;
        }
    }
    catch (string s) {
        cout << s << endl;
        // insert a crying face 
    }
}

/* Function: noZeros() 
// Purpose : Testing for zeros in the playing Soduku grid to see if the game is over or not
// Inputs: Grid reference 
// outputs: integer indicating the amount of integers in the grid
// notes: N/A                                                                                */

int noZeros(Grid& playingGrid) {
    int ifNumber = 0;
    int i = 0; 
    do {
        for(int j = 0; j < 9; j++){
            if(playingGrid.myGrid[i].rowArray[j] != 0){
                ifNumber++;
            }
        }
        i++;
    } while (i < 9);

    return ifNumber;
}

/* Function: startingDisplay() 
// Purpose : Displaying a message in the beginning of the game from a .txt file
// Inputs: N/A
// outputs: N/A
// notes: N/A                                         */

void startingDisplay() {
    ifstream fin("art.txt");
    string line1, line2, line3, line4, line5, line6, line7, line8, line9;
    string line10, line11, line12, line13;
    getline(fin, line1);
    getline(fin, line2);
    getline(fin, line3);
    getline(fin, line4);
    getline(fin, line5);
    getline(fin, line6);
    getline(fin, line7);
    getline(fin, line8);
    getline(fin, line9);
    getline(fin, line10);
    getline(fin, line11);
    getline(fin, line12);
    getline(fin, line13);
    cout << line1 << endl << line2 << endl << line3 << endl << line4 << endl;
    cout << line5 << endl << line6 << endl << line7 << endl << line8 << endl;
    cout << line9 << endl << line10 << endl << line11 << endl << line12 << endl;
    cout << line13 << endl;
    fin.close();
    cout << "                   ";
    cout << "Welcome to the game of Sudoku!" << endl;
}

/* Function: completionDisplay() 
// Purpose : Displaying a message at the end of the game from a .txt file
// Inputs: N/A
// outputs: N/A
// notes: N/A                                         */

void completionDisplay() {
    ifstream fin("art.txt");
    string line15, line16, line17, line18, line19, line20, line21, line22;
    getline(fin, line15);
    getline(fin, line16);
    getline(fin, line17);
    getline(fin, line18);
    getline(fin, line19);
    getline(fin, line20);
    getline(fin, line21);
    getline(fin, line22);
    cout << line15 << endl << line16 << endl << line17 << endl << line18 << endl;
    cout << line19 << line20 << endl << line21 << endl << line22;
    fin.close();
    cout << "Game ended!";
}


/* Function: playGame() 
// Purpose : Overloading the << operator to print a grid object
// Inputs: ouptut stream reference, grid reference
// outputs: output stream reference
// notes: N/A                                         */

void playGame() {
    char keepPlaying = 'y';
    int diffLevel = 0;
    bool ifCorrectOutput = false;
    int numOfNums = 0;
    startingDisplay();
    diffLevel = selectDiff();
    Grid answerGrid(createAnswerGrid(diffLevel));
    Grid playingGrid(diffLevel);
    cout << playingGrid;
    numOfNums = noZeros(playingGrid);
    while(numOfNums < 81) {
        ifCorrectOutput = answerGrid.ifCorrect(playingGrid);
        printFeedback(ifCorrectOutput);
        cout << playingGrid;
        numOfNums = noZeros(playingGrid);
    }
    
}









