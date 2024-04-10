#include <bits/stdc++.h>

/**
 * Runtime: beats 100% of users with C++
 * Memory: beats 67.85% of users with C++
 * Daily problem (Streak 57)
*/

class Solution {
public:
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        std::sort(deck.begin(), deck.end());

        int n = deck.size();

        std::deque<int> dq;
        dq.push_front(deck[n - 1]);

        for(int i = n - 2; i >= 0; i--) {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }

        for(int i = 0; i < n; i++) {
            deck[i] = dq.front();
            dq.pop_front();
        }

        return deck;
    }
};