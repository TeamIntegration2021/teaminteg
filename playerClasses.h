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
void player::setPlay1Marker(char mark) {
	marker1 = mark;
}
void player::setPlay2Marker(char mark) {
	marker2 = mark;
}




	
#endif		


