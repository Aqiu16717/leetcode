from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right        

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) ->Optional[TreeNode]:
        if not preorder:
            return None
        left_size = inorder.index(preorder[0])
        left = self.buildTree(preorder[1 : 1 + left_size],inorder[:left_size])
        right = self.buildTree(preorder[1 + left_size:], inorder[1 + left_size:])
        return TreeNode(preorder[0], left, right)

def test_buildTree():
    solution = Solution()
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]
    root = solution.buildTree(preorder, inorder)
    assert root.val == 3
    assert root.left.val == 9
    assert root.right.val == 20
    assert root.right.left.val == 15
    assert root.right.right.val == 7
    print("PASSED")

test_buildTree()