#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    int score1 = 0;
    int score2 = 0;

    std::string line;
    while (std::getline(input, line)) {
        char opp = line[0];
        char me = line[2];
        
        if (opp == 'A') {
            switch (me) {
                case 'X':
                    score1 += 1 + 3;
                    score2 += 3;
                    break;
                case 'Y':
                    score1 += 2 + 6;
                    score2 += 1 + 3;
                    break;
                case 'Z':
                    score1 += 3;
                    score2 += 2 + 6;
                    break;
                default:
                    break;
            }
        }
        else if (opp == 'B') {
            switch (me) {
                case 'X':
                    score1 += 1;
                    score2 += 1;
                    break;
                case 'Y':
                    score1 += 2 + 3;
                    score2 += 2 + 3;
                    break;
                case 'Z':
                    score1 += 3 + 6;
                    score2 += 3 + 6;
                    break;
                default:
                    break;
            }
        }
        else if (opp == 'C') {
            switch (me) {
                case 'X':
                    score1 += 1 + 6;
                    score2 += 2;
                    break;
                case 'Y':
                    score1 += 2;
                    score2 += 3 + 3;
                    break;
                case 'Z':
                    score1 += 3 + 3;
                    score2 += 1 + 6;
                    break;
                default:
                    break;
            }
        }
    }

    std::cout << "Part 1: " << score1 << std::endl;
    std::cout << "Part 2: " << score2 << std::endl;

    return 0;
}