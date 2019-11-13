#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
    BinaryTree tree;
    tree.insertNode(20);
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(40);
    tree.insertNode(45);
    tree.insertNode(30);
    cout << "Binary Tree printed out:" << endl;
    tree.printTree();
    return 0;
}
