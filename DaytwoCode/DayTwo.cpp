#include <iostream>
#include <fstream>
#include <vector>

int main() {
    //Opens file stream, this is declaration and instantiationo
    std::ifstream file("input.txt");
    //Takes line of text from input document
    std::string line;

    //Vectors to order sets
    std::vector<std::string> strings;
    std::vector<char> temp;
    std::vector<int> reports;


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

    //Builds reports vector and tests if valid report. Increments when requirements met.
    for(std::string word : strings) {
        for(char c : word) {
            if(c != ' ') {
                temp.push_back(c);
            }
            if(temp.size() == 2) {
                reports.push_back(std::stoi(std::string(temp.data(), temp.size())));
                temp.clear();
            }
        }
    }

    for(auto report : reports) {
        std::cout << report << std::endl;
    }

    return 0;
}