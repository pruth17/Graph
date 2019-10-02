#include "Graph.h"
#include <iostream>
#include <vector>
#include <assert.h>
#include "Queue.h"


Graph::Graph(int n)
{
    vertices=n;
    for(int i = 0; i <= n; i++)
    {
        adj.push_back(List<int>());
        color.push_back('W');
        distance.push_back(-1);
        parent.push_back(0);
    }
    edges=0;
}
    
int Graph::getNumEdges() const
{
   return edges;
}

int Graph::getNumVertices() const
{
    return vertices;
}

bool Graph::isEmpty() const
{
    return getNumVertices() == 0 ;
}

int Graph::getParent(int v) const
{
    assert(v <=  vertices);
    return parent[v];
}

int Graph::getDistance(int v) const
{
    assert(v <= vertices);
    return distance[v];
}

char Graph::getColor(int v) const
{
    assert(v <= vertices);
    return color[v];
}

void Graph::addEdge(int u, int v)
{
 
       // cout << "EDges that are being addded " << u << " " << v << endl;
    adj[u].insertLast(v);
    adj[v].insertLast(u);
    edges++;
    }
    


void Graph::printGraph(ostream &out)
{
    double VertSize = adj.size();
    for(int i = 1; i < VertSize ; i++)
    {
        out << "vertex " << i << ": ";
        adj[i].printList(out);
        out <<  " " << endl;
    }
    out << endl;
}

void Graph::BFS(int s)
{
    assert(vertices >= 1);
   // assert(s )
    for(int i = 1; i < 10;i++)
    {
        color[i]= 'W';
        distance[i] = -1;
        parent[i] = 0;
    }
    color[s] = 'G';
    
    distance[s] = 0;
    Queue<int> q;
    q.enqueue(s);
    while(!q.isEmpty())
    {
        int x = q.getFront();
        adj[x].startIterator();
        q.dequeue();
       
        while(!adj[x].offEnd())
        {
            int k = adj[x].getIterator();
            adj[x].advanceIterator();
            
           if( color[k] == 'W')
           {
               color[k] = 'G';
               distance[k] = distance[x] + 1;
               parent[k] = x;
               q.enqueue(k);
            }
        }
            color[x] = 'B';
        
    }
   
}

void Graph::printBFS(ostream &out)
{
    out << "V       " << "C       " << " P        " << " D       " << endl;
    for(int i = 1 ; i<=getNumVertices();i++)
    {
        out << i <<"       " << color[i]<< "        " << parent[i] <<"         " << distance[i] << endl;
    }
}


void Graph::printPath(int source, int destination, ostream &out)
{
   
    
    //out << "Here are different Paths from " << source <<" to " << destination  << ":  " << endl;
    if (destination == source)
    {
        out << source << " ";
        //d++;
        
    }
        
        else if (parent[destination] == 0)
        {
            out << "No path exists ";
            return;
    
        }
        else
        {
                printPath(source, parent[destination], out);
     
                out  << destination << " ";
        }
    
}




