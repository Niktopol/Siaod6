#include "graph.h"

void graph::print_chains(std::vector<int> path, int pos){
    if(path.size() > 1){
        for(int i = 0; i < path.size()-1; i++){
            std::cout << path.at(i) << "->";
        }
        std::cout << path.at(path.size()-1) << std::endl;
    }
    bool flag;
    for(int i = 0; i < size; i++){
        flag = true;
        if(matrix[pos-1][i] > 0){
            if (is_oriented){
                for(int j = 0; j < path.size()-1; j++){
                    if((path.at(j) == pos) && (path.at(j+1) == (i+1))){
                        flag = false;
                        break;
                    }
                }
            }else{
                for(int j = 0; j < path.size()-1; j++){
                    if(((path.at(j) == pos) && (path.at(j+1) == (i+1))) || ((path.at(j) == (i+1)) && (path.at(j+1) == pos))){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                std::vector<int> path_next = path;
                path_next.push_back(i+1);
                print_chains(path_next, i+1);
            }
        }
    }
}

void graph::find_path(std::vector<int> path, int pos, int targ, double len, double& shortest){
    if(std::find(path.begin(), path.end(), targ) != path.end()){
        for(int i = 0; i < path.size()-1; i++){
            std::cout << path.at(i) << "->";
        }
        shortest = ((shortest < 0) || (len < shortest))? len: shortest;
        std::cout << path.at(path.size()-1) << " length = " << len << std::endl;
        return;
    }
    bool flag;
    for(int i = 0; i < size; i++){
        flag = true;
        if(matrix[pos-1][i] > 0){
            if(std::find(path.begin(), path.end(), i+1) != path.end()){
                continue;
            }else{
                std::vector<int> path_next = path;
                path_next.push_back(i+1);
                find_path(path_next, i+1, targ, len+matrix[pos-1][i], shortest);
            }
        }
    }
}

void graph::add_graph_edge(){
    int a;
    int b;
    double distance;
    std::cout << "Enter starting point: ";
    std::cin >> a;
    std::cout << "Enter finishing point: ";
    std::cin >> b;
    std::cout << "Enter distance: ";
    std::cin >> distance;
    if((a <= size) && (b <= size) && (a > 0) && (b > 0)){
        matrix[a-1][b-1] = distance;
        if(!is_oriented){
            matrix[b-1][a-1] = distance;
        }
    }
}

void graph::print_graph(){
    std::cout << "digraph G {" << std::endl;
    if(is_oriented){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(matrix[i][j] > 0){
                    std::cout << "    "<< i+1 << "->" << j+1 << "[label=" << matrix[i][j] << ",len=" << matrix[i][j] << "]" << std::endl;
                }
            }
            std::cout<< "    " << i+1 << "[shape=circle]" << std::endl;
        }
    }else{
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if(matrix[i][j] > 0){
                    std::cout << "    "<< i+1 << "->" << j+1 << "[label=" << matrix[i][j] << ",len=" << matrix[i][j] << ",arrowhead=none]" << std::endl;
                }
            }
            std::cout<< "    " << i+1 << "[shape=circle]" << std::endl;
        }
    }
    std::cout << "}" << std::endl;
}

void graph::print_chains(){
    for(int i = 0; i < size; i++){
        std::vector<int> path;
        path.push_back(i+1);
        print_chains(path, i+1);
    }
}
void graph::find_path(){
    int start;
    int end;
    std::cout << "Enter starting point: ";
    std::cin >> start;
    std::cout << "Enter finishing point: ";
    std::cin >> end;
    if((start > 0) && (start <= size) && (end > 0) && (end <= size) && (start != end)){
        std::vector<int> path;
        path.push_back(start);
        double shortest = -1;
        find_path(path, start, end, 0, shortest);
        if(shortest > 0){
            std::cout << "Shortest path = " << shortest << std::endl;
        }else{
            std::cout << "Path not found" << std::endl;
        }
    }
}

graph::graph(bool type){
    is_oriented = type;
    std::cout << "Enter graph size: ";
    std::cin >> size;
    matrix = new double*[size];
    for(int i = 0; i < size; i++){
        matrix[i] = new double[size];
        for(int j = 0; j < size; j++){
            matrix[i][j] = 0;
        }
    }
}
graph::~graph(){
    for(int i = 0; i < size; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}