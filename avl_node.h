//
// Created by Dvir on 01/05/2018.
//
#include<iostream>
#include<cstdio>
#include <cmath>

using namespace std;

#ifndef HW1DS_AVL_NODE_H
#define HW1DS_AVL_NODE_H


template<typename T>
struct avl_node {
    T data;
    struct avl_node *right;
    struct avl_node *left;
    int heightRight;
    int heightLeft;
    //    struct avl_node *father;
};


template<typename T, typename Pred>
class avl_tree {

public:

    struct avl_node<T> *head;

    avl_tree() : head(nullptr) {};

    ~avl_tree();

    avl_node<T> *ll_rotate(avl_node<T> *node);

    avl_node<T> *lr_rotate(avl_node<T> *node);

    avl_node<T> *rr_rotate(avl_node<T> *node);

    avl_node<T> *rl_rotate(avl_node<T> *node);

    T *extract_data_to_array(int);

    avl_node<T> *removeNodeAux(avl_node<T> *root, avl_node<T> *father, const T
    &data);

    void removeNode(const T &data);

//
//    void delete_all_tree();

    avl_node<T> *balance(avl_node<T> *node);

    avl_node<T> *insert_node(avl_node<T> *root, T data);

    int bfCalculate(avl_node<T> *temp);

    void preOrder(avl_node<T> *head);

    void inOrder(avl_node<T> *head);

    void insert_into_array_aux(T *, int *, avl_node<T> *);

    void copyNode(avl_node<T> *const to, const avl_node<T> *from);

    void updateHeight(avl_node<T> *root);

    avl_node<T> *findNextByInorder(avl_node<T> *root);

    void UpdateInPreOrder(avl_node<T> *node, Pred pred);

    void updateNodeDataByFunction(Pred pred);

    void deleteAllNodes(avl_node<T> *node);

    int countAvlNodesAux(avl_node<T> *node);

    int countAvlNodes();

    void remove_unnessesery_nodes(int *sizeToRemove,
                                  avl_node<T> *node,
                                  avl_node<T> *father);

    //avlFinal should be built - using new before calling this function
    void array_to_tree(T *arr, int size, avl_tree<T, Pred>
    *avlFinal);

    avl_node<T> *build_empty_tree(int n, avl_node<T> *node);

    void updateTreeHeight(avl_node<T> *node);

    void insert_into_tree_from_array(int *size, T *arr, avl_node<T> *node,
                                     int *index);

    bool exists_in_avl_tree(avl_node<T> *, T data);


    class TreeException : public std::exception {
    };

    class DataNotInTree : TreeException {
    };

    class AlreadyExistsInTree : TreeException {
    };

};

template<typename T, typename Pred>
bool avl_tree<T, Pred>::exists_in_avl_tree(avl_node<T> *node, T data) {
    if (node == nullptr)
        return false;
    if (data == node->data)
        return true;
    return exists_in_avl_tree(node->left, data) || exists_in_avl_tree(node->right, data);
}


template<typename T, typename Pred>
avl_node<T> *avl_tree<T, Pred>::insert_node(avl_node<T> *root, T data) {
    if (root == nullptr) {
        root = new avl_node<T>;
        root->data = data; //copy assignment
        root->left = nullptr;
        root->right = nullptr;
        root->heightRight = 0;
        root->heightLeft = 0;
        return root;
    } else if (data < root->data) {
//        root->heightLeft++;
        root->left = insert_node(root->left, data);
        root->heightLeft =
                1 + (root->left->heightLeft > root->left->heightRight
                     ? root->left->heightLeft
                     : root->left->heightRight);
        root = balance(root);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
        root->heightRight = 1 +
                            (root->right->heightLeft >
                             root->right->heightRight
                             ? root->right->heightLeft
                             : root->right->heightRight);
        root = balance(root);
    } else if (data == root->data)
        throw AlreadyExistsInTree();
    return root;
}

template<typename T, typename Pred>
avl_node<T> *avl_tree<T, Pred>::rr_rotate(avl_node<T> *parent) {
    avl_node<T> *temp;
    temp = parent->right;
    parent->right = temp->left;
    if (parent->right == nullptr)
        parent->heightRight = 0;
    else
        parent->heightRight = (parent->right->heightLeft >
                               parent->right->heightRight
                               ? 1 + parent->right->heightLeft
                               : 1 + parent->right->heightRight);
    temp->left = parent;
    if (temp->left == nullptr)
        temp->heightLeft = 0;
    else
        temp->heightLeft = (temp->left->heightLeft >
                            temp->left->heightRight ?
                            1 + temp->left->heightLeft
                                                    :
                            1 + temp->left->heightRight);
    return temp;
}

template<typename T, typename Pred>
avl_node<T> *avl_tree<T, Pred>::ll_rotate(avl_node<T> *parent) {
    avl_node<T> *temp;
    temp = parent->left;
    parent->left = temp->right;
    if (parent->left == nullptr)
        parent->heightLeft = 0;
    else
        parent->heightLeft = 1 + (parent->left->heightLeft >
                                  parent->left->heightRight
                                  ? parent->left->heightLeft
                                  : parent->left->heightRight);
    temp->right = parent;
    if (temp->right == nullptr)
        temp->heightRight = 0;
    else
        temp->heightRight = 1 + (temp->right->heightLeft >
                                 temp->right->heightRight
                                 ? temp->right->heightLeft
                                 : temp->right->heightRight);
    return temp;
}

template<typename T, typename Pred>
avl_node<T> *avl_tree<T, Pred>::lr_rotate(avl_node<T> *parent) {
    avl_node<T> *temp;
    temp = parent->left;
    parent->left = rr_rotate(temp);
    return ll_rotate(parent);
}

template<typename T, typename Pred>
avl_node<T> *avl_tree<T, Pred>::rl_rotate(avl_node<T> *parent) {
    avl_node<T> *temp;
    temp = parent->right;
    parent->right = ll_rotate(temp);
    return rr_rotate(parent);
}

template<typename T, typename Pred>
avl_node<T> *avl_tree<T, Pred>::balance(avl_node<T> *temp) {
    int bal_factor = bfCalculate(temp);
    if (bal_factor > 1) {
        if (bfCalculate(temp->left) >= 0)
            temp = ll_rotate(temp);
        else
            temp = lr_rotate(temp);
    } else if (bal_factor < -1) {
        if (bfCalculate(temp->right) > 0)
            temp = rl_rotate(temp);
        else
            temp = rr_rotate(temp);
    }
    return temp;
}

template<typename T, typename Pred>
T *avl_tree<T, Pred>::extract_data_to_array(int size) {
    T *treeArray = new T[size];
    int i = 0;
    insert_into_array_aux(treeArray, &i, this->head);
    return treeArray;
}

template<typename T, typename Pred>
void avl_tree<T, Pred>::insert_into_array_aux(T *array, int *index,
                                              avl_node<T> *node) {
    if (node == nullptr)
        return;
    insert_into_array_aux(array, index, node->left);
    array[*index] = node->data;
    *index = *index + 1;
    insert_into_array_aux(array, index, node->right);
}

template<typename T, typename Pred>
void avl_tree<T, Pred>::copyNode(avl_node<T> *const to, const avl_node<T>
*from) {
    to->left = from->left;
    to->right = from->right;
    to->data = from->data;
    to->heightLeft = from->heightLeft;
    to->heightRight = from->heightRight;
};

template<typename T, typename Pred>
void avl_tree<T, Pred>::updateHeight(avl_node<T> *root) {
    if (root->left != nullptr) {
        root->heightLeft =
                (root->left->heightLeft > root->left->heightRight)
                ? 1 + root->left->heightLeft : 1 + root->left->heightRight;
    } else {
        root->heightLeft = 0;
    }

    if (root->right != nullptr) {
        root->heightRight =
                (root->right->heightLeft > root->right->heightRight)
                ? 1 + root->right->heightLeft : 1 +
                                                root->right->heightRight;
    } else {
        root->heightRight = 0;
    }
};

template<typename T, typename Pred>
avl_node<T> *avl_tree<T, Pred>::findNextByInorder(avl_node<T> *root) {
    avl_node<T> *temp = root;
    while (root != nullptr) {
        temp = root;
        root = root->left;
    }
    return temp;
};

template<typename T, typename Pred>
avl_node<T> *avl_tree<T, Pred>::removeNodeAux(avl_node<T> *root, avl_node<T>
*father, const T &data) {
    if (root == nullptr) {
        return root;
    }
    if (data < root->data) {
        removeNodeAux(root->left, root, data);
    } else if (data > root->data) {
        removeNodeAux(root->right, root, data);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            // case root with no children
            if (father != nullptr && father->right == root) {
                father->right = nullptr;
                father->heightRight = 0;
            } else if (father != nullptr && father->left == root) {
                father->left = nullptr;
                father->heightLeft = 0;
            } else {
                this->head = nullptr;
            }
            delete root;
            return father;
        } else if (root->left == nullptr || root->right == nullptr) {
//             case root has only one child
            avl_node<T> *child = (root->left == nullptr) ? root->right
                                                         : root->left;
            copyNode(root, child);
            delete child;
        } else {
            //case 2 childrens
            avl_node<T> *child = findNextByInorder(root->right);
            root->data = child->data;
            removeNodeAux(root->right, root, child->data);
        }
    }
    updateHeight(root);
    if (father != nullptr && father->right == root) {
        father->right = balance(root);
    } else if (father != nullptr && father->left == root) {
        father->left = balance(root);
    } else if (father == nullptr && ((root->heightLeft - root->heightRight) > 1 ||
                                     (root->heightLeft - root->heightRight) < -1)) {
        this->head = balance(root);
    } else {
        this->head = root;
    }
    return root;
}

template<typename T, typename Pred>
void avl_tree<T, Pred>::removeNode(const T &data) {
    if (!exists_in_avl_tree(this->head, data)) {
        throw DataNotInTree();
    }
    removeNodeAux(this->head, nullptr, data);
};

template<typename T, typename Pred>
int avl_tree<T, Pred>::bfCalculate(avl_node<T> *temp) {
    return temp == nullptr ? 0 : temp->heightLeft - temp->heightRight;
}

template<typename T, typename Pred>
void avl_tree<T, Pred>::inOrder(avl_node<T> *node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);
    cout << node->data << " ,";
    inOrder(node->right);
}

template<typename T, typename Pred>
void avl_tree<T, Pred>::preOrder(avl_node<T> *node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " ,";
    preOrder(node->left);
    preOrder(node->right);

}


template<typename T, typename Pred>
void avl_tree<T, Pred>::UpdateInPreOrder(avl_node<T> *node, Pred pred) {
    if (node == nullptr) {
        return;
    }
    pred(node->data);
    UpdateInPreOrder(node->left, pred);
    UpdateInPreOrder(node->right, pred);
}

template<typename T, typename Pred>
void avl_tree<T, Pred>::updateNodeDataByFunction(Pred pred) {
    UpdateInPreOrder(this->head, pred);
}


template<typename T, typename Pred>
void avl_tree<T, Pred>::deleteAllNodes(avl_node<T> *node) {
    if (node == nullptr) {
        return;
    }
    deleteAllNodes(node->left);
    deleteAllNodes(node->right);
    delete node;
}

template<typename T, typename Pred>
avl_tree<T, Pred>::~avl_tree() {
    deleteAllNodes(this->head);
}


template<typename T, typename Pred>
int avl_tree<T, Pred>::countAvlNodesAux(avl_node<T> *root) {
    if (root == nullptr)
        return 0;
    return 1 + countAvlNodesAux(root->left) +
           countAvlNodesAux(root->right);
}

template<typename T, typename Pred>
int avl_tree<T, Pred>::countAvlNodes() {
    return countAvlNodesAux(this->head);
}


template<typename T, typename Pred>
void avl_tree<T, Pred>::insert_into_tree_from_array(int *size, T *arr, avl_node<T> *node,
                                                    int *index) {
    if (*size == (*index))
        return;
    if (node == nullptr)
        return;
    this->insert_into_tree_from_array(size, arr, node->left, index);
    node->data = arr[*index];
    *index = *index + 1;
    this->insert_into_tree_from_array(size, arr, node->right, index);
}

template<typename T, typename Pred>
void avl_tree<T, Pred>::array_to_tree(T *arr, int size,
                                      avl_tree<T, Pred> *avlFinal) {
    if (arr == nullptr)
        return;
    double h = log2(size + 1) == ((int) (log2(size + 1))) ?
               (int) (log2(size + 1)) - 1 : (int) (log2(size + 1));
    int n = pow(2.0, h + 1) - 1;
//    build full tree
    avlFinal->head = build_empty_tree(n, avlFinal->head);
    n = n - size;
    remove_unnessesery_nodes(&n, avlFinal->head, nullptr);
    int i = 0;
    insert_into_tree_from_array(&size, arr, avlFinal->head, &i);
    updateTreeHeight(avlFinal->head);
}

template<typename T, typename Pred>
void avl_tree<T, Pred>::updateTreeHeight(avl_node<T> *node) {
    if (node == nullptr)
        return;
    updateTreeHeight(node->left);
    updateTreeHeight(node->right);
    updateHeight(node);
}


template<typename T, typename Pred>
avl_node<T> *avl_tree<T, Pred>::build_empty_tree(int n, avl_node<T> *node) {
    if (n <= 0)
        return nullptr;
    else if (node == nullptr) {
        node = new avl_node<T>;
        node->left = nullptr;
        node->right = nullptr;
//        node->data = nullptr;
        node->heightRight = 0;
        node->heightLeft = 0;
    }
    node->right = build_empty_tree(n - ((n / 2) + 1), node->right);
    node->left = build_empty_tree(n - ((n / 2) + 1), node->left);
    return node;
}

template<typename T, typename Pred>
void avl_tree<T, Pred>::remove_unnessesery_nodes(int *sizeToRemove, avl_node<T> *node,
                                                 avl_node<T> *father) {
    if (*sizeToRemove == 0)
        return;
    if (node->left == nullptr && node->right == nullptr) {
        if (father->right == node) {
            delete (node);
            node = nullptr;
            father->right = nullptr;
        } else {
            delete (node);
            node = nullptr;
            father->left = nullptr;
        }
        (*sizeToRemove)--;
        return;
    }
    remove_unnessesery_nodes(sizeToRemove, node->right, node);
    remove_unnessesery_nodes(sizeToRemove, node->left, node);
}

#endif //HW1DS_AVL_NODE_H
