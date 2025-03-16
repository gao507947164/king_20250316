# 项目说明

本仓库包含两个主要实现：

## 1. 红黑树 (red_black_tree.py)

### 概述
红黑树是一种自平衡的二叉搜索树，通过以下特性保持平衡：
1. 每个节点是红色或黑色
2. 根节点始终是黑色
3. 红色节点不能有红色子节点
4. 从任一节点到其所有后代 NULL 节点的路径包含相同数量的黑色节点

### 实现细节
- 包含 key、color、left、right 和 parent 指针的 Node 类
- 包含插入和平衡操作的 RedBlackTree 类
- 用于树平衡的左右旋转方法
- 用于显示树内容的中序遍历

### 使用示例
```python
rb_tree = RedBlackTree()
keys = [7, 3, 18, 10, 22, 8, 11, 26]
for key in keys:
    rb_tree.insert(key)
rb_tree.inorder_traversal(rb_tree.root)
```

## 2. 学生管理系统 (student_management.c)

### 概述
一个简单的基于控制台的学生管理系统，功能包括：
- 添加新学生
- 显示所有学生
- 按 ID 搜索学生
- 删除学生
- 将数据保存到文件/从文件加载

### 实现细节
- 包含 ID、姓名和 GPA 字段的 Student 结构体
- 最多可存储 100 名学生的数组
- 用于数据持久化的文件 I/O 操作
- 用于用户交互的菜单驱动界面

### 使用说明
编译并运行程序：
```bash
gcc student_management.c -o student_management
./student_management
```

按照屏幕菜单管理学生记录。
