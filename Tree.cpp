#include "Tree.h"

/**
	это все основные функции в этой программе
*/
void Tree::createRoot(int val) {
    ptrFather = new Node;
    ptrFather->value = val;
    ptrFather->Num = ++score;
}
/**
@brief direct print
*/
void Tree::_printDirect(Node* node) {
    Node* temp = node;
    cout << temp->value << " ";
    for (int index = 0; index < temp->nexts; index++) {
        if (temp->nexts)
        _printDirect(temp->pNext[index]);
    }
}
/**
@brief back print
*/
void Tree::_printBack(Node* node) {
    Node* temp = node;
    for (int index = 0; index < temp->nexts; index++) {
            _printBack(temp->pNext[index]);
    }
    cout << temp->value << " ";
}

void Tree::printDirect() {
    _printDirect(ptrFather);
}

void Tree::printBack() {
    _printBack(ptrFather);
}

void Tree::printSym() {
   
    _printSym(ptrFather);
}

void Tree::_printSym(Node* node) {
    Node* temp = node;
    for (int index = 0; index < temp->nexts; index++) {
        if (index == temp->nexts/2.0f) {
            cout<< temp->value <<" ";
        }
        _printSym(temp->pNext[index]);
        if (temp ->nexts == 1) {
            cout<< temp->value <<" ";
        }
    }
    if (!temp->nexts)
    cout << temp->value << " ";
}

Node* Tree::findNode(int number, Node* node) {
    if (number > score)
        throw std::string("Not found!");
    if (node->Num == number) return node;
    Node *temp = node, *result = node;
    for (int index = 0; index < temp->nexts; index++) {
        if (temp->pNext[index] && temp->pNext[index]->Num == number) {
            return temp->pNext[index];
        } else if (temp->pNext[index] && (result = findNode(number, temp->pNext[index]))->Num == number) {
            return result;
        }
    }
    return result;
}
/**
@brief general function of all job, push element into your tree
*/
void Tree::pushNode(int number, int value) {
    if (number > score)
        throw std::string("Not found!");
    Node* pPrev = findNode(number, ptrFather);
    if (!pPrev->nexts) {
        pPrev->pNext = (Node**)malloc(sizeof(Node*));
        *(pPrev->pNext) = NULL;
    } else
    pPrev->pNext = (Node**)realloc(pPrev->pNext, (pPrev->nexts + 1) * sizeof(Node*));
    pPrev->pNext[pPrev->nexts++] = new Node(value, ++score);
	pPrev->pNext[pPrev->nexts-1]->nexts = 0;
    
}

void Tree::findElement( int num )
{
	_findElement( ptrFather, num );
}

static bool BOOL = true;

void Tree::_findElement( Node* node, int num )
{
	Node* temp = node;
	int index = 0;
	if ( num == 1 && BOOL ){
			cout << temp->value << " ";
			BOOL = false;
	}
			
		
    for (index = 0; index < temp->nexts; index++) {
		  _findElement(temp->pNext[index], num - 1);
    }
   
}
