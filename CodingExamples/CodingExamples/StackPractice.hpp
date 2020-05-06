//
//  StackPractice.hpp
//  CodingExamples
//
//  Created by Kostiantyn Karlash on 06.05.20.
//  Copyright © 2020 Kostiantyn Karlash. All rights reserved.
//

#ifndef StackPractice_hpp
#define StackPractice_hpp

#include <vector>
#include <stdio.h>
using namespace std;

class StackPractice {
public:
    StackPractice();
    int numIslands(vector<vector<char>>& grid);
    
private:
    vector<vector<char>> m_grid;
};
#endif /* StackPractice_hpp */
