#ifndef DirectedGraph_h
#define DirectedGraph_h
#include <iterator>
#include <list>
#include <algorithm>
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

using namespace std;

class DirectedGraph: public Graph{
private:
    int size;
    Vertex** Vertices;
    int count;

public:
    DirectedGraph(){
        size = 0;
        count = 0;
        Vertices = new Vertex*[size];
}
    
    DirectedGraph(const DirectedGraph &D) {
        size = D.size;
        count = D.count;
        
        Vertices = new Vertex*[count];
        for (int i = 0; i < size; i++)
            Vertices[i] = D.Vertices[i];
        
    }
//Vertex vertices[get_count()];
//add a vertex
    
virtual bool addVertex(Vertex* v){          //EDITED: From Reference to Pointer
//  for (int i=0;i<=size;i++){
//      if (v->get_ID() == Vertices[i]->get_ID())
//      {
//      cout << "this vertex already exists";
//      return false;
//      }
//    }
    
    addVertices(v);
    return true;
}
//   for (int i=0; i < vertices.size(); i++){
//     if (v.get_ID() == vertices.at(i).get_ID()){
//       cout<< "this vertex already exists";
//       return false;
//     }
//     else
//       vertices.push_back(v);
//     cout<<"New vertex was added";
    
//   }
  
// return true;
//}

    virtual bool addVertices(Vertex* vArray){
    //EDITED: From Reference to Pointer
    Vertices[size] = vArray;
    size++;

  return true;
}

//remove vertex and edges that have connection with vertex
virtual bool removeVertex(Vertex* v){
    
for (int i=0; i < size; i++){
    if (v->get_ID() == Vertices[i]->get_ID())
        delete v;
        Vertices[i] = 0;
        //removeedge
    
//        if (v->get_ID()==vertices.at(i).get_ID())
//        vertices.erase(vertices.begin()+i);
}
    
  return true;
}

//add edge
virtual bool addEdge(Edge& e){
  for (int i=0; i <= size; i++){
      if (e.startidVertex() == Vertices[i]->get_ID() )
      {
          Vertices[i]->listOfEdges.push_back(e);
          count++;
          cout << e.startidVertex() << " -> " << e.endIdVertex() << " created." << endl;
          return true;
      }
  }
    cout << "No vertex found." << endl;
    return false;
    
//    vertices.at(i).listOfEdges.push_back(e);

//if (vertices.at(i).get_ID()==e.startidVertex());
//     e.listOfEdges[e.startidVertex()].push_back(e.endIdVertex());
//follow video already have a stat and end in edge parameter constructor so no need to also have it in implementation
}

//remove the edge(orphane vertex)
virtual bool removeedge(Edge& e){
    for (int i=0;i <= size-1; i++){
     auto it = Vertices[i]->listOfEdges.begin();//checks if the edge exists
     advance(it, i);
       
       if (*it == e){
         Vertices[i]->listOfEdges.remove(e);
           cout << "Deleted" << endl;
         return true;
         }
        
  }
 
   cout<<"this edge does not exist" << endl;
return false;
}

//to see if vertex exists
virtual int searchVertex(const Vertex* v) const{
return 0;
}

//search edge
virtual bool searchEdge(const Edge& e){
  return true;
}
    
    
    
virtual bool findEdge(Edge& e){
    for (int i=0;i <= count; i++){
      auto it = Vertices[i]->listOfEdges.begin();
      advance(it, i);
        
        if (*it == e)
        {
        cout<<"This edge was found between "<<e.startidVertex()<<" and "<<e.endIdVertex()<<endl;
        return true;
        }

    }
        cout << "This is not a valid edge." << endl;
        return false;
}
//convert whole graph to a a list of all the paths
virtual void display()const{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Vertices[i]->get_ID() << ": ";
        
        auto it = Vertices[i]->listOfEdges.begin();
        
        for (int j = 1; j <= Vertices[i]->listOfEdges.size(); j++)
        {
            if (j != Vertices[i]->listOfEdges.size())
            {
            cout << it->endIdVertex() << "-";
            advance(it, 1);
            }
            else
                cout << it->endIdVertex() << endl;
        }
    }
}

//own format of strig representation of the graph
    virtual string toString()const{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Vertices[i]->get_ID() << ": ";
        
        auto it = Vertices[i]->listOfEdges.begin();
        
        for (int j = 1; j <= Vertices[i]->listOfEdges.size(); j++)
        {
            if (j != Vertices[i]->listOfEdges.size())
            {
            cout << it->endIdVertex() << "-";
            advance(it, 1);
            }
            else
                cout << it->endIdVertex() << endl;
        }
    }
        return "";
  }

//remove all vertices and edges
virtual bool clean(){
  return true;
  }

};

#endif
