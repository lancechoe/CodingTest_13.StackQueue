/*
문제
The world should be finely balanced. Positive vs. negative, light vs. shadow, and left vs. right brackets. Your mission is to write a program that judges whether a string is balanced with respect to brackets so that we can observe the balance of the world.

A string that will be given to the program may have two kinds of brackets, round (“( )”) and square (“[ ]”). A string is balanced if and only if the following conditions hold.

For every left round bracket (“(”), there is a corresponding right round bracket (“)”) in the following part of the string.
For every left square bracket (“[”), there is a corresponding right square bracket (“]”) in the following part of the string.
For every right bracket, there is a left bracket corresponding to it.
Correspondences of brackets have to be one to one, that is, a single bracket never corresponds to two or more brackets.
For every pair of corresponding left and right brackets, the substring between them is balanced.
입력
The input consists of one or more lines, each of which being a dataset. A dataset is a string that consists of English alphabets, space characters, and two kinds of brackets, round (“( )”) and square (“[ ]”), terminated by a period. You can assume that every line has 100 characters or less. The line formed by a single period indicates the end of the input, which is not a dataset.

출력
For each dataset, output “yes” if the string is balanced, or “no” otherwise, in a line. There may not be any extra characters in the output.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str) {
    stack<char> s;
    
    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty() || s.top() != '(') return false;
            s.pop();
        } else if (ch == ']') {
            if (s.empty() || s.top() != '[') return false;
            s.pop();
        }
    }
    
    return s.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    while (true) {
        getline(cin, str);
        if (str == ".") break;
        
        cout << (isBalanced(str) ? "yes" : "no") << '\n';
    }
    
    return 0;
}