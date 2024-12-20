#include <iostream>
#include <fstream>
#include <vector>

int main() {
    //Opens file stream, this is declaration and instantiationo
    std::ifstream file("input.txt");
    //Takes line of text from input document
    std::string line;

    int count = 0;

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
    //Temp splits letters into that report values, 
    for(std::string word : strings) {
        for(char c : word) {
            if(c != ' ' || c == word.back()) {
                temp.push_back(c);
            }else if(temp.size() > 0 && temp.size() <= 2) {
                reports.push_back(std::stoi(std::string(temp.data(), temp.size())));
                temp.clear();
            }
        }
        reports.push_back(std::stoi(std::string(temp.data(), temp.size())));
        temp.clear();
    
        bool flag = false;
        bool adding; //If first is adding, tracking will be true. Loop will flag if adding is changed.
        bool tracking; //Loop flags if tracking is different from adding
        //Test the report for valid numbers
        for(int i = 0; i < reports.size(); i++) {
            //Bounds checking
            if(i + 1 < reports.size()) {
                //Absolute value to check distance from current to next value
                int abs = std::abs(reports[i] - reports[i + 1]);
                //Adding sets if the current to next trend is positive or negative
                adding = reports[i] < reports[i + 1];
                //Checks if first iteration
                if(reports[i - 1] == '\0') {
                    tracking = adding;
                }
                //Checks if each number change is within bounds(At least 1, At most 3)
                if(!(abs >= 1 && abs <= 3)) {
                    flag = true;
                //Checks that trend never changed
                } else if( adding != tracking ){
                    flag = true;
                }
            }
            tracking = adding;
        }
        if(!flag) {
            //Success
            count++;
        }
        //Clear buffer
        reports.clear();
    }
    std::cout << count;
    return 0;
}