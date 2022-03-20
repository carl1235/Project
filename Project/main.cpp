#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>

#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"
#include "DAG.h"

using namespace std;

int main(){
    Graph* a1 = new DAG();  //Empty Graph
    
    Graph* D = new DAG();
    Graph* Dag = new DAG();
    
    Vertex *vd1 = new Vertex(1,"Montreal");
    Vertex *vd2 = new Vertex(2,"Toronto");
    Vertex *vd3 = new Vertex(3,"Ottawa");
    Vertex *vd4 = new Vertex(4,"Edmonton");
    Vertex *vd5 = new Vertex(5, "Quebec City");
    
    Vertex *vd11 = new Vertex(1,"Montreal");
    Vertex *vd21 = new Vertex(2,"Toronto");
    Vertex *vd31 = new Vertex(3,"Ottawa");
    Vertex *vd41 = new Vertex(4,"Edmonton");
    Vertex *vd51 = new Vertex(5, "Quebec City");
    
    Dag->addVertex(vd1);
    Dag->addVertex(vd2);
    Dag->addVertex(vd3);
    Dag->addVertex(vd4);
    Dag->addVertex(vd5);
    
    D->addVertex(vd11);
    D->addVertex(vd21);
    D->addVertex(vd31);
    D->addVertex(vd41);
    D->addVertex(vd51);
    
    Edge edM1(1000, vd1, vd2);
    Edge edM2(500, vd1, vd3);
    Edge edM3(5000, vd1, vd4);
    
    Edge edT1(628, vd2, vd3);
    Edge edT2(802, vd2, vd4);
    
    Edge edO1(500, vd3, vd5);
    Edge edO2(4000, vd3, vd4);
    Edge edO3(250, vd3, vd1);
    
    Edge edE1(5200, vd4, vd5);
    
    Edge edM21(500, vd11, vd31);
    Edge edM31(5000, vd11, vd41);
    
    Edge edT21(802, vd21, vd41);
    
    Edge edO11(500, vd31, vd51);
    
    Dag->addEdge(edM1);
    Dag->addEdge(edM2);
    Dag->addEdge(edM3);
    
    Dag->addEdge(edT1);
    Dag->addEdge(edT2);
    
    Dag->addEdge(edO1);
//    Dag->addEdge(edO2);
//    Dag->addEdge(edO3);
    
    Dag->addEdge(edE1);

    Dag->searchEdge(edO1);
    
    D->addEdge(edM21);
    D->addEdge(edM31);
    
    D->addEdge(edT21);
    
    D->addEdge(edO11);
//    Dag->removeedge(edM1);
//    Dag->removeedge(edM2);
//    Dag->removeedge(edM3);
//
//    Dag->removeedge(edT1);
//    Dag->removeedge(edT2);
//
//    Dag->removeedge(edO1);
//    Dag->removeedge(edO2);
//
//    Dag->removeedge(edE1);
//
//    Dag->removeedge(edQ1);
    
//    D = Dag;

//    if (D < Dag)
//        cout << "True";
//    else
//        cout << "False";
//    cout<<"the weight of edM1 before pre increment is: "<<edM1.get_weight()<<endl;
//
////      ++Dag;
//      cout<<"the weight of edge edM1 with pre increment is : "<<edM1.get_weight();
////
////
////      Dag++;
//    cout << endl << D->toString() << endl;
//    D->clean();
    cout << Dag;
    
    DAG Dag1 = *dynamic_cast<DAG*>(Dag);
    DAG D1 = *dynamic_cast<DAG*>(D);
    DAG a2 = *dynamic_cast<DAG*>(a1);
    Dag1++;
    
    cout << Dag;
    cout << D;
    
    a2 = D1 + Dag1;
    
//    D = Dag;
    
    cout << "Sum: \n"<< a1;
    cout << Dag;
    Dag->display();
//    cout << Dag;
//    cout << ++Dag;
    
//    cout << Dag++;
//    cout << Dag;
    
//    D->clean();
    
//    cout << Dag++;
//
//    cout << Dag;
//    Dag->display();

//    directed->findEdge(ed1);
//    directed->findEdge(ed2);
    
//    // Undirected
//    Graph* undirected = new UndirectedGraph();
//
//    Vertex *vu1 = new Vertex(1,"Ny");
//    Vertex *vu2 = new Vertex(2, "Chicago");
//
//    Edge eu1(1000, vu1, vu2);
//
//    undirected->addVertex(vu1);
//    undirected->addVertex(vu2);
//
//    undirected->addEdge(eu1);
//
//    undirected->findEdge(eu1);
    
//    delete Dag;
//    if (D != Dag)
//    delete D;
    
    return 0;
}
