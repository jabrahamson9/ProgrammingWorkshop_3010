#include <iostream>
#include <string>
#include "Point.h"
#include <vector>
using namespace std;

/**
 * JC Abrahamson
 * PE 1
 * This program creates three user generated points on a 2D
 * plane. It then translates and calculates euclidean distance 
 * between the points and displays its results to the user.
 */

int main(){
	std::vector<int> p1_vec = {2,6,3,10};
	std::vector<int> p2_vec = {-3,-7,6,6};
	std::vector<int> p3_vec = {8,4,-2,1};
    Point origin();
    Point p1(p1_vec);
    Point p2(p2_vec);
    Point p3(p3_vec);

    cout << "Point 1:(";
	for(unsigned int i = 0; i<p1.dimensions.size(); i++){
		if (i == p1.dimensions.size()-1){
			cout << to_string(p1.dimensions.at(i)) + ") #Dimensions = " + to_string(p1.NumberDim(p1)) << endl;
		}
		else{
			cout << to_string(p1.dimensions.at(i)) + ", ";
		}
	}
    cout << "Point 2:(";
	for(unsigned int i = 0; i<p2.dimensions.size(); i++){
		if (i == p2.dimensions.size()-1){
			cout << to_string(p2.dimensions.at(i)) + ") #Dimensions = " + to_string(p2.NumberDim(p2)) << endl;
		}
		else{
			cout << to_string(p2.dimensions.at(i)) + ", ";
		}
	}
    cout << "Point 3:(";
	for(unsigned int i = 0; i<p3.dimensions.size(); i++){
		if (i == p3.dimensions.size()-1){
			cout << to_string(p3.dimensions.at(i)) + ") #Dimensions = " + to_string(p3.NumberDim(p3)) << endl << endl;
		}
		else{
			cout << to_string(p3.dimensions.at(i)) + ", ";
		}
	}

    int dis12 = p1.Distance(p1, p2);
    cout << "Distance between points 1 & 2: " + to_string(dis12) << endl;
    int dis13 = p1.Distance(p1, p3);
    cout << "Distance between points 1 & 3: " + to_string(dis13) << endl;
    int dis23 = p2.Distance(p2, p3);
    cout << "Distance between points 2 & 3: " + to_string(dis23) << endl << endl;
    
	p1.Translate(p1, 4);
    cout << "Point 1 Translated +4 units: (";
	for(unsigned int i = 0; i<p1.dimensions.size(); i++){
		if (i ==p1.dimensions.size()-1){
			cout << to_string(p1.dimensions[i]) + ')' << endl;
		}
		else{
			cout << to_string(p1.dimensions[i]) + ", ";
		}
	}
    dis12 = p1.Distance(p1, p2);
    cout << "Distance between points 1 & 2: " + to_string(dis12) << endl;
	dis13 = p1.Distance(p1, p3);
    cout << "Distance between points 1 & 3: " + to_string(dis13) << endl;
    dis23 = p2.Distance(p2, p3);
    cout << "Distance between points 2 & 3: " + to_string(dis23) << endl << endl;


	p1.Translate(p1, -8);
    cout << "Point 1 Now Translated -8 units: (";
	for(unsigned int i = 0; i<p1.dimensions.size(); i++){
		if (i == p1.dimensions.size()-1){
			cout << to_string(p1.dimensions[i]) + ')' << endl;
		}
		else{
			cout << to_string(p1.dimensions[i]) + ", ";
		}
	}
    dis12 = p1.Distance(p1, p2);
    cout << "Distance between points 1 & 2: " + to_string(dis12) << endl;
	dis13 = p1.Distance(p1, p3);
    cout << "Distance between points 1 & 3: " + to_string(dis13) << endl;
    dis23 = p2.Distance(p2, p3);
    cout << "Distance between points 2 & 3: " + to_string(dis23) << endl << endl;

	int get_dim = p3.GetDims(3);
	cout << "Test of getter function:" << endl;
	cout << "Get the 4th dimension (index = 3) @ Point 3   =" +
			to_string(get_dim) << endl;

    return 0;
}   