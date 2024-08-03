# AVL Tree

An AVL tree is a special type of binary tree that is always "partially" balanced. This balance is determined by the difference in heights of the subtrees of any node in the tree. The height of a tree is defined as the number of levels it contains.

## Definition of Height

- The height of a tree with no elements is 0.
- The height of a tree with one element is 1.
- The height of a tree with more than one element is equal to 1 plus the height of its tallest subtree.

## AVL Tree Characteristics

An AVL tree is a binary tree in which the difference between the height of the right and left subtrees of any node is never more than one. This balance ensures that the tree remains efficient for operations like insertion, deletion, and lookup.

## Maintaining Balance

To maintain the "AVL-ness" of an AVL tree, whenever an item is inserted or deleted, we must ensure that the tree remains balanced. If the insertion or deletion causes the tree to become unbalanced, we restore balance by performing rotations. These rotations can be either single or double, and each type has left and right versions.

### Types of Rotations

1. **Single Rotations:**
   - **Left Rotation**
   - **Right Rotation**

2. **Double Rotations:**
   - **Left-Right Rotation**
   - **Right-Left Rotation**

## Implementation

The implementation of an AVL tree typically involves the following steps:

1. **Insertion:**
   - Insert the new node as in a regular binary search tree.
   - Update the height of the ancestor nodes.
   - Check for balance at each ancestor node.
   - Perform rotations if the tree becomes unbalanced.

2. **Deletion:**
   - Remove the node as in a regular binary search tree.
   - Update the height of the ancestor nodes.
   - Check for balance at each ancestor node.
   - Perform rotations if the tree becomes unbalanced.

---

For further details and advanced usage, you can refer to the documentation and source code within the repository.
