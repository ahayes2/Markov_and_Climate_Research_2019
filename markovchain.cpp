// Starts with an initial state, use the transition matrix to 
// randomly choose the next state. 

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<array>
using namespace std;

int main()
{

    int t = 1;
    int cur;
    int next;
    int maxTime;
    double rnd;
    int size;
    double total;
    unsigned seed = time(0);
    srand(seed);
    ifstream inputFile;

    inputFile.open("data.txt");

    inputFile >> size;
    double P[size][size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            inputFile >> P[i][j]; 
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Size: " << size << endl << endl;
    inputFile >> cur;
    cout << "State: " << cur << endl << endl;
    inputFile >> maxTime;
    cout << "Max time: " <<maxTime << endl << endl;

    inputFile.close();

    while(t <= maxTime)
    {
        cout << "---- TIME STEP " << t << " ----" << endl << endl;
        rnd = (double) ((rand() % 10)*0.1);
        cout << "Random number: " << rnd << endl;
        cout << "Current state: " << cur << endl;

        for(int i = 0; i <= size; i++)
        {
            if((i + 1) == cur)
            {
                total = 0;
                for(int j = 0; j < size; j++)
                { 
                    if(rnd >= total && rnd <= (total + P[i][j]))
                    {
                        next = j + 1;
                        break;
                    }
                    else
                    {
                        total += P[i][j];
                    }
                        
                }    
            } 
        } 

        cout << "Next state: " << next << endl << endl;
        cur = next;
        t++;
    }
    
    return 0;
}
