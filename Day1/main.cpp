#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> sums;

    std::ifstream input("input.txt");
    std::string line;
    int sum = 0;
    while (std::getline(input, line)) {
        // std::cout << line << std::endl;
        if (line == "") {
            sums.push_back(sum);
            sum = 0;
        }
        else {
            sum += std::stoi(line);
        }
    }

    int max = *std::max_element(sums.begin(), sums.end());
    std::cout << "Part 1: " << max << std::endl;

    std::sort(sums.begin(), sums.end(), std::greater<int>());
    int top_sum = sums[0] + sums[1] + sums[2];
    std::cout << "Part 2: " << top_sum << std::endl;

    return 0;
}