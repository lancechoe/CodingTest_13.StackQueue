/*
Problem
N balloons are placed in a circular pattern, numbered from 1 to N. Balloons i+1 are located on the right side of balloons i and i-1 are located on the left side. However, balloon N is located on the left side of balloon 1 and balloon 1 is located on the right side of balloon N. Each balloon has a piece of paper with an integer greater than or equal to -N and less than or equal to N. Pop these balloons according to the following rule.

First, pop balloon number one. Next, take out the paper inside the balloon, move it as much as the value written on it, and pop the next balloon. If a positive number is written, move to the right, and if a negative number is written, move to the left. When moving, take out the balloon that has already popped and move.

For example, five balloons have 3, 2, 1, -3, and -1 written in order. In this case, balloon 1 with 3 written on it, balloon 4 with -3, balloon 5 with -1, balloon 3 with 1 written on it, and balloon 2 with 2 written on it.

Input
The first line gives the natural numbers N (1 ≤ N ≤ 1,000). The next line gives in turn the numbers written on the paper inside each balloon. Zero is not written on the paper.

Output
List the numbers of the balloons that burst on the first line in order.
*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    deque<pair<int, int>> dq;  // {풍선 번호, 이동 수}
    for (int i = 1; i <= N; ++i) {
        int move;
        cin >> move;
        dq.push_back({i, move});
    }

    vector<int> result;

    while (!dq.empty()) {
        auto [idx, move] = dq.front();
        dq.pop_front();
        result.push_back(idx);

        if (dq.empty()) break;

        if (move > 0) {
            // 오른쪽으로 (앞 → 뒤), move - 1번 회전
            for (int i = 0; i < move - 1; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            // 왼쪽으로 (뒤 → 앞), |move|번 회전
            for (int i = 0; i < -move; ++i) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}