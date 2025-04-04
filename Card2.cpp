/*
Problem
There are N cards. Each card is numbered from 1 to N in turn, with card number 1 at the top and card number N at the bottom.

Now repeat the following actions until there is only one card left. First, throw the top card on the floor. Then, move the top card under the bottom card.

For example, let's consider that N=4. The cards sit in the order of 1234 from the top. If you discard 1, 234 remains. If you move 2 to the bottom, you get 342. 
If you throw away 3, you get 42, and if you move 4 down, you get 24. Finally, if you throw away 2, you get 4.

Write a program to find the last card left, given N.

Input
The first line is given an integer N (1 ≤ N ≤ 500,000).

Output
Print out the number of cards left in the first line.
*/

#include<iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;

    queue<int> Deck;

    for(int i=1;i<N+1;i++){
        Deck.push(i);
    }

    int front;

    while(Deck.size() >= 1){
        if(Deck.size() == 1){
            cout << Deck.front();
            break;
        }
        if(Deck.size() == 2){
            Deck.pop();
            cout << Deck.front();
            break;
        }
        Deck.pop();
        front = Deck.front();
        Deck.pop();
        Deck.push(front);
    }
}