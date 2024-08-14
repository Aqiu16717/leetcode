## 128.Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!s.count(nums[i] - 1)) {
                int cnt = 1; 
                int tmp = nums[i] + 1;
                int j = 1;
                for (; s.count(nums[i]+j) > 0;++j) {}
                ret = max(ret, j);
            }
        }
        return ret;
    }
};
```

## 双指针

### 11. 盛最多水的容器

给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。返回容器可以储存的最大水量。说明：你不能倾斜容器。

* 思路  
定义两个指针，初始化为0和n-1，然后向中间移动，每次移动较小的那个指针，并更新面积。
* 代码
    ```c++
    class Solution {
    public:
        int maxArea(vector<int>& height) {
            int ret = 0;
            int left = 0;
            int right = height.size() - 1;
            while (left < right) { 
                ret = max(ret, min(height[left], height[right]) * (right-left));
                if (height[left] < height[right]) {
                    ++left;
                } else {
                    --right;
                }
            }
            return ret;
        }
    };
    ```

## 链表
### 23. 合并 K 个升序链表
给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并到一个升序链表中，返回合并后的链表。

**题解**

* 使用一个优先队列（最小堆）来存储链表节点。
* 自定义比较器 cmp 确保优先队列按节点值排序。
* 将每个链表的头节点推入优先队列。
* 通过循环不断从优先队列中取出最小节点，将其加入结果链表，并将其后续节点（如果存在）推入优先队列。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* lhs, const ListNode* rhs) {
            return lhs->val > rhs->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> que(cmp);
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                que.push(lists[i]);
            }
        }
        ListNode dummy_head;
        ListNode* pre = &dummy_head;
        while (!que.empty()) {
            ListNode* node = que.top();
            que.pop();
            pre->next = node;
            pre = pre->next;
            if (node->next) {
                que.push(node->next);
            }
        }
        return dummy_head.next;
    }
};
```