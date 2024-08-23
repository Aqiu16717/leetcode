## binary search tree

* time complexity

|Operation|Average  |Worstcase|
|---------|---------|---------|
|Search	  |O(log n) |O(n)     |
|Insert	  |O(log n) |O(n)     |
|Delete	  |O(log n) |O(n)     |

* space complexity

|         |Average  |Worstcase|
|---------|---------|---------|
|Space	  |O(n)     |O(n)     |

* delete
  * The deletion of node `x` from the bst has three cases:
    * x is a leaf node
      ```
        a              a
       / \    --->    /
      b   x          b
      ```
    * x has one child
      ```
        a              a
       / \    --->    / \
      b   x          b   c
         /
        c
      ```
    * x has both left and right child
      ```
        a              a
       / \    --->    / \
      b   x          b   c
         / \              \
        c   d              d
      ```

## TODO
* [x] implement binary search tree
* [ ] add bst test case
* [ ] add bst doc
* [ ] implement avl tree
* [ ] implement b tree
* [ ] implement b+ tree
* [ ] implement lsm tree
* [ ] implement read-black tree
