#pragma once

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    int Num;
    Node** pNext;
    int nexts;
	Node(){ value = 0; Num = 0; pNext = NULL; nexts = 0;}
    Node(int val, int n): value(val), Num(n) {}
};
/**
��� ������ Tree
 
�������� ������
*/
class Tree {
    Node* ptrFather;
    int score;
    Node* findNode(int, Node*);
    void _printDirect(Node*);
    void _printBack(Node*);
    void _printSym(Node*);
	void _findElement(Node*, int);
/**
	public-����� ������
*/
public:
    Tree(){ ptrFather = NULL; score = 0;}
    void findElement(int);
    void pushNode(int, int);
    void createRoot(int);
    void printDirect();
    void printBack();
    void printSym();
};

