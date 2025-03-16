# Project Explanation

This repository contains two main implementations:

## 1. Red-Black Tree (red_black_tree.py)

### Overview
A Red-Black Tree is a self-balancing binary search tree that maintains balance through specific properties:
1. Each node is either red or black
2. The root is always black
3. Red nodes cannot have red children
4. Every path from a node to its descendant NULL nodes has the same number of black nodes

### Implementation Details
- Node class with key, color, left, right, and parent pointers
- RedBlackTree class with insertion and balancing operations
- Left and right rotation methods for tree balancing
- In-order traversal for displaying tree contents

### Usage
```python
rb_tree = RedBlackTree()
keys = [7, 3, 18, 10, 22, 8, 11, 26]
for key in keys:
    rb_tree.insert(key)
rb_tree.inorder_traversal(rb_tree.root)
```

## 2. Student Management System (student_management.c)

### Overview
A simple console-based student management system that allows:
- Adding new students
- Displaying all students
- Searching for students by ID
- Deleting students
- Saving and loading data to/from file

### Implementation Details
- Student structure with ID, name, and GPA fields
- Array-based storage for up to 100 students
- File I/O operations for data persistence
- Menu-driven interface for user interaction

### Usage
Compile and run the program:
```bash
gcc student_management.c -o student_management
./student_management
```

Follow the on-screen menu to manage student records.
