//
//  binarytree.cpp
//  CodingExamples
//
//  Created by Kostiantyn Karlash on 15.01.20.
//  Copyright © 2020 Kostiantyn Karlash. All rights reserved.
//

#include "binarytree.h"
#include <iostream>

BinaryTree::BinaryTree() {
    m_root = nullptr;
}

TreeNode* BinaryTree::root() {
    return m_root;
}

int BinaryTree::maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

void BinaryTree::printTree() {
    printNode(m_root);
}

void BinaryTree::printNode(TreeNode* node) {
    if (node == nullptr) return;
    printNode(node->left);
    std::cout<<" "<<node->val<<" ";
    printNode(node->right);
}

bool BinaryTree::isEmpty() const {
    return m_root == nullptr;
}

bool BinaryTree::isMirror(TreeNode* node1, TreeNode* node2) {
    if (node1 == nullptr && node2 == nullptr) return true;
    return node1 != nullptr && node2 != nullptr &&
    node1->val == node2->val &&
    isMirror(node1->left, node2->right) &&
    isMirror(node1->right, node2->left);
}

bool BinaryTree::isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}

bool BinaryTree::hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) return false;
    int subSum = sum - root->val;
    if (subSum == 0 && root->left == nullptr && root->right == nullptr) return true;
    bool result = false;
    if (root->left != nullptr) result = result || hasPathSum(root->left, subSum);
    if (root->right != nullptr) result = result || hasPathSum(root->right, subSum);
    return result;
}

TreeNode* BinaryTree::buildTree(vector<int>& inorder, vector<int>& postorder) {
    int pIndex = postorder.size() - 1;
    return buildSubTree(inorder, postorder, 0, inorder.size() - 1, &pIndex);
}

TreeNode* BinaryTree::buildSubTree(vector<int>& inorder, vector<int>& postorder, int inStrt, int inEnd, int* pIndex) {
    if (inStrt > inEnd) return nullptr;
    TreeNode* node = new TreeNode(postorder[*pIndex]);
    (*pIndex)--;
    if (inStrt == inEnd) return node;
    int iIndex = searchIndexByVal(inorder, inStrt, inEnd, node->val);
    node->right = buildSubTree(inorder, postorder, iIndex + 1, inEnd, pIndex);
    node->left = buildSubTree(inorder, postorder, inStrt, iIndex - 1, pIndex);
    return node;
}

TreeNode* BinaryTree::buildSubTree(vector<int>& inorder, vector<int>&  preorder, int inStrt, int inEnd)
{
    static int preIndex = 0;
    if (inStrt > inEnd) return nullptr;
    if (preIndex < 0 || preIndex >= preorder.size()) return nullptr;
    TreeNode* node = new TreeNode(preorder[preIndex++]);
    if (inStrt == inEnd) return node;
    int inIndex = searchIndexByVal(inorder, inStrt, inEnd, node->val);
    node->left = buildSubTree(inorder, preorder, inStrt, inIndex - 1);
    node->right = buildSubTree(inorder, preorder, inIndex + 1, inEnd);
    return node;
}

int BinaryTree::searchIndexByVal(vector<int>& arr, int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}

vector<int> BinaryTree::preorderTraversal(TreeNode* root) {
    if (root == nullptr) return m_vectorView;
    if (root->left != nullptr) preorderTraversal(root->left);
    m_vectorView.push_back(root->val);
    if (root->right != nullptr) preorderTraversal(root->right);
    return m_vectorView;
}

vector< vector<int> > BinaryTree::levelOrder(TreeNode *root) {
    vector< vector<int> > matrix;
    return matrix;
}

void BinaryTree::insertNode(int value) {
    TreeNode* node = new TreeNode(0);
    TreeNode* parent;
    node->val = value;
    node->left = nullptr;
    node->right = nullptr;
    parent = nullptr;
    if (isEmpty())
        m_root = node;
    else {
        TreeNode* tmp;
        tmp = m_root;
        while(tmp != nullptr) {
            parent = tmp;
            if (value > tmp->val)
                tmp = tmp->right;
            else
                tmp = tmp->left;
        }
        if(value < parent->val)
            parent->left = node;
        else
            parent->right = node;
    }
}
