#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "avl_node.h"


void checkInsert() {
    avl_tree<int, int> a = avl_tree<int, int>();
    a.head = a.insert_node(a.head, 1);
    a.head = a.insert_node(a.head, 2);
    a.head = a.insert_node(a.head, 4);
    a.head = a.insert_node(a.head, 20);
    a.head = a.insert_node(a.head, 3);
    a.head = a.insert_node(a.head, 5);
    a.head = a.insert_node(a.head, 7);
    a.head = a.insert_node(a.head, 21);
    try {
        a.head = a.insert_node(a.head, 5);
    } catch (avl_tree<int, int>::AlreadyExistsInTree &e) {
        std::cout << "Working!!! - 5 is Already in the tree" << std::endl;
    }
    try {
        a.head = a.insert_node(a.head, 7);
    } catch (avl_tree<int, int>::AlreadyExistsInTree &e) {
        std::cout << "Working!!! - 7 is Already in the tree" << std::endl;
    }
    a.head = a.insert_node(a.head, 8);
    try {
        a.head = a.insert_node(a.head, 8);
    } catch (avl_tree<int, int>::AlreadyExistsInTree &e) {
        std::cout << "Working!!! - 8 is Already in the tree" << std::endl;
    }
    a.head = a.insert_node(a.head, 99);
    a.head = a.insert_node(a.head, 100);
    system("Color A4");
    std::cout << "-----------------checkInsert---------------" << std::endl;
    std::cout << "in order" << std::endl;
    a.inOrder(a.head);
    std::cout << "\npre order" << std::endl;
    a.preOrder(a.head);
}

bool isExists() {
    system("Color A4");
    std::cout << "-----------------isExists---------------" << std::endl;
    avl_tree<int, int> a = avl_tree<int, int>();
    a.head = a.insert_node(a.head, 1);
    a.head = a.insert_node(a.head, 2);
    a.head = a.insert_node(a.head, 4);
    a.head = a.insert_node(a.head, 20);
    a.head = a.insert_node(a.head, 3);
    a.head = a.insert_node(a.head, 5);
    a.head = a.insert_node(a.head, 7);
    a.head = a.insert_node(a.head, 21);
    a.head = a.insert_node(a.head, 8);
    a.head = a.insert_node(a.head, 99);
    a.head = a.insert_node(a.head, 100);
    assert(a.exists_in_avl_tree(a.head, 20));
    assert(a.exists_in_avl_tree(a.head, 21));
    assert(a.exists_in_avl_tree(a.head, 100));
    assert(a.exists_in_avl_tree(a.head, 8));
    assert(a.exists_in_avl_tree(a.head, 3));
    assert(a.exists_in_avl_tree(a.head, 5));
    if (a.exists_in_avl_tree(a.head, 55))
        std::cout << "Problem - 55 is not in the fucking tree!!!" << std::endl;
    else
        std::cout << "" << std::endl;

}

void deleteNode() {
    system("Color A4");
    std::cout << "-----------------deleteNode---------------" << std::endl;
    avl_tree<int, int> a = avl_tree<int, int>();
    a.head = a.insert_node(a.head, 1);
    a.head = a.insert_node(a.head, 2);
    a.head = a.insert_node(a.head, 4);
    a.head = a.insert_node(a.head, 20);
    a.head = a.insert_node(a.head, 3);
    a.head = a.insert_node(a.head, 5);
    a.head = a.insert_node(a.head, 7);
    a.head = a.insert_node(a.head, 21);
    a.head = a.insert_node(a.head, 8);
    a.head = a.insert_node(a.head, 99);
    a.head = a.insert_node(a.head, 100);
    try {
        a.removeNode(3);
        a.removeNode(5);
//        a.removeNode(3);
        a.removeNode(20);
        a.removeNode(2);
        a.removeNode(21);

    } catch (avl_tree<int, int>::DataNotInTree &e) {
        std::cout << "3 is not in the tree" << std::endl;
    }
    std::cout << "in order" << std::endl;
    a.inOrder(a.head);
    std::cout << "\npre order" << std::endl;
    a.preOrder(a.head);
}

void extractToArray() {
    system("Color A4");
    std::cout << "-----------------extractToArray---------------" << std::endl;
    avl_tree<int, int> a = avl_tree<int, int>();
    a.head = a.insert_node(a.head, 1);
    a.head = a.insert_node(a.head, 2);
    a.head = a.insert_node(a.head, 4);
    a.head = a.insert_node(a.head, 20);
    a.head = a.insert_node(a.head, 3);
    a.head = a.insert_node(a.head, 5);
    a.head = a.insert_node(a.head, 7);
    a.head = a.insert_node(a.head, 21);
    a.head = a.insert_node(a.head, 8);
    a.head = a.insert_node(a.head, 99);
    a.head = a.insert_node(a.head, 100);
    int sizeTree = a.countAvlNodes();
    assert(sizeTree == 11);
    int *arr = a.extract_data_to_array(sizeTree);

    std::cout << "arr:" << std::endl;
    for (int i = 0; i < sizeTree; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\nin order" << std::endl;
    a.inOrder(a.head);

}

void createAvlOutOfArr() {
    system("Color A4");
    std::cout << "-----------------createAvlOutOfArr---------------" << std::endl;
    avl_tree<int, int> a = avl_tree<int, int>();
    avl_tree<int, int> b =avl_tree<int, int>();
    a.head = a.insert_node(a.head, 1);
    a.head = a.insert_node(a.head, 2);
    a.head = a.insert_node(a.head, 4);
    a.head = a.insert_node(a.head, 20);
    a.head = a.insert_node(a.head, 3);
    a.head = a.insert_node(a.head, 5);
    a.head = a.insert_node(a.head, 7);
    a.head = a.insert_node(a.head, 21);
    a.head = a.insert_node(a.head, 8);
    a.head = a.insert_node(a.head, 99);
    a.head = a.insert_node(a.head, 100);
    int sizeTree = a.countAvlNodes();
    assert(sizeTree == 11);
    int *arr = a.extract_data_to_array(sizeTree);
    a.array_to_tree(arr,sizeTree,&b);
    system("Color A4");
    std::cout << "in order a:" << std::endl;
    a.inOrder(a.head);
    std::cout << "\npre order a:"<< std::endl;
    a.preOrder(a.head);
    std::cout << "\n\nin order b:" << std::endl;
    b.inOrder(b.head);
    std::cout << "\npre order b:" << std::endl;
    b.preOrder(b.head);
}

int main() {
//    checkInsert();
//    isExists();
//    deleteNode();
//    extractToArray();
    createAvlOutOfArr();
    return 0;
}