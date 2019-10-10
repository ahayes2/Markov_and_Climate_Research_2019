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
    int cur; // current state
    int nex; // next state
    int maxTime;
    int n;
    double rnd; 
    int s;
    double total;
    unsigned seed = time(0);
    srand(seed);
    ifstream inputFile;

    inputFile.open("data2.txt");

    inputFile >> n;

    // allocate transition matrix
    double** P = new double*[n];
    for(int iii = 0; iii < n; ++iii)
    {
        P[iii] = new double[n];
    }
    
    // allocate current transition probabilities according to current state
    double* curP = new double[n];
    
    //input transition matrix from data
    for(int ii = 0; ii < n; ii++)
    {
        for(int jj = 0; jj < n; jj++)
        {
            inputFile >> P[ii][jj]; 
            cout << P[ii][jj] << " ";
        }
        cout << endl;
    }

    cout << "Size: " << n << endl;
    inputFile >> cur;
    cout << "State: " << cur << endl;
    inputFile >> maxTime;
    cout << "Max time: " << maxTime << endl << endl;

    inputFile.close();
    
    //allocate for tracking state of process over all timesteps
    int* X = new int[maxTime+1];
    X[0] = cur;
    
    //allocate for getting percentage of tiemsteps in each state, and set all to zero
    int* statePerc = new int[n];
    for (int j = 0; j < n; j++)
    {
        statePerc[j] = 0; 
    }
        
    while(t <= maxTime)
    {
        
        rnd = (double) ((rand() % 10000)*0.0001);
        cout << "Random number: " << rnd << endl;

        for(int i = 1; i <= n; i++)
        {
            if(cur == i)
            {
                total = P[i-1][0];
                
                for(int m=0; m<n; m++){
                    curP[m] = P[i-1][m];
                }
                
                cout << "total: " << total << endl;
                
                cout << "curP: ";
                for(int ck = 0; ck < n; ck++){
                    cout << curP[ck] << " ";
                }
                cout << endl;
                
                if(rnd <= total)
                {
                    nex = 1;
                    cout << "went to state 1" << endl;
                }
                else
                {
                for(int j = 1; j < n; j++)
                {
                    if(rnd > total && rnd <= (total + P[i-1][j]))
                    {
                        nex = j + 1;
                        cout << "code break, went to state: " << nex << endl;
                        break;
                    }
                    
                    total = total + P[i-1][j];
                    cout << "no for loop break, total: " << total << endl;
                }
                
                
                }
            } 
            
        } 
        cur=nex;
        X[t] = cur;
        cout << "State at time " << t << " is " << cur << "." << endl << endl;

        t++;
    }
    
    //output complete list of states over time
    for (int i = 0; i <= maxTime; i++)
    {
        cout << X[i];
        for (int j = 0; j<n; j++)
        {
            if (X[i] == j + 1)
            {
                statePerc[j] = statePerc[j] + 1;
            }
        }
    }
    cout << endl << endl;
    
    //output counts in each state
    for (int j = 0; j<n; j++)
    {
        cout << "number of timesteps in state " << j + 1 << " is " << statePerc[j] << endl;
    }
    
    return 0;
}