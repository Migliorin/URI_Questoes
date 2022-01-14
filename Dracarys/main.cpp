#include <iostream>

using namespace std;
 
int main() {
    int vect[4];

    for (int itr = 0; itr < 4; itr++)
    {
        cin >> vect[itr];
        
    }

    
    int e = min(vect[0], vect[1]);
    int f = min(vect[2], vect[3]);
       
    e += f;
    int g = min(max(vect[0], vect[1]), max(vect[2], vect[3]));
    
    int h = min(e, g);
    
    cout << h * h << "\n";

    return 0;
}
