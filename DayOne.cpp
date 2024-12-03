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
    std::vector<int> left;
    std::vector<int> right;

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
                    left.push_back(std::stoi(std::string(temp.data(), temp.size())));
                    temp.clear();
                    count++;
                } else {
                    right.push_back(std::stoi(std::string(temp.data(), temp.size())));
                    temp.clear();
                    count++;
                }
            }
        }
    }

    //Sorts each vector into ascending order
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int answer = 0;
    //Iterates through each vector to find absolute value of the distance, and adds that to the answer
    for(int i = 0; i < left.size(); i++) {
        answer += abs(left[i] - right[i]);
    }
    std::cout << answer << std::endl;
    return 0;
}