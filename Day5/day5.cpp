#include <iostream>
#include <fstream>
#include <stack>
#include <deque>
#include <vector>


int main() {
    std::ifstream input("input.txt");

    std::vector<std::string> lines;
    
    int i = 0;
    int stacks_line = 0;

    // read all lines
    std::string line;
    while (std::getline(input, line)) {
        if (stacks_line == 0) {
            int j = line.find('[');
            if (j == std::string::npos) {
                stacks_line = i;
            }
            i++;
        }
        lines.push_back(line);
    }

    // construct the stacks
    // there are tooo many, but we don't care
    int stack_count = lines[stacks_line].length();
    std::vector<std::deque<char>> starting_stacks(stack_count);
    for (int i = stacks_line - 1; i >= 0; i--) {
        auto line = lines[i];

        int current_stack = 1;
        for (int j = 0; j < line.length(); j++) {
            char c = line[j];
            if (j % 4 == 1) {
                if (c >= 'A' && c <= 'Z') {
                    starting_stacks[current_stack].push_front(c);
                }
                current_stack++;
            }
        }
    }


    std::vector<std::deque<char>> stacks = starting_stacks;

    // move stuff between stacks
    for (int i = stacks_line + 2; i < lines.size(); i++) {
        std::string line = lines[i];
        int first_space = line.find(' ');
        int second_space = line.find(' ', first_space+1);
        int third_space = line.find(' ', second_space+1);
        int fourth_space = line.find(' ', third_space+1);
        int fifth_space = line.find(' ', fourth_space+1);

        int quantity = std::stoi(line.substr(first_space + 1, second_space - first_space - 1));
        int s1 = std::stoi(line.substr(third_space + 1, fourth_space - third_space - 1));
        int s2 = std::stoi(line.substr(fifth_space + 1));

        for (int j = 0; j < quantity; j++) {
            char value = stacks[s1].front();
            stacks[s1].pop_front();
            stacks[s2].push_front(value);
        }
    }

    std::cout << "Part 1: ";
    for (auto s : stacks) {
        if (!s.empty()) {
            std::cout << s.front();
        }
    }
    std::cout << std::endl;

    stacks = starting_stacks;

    // move stuff between stacks
    for (int i = stacks_line + 2; i < lines.size(); i++) {
        std::string line = lines[i];
        int first_space = line.find(' ');
        int second_space = line.find(' ', first_space+1);
        int third_space = line.find(' ', second_space+1);
        int fourth_space = line.find(' ', third_space+1);
        int fifth_space = line.find(' ', fourth_space+1);

        int quantity = std::stoi(line.substr(first_space + 1, second_space - first_space - 1));
        int s1 = std::stoi(line.substr(third_space + 1, fourth_space - third_space - 1));
        int s2 = std::stoi(line.substr(fifth_space + 1));

        std::deque<char> crates;
        for (int j = 0; j < quantity; j++) {
            char value = stacks[s1].front();
            stacks[s1].pop_front();
            crates.push_front(value);
        }

        for (char value : crates) {
            stacks[s2].push_front(value);
        }
    }

    std::cout << "Part 2: ";
    for (auto s : stacks) {
        if (!s.empty()) {
            std::cout << s.front();
        }
    }
    std::cout << std::endl;

    return 0;
}



