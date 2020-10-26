#include <iostream>
#include <string>

using namespace std;

struct TreeNode // builds tree structure
{
    string games;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(string g)
    {
        games = g;
        left = nullptr;
        right = nullptr;
    }

};

void in_order_tree_walk(TreeNode* root) // method for tree
{
    if (root != nullptr)
    {
        in_order_tree_walk(root->left);
        cout << root->games << '\n';
        in_order_tree_walk(root->right);
    }
}

TreeNode* insertValue(TreeNode* root, string newValue) // method for insertion
{
    if (root == nullptr)
    {
        root = new TreeNode(newValue);
        return root;
    }
    if (root->games > newValue)
    {
        root->left = insertValue(root->left, newValue);
    }
    else {
        root->right = insertValue(root->right, newValue);
    }
    return root;
}

string leftTraversal(TreeNode* root) // method for traversing left
{

    root = root->left;
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->games;
}

string rightTraversal(TreeNode* root) // method for traversing right
{

    root = root->right;
    while (root->left != nullptr)
    {
        root = root->left;
    }

    return root->games;
}


TreeNode* deleteValue(TreeNode* root, string value) // method for deletion
{
    if (root == nullptr)
    {
        return root;
    }
    if (root->games > value)
    {
        root->left = deleteValue(root->left, value);
    }
    else if (root->games < value)
    {
        root->right = deleteValue(root->right, value);
    }
    else {
        if (root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
        }
        else if (root->left != nullptr)
        {
            root->games = leftTraversal(root);
            root->left = deleteValue(root->left, root->games);
        }
        else {

            root->games = rightTraversal(root);
            root->right = deleteValue(root->right, root->games);
        }
    }
    return root;
}

int main() { // main method
    struct TreeNode* root = new TreeNode("The Last of Us 2");
    root->left = new TreeNode("Command & Conquer Remastered");
    root->right = new TreeNode("Red Dead Redemption 2");

    root->left->left = new TreeNode("Among Us");
    root->left->right = new TreeNode("Genshin Impact");
    root->left->right->left = new TreeNode("DOOM Eternal");
    root->left->right->right = new TreeNode("Minecraft");

    root->right->left = new TreeNode("Rising Storm 2 Vietnam");
    root->right->right = new TreeNode("Spongebob Squarepants Rehydrated");

    in_order_tree_walk(root);
    cout << '\n';
    insertValue(root, "Rimworld");
    insertValue(root, "Warcraft 3 Reforged");
    cout << "Succesfully inserted Rising Storm 2 Vietnam and Warcraft 3 Reforged. The final tree structure is: " << '\n';
    in_order_tree_walk(root);
    cout << '\n';
    deleteValue(root, "The Last of Us 2");
    cout << "Succesfully deleted The Last of Us 2. The final tree structure is: " << '\n';
    in_order_tree_walk(root);
}