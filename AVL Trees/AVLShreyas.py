'''AVL Tree Implementation'''''
'''Source :  http://www.geeksforgeeks.org/avl-tree-set-1-insertion/'''

class AVLNode :

    def __init__(self,data = 0):

        self.left = None
        self.right = None
        self.data = data
        self.height = 1

def insertIntoAVL(root, toBeAdded):

    '''Standard BST Insertion'''
    if toBeAdded is None :
        return
    if root is None:
        return toBeAdded
    else :
        if root.data < toBeAdded.data :
            root.right = insertIntoAVL(root.right, toBeAdded)
        else :
            root.left = insertIntoAVL(root.left, toBeAdded)

    lNode = root.left
    rNode = root.right

    '''Height Update'''
    root.height = 1 + max(height(lNode),height(rNode))


    '''Balance Checker has 4 cases if unbalanced'''


    diffOfLevels = getSlopeOfNode(root)
    key = toBeAdded.data

    '''1. Left Left Case
       2. Right Right Case
       3. Left Right Case
       4. Right Left Case
    '''
    if diffOfLevels > 1 and key < lNode.data:
        return rightRotate(root)
    elif diffOfLevels < -1 and key > rNode.data:
        return leftRotate(root)
    elif diffOfLevels > 1 and key < lNode.data:
        root.left = leftRotate(root.left)
        return rightRotate(root)
    elif diffOfLevels < -1 and key < rNode.data:
        root.right = rightRotate(root.right)
        return leftRotate(root)

    return root


def inOrderTraversal(root):
    if root is None :
        return
    else :
        inOrderTraversal(root.left)
        print root.data , " " , root.height
        inOrderTraversal(root.right)

def height(node):
    if node is None :
        return 0
    else:
        return node.height

def leftRotate(x):

    '''Temp Variables'''
    y = x.right
    T2 = y.left

    '''Perform Rotation'''
    y.left = x
    x.right = T2

    '''Heights of Subtrees'''
    xleft = x.left
    xright = x.right
    yleft = y.left
    yright = y.right

    '''Update Height of X'''
    x.height = max(height(xleft),height(xright)) + 1

    '''Update Height of Y'''
    y.height = max(height(yleft),height(yright)) + 1

    return y

def rightRotate(y):

    '''Temp Variables'''
    x = y.left
    T2 = x.right
    '''Perform Rotation'''
    x.right = y
    y.left = T2

    '''Heights of Subtrees'''
    xleft = x.left
    xright = x.right
    yleft = y.left
    yright = y.right

    '''Update Height of X'''
    x.height = max(height(xleft),height(xright)) + 1

    '''Update Height of Y'''
    y.height = max(height(yleft),height(yright)) + 1

    return x

def getSlopeOfNode(node) :

    return height(node.left) - height(node.right)

if __name__ == '__main__':

    root = None
    root = insertIntoAVL(root,AVLNode(50))
    root = insertIntoAVL(root,AVLNode(40))
    root = insertIntoAVL(root,AVLNode(65))
    root = insertIntoAVL(root,AVLNode(70))
    root = insertIntoAVL(root,AVLNode(80))
    root = insertIntoAVL(root,AVLNode(90))
    print "Data Height"
    inOrderTraversal(root)
