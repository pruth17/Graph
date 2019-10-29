#include "Graph.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    string in,out;
    ifstream inFile;
    do
    {
        cout << "Enter: ";
        cin >> in;
        inFile.open(in);
    }
    while(!inFile);
   
    cout << "***Reading from " << in << "***" << endl;
    cout<< endl << "Please enter the name of the output file: ";
    cin >> out;
    ofstream outFile;
    outFile.open(out);
    
        int n = 0;
        inFile >> n;
  
        Graph g1(n);
        inFile.clear();
        int u ,v,x,y;

        while(inFile >> u >> v )
        {
         
            if(u==0 && v==0)
            {
                inFile.ignore();
                while(inFile >> x >> y && x !=0 && y != 0)
                {
                
                    g1.BFS(x);
                    cout << x << endl;
                    g1.printBFS(cout);
                    cout << endl;
            
                    outFile << "The distance between " << x << " to " << y << " is " <<  g1.getDistance(y) << endl;
                    outFile << "Path from " << x << " to " << y << " is: ";
                    g1.printPath(x, y, outFile);
                    outFile << endl;

                
            }

            }
            
           
            else

    g1.addEdge(u, v);

            

            }
    outFile << endl << endl;
    
    g1.printGraph(outFile);
            
        

    
    int k =0;
   
    

    
    return 0;
    
    
}
