#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

int main() {
    //Opens file stream
    std::ifstream file("input.txt");
    //Handles file open failure
    if(!file.is_open()) {
        std::cerr << "Could not open file.\n";
        return 1;
    }

    //Line holder for string stream
    std::string line;

    //Collection for all matched regex's
    std::vector<std::string> matched;

    int sum = 0;

    //While theres another line, pull it into line
    while(std::getline(file, line)) {
        //Open a new string stream
        std::stringstream iss(line);

        //Find all patterns in matching
        std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|don't\(\)|do\(\))");
        std::smatch matches;

        //Creates iterator for all matched items to be stored into from first character to last
        std::sregex_iterator begin(line.begin(), line.end(), pattern);
        //Stores the last character of the input by index
        std::sregex_iterator end;

        //Stores every matched goal into the matched vector
        for( std::sregex_iterator i = begin; i != end; i++) {
            matched.push_back(i->str());
        }
    }

    //State tracking of last do or don't
    bool last = false;

    //Starts summation
    for(int i = 0; i < matched.size(); i++) {
        //Local Variables
        std::string temp;
        std::vector<int> toMult;

        //Do and Don't check
        if(matched[i] == "do()") {
            last = false;
        } else if(matched[i] == "don't()") {
            last = true;
        } else {
            if(last) { //If last was a don't, ignore this iteration
            } else {
                //Parse string to get numbers
                for(int j = 0; j < matched[i].size(); j++) {
                    if((char)isdigit(matched[i][j])) {
                        temp.push_back(matched[i][j]);
                    } else if(temp != "") {
                        toMult.push_back(stoi(temp));
                        temp.clear();
                    }
                }
                sum += toMult[0] * toMult[1];
                toMult.clear(); //Clear buffer of numbers
            }
        }
    }
    std::cout << sum;
    return sum;
}