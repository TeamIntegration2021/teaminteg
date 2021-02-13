
#include <iomanip>
#include <iostream>
#include <string>
//Variable Declaration for the positions on the board
using namespace std;
char board[9] =  {'1','2','3','4','5','6','7','8','9'};
int choice;



void showBoard() {

    // Creates Game board layout

    cout << "TIC TAC TOE BOARD" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout <<"  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << " " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << " " << endl;
    cout << "     |     |     " << endl;
}
int main()
{
    //function calls to test the board to see if it is working
    showBoard(); //Displays original board at start of game with no spots filled yet
    cout << "Please enter a number corresponding to the spot on the board you would like to mark and press enter:";
    cin >> choice; // User selects spot on the board they would like to mark
    board[choice-1] = 'X'; //Fills correspond spot with player mark, will change to call each player's mark after player classes are created
    showBoard(); // Displays updated board with player mark denoted
}