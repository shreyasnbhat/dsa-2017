class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.key = key
        self.size = 0  # Stores height of node. (Augmentation)


def insert(root, key):
    if root is None:
        root = Node(key)
    else:
        if root.key > key:
            root.left = insert(root.left, key)
        else:
            root.right = insert(root.right, key)
        update_size(root)
        root = rebalance(root)
    return root

# def insert(root, key):
#     if root is None:
#         root = Node(key)
#     else:
#         root.size += 1
#         if root.key > key:
#             root.left = insert(root.left, key)
#             if subtree_size(root.left) - subtree_size(root.right) > 1:
#                 if root.left.left is None:
#                     root.left = left_rotate(root.left)
#                 root = right_rotate(root)
#
#         else:
#             root.right = insert(root.right, key)
#             if subtree_size(root.right) - subtree_size(root.left) > 1:
#                 if root.right.right is None:
#                     root.right = right_rotate(root.right)
#                 root = left_rotate(root)
#     update_size(root)
#     return root


def rebalance(root):
    if get_balance(root) > 1:  # If the root is at least doubly heavy on the left side
        if get_balance(root.left) <= -1:  # If root's left child is heavier to the right
            root.left = left_rotate(root.left)
        root = right_rotate(root)
    elif get_balance(root) < -1:  # If the root is at least doubly heavy on the right side
        if get_balance(root.right) >= 1:  # If root's right child is heavier to the left
            root.right = right_rotate(root.right)
        root = left_rotate(root)
    return root


def get_balance(root):
    if root is None:
        return 0
    return subtree_size(root.left) - subtree_size(root.right)


def left_rotate(x):
    y = x.right
    x.right = y.left
    update_size(x)
    y.left = x
    update_size(y)
    return y


def right_rotate(y):
    x = y.left
    y.left = x.right
    update_size(y)
    x.right = y
    update_size(x)
    return x


def update_size(x):
    if x is None:
        return
    x.size = 1 + max(subtree_size(x.left), subtree_size(x.right))


def subtree_size(root):
    if root is None:
        return -1
    else:
        return root.size


# sorting
def print_in_order(root):
    if root is None:
        return
    else:
        if root.left is not None:
            print_in_order(root.left)
        print((root.key, root.size), end=" ")
        if root.right is not None:
            print_in_order(root.right)


# Returns the reference to the node.
def search(root, key):
    if root is None:
        return root
    if root.key == key:
        return root
    else:
        if root.key < key:
            return search(root.right, key)
        else:
            return search(root.left, key)


# find_min and find_max also return references to the minimum/maximum here
def find_min(root):
    if root is None:
        return None
    elif root.left is None:
        return root
    else:
        return find_min(root.left)


def find_max(root):
    if root is None:
        return None
    elif root.right is None:
        return root
    else:
        return find_max(root.right)


# Replace it by the max of the left subtree or the min of the right subtree
def delete(root, key):
    if root is None:
        return
    else:
        if root.key == key:
            if root.left is None:
                if root.right is None:
                    root = None  # If root is a leaf
                else:
                    root.key = find_min(root.right).key
                    root.right = delete(root.right, root.key)
            else:
                root.key = find_max(root.left).key
                root.left = delete(root.left, root.key)
        else:
            if root.key > key:
                root.left = delete(root.left, key)
            else:
                root.right = delete(root.right, key)
        update_size(root)
        root = rebalance(root)
        return root


def print_level_order(root):
    if root is None:
        return
    else:
        tree = list()
        tree.append(root)
        while len(tree) > 0:
            if tree[0].left is not None:
                tree.append(tree[0].left)
            if tree[0].right is not None:
                tree.append(tree[0].right)
            print((tree[0].key, tree[0].size), end=" ")
            tree.remove(tree[0])


def check_balanced(root):
    if root is None:
        return True
    return abs(subtree_size(root.left) - subtree_size(root.right)) <= 1 and check_balanced(root.left) and \
           check_balanced(root.right)


class AVLTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def insert(self, key):
        self.root = insert(self.root, key)

    def delete(self, key):
        self.root = delete(self.root, key)

    def print_in_order(self):
        print_in_order(self.root)
        print()

    def print_level_order(self):
        print_level_order(self.root)
        print()

    def find_max(self):
        return find_max(self.root).key

    def find_min(self):
        return find_min(self.root).key

    def __contains__(self, item):
        return self.contains(item)

    def contains(self, key):
        return self.search(key) is not None

    def search(self, key):
        return search(self.root, key)

    def is_balanced(self):
        return check_balanced(self.root)

if __name__ == "__main__":
    bst = AVLTree()
    bst.insert(42)
    bst.print_level_order()
    print(bst.is_balanced())
    bst.insert(52)
    bst.print_level_order()
    print(bst.is_balanced())
    bst.insert(50)
    bst.print_level_order()
    print(bst.is_balanced())
    bst.insert(6)
    bst.print_level_order()
    print(bst.is_balanced())
    bst.insert(39)
    bst.print_level_order()
    bst.print_in_order()
    print(bst.is_balanced())
    bst.delete(52)
    bst.print_level_order()
    print(bst.is_balanced())
    bst.delete(6)
    bst.delete(36)
    bst.print_level_order()
    bst.insert(42)
    bst.insert(39)
    bst.insert(50)
    bst.delete(50)
    print_level_order(search(bst.root, 42))
    print()
    bst.print_level_order()
    print(bst.is_balanced())
    import random
    avl = AVLTree()
    random.seed(2)
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.insert(random.randint(0, 300))
    avl.print_level_order()
    print(avl.is_balanced())

'''
(42, 0)
True
(42, 1) (52, 0)
True
(50, 1) (42, 0) (52, 0)
True
(50, 2) (42, 1) (52, 0) (6, 0)
True
(50, 2) (39, 1) (52, 0) (6, 0) (42, 0)
(6, 0) (39, 1) (42, 0) (50, 2) (52, 0)
True
(39, 2) (6, 0) (50, 1) (42, 0)
True
(42, 1) (39, 0) (50, 0)
(42, 2) (39, 1) (42, 1) (39, 0) (50, 0)
(42, 2) (39, 1) (42, 1) (39, 0) (50, 0)
True
(86, 4) (43, 2) (220, 3) (28, 1) (46, 1) (157, 2) (278, 2) (18, 0) (81, 0) (128, 1) (190, 1) (257, 1) (297, 0) (108, 0) (137, 0) (184, 0) (201, 0) (227, 0) (260, 0)
True
'''