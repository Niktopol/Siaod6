#include "graph.h"
#include <string>

int main(){
    std::string s;
    bool is_oriented;
    while (true){
        std::cout << "Is graph oriented? (y/n) ";
        std::cin >> s;
        if(s == "y"){
            is_oriented = true;
            break;
        }else if(s == "n"){
            is_oriented = false;
            break;
        }
    }
    graph gr(is_oriented);
    while (true){
        std::cout << "Enter the command: ";
        std::cin >> s;
        if(s == "Add"){
            gr.add_graph_edge();
        }else if (s == "Stop"){
            gr.print_graph();
            gr.print_chains();
            gr.find_path();
            break;
        }
    }
    return 0;
}