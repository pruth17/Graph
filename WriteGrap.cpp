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


        //ifstream inFile;
       // inFile.open("vv.txt");
//        if(!inFile)
//        {
//            cout << "Error opening file" << endl;
//        }
    ofstream outFile;
    outFile.open(out);
    
        int n = 0;
        inFile >> n;
    //cout << "HIIIIIII " << n << endl;
        Graph g1(n);
        inFile.clear();
        int u ,v,x,y;
        //cout << endl;
        while(inFile >> u >> v )
        {
           // cout << u << " " << v << endl;
            if(u==0 && v==0)
            {
                inFile.ignore();
                while(inFile >> x >> y && x !=0 && y != 0)
                {
                    //cout << endl;
               // cout << "for BFS " << endl;
                    g1.BFS(x);
                    cout << x << endl;
                    g1.printBFS(cout);
                    cout << endl;
                   // cout << "for " << x << endl;
                   // g1.printBFS(cout);
                   
                    //outFile << endl;
                    outFile << "The distance between " << x << " to " << y << " is " <<  g1.getDistance(y) << endl;
                    outFile << "Path from " << x << " to " << y << " is: ";
                    g1.printPath(x, y, outFile);
                    outFile << endl;
//                    g1 = Graph(n);
                  
//                    if(x==0 && y==0)
//                        inFile.ignore();
            
                        //Graph g1(n);
                
            }
                   //g1 = Graph(n);
                
            }
            
           
            else
            
                //cout << "Edges that are being added " << u << " " << v << endl;
    g1.addEdge(u, v);

            

            }
    outFile << endl << endl;
    
    g1.printGraph(outFile);
            
        
    
    
        
       // g1.printGraph(cout);
    
    int k =0;
   
    

    
    return 0;
    
    
}
