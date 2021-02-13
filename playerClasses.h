#pragma once
#include<iostream>
#include <string>
using namespace std;

#ifndef playerClasses_h
#define playerClasses_h
//create two classes where players can enter their name, choose which marker to play with, and play on the board.

class player {
	//public access to variables
private:
	// create variables to hold players names and markers
	string playerName1 = " ";
	string playerName2 = " ";
	
	
	// public members
public:
	//member function definitions
	string getplayer1Name()const;
	void setplayer1Name(string);
	char getPlay1Marker()const;

	void setPlay1and2Marker(char, char);
		

	string getplayer2Name()const;
	void setplayer2Name(string);
	char getPlay2Marker()const;
	
	//create variables to hold the x or o
	char marker1;
	char marker2;
};
//member function: get and set functions for players names and marker
string player::getplayer1Name() const
{
	return playerName1;
}

void player::setplayer1Name(string s)
{
	if (s.length() == 0)
		playerName1 = "No name assigned";
	else
		playerName1 = s;
}

string player::getplayer2Name() const
{
	return playerName2;
}

void player::setplayer2Name(string s)
{
	if (s.length() == 0)
		playerName2 = "No name assigned";
	else
		playerName2 = s;
}
//end of player name functions

char player::getPlay1Marker() const {
	return marker1;
}
char player::getPlay2Marker()const {
	return marker2;
}


//create one member function to ask player 1, 'x' or 'o' and set both players markers
void player::setPlay1and2Marker(char marker1, char marker2)  {
	cout << playerName1 + " , would you like to be 'x' or 'o' ?" << endl;
	//if statment that checks if player 1 entered a capital or lowercase x and if so, set marker 1 to x
	if (marker1 = "x" || "X") {

		marker1 == 'x';
		//if marker equals capital or lowercase o then it sets marker 1 to o
	}
	else if (marker1 = "o" || "O") {

		marker1 == 'o';

	}
	// else statment to ensure the user enters either an x or an o, and if not send an error message
	else {

		while (marker1 != 'x' && marker1 != 'X' && marker1 != 'o' && marker1 != 'O') {
			cout << "Not a valid choice" << endl;
			cout << "Enter 'x' or 'o' " << endl;
			cin >> marker1;
		}
	}
	
	// seperate if statment that sets the opposite of whatever player 1 chose, as marker2
		if (marker1 = "x" || "X") {
		marker2 == 'o';

		}
		else if (marker1 = "o" || "O") {
			marker2 == 'x';
		}

	
#endif		
};

