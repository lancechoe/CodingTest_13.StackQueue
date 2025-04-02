/*
문제
Your boss has asked you to add up a sequence of positive numbers to determine how much money your company made last year.

Unfortunately, your boss reads out numbers incorrectly from time to time.

Fortunately, your boss realizes when an incorrect number is read and says “zero”, meaning “ignore the current last number.”

Unfortunately, your boss can make repeated mistakes, and says “zero” for each mistake.

For example, your boss may say “One, three, five, four, zero, zero, seven, zero, zero, six”, which means the total is 7 as explained in the following chart:

Boss statement(s)	Current numbers	Explanation
“One, three, five, four”	1, 3, 5, 4	Record the first four numbers.
“zero, zero“	1, 3	Ignore the last two numbers.
“seven”	1, 3, 7	Record the number 7 at the end of our list.
“zero, zero”	1	Ignore the last two numbers.
“six”	1, 6	We have read all numbers, and the total is 7.
At any point, your boss will have said at least as many positive numbers as “zero” statements. If all positive numbers have been ignored, the sum is zero.

Write a program that reads the sequence of boss statements and computes the correct sum.

입력
The first line of input contains the integer K (1 ≤ K ≤ 100 000) which is the number of integers (including “zero”) your boss will say. On each of the next K lines, there will either be one integer between 1 and 100 (inclusive), or the integer 0.

출력
The output is one line, containing the integer which is the correct sum of the integers read, taking the “zero” statements into consideration. You can assume that the output will be an integer in the range 0 and 1 000 000 (inclusive).
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K;
    cin >> K;
    
    stack<int> s;
    
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        
        if (num == 0 && !s.empty()) {
            s.pop();
        } else {
            s.push(num);
        }
    }
    
    long long sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    
    cout << sum << '\n';
    
    return 0;
}
