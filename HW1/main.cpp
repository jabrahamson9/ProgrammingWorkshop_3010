#include "Maze.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main(){  
    system("clear");
    cout << "Welcome to the Maze!" << endl;
    cout << "-----------    RULES    -----------" << endl;
    cout << "1. Type the given direction for each turn (right, left, up, down)" << endl;
    cout << "2. Avoid Enemies" << endl;
    cout << "3. You cant move onto a wall (coutns as a pass)" << endl;
    cout << "4. Collect treasure for points" << endl;
    cout << "-----------    GOAL     -----------" << endl;
    cout << "5. Reach exit without being attacked by an enemy!" << endl << endl;

    string name;
    cout << "Player Name: ";
    getline(cin, name); //get full line incase name has a space
    
    system("clear");
    Player* human = new Player(name, true); //create human player instance
    Maze mze; //intialize instance of Maze class
    mze.NewGame(human, 2); //Start new game with human
    
    Player* cur = human; //player instance whose turn it currently is
    //whole game in this loop until game over is true
    while(!mze.IsGameOver()) {
        cur = mze.GetNextPlayer();
        mze.TakeTurn(cur);
    }
    cout << name << ": " << human->get_points() << " points." << endl;
    cout << "Enemy_1: " << mze.GetEnemyScore(1) << " points." << endl;
    cout << "Enemy_2: " << mze.GetEnemyScore(2) << " points." << endl;
    cout << "Thank you for playing the maze!" << endl;
    return 0;
}