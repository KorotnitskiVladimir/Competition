#include <iostream>
#include "Competition.h"
using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int c, o;
    cout << "Welcome to competition simulation" << endl;
    cout << "Please enter number of participants and number of obstacles ->" << endl;
    cin >> c >> o;
    if (c>0 && o>0)
    {
        Competition comp;
        comp.c = c;
        comp.o = o;
        comp.initCompetition();
    }
    else
        cout << "number of participants and/or obstacles can't be less or equal to zero" << endl;
    
    return 0;
}
