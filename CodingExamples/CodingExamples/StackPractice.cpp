//
//  StackPractice.cpp
//  CodingExamples
//
//  Created by Kostiantyn Karlash on 06.05.20.
//  Copyright © 2020 Kostiantyn Karlash. All rights reserved.
//

#include "StackPractice.hpp"
#include <stack>
#include <utility>

#include <iostream>

StackPractice::StackPractice() {
    m_grid = {
    {1, 1, 1, 1, 0},
    {1, 1, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    };
    
    std::cout << "Result is:" << numIslands(m_grid);
}

int StackPractice::numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) return 0;
    int result = 0;
    stack<pair<int, int>> st;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                st.push({i, j});
                while (st.empty() == false) {
                    auto indexes = st.top();
                    st.pop();
                    grid[indexes.first][indexes.second] = '0';
                    if (indexes.first + 1 < grid.size() &&
                        grid[indexes.first + 1][indexes.second] == '1') {
                        st.push({indexes.first + 1, indexes.second});
                    }
                    if (indexes.first - 1 >= 0 &&
                        grid[indexes.first -1 ][indexes.second] == '1') {
                        st.push({indexes.first - 1, indexes.second});
                    }
                    if (indexes.second + 1 < grid[indexes.first].size() &&
                        grid[indexes.first][indexes.second + 1] == '1') {
                        st.push({indexes.first, indexes.second + 1});
                    }
                    if (indexes.second - 1 >= 0 &&
                        grid[indexes.first][indexes.second - 1] == '1') {
                        st.push({indexes.first, indexes.second - 1});
                    }
                }
                result++;
            }
        }
    }
    return result;
}

