#include <iostream>
using namespace std;

class TreeNode
{
  private:
  public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data);
    ~TreeNode();
};

TreeNode::TreeNode(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

TreeNode::~TreeNode()
{
    if(left != nullptr)
        (*left).~TreeNode();
    if(right != nullptr)
        (*right).~TreeNode();
}

class BinaryTree
{
  private:
    /* data */
  public:
    TreeNode *root;
    BinaryTree();
    ~BinaryTree();
};

BinaryTree::BinaryTree()
{
    this->root = new TreeNode(4);
    this->root->left = new TreeNode(2);
    this->root->right = new TreeNode(5);
    this->root->left->left = new TreeNode(4);
    this->root->right->left = new TreeNode(6);
    cout << this->root->data << " " << this->root->left->data << " " << this->root->right->data;
}

BinaryTree::~BinaryTree()
{
}

int main()
{
    BinaryTree tree = BinaryTree();
    return 0;
}
