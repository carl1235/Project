#ifndef Edge_h
#define Edge_h
#include "Vertex.h"

class Edge{
private:
    int weight;
    Vertex *start;
    Vertex *end;
    
public:
    Edge(){}

    Edge(int weight, Vertex *startV, Vertex *endV)
    :start(startV),end(endV){
        this->weight=weight;
    }
    
    Vertex* startVertex(){
      return start;
    }
    
    Vertex* endVertex(){
      return end;
    }
    
    Edge(const Edge &e){
        weight = e.weight;
        start = e.start;
        end = e.end;
    }

    int startidVertex() const{
        return start->get_ID();
    }

    int endIdVertex() const{
        return end->get_ID();
    }

    void set_weight(int weight){
        this->weight=weight;
    }

    int get_weight() const{
        return weight;
    }
    
    bool operator==(const Edge& rhs) const{
      return start == rhs.start
        && end == rhs.end
          && weight==rhs.weight;
    }

};

#endif
