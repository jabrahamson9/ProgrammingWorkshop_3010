#include <iostream>
#include "Maze.h"
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

// __________________________ Board Class _____________________________
/**
 * Board class constructor to initalize random function, a position at (0,0) and a blank boad of size (4,4)
 */
Board::Board(){
    //Initializing rand() function
    srand(time(NULL));
    Position pos;
    pos.row = 0;
    pos.col = 0;
    //Generating random board
    for(int i=0 ; i<4 ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            pos.row = i;
            pos.col = j;
            SetBoardValue(pos);
        }
    }
}

string SquareTypeStringify(SquareType sq){
    if(sq == SquareType::Wall){
        return " Wall ";
    }
    else if(sq == SquareType::Exit){
        return " Exit ";
    }
    else if(sq == SquareType::Human){
        return " Human ";
    }
    else if(sq == SquareType::Enemy){
        return " Clown ";
    }
    else if(sq == SquareType::Treasure){
        return " Treausure ";
    }
    else{
        return " Empty ";
    }
}

/**
 * Print board depending on each square type value
 */
void Board::PrintBoard(){
    for(int i=0 ; i<4 ; i++){
        for(int j=0 ; j<4 ; j++){
            if(arr_[i][j] == SquareType::Empty){
                cout << "  Empty   ";
            }
            else if(arr_[i][j] == SquareType::Wall){
                cout << "   Wall   ";
            }
            else if(arr_[i][j] == SquareType::Exit){
                cout << "   Exit   ";
            }
            else if(arr_[i][j] == SquareType::Human){
                cout << "  Human   ";
            }
            else if(arr_[i][j] == SquareType::Enemy){
                cout << "  Enemy   ";
            }
            else if(arr_[i][j] == SquareType::Treasure){
                cout << " Treasure ";
            }
        }
        cout << endl;
    }
}

/**
 * sets the sqare type value for a specified position
 * @param pos the position on the board to set a value for
 */
void Board::SetBoardValue(Position pos)
{
    int x = pos.row;
    int y = pos.col;
    //Human start is always at board_[0][0]
    if(x == 0 && y == 0){
        arr_[x][y] = SquareType::Human;
    }
    //Exit is always located at board_[3][3]
    else if(x==3 && y==3){
        arr_[x][y] = SquareType::Exit;
    }
    //Randomly generates the board with 10% chance for treasure and 20% chance for wall if position is a valid wall position
    //Otherwise set the square to empty
    else{
        int random_num = rand() % 100;
        //Treasure Placement
        if(random_num <= 10){
            arr_[x][y] = SquareType::Treasure;
        }
        //Wall Placement
        else if(random_num > 10 && random_num <= 30 && IsValidWall(pos) == true){
            arr_[x][y] = SquareType::Wall;
        }
        //Empty Placement
        else{
            arr_[x][y] = SquareType::Empty;
        }
    }
}

/**
 * Checks if a new position is a wall or enemy and is in the board frame
 * @param pos position to move to
 * @return bool of whether or not the pos offers a valid move
 */
bool Board::IsValidMove(Position pos){
    int x = pos.row;
    int y = pos.col;
    //position is in board frame
    if(x<0 || x>3 || y<0 || y>3){
        return false;
    }
    //check if position is either a wall or an enemy player
    else if(get_square_value(pos) == SquareType::Wall || get_square_value(pos) == SquareType::Enemy){
        return false;
    }
    //Valid move
    else{
        return true;
    }
}

/**
 * Check if a position offers a valid wall placement
 * @param pos position to check if space would be valid for a wall
 * @return bool of whether or not the pos offers a valid wall placement
 */
bool Board::IsValidWall(Position pos){
    //Case 1: no walls next to player
    if(pos.row==1 && pos.col==0){
        return false;
    }
    //Case 2: no walls next to player
    else if(pos.row==0 && pos.col==1){
        return false;
    }
    //Case 3: no walls next to exit
    else if(pos.row==3 && pos.col==2){
        return false;
    }
    //Case 4: no walls next to exit
    else if(pos.row==2 && pos.col==3){
        return false;
    }
    else{
        return true;
    }
}

/**
 * gets the sqaure type for a given position
 * @param pos position to check sqauretype
 * @return SquareType the type of square 
 */
SquareType Board::get_square_value(Position pos) const{
    return arr_[pos.row][pos.col];
}

/**
 * Set the Square type for a given position
 * @param pos position to set squaretype
 * @param value the Squaretype to set to the pos
 */
void Board::SetSquareValue(Position pos, SquareType value){
    arr_[pos.row][pos.col] = value;
}

/**
 * Update position of player 
 * @param pos updated position to move player to
 * @param *p a reference to the player to make changes to instance
 * @return true if move was successful false otherwise
 */
bool Board::MovePlayer(Player *p, Position pos){
    //Starting position of passed player, changing it to empty
    Position curr = p->get_position();
    SetSquareValue(curr,SquareType::Empty);
    //Updating position with passed position
    p->SetPosition(pos);
    //Human move
    if(IsValidMove(pos) && p->is_human()){
        SetSquareValue(pos, SquareType::Human);
    }
    //Enemy move
    else if(IsValidMove(pos) && !p->is_human()){
        SetSquareValue(pos, SquareType::Enemy);
    }
    //Invalid move
    else{
        //Treat case as attempt for human to run into human resulting in a pass
        if(p->is_human()){
            SetSquareValue(curr, SquareType::Human);
        }
        //Treat case as attempt for Enemy to run into Enemy resulting in a pass
        else{
            SetSquareValue(curr, SquareType::Enemy);
        }
    }
    return true;
}



// __________________________ Maze Class _____________________________
/**
 * Maze class constructor to set the total turn count to 0
 */
Maze::Maze(){
    turn_count_ =0;
}

/**
 * initialize a new game with a blank board
 * @param *human passes a human player as a reference so that the attributes could be updated
 * @param enemies the number of enemies in game
 */
void Maze::NewGame(Player *human, const int enemies){
    board_ = new Board(); //
    Position human_start;
    human_start.row = 0;
    human_start.col = 0;
    human->SetPosition(human_start);
    players_.push_back(human);
    
    //These two variables help add enemies in a diagnol column starting at board_[1][2]
    //They get incremented each time an enemy is added to palyers_ vector by 1 to create the diagnol pattern
    int row_tracker = 1;
    int col_tracker = 2;
    
    string enemyName;
    for(int i=0 ; i<enemies ; i++)
    {
        enemyName = "Enemy_" + to_string(i+1);
        Player* enem = new Player(enemyName,false);
        
        Position enemyStart;
        enemyStart.row = row_tracker;
        row_tracker++;
        enemyStart.col = col_tracker;
        col_tracker++;
        
        enem->SetPosition(enemyStart);
        board_->SetSquareValue(enemyStart,SquareType::Enemy);

        players_.push_back(enem);
    }
    cout << "    BEGIN" << endl;
    board_->PrintBoard();
}

/**
 * displays valid moves for the player's turn
 * @param *p reference to player to update attributes
 */
void Maze::TakeTurn(Player* p){
    //Store valid moves in a vector
    vector<Position> p_moves = board_->Board::GetMoves(p); 
    string move_input;
    cout << p -> get_name() << " can move: " << board_ -> Board::GetMovesStr() << endl;
    //get the users move input
    getline(cin, move_input);
    //make input lower case for easy comparison
    for(unsigned int i=0 ; i < move_input.length() ; i++){
        move_input[i] = tolower(move_input[i]);
    }
    //Move options
    if(move_input=="right" || move_input=="left" || move_input=="down" || move_input=="up" || move_input=="pass"){
        DetectCollision(p,move_input); //
    }
    //Gives them one chance to fix move_input, most people will correct error after seeing it
    else{
        cout << "INVALID MOVE" << endl;
        cout << "Try again: ";
        getline(cin,move_input);
        system("clear");
        if(move_input=="right" || move_input=="left" || move_input=="down" || move_input=="up" || move_input=="pass"){
            DetectCollision(p,move_input); //execute move
        }
    }
    turn_count_++;
}

/**
 * execute move by calling MovePlayer and check if new position results in
 * a collision and produce the outcome appropriately
 * @param *p reference to player to update attributes
 * @param dir string dir as a user input to move player in that dir
 */
void Maze::DetectCollision(Player* p, string dir){
    Position new_pos;
    //Current player's position
    Position current = p -> get_position();
    //Translates the given dir into a position
    if(dir=="right"){
        new_pos.row = current.row;
        new_pos.col = current.col + 1;
    }
    else if(dir=="left"){
        new_pos.row = current.row;
        new_pos.col = current.col - 1;
    }
    else if(dir=="down"){
        new_pos.row = current.row + 1;
        new_pos.col = current.col;
    }
    else if(dir=="up"){
        new_pos.row = current.row - 1;
        new_pos.col = current.col;
    }
    //Checking for out of bounds on new position just calculated
    if(new_pos.row < 0 || new_pos.row > 3 || new_pos.col < 0 || new_pos.col > 3){
        system("clear");
        cout << "Sorry move out of bounds!" << endl;
        board_ -> PrintBoard();
        return;
    }
    //get square type of the new position for evaluation
    SquareType collision_type = board_ -> get_square_value(new_pos);
    //Human's turn
    if(p -> is_human()){
        //Collide with enemy
        if(collision_type == SquareType::Enemy){
            board_ -> SetSquareValue(p->get_position(), SquareType::Empty);
            system("clear");
            board_ -> PrintBoard(); //print updated board
            cout << "Enemy killed you! GAME OVER" << endl;
        }
        //Collide with treasure
        else if(collision_type == SquareType::Treasure){
            board_ -> MovePlayer(p, new_pos);
            system("clear");
            cout << p -> get_name() << " collected a Treasure! +100 points" << endl;
            board_ -> PrintBoard(); //print updated board
            p -> ChangePoints(100); //add 100 points to player's points
        }
        //Collide with exit square
        else if(collision_type == SquareType::Exit){
            board_ -> MovePlayer(p, new_pos);
            system("clear");
            board_ -> PrintBoard(); //print updated board
            cout << "CONGRATULATIONS YOU WIN!" << endl;
        }
        //Collision with wall
        else if(collision_type == SquareType::Wall){
            system("clear");
            cout << p -> get_name() << " ran into the wall..." << endl;
            board_ -> PrintBoard(); //no change to board
        }
        //Moving to empty square
        else{
            board_ -> MovePlayer(p,new_pos);
            system("clear");
            cout << p -> get_name() << " moved to an empty square" << endl;
            board_ -> PrintBoard();  //print updated board
        }
    }
    //Enemy's turn
    else{
        //Enemy collide with human
        if(collision_type == SquareType::Human){
            board_ -> MovePlayer(p, new_pos);
            system("clear");
            board_ -> PrintBoard(); //print updated board
            cout << "Enemy killed you! GAME OVER" << endl;
        }
        //Enemy collide with treasure
        else if(collision_type==SquareType::Treasure){
            board_ -> MovePlayer(p,new_pos);
            system("clear");
            cout << p -> get_name() << " collected a Treasure! +100 points" << endl;
            board_ -> PrintBoard(); //print updated board
            p -> ChangePoints(100);
        }
        //Enemy collide with exit square
        else if(collision_type == SquareType::Exit){
            system("clear");
            cout << "Enemy can not leave!" << endl;
            board_ -> PrintBoard(); //print unchanged board
        }
        //Enemy collide with other enemy
        else if(collision_type == SquareType::Enemy){
            system("clear");
            cout << "Enemies ran into eachother! No move" << endl;
            board_ -> PrintBoard(); //print unchanged board
        }
        //Enemy collide with Wall
        else if(collision_type==SquareType::Wall){
            system("clear");
            cout << p -> get_name() << " ran into a wall..." << endl;
            board_ -> PrintBoard(); //print unchanged board
        }
        //Enemy collide with empty space
        else{
            board_ -> MovePlayer(p, new_pos); //move player to new position
            system("clear");
            cout << p -> get_name() << " moved to an empty square" << endl;
            board_->PrintBoard();  //print updated board
        }
    }
}

/**
 * Returns the score of the enemy
 * @param enemy_index reference to enemy player id
 * @return Enemy points
 */
int Maze::GetEnemyScore(int enemy_array_index){
    return players_[enemy_array_index] -> get_points();
}

/**
 * Calculates the next player up in turn by keeping track of turn count
 * @return the player whos turn it is
 */
Player* Maze::GetNextPlayer(){
    int num_players = players_.size();
    int turn = turn_count_ % num_players; //it will always be 0,1,2 since we are dividing by 3
    Player* p = players_[turn]; //sets player turn
    return p;
}

/**
 * Checks if the game is over
 * @return true if game is over and false if not
 */
bool Maze::IsGameOver(){
    if(board_ -> GetExitOccupant() == SquareType::Human){
        return true;
    }
    else if(players_[0] -> get_position() == players_[1] -> get_position() || players_[0] -> get_position() == players_[2] -> get_position()){
        return true; //human has been destroyed by Enemy
    }
    else{
        return false; //game continues
    }
}

/**
 * method that gets the moves_string_ attribute
 * @return the private string moves_string_
 */
string Board::GetMovesStr(){
    return moves_string_;
}

/**
 * Calculates the possible moves, given a player
 * @param p a player to calculate possible moves for
 * @return vector of possible moves
 */
vector<Position> Board::GetMoves(Player* p){
    //Calculates the adjacent positions
    int cur_row = p -> get_position().row;
    int cur_col = p -> get_position().col;
    int to_right = p -> get_position().col+1;
    int to_left = p -> get_position().col-1;
    int to_down = p -> get_position().row+1;
    int to_up = p -> get_position().row-1;
    vector<Position> possible_moves;
    //Initialize instances Position struct to make vector of possible_moves
    Position right_vector;
    right_vector.row = cur_row;
    right_vector.col = to_right;
    Position left_vector;
    left_vector.row = cur_row;
    left_vector.col = to_left;
    Position up_vector;
    up_vector.row = to_up;
    up_vector.col = cur_col;
    Position down_vector;
    down_vector.row = to_down;
    down_vector.col = cur_col;
    //String to print out possible moves to player
    moves_string_ = "";
    //Check to make sure moves are valid
    if(IsValidMove(up_vector)){
        possible_moves.push_back(up_vector);
        moves_string_ += " UP ";
    }
    if(IsValidMove(down_vector)){
        possible_moves.push_back(down_vector);
        moves_string_ += " DOWN ";
    }
    if(IsValidMove(right_vector)){
        possible_moves.push_back(right_vector);
        moves_string_ += " RIGHT ";
    }
    if(IsValidMove(left_vector)){
        possible_moves.push_back(left_vector);
        moves_string_ += " LEFT ";
    }
    return possible_moves;
}

/**
 * get the exit position on board array
 * @return position of exit square
 */
SquareType Board::GetExitOccupant(){
    return arr_[3][3];
}