#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int xf,yf,xi,yi,vi,r1,r2;
    float max_alc,dist_perc,dist_fi;
    while(cin >> xf >> yf >> xi >> yi >> vi >> r1 >> r2)
    {

        max_alc = r1+r2;
        dist_perc = 1.5*vi;

        dist_fi = sqrt(pow(xf-xi,2) + pow(yf-yi,2));
        dist_fi += dist_perc;

        if(max_alc >= dist_fi){
            cout << 'Y' << endl;
        }
        else
        {
            cout << 'N' << endl;
        }
    }
    return 0 ;
}
