#ifndef Graph_h
#define Graph_h
#include "Vertex.h"
#include "Edge.h"
class DAG;

//abstract class
class Graph{
private:
    int count;
public:
    Graph(){
      count+=1;
    }
    
//add a vertex pure virtual
    virtual bool addVertex(Vertex* v) = 0;

//?
    virtual bool addVertices(Vertex* vArray) = 0;

//remove vertex and edges that have connection with vertex
    virtual bool removeVertex(Vertex* v) = 0;

//pure virtual add edge
    virtual bool addEdge(Edge& e) = 0;

//pure virtual remove the edge(orphane vertex)
    virtual bool removeedge(Edge& e) = 0;

//pure virtual to see if vertex exists
    virtual int searchVertex(const Vertex* v) const = 0;

//pure virtual search edge
    virtual bool searchEdge(const Edge& e) = 0;
    
//pure virtual convert whole graph to a a list of all the paths
    virtual void display() const = 0;

//pure virtual own format of strig representation of the graph
    virtual string toString() const = 0;

//remove all vertices and edges
    virtual bool clean() = 0;
    
    virtual Graph& operator++() = 0;
    virtual Graph& operator++(int) = 0;
    virtual Graph& operator+(DAG& right) = 0;
    friend ostream& operator<<(ostream &output, const Graph* Gright);
//destructor
    virtual ~Graph(){}
    
    
   
};


#endif
