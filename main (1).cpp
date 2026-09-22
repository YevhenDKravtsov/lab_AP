/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream> 
using namespace std; 
 
int main() 
{ 
    const double PI = 3.14; 
    double L, R, S; 
 
    cout << "Vvedit dovzhynu okruzhnosti L: "; 
    cin >> L; 
 
    R = L / (2 * PI); 
    S = PI * R * R; 
 
    cout << "Radius R = " << R << endl; 
    cout << "Ploshcha S = " << S << endl; 
 
    return 0; 
} 