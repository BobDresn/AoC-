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
    std::unordered_map<int, int> map_right;
    

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
            }
            //Push this to the correct array
            if(temp.size() == 5) { 
                //Stores string as a number
                int number = std::stoi(std::string(temp.data(), temp.size()));
                //If first number in line, push to left vector
                if(count % 2 == 0) {
                    left.push_back(number); //Adds to vector
                    temp.clear(); //Clear buffer
                    count++; //Increment
                } else {
                    //If second number in line, adds number to the map
                    //Checks if the map already contains this number, and if so increments
                    if(map_right.count(number) > 0) {
                        map_right.at(number)++;
                        temp.clear();
                    } else {
                        //Otherwise add the value and set value to 1 to start count
                        map_right.insert({number, 1});
                        temp.clear(); //Clear buffer
                    }
                    count++;
                }
            }
        }
    }
    count = 0;


    for(auto key : map_right) {
        std::cout << key.first << ' ' << key.second << std::endl;
        count+= abs(key.second * key.first);
    }
    std::cout << count;
    return 0;
}