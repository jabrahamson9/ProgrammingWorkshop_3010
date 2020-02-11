#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

// std::vector<std::string> CreateBoard(){
//     std::vector<std::vector<std::string>> board[3][3];
//     std::string init = "EMPTY";
//     for (int i = 0; i < 3; i++) { 
//         for (int j = 0; j < 3; j++){
//             std::cout << board[i][j] << "|";
//         }
//     }
//     return board;
// }

std::vector<std::vector<char>> CreateBoard(){
    int n = 3; 
    int m = 3; 
    std::vector<std::vector<char> > vec( n , std::vector<char> (m, '-'));  
    return vec;
}

void DisplayBoard(std::vector<std::vector<char>> vec){
    for(int i = 0; i < vec[0].size(); i++) {
        cout<< "|";
        for (int j = 0; j < vec[0].size(); j++){ 
            std::cout<< vec[i][j]<< "|"; 
        } 
        cout<< "\n"; 
    } 
}

string GetPlayerChoice(){
    cout << "WHERE WOULD YOU LIKE TO PLAY: " << endl;
    cout << "TL | TM | TR" << endl;
    cout << "CL | CM | CR" << endl;
    cout << "BL | BM | BR" << endl << endl;
    string choice = "";
    getline(cin, choice);
    int i = 0;
    char c;
    while(choice[i]){
        c = choice[i];
        choice[i] = (toupper(c));
        i++;
    }
    return choice;
}

std::vector<std::vector<char>> PlaceMarker(std::vector<std::vector<char> > vec, string location, int marker){
    if(location == "TL"){vec[0][0] = marker;}
    if(location == "TM"){vec[0][1] = marker;}
    if(location == "TR"){vec[0][2] = marker;}
    if(location == "CL"){vec[1][0] = marker;}
    if(location == "CM"){vec[1][1] = marker;}
    if(location == "CR"){vec[1][2] = marker;}
    if(location == "BL"){vec[2][0] = marker;}
    if(location == "BM"){vec[2][1] = marker;}
    if(location == "BR"){vec[2][2] = marker;}
    return vec;
}


int main(){
    std::vector<std::vector<char>> vec = CreateBoard();
    DisplayBoard(vec);
    string user_choice = GetPlayerChoice();
    char marker_char;
    cout << "Which Player Are You (X or O): " << endl;
    cin >> marker_char;
    int player = int(marker_char);
    vec = PlaceMarker(vec, user_choice, player);
    DisplayBoard(vec);
    return 0;
}

