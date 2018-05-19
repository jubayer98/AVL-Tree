#include <iostream>
#include "avltree.cpp"
using namespace std;

int main(void)
{
	/*creating tree object*/
	AVLtree<char> TreeObject;
	cout << "AVL tree object is created." << endl;
	cout << endl;

	/*checking is empty or not*/
	if(TreeObject.IsEmpty() == true)
        cout << "Tree is empty." << endl;
    else
        cout << "Tree is not empty." << endl;
    cout << endl;

	/*inserting tree node*/
	int totalNode;
	cout << "Enter the total node of tree you want to insert: ";
	cin >> totalNode;

	cout << "Insert nodes for creating tree(char):" << endl;
	char nodeValue;
	for (int i=0; i <totalNode; i++)
	{
	    cin >> nodeValue;
	    TreeObject.insert(nodeValue);
	}
	cout << endl;

	/*after inserting values, checking is empty or not*/
	if(TreeObject.IsEmpty() == true)
        cout << "Tree is empty." << endl;
    else
        cout << "Tree is not empty." << endl;
    cout << endl;

	/*checking avl tree balance*/
	cout << "Printing balance: ";
	TreeObject.printBalance();
	cout << endl;

	/*checking the length*/
    cout << "Total nodes of the tree is: " << TreeObject.LengthIs();
    cout << endl;

    /*checking the height*/
    cout << "\nHeight is: " << TreeObject.heightIs();
    cout << endl;

    /*searching a node */
    //--- comment out to fix compiling error
    cout <<"Enter a node, you want to search: ";
    cin >> nodeValue;
    TreeObject.SearchTree(nodeValue);
    if(TreeObject.SearchTree() != NULL)
       cout << "Item is found!" << endl;
    else
       cout <<"Item is not found!" << endl;


    /*delete a node from the tree*/
    cout << "\nEnter the node(char) you want to delete: ";
    cin >> nodeValue;
    TreeObject.deleteKey(nodeValue);
    cout << "Node >> " << nodeValue << " << is deleted." << endl;
    cout << "After deleting node >> " << nodeValue << " <<, new balance of the tree is: ";
    TreeObject.printBalance();
    cout << "Total node of tree is now: " << TreeObject.LengthIs();
    cout << "\nNew height is: " << TreeObject.heightIs();
    cout << endl;

    /*clearing avl tree*/
    //--- comment out to fix compiling error
    char c;
    cout << "Please enter >> c << for clearing tree nodes: ";
    cin >> c;
    if(TreeObject.clearNode(c) == 'c')
        cout << "Tree is clear.";
    else
        cout << "Wrong character. Access denied." << endl;
}
