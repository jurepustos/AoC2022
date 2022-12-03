#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

int priority(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    else {
        return c - 'A' + 27;
    }
}

int main() {
    std::ifstream input("input.txt");
    int sum = 0;

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input, line)) {
        lines.push_back(line);
        int item_count = line.length();

        std::vector<char> r1;
        std::vector<char> r2;
        
        for (int i = 0; i < item_count / 2; i++) {
            r1.push_back(line[i]);
            r2.push_back(line[i + item_count / 2]);
        }

        std::sort(r1.begin(), r1.end());
        std::sort(r2.begin(), r2.end());

        std::vector<char> common;
        std::set_intersection(r1.begin(), r1.end(),
            r2.begin(), r2.end(), std::back_inserter(common));

        sum += priority(common[0]);
    }
    std::cout << "Part 1: " << sum << std::endl;

    sum = 0;
    for (auto it = lines.begin(); it != lines.end(); ++it) {
        std::string first = *it;
        ++it;
        std::string second = *it;
        ++it;
        std::string third = *it;

        std::sort(first.begin(), first.end());
        std::sort(second.begin(), second.end());
        std::sort(third.begin(), third.end());

        std::vector<char> first_second_common;
        std::set_intersection(first.begin(), first.end(),
            second.begin(), second.end(), std::back_inserter(first_second_common));
        
        std::sort(first_second_common.begin(), first_second_common.end());
        std::vector<char> common;
        std::set_intersection(first_second_common.begin(), first_second_common.end(),
            third.begin(), third.end(), std::back_inserter(common));

        sum += priority(common[0]);
    }
    std::cout << "Part 2: " << sum << std::endl;


    return 0;
}