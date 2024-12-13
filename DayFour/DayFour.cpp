#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int searchWord(std::vector<std::string> map, int x, int y, std::string word) 
{
    int num = 0;
    //Horizontal
    if(x + word.length() <= map[0].size())
    {
        int i = 0;
        while(i < word.length() && map[x][y] == word[i])
        {
            i++;
        }
        if(i == word.length())
        {
            num++;
        }
    }

    //Vertical 
    if(y + word.length() <= map.size())
    {
        int i = 0;
        while(i < word.length() && map[y + i][x] == word[i])
        {
            i++;
        }
        if(i == word.length())
        {
            num++;
        }
    }

    //Diagonal
    if(x + word.length() <= map[0].size() && y + word.length() <= map.size()) 
    {
        int i = 0;
        while(i < word.length() && map[x + i][y + i] == word[i])
        {
            i++;
        }
        if(i == word.length())
        {
            num++;
        }
    }

    return num;
}


int main() {
    //Opens file
    std::fstream file("input.txt");
    if(!file.is_open()) 
    {
        std::cerr << "File could not be opened.";
        return 1;
    }

    //Vector of vectors of chars for holding our cross word puzzle
    std::vector<std::string> map;

    //File text handling string
    std::string line;

    //File text reading loop
    while(std::getline(file, line)) 
    {
        map.push_back(line);
    }

    int count = 0;

    for(int i = 0; i < map.size(); i++) 
    {
        for(int j = 0; j < map[0].size(); j++)
        {
            count += searchWord(map, i, j, "XMAS");
        }
    }

    for(std::string each : map) {
        std::reverse(each.begin(), each.end());
    }
    std::reverse(map.begin(), map.end());

    for(int i = 0; i < map.size(); i++) 
    {
        for(int j = 0; j < map[0].size(); j++)
        {
            count += searchWord(map, i, j, "XMAS");
        }
    }

    std::cout << count;
    return count;
}