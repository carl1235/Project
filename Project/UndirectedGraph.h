#ifndef UndirectedGraph_h
#define UndirectedGraph_h
#include <iterator>
#include <list>
#include <algorithm>
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

using namespace std;

class UndirectedGraph: public Graph{
private:
    int size;
    Vertex** Vertices;
    int count;

public:
    UndirectedGraph(){
        size = 0;
        count = 0;
        Vertices = new Vertex*[size];
}
    
    UndirectedGraph(const UndirectedGraph &D) {
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
          for (int i=0; i <= size-1; i++){
              if (e.startidVertex() == Vertices[i]->get_ID() )
              {
                  Vertices[i]->listOfEdges.push_back(e);
                  break;
              }
          }
            for (int i=0; i <= size-1; i++){
              if (e.endIdVertex() == Vertices[i]->get_ID())
              {
                  Vertices[i]->listOfEdges.push_back(e);
                  count++;
                  cout << e.startidVertex() << " <-> " << e.endIdVertex() << " created." << endl;;
                  return true;
              }
          }
    return false;
}

//remove the edge(orphane vertex)
virtual bool removeedge(Edge& e){
return true;
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
}

//own format of strig representation of the graph
    virtual string toString()const{
        return "";
    }

//remove all vertices and edges
virtual bool clean(){
  return true;
  }

};

#endif
