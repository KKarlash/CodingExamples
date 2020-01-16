//
//  main.cpp
//  CodingExamples
//
//  Created by Kostiantyn Karlash on 08.01.20.
//  Copyright © 2020 Kostiantyn Karlash. All rights reserved.
//

#include <iostream>
#include "binarytree.h"

using namespace std;

int main(int argc, const char * argv[]) {
    BinaryTree tree;
    tree.insertNode(20);
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(40);
    tree.insertNode(45);
    tree.insertNode(30);
   // cout << "Binary Tree filled out." << endl;
   // cout << tree.maxDepth(tree.root()) << endl;
    std::vector<int> posorder {0, 3, 2, 12, 4, 5, 23, 2};
    std::vector<int> vec {12, 3, 23};
    
    int lookFor = 12;
    
    auto rootValPtr = std::find(posorder.begin(), posorder.end(), lookFor);
    if (rootValPtr != posorder.end()) {
        vector<int> left(posorder.begin(), rootValPtr);
        vector<int> right(rootValPtr + 1, posorder.end());
        
        cout << "Lefr vector: " << endl;
        for (auto item: left) {
            cout << item << " ";
        }
        cout << std::endl;
        
        cout << "Right vector: " << endl;
        for (auto item: right) {
            cout << item << " ";
        }
        cout << std::endl;
    }
    

    
    return 0;
}
