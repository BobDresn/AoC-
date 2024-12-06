#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int checkAllDirections(std::vector<std::string> map, int row, int column) {
    int found = 0;
    bool flag = false;;
    std::string goal = "XMAS";
    for(int i = 0; i < 8; i++) {
        switch (i) {
            case 0:
                //N
                flag = false;
                for(int j = 0; j < 4; j++) {
                    if(row - 3 < 0 || map[row - j][column] != goal[j]) {
                        flag = true;
                    }
                }
                if(!flag) {
                    found++;
                }
            case 1:
                //NE
                flag = false;
                for(int j = 0; j < 4; j++) {
                    if(row - 3 < 0 || column + 3 >= map[row].size() || map[row - j][column + j] != goal[j]){
                        flag = true;
                    }
                }
                if(!flag) {
                    found++;
                }
            case 2:
                //E
                flag = false;
                for(int j = 0; j < 4; j++) {
                    if(column + 3 >= map[row].size() || map[row][column + j] != goal[j]){
                        flag = true;
                    }
                }
                if(!flag) {
                    found++;
                }
            case 3:
                //SE
                flag = false;
                for(int j = 0; j < 4; j++) {
                    if(row + 3 >= map.size() || column + 3 >= map[row].size() || map[row + j][column + j] != goal[j]){
                        flag = true;
                    }
                }
                if(!flag) {
                    found++;
                }
            case 4:
                //S
                flag = false;
                for(int j = 0; j < 4; j++) {
                    if(row + 3 >= map.size() || map[row + j][column] != goal[j]){
                        flag = true;
                    }
                }
                if(!flag) {
                    found++;
                }
            case 5:
                //SW
                flag = false;
                for(int j = 0; j < 4; j++) {
                    if(row + 3 >= map.size() || column - 3 < 0 || map[row + j][column - j] != goal[j]){
                        flag = true;
                    }
                }
                if(!flag) {
                    found++;
                }
            case 6:
                //W
                flag = false;
                for(int j = 0; j < 4; j++) {
                    if(column - 3 < 0 || map[row][column - j] != goal[j]){
                        flag = true;
                    }
                }
                if(!flag) {
                    found++;
                }
            case 7:
                //NW
                flag = false;
                for(int j = 0; j < 4; j++) {
                    if(row - 3 < 0 || column - 3 < 0 || map[row - j][column - j] != goal[j]){
                        flag = true;
                    }
                }
                if(!flag) {
                    found++;
                }
        }
    }
    return found;
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
        for(int j = 0; j < map[i].size(); j++) {
            if(map[i][j] == 'X') {
                count += checkAllDirections(map, i, j);
            }
        }
    }
    std::cout << count;
    return count;
}