//
//  QueuePractice.cpp
//  CodingExamples
//
//  Created by Kostiantyn Karlash on 04.04.20.
//  Copyright © 2020 Kostiantyn Karlash. All rights reserved.
//

#include <stdio.h>
#include "QueuePractice.h"
#include <unordered_set>
#include <queue>


QueuePractice::QueuePractice() {
    m_target = "0202";
    m_deadends = {"0201","0101","0102","1212","2002"};
    
}

int QueuePractice::openLock() {
    return openLock(m_deadends, m_target);
}

int QueuePractice::openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead_ends(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    
    string init = "0000";
    if (dead_ends.find(init) != dead_ends.end()) return -1;
    
    queue<string> q;
    q.push(init);
    visited.insert(init);
    
    int level = 0;
    
    while (q.empty() == false) {
        auto size = q.size();
        for (int i = 0; i < size; ++i) {
            auto lock_state = q.front();
            q.pop();
            vector<string> nxtStates = nextStates(lock_state);
            for (auto item: nxtStates) {
                if (item == target) return ++level;
                if (visited.find(item) != visited.end()) continue;
                if (dead_ends.find(item) == dead_ends.end()) {
                    q.push(item);
                    visited.insert(item);
                }
            }
        }
        level++;
    }
    return -1;
}

int QueuePractice::numSquares(int n) {
    if (n <= 0) return 0;
    vector<int> squares;
    vector<int> takenSquares(n);
    queue<int> bfs;
    
    for (int i = 0; i*i <= n; ++i) {
        squares.push_back(i * i);
        takenSquares[i - 1] = 1;
    }
    
    if (squares.back() == n) return 1;
    
    for (const auto& item: squares) {
        bfs.push(item);
    }
    
    int count = 1;
    while (bfs.empty() == false) {
        count++;
        int size = bfs.size();
        for (int i = 0; i < size; ++i) {
            int tmp = bfs.front();
            for (const auto& square: squares) {
                if (tmp + square > n) break;
                if (tmp + square == n) return count;
                if ((tmp + square < n) && takenSquares[tmp + square - 1] == 0) {
                    takenSquares[tmp + square - 1] = 1;
                    bfs.push(tmp + square);
                    
                }
            }
            bfs.pop();
        }
    }
    
    return 0;
}

vector<string> QueuePractice::nextStates(string state) {
    vector<string> result;
    for (int i = 0; i < 4; ++i) {
        string tmp = state;
        tmp[i] = (state[i] - '0' + 1) % 10 + '0';
        result.push_back(tmp);
        tmp[i] = (state[i] - '0' - 1 + 10) % 10 + '0';
        result.push_back(tmp);
    }
    return result;
}
