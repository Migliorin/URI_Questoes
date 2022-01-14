#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string biits;
    int num_1 = 0;

    getline(cin,biits);

    for (int i = 0; i < biits.length(); i++)
    {
       if(biits[i] == '1'){
           num_1++;
       }
    }

    if(num_1 % 2 == 0){
        biits += '0';
    }
    else
    {
        biits += '1';
    }

    cout << biits << "\n";
    




    return 0;
}
