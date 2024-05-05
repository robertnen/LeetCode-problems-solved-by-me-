class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# Runtime: beats 100% of users with Python3
# Memory: beats 100% of users with Python3
# Daily problem (Streak 82)

class Solution:
    def deleteNode(self, node):
        node.val = node.next.val
        node.next = node.next.next