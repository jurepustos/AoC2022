#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream input("input.txt");

    int count_full = 0;
    int count_partial = 0 ;

    std::string line;
    while (std::getline(input, line)) {
        int first_hyphen_index = line.find('-');
        int comma_index = line.find(',');
        int second_hyphen_index = line.rfind('-');
        int left_id1 = std::stoi(line.substr(0, first_hyphen_index));
        int left_id2 = std::stoi(line.substr(first_hyphen_index+1, comma_index - first_hyphen_index));
        int right_id1 = std::stoi(line.substr(comma_index+1, second_hyphen_index - comma_index));
        int right_id2 = std::stoi(line.substr(second_hyphen_index+1, line.length() - second_hyphen_index));

        if ((left_id1 >= right_id1 && left_id2 <= right_id2)
                || (right_id1 >= left_id1 && right_id2 <= left_id2)) {
            count_full++;
        }

        if ((left_id2 >= right_id1 && right_id1 >= left_id1) 
                || (right_id2 >= left_id1 && left_id1 >= right_id1)) {
            count_partial++;
        }
    }

    std::cout << "Part 1: " << count_full << std::endl;
    std::cout << "Part 2: " << count_partial << std::endl;

    return 0;
}

