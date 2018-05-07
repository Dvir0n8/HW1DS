
#include <iostream>
#include "Player.h"
#include "avl_node.h"

class changeData {
    int number;
    int newNum;
public:
    changeData(int num,int newNum):number(num),newNum(newNum){};
    bool operator()(int& n){
        if (n==number){
            n=newNum;
            return true;
        }
        return false;
    }
};



void printAvlTree(avl_tree<Player, changeData> &avl) {
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

    changeData c (4,12);
    avl_tree<Player, changeData> avl;
    Player p1 (1,0);
    Player p2 (5,12);
    Player p3 (4,0);
    Player p4 (3,2);
    Player p5 (9,2);
    avl.head = avl.insert_node(avl.head, p1);
//    avl.head = avl.insert_node(avl.head, p2);
//    avl.head = avl.insert_node(avl.head, p3);
//    avl.head = avl.insert_node(avl.head, p4);
//    avl.head = avl.insert_node(avl.head, p5);
//    printAvlTree(avl);



//    avl.head = avl.insert_node(avl.head, 4);
//    avl.head = avl.insert_node(avl.head, 2);
//    avl.head = avl.insert_node(avl.head, 1);
//    avl.head = avl.insert_node(avl.head, 6);
//    avl.head = avl.insert_node(avl.head, 7);
//    avl.head = avl.insert_node(avl.head, 9);
//    avl.head = avl.insert_node(avl.head, 24);
//    avl.head = avl.insert_node(avl.head, 70);
//    avl.head = avl.insert_node(avl.head, 88);
//    printAvlTree(avl);
//    avl.updateNodeDataByFunction(c);
//    printAvlTree(avl);

//
//
//    printAvlTree(avl);
//    avl.removeNode(4);
//    printAvlTree(avl);
//    avl.removeNode(5);
//    printAvlTree(avl);
//    avl.removeNode(7);
//    printAvlTree(avl);
//    avl.removeNode(6);
//    printAvlTree(avl);
//    avl.removeNode(1);
//    printAvlTree(avl);
//    avl.removeNode(2);
//    printAvlTree(avl);
//    avl.removeNode(70);
//    printAvlTree(avl);
//    avl.removeNode(9);
//    printAvlTree(avl);
//    avl.removeNode(88);
//    printAvlTree(avl);
//    avl.removeNode(24);
//    printAvlTree(avl);
////
//

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}