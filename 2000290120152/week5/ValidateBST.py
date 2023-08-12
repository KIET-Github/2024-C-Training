# Validate BST

# Check if a binary tree is a BST or not.

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

mn = float('-inf')
mx = float('inf')

def ValidateBST(root):
    return isBST(root, mn, mx)
    
def isBST(node, mn, mx):
    if not node: return True
    
    if node.val < mn or node.val>mx:
        return False
        
    return (isBST(node.left, mn, node.val-1) and isBST(node.right, node.val+1, mx))

root = Node(5)
root.left = Node(3)
root.left.left = Node(2)
root.left.right = Node(4)
root.right = Node(8)
root.right.left = Node(6)
root.right.right = Node(9)



if (ValidateBST(root)):
    print("It is a BST.")
else:
    print("It is not a BST.")


# ------------------------------------------------


def ValidateBSTit(root):
    cur = root
    prev = None
    while cur != None:
        if cur.left == None:
            if prev != None and prev.val >= cur.val:
                return False
            prev = cur
            cur = cur.right
        else:
            nxt = cur.left
            while nxt.right != None and nxt.right != cur:
                nxt = nxt.right
            if nxt.right == None:
                nxt.right = cur
                cur = cur.left
            else:
                nxt.right = None
                if nxt != None and nxt.val >= cur.val:
                    return False
                nxt = cur
                cur = cur.right
    return True

if (ValidateBSTit(root)):
    print("It is a BST.")
else:
    print("It is not a BST.")
    
