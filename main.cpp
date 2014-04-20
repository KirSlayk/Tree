#include "Tree.h"

using namespace std;

void main()
{
	/**
	class tree
	*/
	Tree tree; 
	int max = 0;
	cout<<"Max = ";
	cin>>max;
	int node = 0;
	int val = 0;
	for (int index = 0; index < max; index++) {
		cout<<"Enter node"<<endl;
		cin>>node;
		cout<<"Enter value"<<endl;
		cin>>val;
		if (!index)
			/**
			create root of your tree
			*/
			tree.createRoot(val);
		else
			tree.pushNode(node, val);
	}
	cout << "direct:" << endl;
	tree.printDirect();
	cout << endl << "back:" << endl;
	tree.printBack();
	cout << endl << "sym:" << endl;
	tree.printSym();
    int i = 0;
	cout<< "\nEnter element whould you want see ";
	cin>>i;
	/**
	find element, that would you want see
	*/
	tree.findElement( i );
	system("pause");
}



