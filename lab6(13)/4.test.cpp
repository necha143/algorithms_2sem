#include <iostream>
#include <vector>

using namespace std;

struct node {
    node *left = nullptr;
    node *right = nullptr;
    int key = 0, index = 0, height = 0, point = 0;

    node(int k, int points) {
        key = k;
        point = points;
        left = right = nullptr;
        height = index = 0;
    };

    node() {}
};

struct tree {
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

    node *insert(int key, int points, node *tree) {
        if (tree == nullptr) {
            return new node(key, points);
        }

        if (key < tree->key) {
            tree->left = insert(key, points, tree->left);
        } else {
            tree->right = insert(key, points, tree->right);
        }

        return balance(tree);
    }

    node *del(int elem, node *root) {
        if (root == nullptr) {
            return root;
        }

        if (elem < root->key) {
            root->left = del(elem, root->left);
        } else if (elem > root->key) {
            root->right = del(elem, root->right);

        } else if (root->left != nullptr && root->right != nullptr) {
            root->key = maxElem(root->left)->key;
            root->point = maxElem(root->left)->point;
            root->left = del(root->key, root->left);

        } else {
            if (root->left != nullptr) {
                root = root->left;
            } else if (root->right != nullptr) {
                root = root->right;
            } else {
                root = nullptr;
            }
        }

        if (root == nullptr) {
            return root;
        }

        return balance(root);
    }

    node *maxElem(node *tree) {
        if (tree->right == nullptr) {
            return tree;
        } else {
            return maxElem(tree->right);
        }
    }

    void sum(int &summ, int &count, node *root) {
        if (root != nullptr) {
            sum(summ, count, root->left);
            sum(summ, count, root->right);
            summ += root->point;
            count++;
        }
    }

    void maxx(int &maxP, node *root) {
        if (root != nullptr) {
            maxx(maxP, root->left);
            maxx(maxP, root->right);
            maxP = max(maxP, root->point);
        }
    }

} AVL;

int my_hash(int numb) {
    return numb % 999999;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, Q;
    cin >> M >> Q;

    node *marks[999999];

    for (int i = 0; i < Q; i++) {
        char what;
        cin >> what;
        switch (what) {
            case 'a': {
                int group, summ = 0, cnt = 0;
                cin >> group;
                AVL.sum(summ, cnt, marks[my_hash(group)]);
                cnt == 0 ? cout << 0 << "\n" : cout << summ / cnt << "\n";
                break;
            }
            case '-': {
                int group, isu;
                cin >> group >> isu;
                marks[my_hash(group)] = AVL.del(isu, marks[my_hash(group)]);
                break;
            }
            case '+': {
                int group, isu, points;
                cin >> group >> isu >> points;
                marks[my_hash(group)] = AVL.insert(isu, points, marks[my_hash(group)]);
                break;
            }
            case 'm': {
                int group, maxP = 0;
                cin >> group;
                AVL.maxx(maxP, marks[my_hash(group)]);
                cout << maxP << "\n";
                break;
            }
        }
    }
    return 0;
}