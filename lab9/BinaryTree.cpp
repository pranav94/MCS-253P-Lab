#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<string> LevelString;

void tokenzie(LevelString &levelNodes, string levelString)
{
    stringstream ss;
    ss << levelString;
    while (ss.good())
    {
        string t;
        getline(ss, t, ',');
        levelNodes.push_back(t);
    }
}

string getFileName()
{
    cout << "Enter file name: ";
    string ip;
    cin >> ip;
    return ip;
}

class TreeNode
{
  public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data);
};

TreeNode::TreeNode(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

typedef vector<TreeNode *> Level;
typedef vector<Level> Levels;

class BinaryTree
{
  public:
    TreeNode *root;
    BinaryTree() { root = nullptr; };
    ~BinaryTree();
    void readTree();
    void writeTree();
    void loadTree(LevelString levels);
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
    void deleteTree();
    void inorder(TreeNode *root);
    void preorder(TreeNode *root);
    void postorder(TreeNode *root);
    void levelorder(Levels &levels, TreeNode *root, int level);
    void deleteTree(TreeNode *root);
};

BinaryTree::~BinaryTree()
{
    deleteTree(root);
}

void BinaryTree::levelorder()
{
    Levels levels;
    levelorder(levels, root, 0);
    levels.pop_back();
    for (Level &level : levels)
    {
        for (TreeNode *&node : level)
            if (node != nullptr)
                cout << node->data << " ";
        cout << endl;
    }
}

void BinaryTree::levelorder(Levels &levels, TreeNode *node, int level)
{
    if ((int)levels.size() == level)
        levels.push_back(Level());
    if (node == nullptr)
    {
        levels[level].push_back(nullptr);
        return;
    }
    levels[level].push_back(node);
    levelorder(levels, node->left, level + 1);
    levelorder(levels, node->right, level + 1);
}

void BinaryTree::loadTree(LevelString levels)
{
    if (levels.size() == 0)
    {
        root = nullptr;
        return;
    }
    root = new TreeNode(stoi(levels[0]));
    Levels nodes;
    nodes.push_back(Level());
    nodes[0].push_back(root);
    for (int level = 1; level < (int)levels.size(); level++)
    {
        nodes.push_back(Level());
        int j = 0;
        LevelString levelNodes;
        tokenzie(levelNodes, levels[level]);
        for (int i = 0; i < (int)nodes[level - 1].size(); i++)
        {
            TreeNode *node = nodes[level - 1][i];
            if (node == nullptr)
                continue;
            TreeNode *leftChild = nullptr;
            TreeNode *rightChild = nullptr;
            if (j < (int)levelNodes.size() && levelNodes[j] != "")
                leftChild = new TreeNode(stoi(levelNodes[j]));
            j++;

            if (j < (int)levelNodes.size() && levelNodes[j] != "")
                rightChild = new TreeNode(stoi(levelNodes[j]));
            j++;

            node->left = leftChild;
            node->right = rightChild;
            nodes[i + 1].push_back(leftChild);
            nodes[i + 1].push_back(rightChild);
        }
    }
}

void readLevels(LevelString &levels)
{
    string level;
    ifstream inputFile(getFileName());
    if (!inputFile.good())
        cout << "File does not exist" << endl;
    else
        while (getline(inputFile, level))
            levels.push_back(level);
    inputFile.close();
}

void BinaryTree::readTree()
{
    string level;
    LevelString levels;
    readLevels(levels);
    loadTree(levels);
}

void BinaryTree::writeTree()
{
    string op = getFileName();
    Levels levels;
    levelorder(levels, root, 0);
    ofstream ofile;
    ofile.open(op);
    for (Level &level : levels)
    {
        for (TreeNode *&node : level)
            if (node != nullptr)
                ofile << node->data << ",";
            else
                ofile << ",";
        ofile << endl;
    }
    ofile.close();
}

void BinaryTree::inorder()
{
    cout << "Inorder: ";
    inorder(root);
}

void BinaryTree::preorder()
{
    cout << "Pre-order: ";
    preorder(root);
}

void BinaryTree::postorder()
{
    cout << "Post-order: ";
    postorder(root);
}

void BinaryTree::deleteTree()
{
    deleteTree(root);
}

void BinaryTree::inorder(TreeNode *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void BinaryTree::preorder(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BinaryTree::postorder(TreeNode *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void BinaryTree::deleteTree(TreeNode *root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void printOptions()
{
    cout << endl
         << endl;
    cout << "Enter command:" << endl;
    cout << "1: Read tree" << endl;
    cout << "2: Write tree" << endl;
    cout << "3: Inorder" << endl;
    cout << "4: Pre-order" << endl;
    cout << "5: Post-order" << endl;
    cout << "6: Level order" << endl;
}

void parseCmd(BinaryTree &tree)
{
    int input;
    cin >> input;
    cout << endl;
    switch (input)
    {
    case 1:
        tree.readTree();
        break;
    case 2:
        tree.writeTree();
        break;
    case 3:
        tree.inorder();
        break;
    case 4:
        tree.preorder();
        break;
    case 5:
        tree.postorder();
        break;
    case 6:
        tree.levelorder();
        break;

    default:
        break;
    }
}

int main()
{
    BinaryTree tree = BinaryTree();
    while (!cin.eof())
    {
        printOptions();
        parseCmd(tree);
    }
    cout << endl;
    return 0;
}
