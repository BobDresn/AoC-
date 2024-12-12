#include <fstream>
#include <iostream>
#include <vector>
#include <string>

enum Direction 
{
    N = 0,
    S = 1,
    E = 2,
    W = 3,
    NE = 4,
    SE = 5,
    NW = 6,
    SW = 7
};

std::string xmas = "XMAS";

bool checkNextChar(std::vector<std::string> map, int i, int j, char goal, Direction dir) 
{
    bool flag = false;
    switch(dir) {
        case Direction::N:
            if(i - 1 >= 0) {
                if(map[i - 1][j] == goal) {
                    flag = true;
                }
            }
        case Direction::S:
            if(i + 1 < map.size()) {
                if(map[i + 1][j] == goal) {
                    flag = true;
                }
            }
        case Direction::E:
            if(j + 1 < map[i].size()) {
                if(map[i][j + 1] == goal) {
                    flag = true;
                }
            }
        case Direction::W:
            if(j - 1 >= 0) {
                if(map[i][j - 1] == goal) {
                    flag = true;
                }
            }
        case Direction::NE:
            if(i - 1 >= 0 && j + 1 < map[i].size()) {
                if(map[i - 1][j + 1] == goal) {
                    flag = true;
                }
            }
        case Direction::SE:
            if(i + 1 < map.size() && j + 1 < map[i].size()) {
                if(map[i + 1][j + 1] == goal) {
                    flag = true;
                }
            }
        case Direction::NW:
            if(i - 1 >= 0 && j - 1 >= 0) {
                if(map[i - 1][j - 1] == goal) {
                    flag = true;
                }
            }
        case Direction::SW:
            if(i + 1 < map.size() && j - 1 >= 0) {
                if(map[i + 1][j - 1] == goal) {
                    flag = true;
                }
            }
    }
    return flag;
}

int countAllPossible(std::vector<std::string> map, int i, int j) {
    for(int y = 0; y < 8; y++) {

    }
}


int main() {
    //Opens file
    std::fstream file("input.txt");
    if(!file.is_open()) {
        std::cerr << "File could not be opened.";
        return 1;
    }

    //Vector of vectors of chars for holding our cross word puzzle
    std::vector<std::string> map;

    //File text handling string
    std::string line;

    //File text reading loop
    while(std::getline(file, line)) {
        map.push_back(line);
    }

    int count = 0;

    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[0].size(); j++) {
        }
    }
    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[i].size(); j++) {
            if(map[i][j] == 'X') {
            }
        }
    }


    std::cout << count;
    return count;
}