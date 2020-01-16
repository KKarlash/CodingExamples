//
//  binarytree.h
//  CodingExamples
//
//  Created by Kostiantyn Karlash on 08.01.20.
//  Copyright © 2020 Kostiantyn Karlash. All rights reserved.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    BinaryTree();

    TreeNode* root();
    int maxDepth(TreeNode* root);
    void printTree();
    void printNode(TreeNode* node);

    bool isEmpty() const;
    bool isMirror(TreeNode* node1, TreeNode* node2);
    bool isSymmetric(TreeNode* root);
    bool hasPathSum(TreeNode* root, int sum);
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, int inStrt, int inEnd, int* pIndex);
    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& preorder, int inStrt, int inEnd);
   
    int searchIndexByVal(vector<int>& arr, int strt, int end, int value);
    vector<int> preorderTraversal(TreeNode* root);
    vector< vector<int> > levelOrder(TreeNode *root);
    void insertNode(int value);

private:
    TreeNode* m_root;
    vector<int> m_vectorView;
};

#endif // BINARYTREE_H
