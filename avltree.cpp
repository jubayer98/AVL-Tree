#include <iostream>
#include "avltree.h"

using namespace std;

template <class ItemType>
void AVLtree<ItemType>::rebalance(AVLnode<ItemType> *n) {
	setBalance(n);

	if (n->balance == -2) {
		if (height(n->left->left) >= height(n->left->right))
		n = rotateRight(n);
		else
		n = rotateLeftThenRight(n);
	}
	else if (n->balance == 2) {
		if (height(n->right->right) >= height(n->right->left))
		n = rotateLeft(n);
		else
		n = rotateRightThenLeft(n);
	}

	if (n->parent != NULL) {
		rebalance(n->parent);
	}
	else {
		root = n;
	}
}

template <class ItemType>
bool AVLtree<ItemType>::IsEmpty()
{
    return root == NULL;
}

template <class ItemType>
int CountNodes(AVLnode<ItemType>* tree)
{
    if(tree == NULL)
        return 0;
    else
        return CountNodes(tree->left)+ CountNodes(tree->right) + 1;
}

template <class ItemType>
int AVLtree<ItemType>::LengthIs()
{
    return CountNodes(root);
}

template <class ItemType>
void AVLtree<ItemType>::recalculate(AVLnode<ItemType> *n) {
    int count = 0;
    if (n == NULL)  {
        return;
    }
    if (n->getLeft() == NULL && n->getRight() == NULL) {
        // no child, the height is 0
        height(0);
        return;
    }
    if (n->getLeft() != NULL) {
        recalculate(n->getLeft());
        count = n->getLeft()->recalculate();
    }
    if (n->getRight() != NULL){
        recalculate(n->getRight());
        count = max(count, n->getRight()->recalculate());
    }
    // include leaf in the height
    height(count+1);
}

template <class ItemType>
int AVLtree<ItemType>::heightIs()
{
    return height(root)+1; //counting height from position 1
}

template <class ItemType>
void AVLtree<ItemType>::SearchTree(AVLnode<ItemType> *a)

{
    char ValueInTree = NULL;
    AVLnode<ItemType> *temp;

    temp = root;
    while((temp != NULL) && (temp->a != a))
    {
        if(a < temp->a)
            temp = temp->left;  // Search key comes before this node.
        else
            temp = temp->right; // Search key comes after this node
    }

}

// Note that RotateLeft and RotateRight are *static* member
// functions because otherwise they would have to re-assign
template <class ItemType>
AVLnode<ItemType>* AVLtree<ItemType>::rotateLeft(AVLnode<ItemType> *a) {
	AVLnode<ItemType> *b = a->right;
	b->parent = a->parent;
	a->right = b->left;

	if (a->right != NULL)
	a->right->parent = a;

	b->left = a;
	a->parent = b;

	if (b->parent != NULL) {
		if (b->parent->right == a) {
			b->parent->right = b;
		}
		else {
			b->parent->left = b;
		}
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template <class ItemType>
AVLnode<ItemType>* AVLtree<ItemType>::rotateRight(AVLnode<ItemType> *a) {
	AVLnode<ItemType> *b = a->left;
	b->parent = a->parent;
	a->left = b->right;

	if (a->left != NULL)
	a->left->parent = a;

	b->right = a;
	a->parent = b;

	if (b->parent != NULL) {
		if (b->parent->right == a) {
			b->parent->right = b;
		}
		else {
			b->parent->left = b;
		}
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template <class ItemType>
AVLnode<ItemType>* AVLtree<ItemType>::rotateLeftThenRight(AVLnode<ItemType> *n) {
	n->left = rotateLeft(n->left);
	return rotateRight(n);
}

template <class ItemType>
AVLnode<ItemType>* AVLtree<ItemType>::rotateRightThenLeft(AVLnode<ItemType> *n) {
	n->right = rotateRight(n->right);
	return rotateLeft(n);
}

template <class ItemType>
int AVLtree<ItemType>::height(AVLnode<ItemType> *n) {
	if (n == NULL)
	return -1;
	return 1 + max(height(n->left), height(n->right));
}

template <class ItemType>
void AVLtree<ItemType>::setBalance(AVLnode<ItemType> *n) {
	n->balance = height(n->right) - height(n->left);
}

template <class ItemType>
void AVLtree<ItemType>::printBalance(AVLnode<ItemType> *n) {
	if (n != NULL) {
		printBalance(n->left);
		cout << n->balance << " ";
		printBalance(n->right);
	}
}

template <class ItemType>
AVLtree<ItemType>::AVLtree(void) : root(NULL) {}

template <class ItemType>
AVLtree<ItemType>::~AVLtree(void) {
	delete root;
}

template <class ItemType>
bool AVLtree<ItemType>::insert(ItemType key) {
	if (root == NULL) {
		root = new AVLnode<ItemType>(key, NULL);
	}
	else {
		AVLnode<ItemType>
		*n = root,
		*parent;

		while (true) {
			if (n->key == key)
			return false;

			parent = n;

			bool goLeft = n->key > key;
			n = goLeft ? n->left : n->right;

			if (n == NULL) {
				if (goLeft) {
					parent->left = new AVLnode<ItemType>(key, parent);
				}
				else {
					parent->right = new AVLnode<ItemType>(key, parent);
				}

				rebalance(parent);
				break;
			}
		}
	}

	return true;
}

//delete the given key from the given tree. Return NULL
//if the key is not found in the tree. Otherwise return
template <class ItemType>
void AVLtree<ItemType>::deleteKey(const ItemType delKey) {
	if (root == NULL)
	return;

	AVLnode<ItemType>
	*n       = root,
	*parent  = root,
	*delNode = NULL,
	*child   = root;

	while (child != NULL) {
		parent = n;
		n = child;
		child = delKey >= n->key ? n->right : n->left;
		if (delKey == n->key)
		delNode = n;
	}

	if (delNode != NULL) {
		delNode->key = n->key;

		child = n->left != NULL ? n->left : n->right;

		if (root->key == delKey) {
			root = child;
		}
		else {
			if (parent->left == n) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}

			rebalance(parent);
		}
	}
}

template <class ItemType>
void AVLtree<ItemType>::clearNode(AVLnode<ItemType> *T)
{
    if(T==NULL) return;  // Nothing to clear
    if(T->left != NULL) clearNode(T->left); // Clear left sub-tree
    if(T->right != NULL) clearNode(T->right); // Clear right sub-tree
    delete T;    // Destroy this node
    return;
}

template <class ItemType>
void AVLtree<ItemType>::printBalance() {
	printBalance(root);
	cout << endl;
}
