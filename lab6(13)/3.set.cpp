#include <iostream>

using namespace std;

struct node {
    node *left = nullptr;
    node *right = nullptr;
    int key = 0, index = 0, height = 0;

    node(int k) {
        key = k;
        left = right = nullptr;
        height = index = 0;
    };

    node() {}
};

struct tree {
    node *root = nullptr;

    int height(node *root) {
        if (root != nullptr) {
            return root->height;
        } else {
            return 0;
        }
    }

    int balancing(node *root) {
        return height(root->right) - height(root->left);
    }

    void new_height(node *root) {
        if (root->left != nullptr) {
            new_height(root->left);
        }
        if (root->right != nullptr) {
            new_height(root->right);
        }

        root->height = max(height(root->left), height(root->right)) + 1;
    }

    node *rotate_right(node *tree) {
        node *tree_new = tree->left;;
        tree->left = tree_new->right;
        tree_new->right = tree;
        new_height(tree);
        new_height(tree_new);
        return tree_new;
    }

    node *rotate_left(node *tree) {
        node *tree_new = tree->right;
        tree->right = tree_new->left;
        tree_new->left = tree;
        new_height(tree);
        new_height(tree_new);
        return tree_new;
    }

    node *balance(node *tree) {
        new_height(tree);
        if (balancing(tree) == -2) {
            if (balancing(tree->left) > 0) {
                tree->left = rotate_left(tree->left);
            }
            return rotate_right(tree);

        }
        if (balancing(tree) == 2) {
            if (balancing(tree->right) < 0) {
                tree->right = rotate_right(tree->right);
            }
            return rotate_left(tree);
        }
        return tree;
    }

    node *insert(int key, node *root) {
        if (root == nullptr) {
            return new node(key);
        }

        if (key < root->key) {
            root->left = insert(key, root->left);
        } else {
            root->right = insert(key, root->right);
        }

        return balance(root);
    }

    void index_res(char *what, node *tree, int &i) {
        if (tree == nullptr) {
            return;
        }

        if (what == "index") {

            tree->index = i;
            i++;
            char *gg = "index";
            index_res(gg, tree->left, i);
            index_res(gg, tree->right, i);

        } else if (what == "res") {

            cout << tree->key << " ";
            if (tree->left != nullptr) {
                cout << tree->left->index << " ";
            } else {
                cout << 0 << " ";
            }
            if (tree->right != nullptr) {
                cout << tree->right->index << " ";
            } else {
                cout << 0 << " ";
            }
            cout << "\n";

            int res = -1;
            char *gg = "res";
            index_res(gg, tree->left, res);
            index_res(gg, tree->right, res);
        }
    }

    node *find(int item, node *avl) {
        while (avl != nullptr && avl->key != item) {
            if (item < avl->key) {
                avl = avl->left;
            } else {
                avl = avl->right;
            }
        }
        return avl;
    }
};

int my_hash(int numb) {
    return numb % 9999;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    if (N == 0) {
        cout << "YES";
        return 0;
    }

    tree hashTable[9999];

    for (int i = 0; i < N; i++) {
        int numb;
        cin >> numb;

        int index = my_hash(numb);
        hashTable[index].root = hashTable[index].insert(numb, hashTable[index].root);
    }

    bool check = false;
    for (int i = 0; i < N; i++) {
        int numb;
        cin >> numb;

        int index = my_hash(numb);
        if (hashTable[index].find(numb, hashTable[index].root) != nullptr) {
            check = true;
        } else {
            check = false;
            break;
        }
    }

    check ? cout << "YES" : cout << "NO";
    return 0;
}
