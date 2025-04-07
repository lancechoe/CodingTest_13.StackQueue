/*
Problem
Implement a deck that stores integers, then write a program that processes commands given as inputs.

There are eight orders in total.

1 X: Put an integer X in front of the deck (1 ≤ X ≤ 100,000)
2 X: Put an integer X behind the deck (1 ≤ X ≤ 100,000)
3: If the deck has an integer, subtract the first integer and print it out. If not, print -1 instead.
4: If the deck has an integer, subtract the last integer and print it out. If not, print -1 instead.
5: Outputs the number of integers in the deck.
6: If the deck is empty, it outputs 1 or 0.
7: If the deck has an integer, it outputs the first integer. If not, it outputs -1 instead.
8: If the deck has an integer, it outputs the last integer. If not, it outputs -1 instead.
Input
The number of commands N is given in the first line (1 ≤ N ≤ 1,000,000)

From the second line, one command is given to each of the N lines.

More than one command is given that requires output.

Output
Whenever a command is given that requires output, the result of the command is output one line at a time.
*/

#include <iostream>
#include <deque>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::deque<int> dq;
    std::string command;
    int x;

    for (int i = 0; i < N; ++i) {
        std::cin >> command;

        if (command == "1") {
            std::cin >> x;
            dq.push_front(x);
        }
        else if (command == "2") {
            std::cin >> x;
            dq.push_back(x);
        }
        else if (command == "3") {
            if (!dq.empty()) {
                std::cout << dq.front() << "\n";
                dq.pop_front();
            } else {
                std::cout << "-1\n";
            }
        }
        else if (command == "4") {
            if (!dq.empty()) {
                std::cout << dq.back() << "\n";
                dq.pop_back();
            } else {
                std::cout << "-1\n";
            }
        }
        else if (command == "5") {
            std::cout << dq.size() << "\n";
        }
        else if (command == "6") {
            std::cout << (dq.empty() ? 1 : 0) << "\n";
        }
        else if (command == "7") {
            if (!dq.empty()) {
                std::cout << dq.front() << "\n";
            } else {
                std::cout << "-1\n";
            }
        }
        else if (command == "8") {
            if (!dq.empty()) {
                std::cout << dq.back() << "\n";
            } else {
                std::cout << "-1\n";
            }
        }
    }

    return 0;
}
