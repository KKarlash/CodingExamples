#ifndef BINARYTREE_H
#define BINARYTREE_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    BinaryTree() {m_root = nullptr;}
    //TODO ~BinaryTree(){}

    void insertNode(int value) {
        TreeNode* node = new TreeNode;
        TreeNode* parent;
        node->val = value;
        node->left = nullptr;
        node->right = nullptr;
        parent = nullptr;
        if (isEmpty () )
            m_root = node;
        else{
            TreeNode* tmp;
            tmp = m_root;
            while (tmp != nullptr) {
                parent = tmp;
                if (value > tmp->val)
                    tmp = tmp->right;
                else
                    tmp = tmp->left;
            }
            if (value < parent->val)
                parent->left = node;
            else
                parent->right = node;
        }
    }

    void printTree() {
        printNode(m_root);
    }
private:
    bool isEmpty() const {return m_root == nullptr;}
    void printNode(TreeNode* node) {
        if (node == nullptr) return;
        printNode(node->left);
        std::cout<<" "<<node->val<<" ";
        printNode(node->right);
    }

    TreeNode* m_root;
};

#endif // BINARYTREE_H
