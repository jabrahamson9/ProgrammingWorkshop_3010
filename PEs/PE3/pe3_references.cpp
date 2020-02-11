#include <iostream>
using namespace std;

// Name: JC Abrahamson
//

// Write any functions you need here!
class Person{
    public:
        // cunstructor to set private attributes
        Person (int h, int w){
            height = h;
            weight = w;
        }
        Person (){}
        //override + operator to be able to add objects together
        Person operator + (const Person& obj) { 
            Person p1; 
            p1.height = height + obj.height; 
            p1.weight = weight + obj.weight; 
            return p1; 
        } 
        //needed helper functions to access private attributes
        void PrintHeight(Person p){
            cout << p.height << endl;
        }
        void PrintWeight(Person p){
            cout << p.weight << endl;
        }
        // override the == operator to compare Person objects
        bool operator ==(const Person& p){
            if(height == p.height && weight == p.weight){
                return true;
            }
            return false;
        }
    private:
        int height;
        int weight;
};

//bass by pointer function
void pbp(int* n){
    cout <<"Pass By Pointer: " << *n << endl;
}
//pass by reference function
void pbr(int& n){
    cout <<"Pass By Reference: " << n << endl;
}
//sets a output variable int* equal to a const int parameter value
void foo(const int reference, int* n){
    *n = reference;
}


int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    int x = 5;
    cout << "Int: " << x << endl << endl;
    // 2) Declare a pointer to that int
    int *x_p = &x;
    // 3) Increment the int via the pointer
    (*x_p)++;
    // 4) Declare a reference to your int
    int &x_r = x;
    // 5) Increment the int via the reference
    x_r++;
    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: 
    x++;
    cout << "x= " << x << endl;
    cout << "Reference x_r: " << x_r << endl;
    cout << "Pointer *x_p: " << *x_p << endl << endl;
    //Answer: both the pointer and the reference are modified to see the change

    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: all variables will be modified to see the change

    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: all variables will be modified to see the change

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)
    
    // void pbp(int* n){
    //     cout <<"Pass By Pointer: " << &n << endl;
    // }
    pbp(&x);


    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer: No
    

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)
    // void pbr(int& n){
    //     cout <<"Pass By Reference: " << n << endl;
    // }
    pbr(x);

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: No

    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer: Yes

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.

    // void foo(const int reference, int* n){
    //     &n = reference;
    //     cout << n << endl;
    // }
    int n1 = 0;
    const int cn1 = 1;
    cout << endl << "const int cn1 = " << cn1 << endl;
    cout << "int* n1 = " << n1 << endl;
    foo(cn1, &n1); 
    cout << "Output Parameter n: " << n1 << endl;

    int n2 = -5;
    const int cn2 = 0;
    cout << endl << "const int cn2 = " << cn2 << endl;
    cout << "int* n2 = " << n2 << endl;
    foo(cn2, &n2); 
    cout << "Output Parameter n: " << n2 << endl;

    int n3 = 7;
    const int cn3 = -2;
    cout << endl << "const int cn3 = " << cn3 << endl;
    cout << "int* n3 = " << n3 << endl;
    foo(cn3, &n3); 
    cout << "Output Parameter n3: " << n3 << endl;


    // 15) What is/are the difference(s) between output parameters and return values?

    // Answer: Using a return value when you only need to return one item. Using output parameters when you need to return more than one value.


    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)

    // Answer:
    Person p1(6, 180);
    Person p2(5, 155);
    Person p3(6, 180);

    cout << "p1 height: "; 
    p1.PrintHeight(p1);
    cout << "p1 weight: ";
    p1.PrintWeight(p1);
    cout << "p2 height: "; 
    p2.PrintHeight(p2);
    cout << "p2 weight: ";
    p2.PrintWeight(p2);
    cout << "p3 height: "; 
    p3.PrintHeight(p3);
    cout << "p3 weight: ";
    p3.PrintWeight(p3);

    if(p1 == p3){
        cout << endl << "p1 and p3 are equal!" << endl << endl;
    }

    Person p4 = p1+ p2;
    cout << "p4 = p1 + p2" << endl;
    cout << "p4 height: "; 
    p4.PrintHeight(p4);
    cout << "p4 weight: ";
    p4.PrintWeight(p4);

}