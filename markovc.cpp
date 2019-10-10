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
    int maxTime;
    double rnd;
    int size;
    //double P[size][size];
    int s;
    double total;
    unsigned seed = time(0);
    srand(seed);
    ifstream inputFile;

    inputFile.open("data.txt");

    inputFile >> size;


    double P[size][size];
    for(int ii = 0; ii < size; ii++)
    {
        for(int jj = 0; jj < size; jj++)
        {
            inputFile >> P[ii][jj]; 
            cout << P[ii][jj] << " ";
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
	int next;
	cout << "---- time step " << t << " ----" << endl;
        rnd = (double)((rand() % 10) * 0.1);
        cout << "Random number: " << rnd << endl;
	cout << "current state: " << cur << endl <<  endl;

        for(int i = 0; i < size; i++)
        {		
	    if((i + 1) == cur) 
	    {
	        float total = 0;
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

        cout << "Next state: " << next << endl;
	cur = next;
        t++;
    }
    
    return 0;
}
