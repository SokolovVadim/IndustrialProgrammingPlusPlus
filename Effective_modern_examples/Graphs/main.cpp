#include "Graphs.hpp"

int main() {


    Graph<int>   intGraph  (10);
    Graph<float> floatGraph(1);
    std::cout << intGraph.getSize() << std::endl;
    intGraph.dump();

    floatGraph.fillWith(10.1);
    floatGraph.dump();

    intGraph.fillWith(11);
    intGraph.dump();

    std::cout << floatGraph[0] << std::endl;


    return 0;
}