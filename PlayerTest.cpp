//
// Created by Dvir on 5/7/2018.
//
#include <iostream>
#include "Player.h"
#include "avl_node.h"


void printAvlTree(avl_tree<Player, updateClanPred> &avl) {
    std::cout << "inOrder:" << std::endl;
    avl.inOrder(avl.head);
    std::cout << std::endl;
    std::cout << "preOrder:" << std::endl;
    avl.preOrder(avl.head);
    std::cout << std::endl;
    std::cout << "nodes:" << avl.countAvlNodes()<< std::endl;
    std::cout << "_________________________________" << std::endl;
}

int main() {

    avl_tree<Player, updateClanPred> avl;
    Player p1 (1,0);
    Player p2 (5,12);
    Player p3 (4,0);
    Player p4 (3,2);
    Player p5 (9,2);
    p1.changeTreeType(SORT_BY_ID);
    p2.changeTreeType(SORT_BY_ID);
    p3.changeTreeType(SORT_BY_ID);
    p4.changeTreeType(SORT_BY_ID);
    p5.changeTreeType(SORT_BY_ID);
    avl.head = avl.insert_node(avl.head, p1);
    avl.head = avl.insert_node(avl.head, p2);
    avl.head = avl.insert_node(avl.head, p3);
    avl.head = avl.insert_node(avl.head, p4);
    avl.head = avl.insert_node(avl.head, p5);
    printAvlTree(avl);
    avl.removeNode(p1);
    avl.removeNode(p2);
    avl.removeNode(p3);
    avl.removeNode(p4);
    avl.removeNode(p5);


    p1.changeTreeType(SORT_BY_COINS);
    p2.changeTreeType(SORT_BY_COINS);
    p3.changeTreeType(SORT_BY_COINS);
    p4.changeTreeType(SORT_BY_COINS);
    p5.changeTreeType(SORT_BY_COINS);
    avl.head = avl.insert_node(avl.head, p1);
    avl.head = avl.insert_node(avl.head, p2);
    avl.head = avl.insert_node(avl.head, p3);
    avl.head = avl.insert_node(avl.head, p4);
    avl.head = avl.insert_node(avl.head, p5);
    printAvlTree(avl);
    avl.removeNode(p1);
    avl.removeNode(p2);
    avl.removeNode(p3);
    avl.removeNode(p4);
    avl.removeNode(p5);



    p1.addCoins(22);
    Player p;
    p = p1;


//    std::cout << "Hello, World!" << std::endl;
    return 0;
}