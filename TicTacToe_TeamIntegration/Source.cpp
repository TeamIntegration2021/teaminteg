
#include <iomanip>
#include <iostream>
#include <string>
#include "playerClass.h"

//Variable Declaration for the positions on the board
using namespace std;
char board[9] =  {'1','2','3','4','5','6','7','8','9'}; //Array to hold the marker spots on the board
int choice; // variable to hold player choice of board position
string p1name;
string p2name;
player player1;
player player2;
char markChoice; // variable to hold player 1's mark choice at beginning of game
char turn; // variable to hold turn of current player
int turnCount = 0; // variable to record the number of turns used



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
//Add bool function to decide if the game is over
bool gameIsOver()
{
    for (int i = 0; i < 9; i++)
    {
        //If statement to check for and vertical or horizontal wins
        if (((i==0 || i==3 || i==6) && (board[i] == board[i + 1] && board[i] == board[i + 2])) || 
            ((i == 1 || i == 4 || i == 7) && (board[i] == board[i + 1] && board[i] == board[i - 1])) ||
            ((i == 2 || i == 5 || i == 8) && (board[i] == board[i - 1] && board[i] == board[i - 2])) ||
            ((i == 0 || i == 1 || i == 2) && (board[i] == board[i + 3] && board[i] == board[i + 6])) ||
            ((i == 3 || i == 4 || i == 5) && (board[i] == board[i - 3] && board[i] == board[i + 3])) ||
            ((i == 6 || i == 7 || i == 8) && (board[i] == board[i - 3] && board[i] == board[i - 6])))
        {
            if (board[i] == player1.getPlay1Marker()) //checks to see if player 1 won the game
            {
                
                cout << player1.getplayer1Name() << " you are the winner!!! Congratulations" << endl;
                return true;
               
            }
            else //Returns player 2 as winner if there are 3 in a row and player  did not win
            {
                    cout << player2.getplayer2Name() << " you are the winner!!! Congratulations" << endl;
                    return true;
                    
            }
            exit(0);
        }
        //else if to check for diagonal wins
        else if (( board[0] == board[4] && board[0] == board[8]) || (board[2] == board[4] && board[2] == board[6]))
        { 
            if (board[4] == player1.getPlay1Marker()) //checks to see if player 1 won the game
            {
                cout <<player1.getplayer1Name() << " you are the winner!!! Congratulations" << endl;
                return true;
               
            }
            else //Returns player 2 as winner if there are 3 in a row and player  did not win
            {
                
                cout << player2.getplayer2Name() << " you are the winner!!! Congratulations" << endl;
                return true;
                
            }
            exit(0);
        }
        //else if to check for draws
        else if (turnCount == 9)
        {
            
            cout << "Nobody wins!!! It is a draw" << endl;
            return true;
            exit(0);
            
        }

        //Else statement to verify game is over
        else
        {
            return false;
        }

    }
}
void playerTurn() 
{
    while (gameIsOver() == false)
    {
        if (turn == player1.getPlay1Marker()) //checks to see if it is player 1's turn and ask for a choice selection if true
        {
            cout << player1.getplayer1Name()
                << " it is your turn. Please enter a number corresponding to the spot on the board you would like to mark and press enter : ";
            cin >> choice; // User selects spot on the board they would like to mark
            while (board[choice - 1] == 'X' || board[choice - 1] == 'O') // checks if the spot on the board is taken
            {
                cout << "I am sorry that spot is already taken. Please choose an open spot on the board" << endl;
                cin >> choice;
            }
            board[choice - 1] = player1.getPlay1Marker(); //marks spot on board for the player
            turnCount++; //updates turn count
            turn = player2.getPlay2Marker(); //switches turn to player 2 after player 1's selction
            showBoard(); // displays updated game board
            playerTurn();


        }
        else if (turn == player2.getPlay2Marker()) //checks to see if it is player 2's turn and ask for a choice selection if true
        {
            cout << player2.getplayer2Name()
                << " it is your turn. Please enter a number corresponding to the spot on the board you would like to mark and press enter : ";
            cin >> choice; // User selects spot on the board they would like to mark
            while (board[choice - 1] == 'X' || board[choice - 1] == 'O')  // checks if the spot on the board is taken
            {
                cout << "I am sorry that spot is already taken. Please choose an open spot on the board" << endl;
                cin >> choice;
            }
            board[choice - 1] = player2.getPlay2Marker(); //marks spot on board for the player
            turnCount++; //updates turn count
            turn = player1.getPlay1Marker(); //switches turn to player 1 after player 2's selction
            showBoard(); // displays updated gameboard
            playerTurn();
        }
    }
   

}

int main()
{
    cout << "Player 1, what is your name? ";
    cin >> p1name; //Takes input for player 1's name
    cout << endl;
    player1.setplayer1Name(p1name); //Sets player 1's name
    cout << "Player 2, what is your name?";
    cin >> p2name; //Takes input for player 2's name
    cout << endl;
    player2.setplayer2Name(p2name); // Sets player 2's name
  
    cout << player1.getplayer1Name() << " would you like to be the X marker? (Enter Y for X or N if you would like to be the O marker):";
    cin >> markChoice;
    while (markChoice != 'y' && markChoice != 'Y' && markChoice != 'N' && markChoice != 'n')
    {
        cout << "Invalid choice! Please try again." << endl;
        cout << player1.getplayer1Name() << " would you like to be the X marker? (Enter Y for X or N if you would like to be the O marker):";
        cin >> markChoice;
    }
    if (markChoice == 'Y' || markChoice == 'y')
    {
        player1.setPlay1Marker('X'); //Set player 1 marker to x if he chooses yes and player 2's marker to o
        player2.setPlay2Marker('O');
    }
    else
    {
        player1.setPlay1Marker('O'); //Set player 1 marker to o if he chooses no and player 2's marker to x
        player2.setPlay2Marker('X');
    }

    turn = player1.getPlay1Marker(); //Sets initial turn to player 1
    showBoard(); // Displays original gameboard
    playerTurn(); //Starts the game
    return 0;
  
}
