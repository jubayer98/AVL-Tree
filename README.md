# AVL-Tree
An AVL tree is a special type of binary tree that is always "partially" balanced. The criteria that is used to determine the "level" of "balanced-ness" is the difference between the heights of sub-trees of a root in the tree. The "height" of tree is the "number of levels" in the tree.
An AVL tree is a special type of binary tree that is always "partially" balanced. The criteria that is used to determine the "level" of "balanced-ness" is the difference between the heights of subtrees of a root in the tree. The "height" of tree is the "number of levels" in the tree. Or to be more formal, the height of a tree is defined as follows:
The height of a tree with no elements is 0
The height of a tree with 1 element is 1
The height of a tree with > 1 element is equal to 1 + the height of its tallest subtree.
An AVL tree is a binary tree in which the difference between the height of the right and left subtrees (or the root node) is never more than one.
The idea behind maintaining the "AVL-ness" of an AVL tree is that whenever we insert or delete an item, if we have "violated" the "AVL-ness" of the tree in anyway, we must then restore it by performing a set of manipulations (called "rotations") on the tree. These rotations come in two flavors: single rotations and double rotations (and each flavor has its corresponding "left" and "right" versions).
