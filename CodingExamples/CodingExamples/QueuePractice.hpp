//
//  QueuePractice.cpp
//  CodingExamples
//
//  Created by Kostiantyn Karlash on 04.04.20.
//  Copyright © 2020 Kostiantyn Karlash. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

class QueuePractice {
public:
    QueuePractice();
    
    int openLock();
    int openLock(vector<string>& deadends, string target);
    vector<string> nextStates(string state);
    
private:
    string m_target;
    vector<string> m_deadends;
    int numSquares(int n);
};
