#include "graph.h"
#include <string>

int main(){
    graph gr(true);
    std::string s;
    while (true){
        std::cin >> s;
        if(s == "Add"){
            gr.add_graph_edge();
        }else{
            gr.print_graph();
            gr.print_chains();
            gr.find_path();
            break;
        }
    }
    
    return 0;
}