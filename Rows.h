#ifndef ROWS_H
#define ROWS_H

#include <iostream>
#include <climits>
#include <string>
#include <fstream>
using namespace std;

class Rows{
    
public:
  int rowArray[9];
  Rows();
  Rows(int*);
  void displayRow();
};

class Grid {
protected:
    int rows = 9;
    int columns = 9;
public:
    Rows myGrid[9];
    Grid(int diffLevel);
    Grid(Rows a,Rows b,Rows c,Rows d,Rows e,Rows f,Rows g,Rows h,Rows i);
    ~Grid() {cout << "";}
    void setCorrect(int row, int column, int guess);
    Grid createAnswerGrid(int diffLevel);
    bool ifCorrect(Grid&);
    void printFeedback();
    void playGame();
    friend ostream& operator <<(ostream &os, Grid &g);
};


//required inheritance we did not need it in our code
class GridArea: public Grid {
public:
    int area() {return rows*columns;}
};

Grid createAnswerGrid(int diffLevel);
int  selectDiff();
int  getRowPositionChoice();
int  getColumnPositionChoice();
int  getGuessValue();
int* getUserGuess();
void playGame();
void printFeedback(bool);
int noZeros(Grid& playingGrid);



#endif 