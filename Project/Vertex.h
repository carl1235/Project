#ifndef Vertex_h
#define Vertex_h
#include <list>
#include "Edge.h"
#include "Vertex.h"

using namespace std;
class Edge;

class Vertex{
private:
    int count;
    int ID=0;
    string value;
//    list <Edge> listOfEdges;

public:
    list<Edge> listOfEdges;
    
    Vertex(){
        count+=count;
    }//default constructor
    //parameterized constructor
    Vertex(int ID, string value){
        this->ID=ID;
        this->value=value;
        count+=1;
    }
    
    Vertex(const Vertex &v){
        count = v.count;
        ID = v.ID;
        value = v.value;
    }

    void set_ID(int ID){
        this->ID=ID;
    }
    
    int get_ID() const{
        return ID;
    }
    
    void set_value(string value){
        this->value=value;
    }
    string get_value() const{
        return value;
    }
    int get_count() const{
        return count;
    }

    list<Edge> getEdge() const{
        return listOfEdges;
    }
    
    bool operator==(const Vertex& rhs) const{
        return ID == rhs.ID && value == rhs.value;
    }

    
    // voID set_Edge(list<Edge> e){
    //     listOfEdges=e;
    // }
};

#endif
