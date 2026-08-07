#!/usr/bin/env python3
"""Module that creates and displays a binary tree."""


class BinaryTreeNode:
    """Represents a binary tree node."""

    def __init__(self, value, parent=None):
        """Create a new node with value and optional parent."""
        self.n = value
        self.parent = parent
        self.left = None
        self.right = None


def print_tree(node, level=0, prefix="Root: "):
    """Print the binary tree visually."""
    if node is not None:
        print(" " * (level * 4) + prefix + str(node.n))
        if node.left or node.right:
            if node.left:
                print_tree(node.left, level + 1, "L--- ")
            if node.right:
                print_tree(node.right, level + 1, "R--- ")


if __name__ == "__main__":
 
    # niveau 0 : racine
    root = BinaryTreeNode(98)
 
    # niveau 1
    root.left = BinaryTreeNode(12, root)
    root.right = BinaryTreeNode(402, root)
 
    # niveau 2
    root.left.left = BinaryTreeNode(6, root.left)
    root.left.right = BinaryTreeNode(16, root.left)
    root.right.left = BinaryTreeNode(256, root.right)
    root.right.right = BinaryTreeNode(512, root.right)
 
    # niveau 3
    root.left.left.left = BinaryTreeNode(1, root.left.left)
    root.left.left.right = BinaryTreeNode(3, root.left.left)
    root.left.right.left = BinaryTreeNode(13, root.left.right)
    root.left.right.right = BinaryTreeNode(19, root.left.right)
    root.right.left.left = BinaryTreeNode(200, root.right.left)
    root.right.left.right = BinaryTreeNode(300, root.right.left)
    root.right.right.left = BinaryTreeNode(490, root.right.right)
    root.right.right.right = BinaryTreeNode(600, root.right.right)
 
    print_tree(root)
 
