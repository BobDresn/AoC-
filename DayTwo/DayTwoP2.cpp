#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

bool isSafe(std::vector<int>& report) {
    bool safe = true;
    //Single or empty reports are safe
    //Edge cases
    if(report.size() < 2) {
        safe = true;
    }

    bool increasing = report[1] > report[0];

    for(int i = 0; i < report.size() - 1; i++) {
        int diff = report[i + 1] - report[i];
        //Out of bounds checks
        if(std::abs(diff) == 0 || std::abs(diff) > 3) {
            safe = false;
        }
        //Checks for consistent change
        if((diff > 0) != increasing) {
            safe = false;
        }
    }
    return safe;
}

bool canBeMadeSafe(std::vector<int>& report) {
    bool safe = false;
    for(int i = 0; i < report.size(); i++) {
        std::vector<int>temp = report;
        temp.erase(temp.begin() + i);
        if(isSafe(temp)) {
            safe = true;
            break;
        }
    }
    return safe;
}

int main() {
    //Opens file stream, this is declaration and instantiation
    std::ifstream file("input.txt");
    if(!file.is_open()) {
        std::cerr << "File wont open." << std::endl;
        return 1;
    }

    //Takes line of text from input document
    std::string line;

    //Counter
    int validReports = 0;

    //While next line isnt null
    while(std::getline(file, line)) {

        //Line from file passed into string stream
        std::istringstream iss(line);

        //Creates vector of ints to pass into checks
        std::vector<int> report;

        //Placeholder
        int num;

        //Parse line into placeholder
        while(iss >> num) {
            //If num in this line, push to report
            report.push_back(num);
        }

        //Checks if the report is safe or can be made safe
        if(isSafe(report) || canBeMadeSafe(report)) {
            validReports++;
        }
    }
    std::cout << validReports << std::endl;
    return validReports;
}

//     //Opens file and pushes it to strings vector
//     if(file.is_open()) {
//         //While still a valid line to read, push to vector
//         while(std::getline(file, line)) {
//             strings.push_back(line);
//         }
//         //Close file stream when done
//         file.close();
//     } else {
//         //Error handle
//         std::cerr << "Unable to open file." << std::endl;
//     }

//     //Holds the current numbers and will be passed into reports
//     std::vector<char> temp;
//     //Holds current line of numbers from reports for testing
//     std::vector<int> reports;

//     //Tracking score
//     int validReports = 0;
//     //Parsing Lines for valid reports
//     for(std::string list : strings) {
//         for(int i = 0; i < list.size(); i++) {
//             if(list[i] != ' ') {
//                 temp.push_back(list[i]);
//             } else {
//                 reports.push_back(std::stoi(std::string(temp.data(), temp.size())));
//                 temp.clear();
//             }
//         }
//         //Lines dont end with endl, need to push final string after iterated through. 
//         reports.push_back(std::stoi(std::string(temp.data(), temp.size())));
//         temp.clear();

//         //TESTING CURRENT REPORT
//         int issues = 0;
//         bool constant = true;
//         bool tracking = true;
//         bool bounds = true;
//         for(int i = 0; i < reports.size() - 1; i++) {
//             int test = reports[i + 1] - reports[i];
//             //Only first iteration, set tracking and constant equal. 
//             //Checks if b - a > 0. This tracks if the set is an increasing or decreasing set
//             //If consistent is ever not equal to that, reports bad
//             if(i == 0) {
//                 (test > 0) ? constant = true: constant = false;
//                 tracking = constant;
//             } else {
//                 (test > 0) ? tracking = true: tracking = false;
//             }
//             if(tracking != constant) {
//                 issues++;
//                 reports.erase(reports.begin() + i + 1);
//                 break;
//             }

//             //Tracking if |b - a| +- 3 as thats the given bounds
//             //If not, flag and reports bad
//             if(abs(test) == 0 || abs(test) > 3) {
//                 issues++;
//                 reports.erase(reports.begin() + i + 1);
//                 break;
//             }

            
//         }

//         //If overall the report came out with < 1 issue, increment validReports
//         //If not, try again after removing bad number
//         if(issues == 0) {
//             validReports++;
//         } else {
//             issues = 0;
//             constant = true;
//             tracking = true;
//             bounds = true;
//             for(int i = 0; i < reports.size() - 1; i++) {
//                 int test = reports[i + 1] - reports[i];
//                 //Only first iteration, set tracking and constant equal. 
//                 //Checks if b - a > 0. This tracks if the set is an increasing or decreasing set
//                 //If consistent is ever not equal to that, reports bad
//                 if(i == 0) {
//                     (test > 0) ? constant = true: constant = false;
//                     tracking = constant;
//                 } else {
//                     (test > 0) ? tracking = true: tracking = false;
//                 }
//                 if(tracking != constant) {
//                     issues++;
//                     reports.erase(reports.begin() + i + 1);
//                     break;
//                 }

//                 //Tracking if |b - a| +- 3 as thats the given bounds
//                 //If not, flag and reports bad
//                 if(abs(test) == 0 || abs(test) > 3) {
//                     issues++;
//                     reports.erase(reports.begin() + i + 1);
//                     break;
//                 }
//             }
//             if(issues == 0) {
//                 validReports++;
//             }
//         }
//         reports.clear();
//     }
//     std::cout << validReports;
//     return validReports;
// }