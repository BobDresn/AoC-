#include <iostream>
#include <fstream>
#include <vector>
#include <map>

int main() {
    //Opens file stream, this is declaration and instantiationo
    std::ifstream file("input.txt");
    //Takes line of text from input document
    std::string line;

    //Vectors to order sets
    std::vector<std::string> strings;
    std::vector<int> left;
    std::vector<int> right;
    std::unordered_map<int, int> dict;

    //Opens file and pushes it to strings vector
    if(file.is_open()) {
        //While still a valid line to read, push to vector
        while(std::getline(file, line)) {
            strings.push_back(line);
        }
        //Close file stream when done
        file.close();
    } else {
        //Error handle
        std::cerr << "Unable to open file." << std::endl;
    }

    int count = 0;
    //Each line of strings, parse removing spaces and new lines
    for(std::string number : strings) {
        std::vector<char> temp;
        //If c is not a space or a newline, push to temp vector
        for(char c : number) {
            if( c != ' ' ) {
                temp.push_back(c);
                //If temp is a space or \n and isnt empty, this means you hit the end of the line. 
                //Push this to the correct array
            }
            if(temp.size() == 5) { 
                if(count % 2 == 0) {
                    left.push_back(std::stoi(std::string(temp.data(), temp.size())));\
                } else {
                    right.push_back(std::stoi(std::string(temp.data(), temp.size())));
                }
                temp.clear();
                count++;
            }
        }
    }
    
    bool contains;
    for(int lNum : left) {
        count = 0;
        for(int rNum : right) {
            if(lNum == rNum) {
                count++;
            }
        }
        //If count == 0, ignore but if greater, check if already in dict. Adds total occurances of that value in right. Extra finds from left dont matter
        if(count > 0 && dict.count(lNum) == 0) {
            dict.insert({lNum, count});
        }
    }

    count = 0;
    //Loops through left, every time its found multiply the value by the occurances at the value
    for(int num : left) {
        //Catches not found errors in dict by ignoring them
        try {
            count += (dict.at(num) * num);
        } catch(const std::out_of_range& e) {
            continue;
        }
    }
    std::cout << count;
    return 0;
}