/*
문제
Parenthesis String (PS) consists of two parenthesis symbols ‘(’ and ‘)’ only. In parenthesis strings, some strings are called a valid PS (shortly, VPS). Let us give the formal definition of VPS. A single “( )” is a member of VPS, called the base VPS. Let x and y be a member of VPS. Then “(x)”, a VPS which encloses a VPS x with a single pair of parenthesis, is also a member of VPS. And xy, the concatenation of two VPS x and y, is a member of VPS. For example, “(())()” and ((()))” are all VPS, but “(()(”, “(())()))” and “(()” are not VPS. You are given a set of PS. You should decide if the input string is VPS or not. 

입력
Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Then PS’s are given in the following T lines one by one. The length of each PS is between 2 and 50, inclusively.

출력
Your program is to write to standard output. Print the result in each line. If the input string is a VPS, then print “YES”. Otherwise print “NO”. 
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isVPS(const string& str) {
    stack<char> s;
    
    for (char ch : str) {
        if (ch == '(') {
            s.push(ch);
        } else { // ch == ')'
            if (s.empty()) {
                return false;
            }
            s.pop();
        }
    }
    
    return s.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        string str;
        cin >> str;
        
        cout << (isVPS(str) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
