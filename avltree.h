#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include <algorithm>
#include <iostream>

/* Node Declaration */
template <class ItemType>
class AVLnode {
public:
	ItemType key;
	int balance;
	AVLnode *left, *right, *parent;

	AVLnode(ItemType k, AVLnode *p) : key(k), balance(0), parent(p),
	left(NULL), right(NULL) {}

	~AVLnode() {
		delete left;
		delete right;
	}
};

/* Class Declaration */
template <class ItemType>
class AVLtree {
public:
	AVLtree(void);
	~AVLtree(void);
	bool IsEmpty();
	bool insert(ItemType key);
	void deleteKey(const ItemType key);
	void printBalance();
	int LengthIs();
	int heightIs();
	void recalculate();
	//void SearchTree();
	void clearNode();
	//AVLnode<ItemType>* SearchTree         ( AVLnode<ItemType> *n );
	void SearchTree                         ( AVLnode<ItemType> *n );

private:
	AVLnode<ItemType> *root;

	AVLnode<ItemType>* rotateLeft           ( AVLnode<ItemType> *a );
	AVLnode<ItemType>* rotateRight          ( AVLnode<ItemType> *a );
	AVLnode<ItemType>* rotateLeftThenRight  ( AVLnode<ItemType> *n );
	AVLnode<ItemType>* rotateRightThenLeft  ( AVLnode<ItemType> *n );
    //AVLnode<ItemType>* SearchTree         ( AVLnode<ItemType> *n );
	//void SearchTree                       ( AVLnode<ItemType> *n );
	void rebalance                          ( AVLnode<ItemType> *n );
	void setBalance                         ( AVLnode<ItemType> *n );
	void printBalance                       ( AVLnode<ItemType> *n );
    int height                              ( AVLnode<ItemType> *n );
    void recalculate                        ( AVLnode<ItemType> *n );
	void clearNode                          ( AVLnode<ItemType> *n );
};


#endif // AVLTREE_H_INCLUDED
