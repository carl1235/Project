#ifndef DAG_h
#define DAG_h

#include <iterator>
#include <list>
#include <algorithm>
#include <string>

#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

using namespace std;

class DAG: public Graph{
private:
    int size;
    Vertex** Vertices;
    int count;

public:
   
    DAG(){
        size = 0;
        count = 0;
        Vertices = new Vertex*[size];
}
    
    DAG(const DAG &D) {
        size = D.size;
        count = D.count;
        
        Vertices = new Vertex*[count];
        for (int i = 0; i < size; i++)
            Vertices[i] = D.Vertices[i];
    }

    virtual bool addVertex(Vertex* v){
    for (int i=0;i<=size;i++){
        if (Vertices[i] == v)
        {
        cout << "this vertex already exists" << endl;
        return false;
        }
    }
    
    addVertices(v);
    return true;
}

    virtual bool addVertices(Vertex* vArray){
        Vertices[size] = vArray;
        size++;

        return true;
    }

//remove vertex and edges that have connection with vertex
    virtual bool removeVertex(Vertex* v){
    for (int i=0; i < size; i++)
    {
        if (v->get_ID() == Vertices[i]->get_ID()){
            delete v;
            Vertices[i] = 0;

            Vertices[i]->listOfEdges.clear(); //Does this remove edge? If not add "RemoveEdge"
            return true;
        }
    }
    return false;
}

//add edge
    virtual bool addEdge(Edge& e){
        for (int i=0;i <= size-1; i++){
            int total = 0;
        for (auto it = Vertices[i]->listOfEdges.begin(); it != Vertices[i]->listOfEdges.end(); it++) {
            total += 1;
          }
            for (int j = 0; j < total; j++){
            auto it = Vertices[i]->listOfEdges.begin();
            advance(it, j);
           
            if (it->startVertex() == e.endVertex())
            {
                cout<<"Could not add edge: "<< e.startidVertex() << " -> "  << e.endIdVertex() << endl;
                return false;
            }
        }
    }
           
        for (int i=0; i <= size-1; i++){
            if (e.startVertex() == Vertices[i])
            {
                Vertices[i]->listOfEdges.push_back(e);
                count++;
                cout << e.startidVertex() << " -> " << e.endIdVertex() << " created." << endl;
                 return true;
            }
        }
        cout << "No vertex found." << endl;
        return false;
    }

//remove the edge(orphane vertex)
    virtual bool removeedge(Edge& e){
        for (int i=0;i <= size-1; i++){
            auto it = Vertices[i]->listOfEdges.begin(); //checks if the edge exists
             
            for (int j = 0; j <= Vertices[i]->listOfEdges.size(); j++){
                advance(it, 1);
                
                if (*it == e){
                    Vertices[i]->listOfEdges.remove(e);
                    cout << "Deleted" << endl;
                    return true;
                }
            }
        }
        cout<<"this edge does not exist" << endl;
        return false;
    }

  //to see if vertex exists
    virtual int searchVertex(const Vertex* v) const{
        for (int i=0;i <= size-1; i++){
            if (Vertices[i] == v){
                return i;
            }
        }
        return 0;
    }

    virtual bool searchEdge(const Edge& e){
        for (int j=0; j <= size-1; j++)
            for (int i=0;i <= count; i++)
            {
                auto it = Vertices[j]->listOfEdges.begin();
                advance(it, i);
            
                if (*it == e)
                {
                    cout<<"This edge was found between "<<e.startidVertex()<<" and "<<e.endIdVertex()<<endl;
                    return true;
                }
            }
        
        cout << e.startidVertex() <<" and " << e.endIdVertex() << " is not a valid edge." << endl;
        return false;
    }
    
//convert whole graph to a a list of all the paths
    virtual void display()const{
        
          for (int j=0; j <= size-1; j++){
              int total = 0;
              cout<< endl << "----------------------------------------"<<endl;
              cout<<"list of edges for: "<<Vertices[j]->get_ID()<<endl;
                for (auto it = Vertices[j]->listOfEdges.begin(); it != Vertices[j]->listOfEdges.end(); it++) {
                    total += 1;
                  }
                  for (int i=0;i<total;i++){
                        auto it = Vertices[j]->listOfEdges.begin();
                        advance(it, i);
                      
                      cout<<it->startidVertex()<<"->"<<it->endIdVertex()<<"; ";
          }
              if (total == 0)
                  cout << "Empty";
            }
        cout << endl;
    }

    
//own format of string representation of the graph
    virtual string toString()const{
         string tostring;
         cout << endl;
         for (int i = 0; i < size; i++)
         {
             tostring += to_string(Vertices[i]->get_ID()) + ": ";

             auto it = Vertices[i]->listOfEdges.begin();

             for (int j = 1; j <= Vertices[i]->listOfEdges.size(); j++)
             {
                 if (j != Vertices[i]->listOfEdges.size())
                 {
                     tostring+= to_string(it->endIdVertex()) + "(" + to_string(it->get_weight()) + ")-";
                     advance(it, 1);
                 }
                 else
                     tostring+= to_string(it->endIdVertex()) + "(" + to_string(it->get_weight()) + ")";
             }
             if (Vertices[i]->listOfEdges.size() == 0)
                 tostring += "Empty";
             
             tostring += "\n";
             
         }
        return tostring;
     }
//        string tostring = "";
//        string savestring;
//        bool ss = false;
//
//        for (int k=0; k < size; k++)
//        {
//            Vertex *v = Vertices[k];
//
//            for (int j=0; j < Vertices[searchVertex(v)]->listOfEdges.size(); j++)
//            {
//                int i = searchVertex(v);
//                bool test = true;
//                int tempj = j;
//                int k = j;
//
//                if (ss)
//                {
//                    ss = false;
//                    tostring += savestring;
//                    j = tempj;
//                    k++;
//                }
//                else
//                    tostring += to_string(Vertices[i]->get_ID());
//
//                while (test)
//                {
//                    auto it = Vertices[i]->listOfEdges.begin();
//                    advance(it, k);
//                    int repeat1 = searchVertex(it->endVertex());
//                    int changesize = int(Vertices[repeat1]->listOfEdges.size());
//
//                    if (Vertices[i]->listOfEdges.empty()){
//                        break;
//                    }
//
//                    if (Vertices[repeat1] == v){ //this is where repeat goes
//                        test=false;
//                        break;
//                    }
//
//                    tostring += "->" + to_string(Vertices[repeat1]->get_ID());
//                    if (changesize > 1)
//                    {
//                        //               eig = changesize--;
//                        ss = true;
//                        savestring = tostring;
//                    }
//                    i = searchVertex(it->endVertex());
//                    k=0;
//
//                }
//                tostring += "; ";
//    //else if()//if vertex exists dont go back on it
//            }
//    //        savestring = "";
//        }
//
//        return tostring;
//    }

   
//remove all vertices and edges
    virtual bool clean(){
        for (int i=0;i<=size-1;i++){
            Vertices[i]->listOfEdges.clear();
            delete [] Vertices;
            Vertices=0;
            
            Vertices=new Vertex*[0];//or 0
        }
        size = 0;
        return true;
    }
    
    ~DAG(){
        delete [] Vertices;
    }
    
//Operator overloading
    bool operator==(const DAG &Gright){
        if (size == Gright.size)
            for (int i=0; i<size-1; i++)
            {
                if(Vertices[i] == Gright.Vertices[i])
                    return true;
                else
                    return false;
            }
        return false;
    }
    
    const DAG &operator=(const DAG &right){
        if (&right !=this)//self assignment
        {
            if (size!=right.size)
            {
                size=right.size;
                Vertices=new Vertex*[size];
            }

            for (int i=0;i<size;i++){
                Vertices[i]=right.Vertices[i];
            }
        }
        return *this;
    }
    
    void helpIncrement(){
        for (int j=0; j <= size-1; j++){
            int total = 0;
            
           
              for (auto it = Vertices[j]->listOfEdges.begin(); it != Vertices[j]->listOfEdges.end(); it++) {
                  total += 1;
                }
                for (int i=0;i<total;i++){
                      auto it = Vertices[j]->listOfEdges.begin();
                      advance(it, i);
                    it->set_weight(it->get_weight()+1);
        }
    }
    }
    
    //Pre Increment
    DAG& operator++(){
        helpIncrement();
        return *this;
    }
    
    //Post Increment
    DAG& operator++(int){
        DAG *temp=new DAG;
        temp=this;
        helpIncrement();
        return *temp;
    }
    
    //DOESNT WORK (RELATED TO POINTERS)
    DAG& operator+(DAG& right){//need to add the weight of the edges in the print
        DAG *sum = new DAG;
        
        
             for (int k=0; k < count; k++){
           for (int j=0; j<size; j++){
           auto it=Vertices[j]->listOfEdges.begin();
               
           advance(it,k);
               
               sum->addVertex(it->endVertex());
               sum->addVertex(it->startVertex());
//               sum->addEdge(*it);

         }
     }

        for(int i=0; i < right.size; i++){
            for (int k=0;k< right.count; k++){
                auto it2=right.Vertices[i]->listOfEdges.begin();

          advance(it2,k);

          auto it=Vertices[i]->listOfEdges.begin();

          advance(it,k);

          if(*it2==*it){
            continue;
          }
                sum->addVertex(it2->endVertex());
                sum->addVertex(it2->startVertex());
//                sum->addEdge(*it2);
          }
          }
        
        return *sum;
        
      }
    
    
    
    
    friend ostream& operator<<(ostream &output, const Graph* Gright){
        output << Gright->toString() << endl;
        return output;
    }
    
    bool operator>(const DAG &right){
        int result=0;
        int result2=0;

        for (int k=0;k < size; k++)
            for (int j=0;j < count; j++){
                auto it = Vertices[k]->listOfEdges.begin();
                advance(it,j);
                
                result += it->get_weight();
            }
        
        for (int k=0;k < right.size; k++)
            for (int j=0;j < right.count; j++){
                auto it2 = right.Vertices[k]->listOfEdges.begin();
                advance(it2,j);
                
                result2 += it2->get_weight();
            }
        
        return result2<result;
    }
    
};
    
#endif

