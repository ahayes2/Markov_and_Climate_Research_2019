// Starts with an initial state, use the transition matrix to 
// randomly choose the next state. 

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{

    int t = 1;
    int cur;
    int maxTime;
    double rnd;
    double P[3][3];
    
    P[0][0] = 0.2;
    P[1][0] = 0.1;
    P[2][0] = 0.7;
    P[0][1] = 0.3;
    P[1][1] = 0.6;
    P[2][1] = 0.1;
    P[0][2] = 0.5;
    P[1][2] = 0.3;
    P[2][2] = 0.2;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;

    cout << "Initial state: ";
    cin >> cur;
    cout << endl;

    cout << "Max time: ";
    cin >> maxTime;
    cout << endl;


    while(t <= maxTime)
    {
        rnd = rand() % 100;
        rnd = rnd / 100;
        cout << rnd << endl << endl;


        if(cur == 1)
        {
            if(rnd < P[0][0])
            {
                cur = 1;
            }
            else if(rnd >= P[0][0] && rnd < (P[0][0] + P[0][1]))
            {
                cur = 2;
            }
            else if(rnd >= (P[0][0] + P[0][1]) && rnd < (P[0][0] + P[0][1] + P[0][2]))
            {
                cur = 3;
            }
        } 

        else if(cur == 2)
        {
            if(rnd < P[1][0])
            {
                cur = 1;
            }
            else if(rnd >= P[1][0] && rnd < (P[1][0] + P[1][1]))
            {
                cur = 2;
            }
            else if(rnd >= (P[1][0] + P[1][1]) && rnd < (P[1][0] + P[1][1] + P[1][2]))
            {
                cur = 3;
            }
        } 

        else if(cur == 3)
        {
            if(rnd < P[2][0])
            {
                cur = 1;
            }
            else if(rnd >= P[2][0] && rnd < (P[2][0] + P[2][1]))
            {
                cur = 2;
            }
            else if(rnd >= (P[2][0] + P[2][1]) && rnd < (P[2][0] + P[2][1] + P[2][2]))
            {
                cur = 3;
            }
        } 

        cout << "State at time " << t << " is " << cur << "." << endl << endl;

        t++;
    }
    
    return 0;
}
