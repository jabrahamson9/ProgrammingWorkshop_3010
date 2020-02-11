#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

struct Position {
	int row;
	int col;
	// already implemented for you!
	bool operator==(const Position &other) {
		return row == other.row && col == other.col;
	}
};

class Player {
public:
	Player(const string name, const bool is_human);  // constructor
	string get_name() const {return name_; }  // inline member function
	int get_points() const {return points_; }  // inline member function
	Position get_position() const {return pos_; }  // inline member function
	bool is_human() const {return is_human_; }  // inline member function
	// You MUST implement the following functions
	void ChangePoints(const int x);  
	void SetPosition(Position pos); // set a new position for this player
	string ToRelativePosition(Position other); // returns a string direction of a position relative to the current (makes it so i dont need to override operator)
	string Stringify(); //creates string with the Player name and their points
private:
	string name_;
	int points_;
	Position pos_;
	bool is_human_; //human or enemy
}; // class Player

#endif  // PLAYER_H
