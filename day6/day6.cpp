#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>


int unique_window_pos(std::string signal, int window_size) {
    std::deque<char> window;

    for (int i = 0; i < signal.size(); i++) {
        if (i < window_size) {
            window.push_front(signal[i]);
        }
        else {
            std::set<char> unique_chars(window.begin(), window.end());
        
            if (unique_chars.size() == window_size) {
                return i;
            }
            else {
                window.pop_front();
                window.push_back(signal[i]);
            }
        }
    }

    return 0;
}


int main() {
    std::ifstream input("input.txt");

    std::string signal;
    input >> signal;

    std::cout << "Part 1: " << unique_window_pos(signal, 4) << std::endl;
    std::cout << "Part 2: " << unique_window_pos(signal, 14) << std::endl;

    return 0;
}

