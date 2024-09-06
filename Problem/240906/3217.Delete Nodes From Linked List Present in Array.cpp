/*題目:
    You are given an array of integers nums and the head of a linked list. 
    Return the head of the modified linked list after removing all nodes 
    from the linked list that have a value that exists in nums.
Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]

Remove the nodes with values 1, 2, and 3.
----------------------------------------------
Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]

Remove the nodes with value 1.
----------------------------------------------
Example 3:

Input: nums = [5], head = [1,2,3,4]

Output: [1,2,3,4]

No node has value 5.
----------------------------------------------
*/
/*解析
### 英文原文：

1. Initialize a set `valuesToRemove` and populate it with the values of the `nums` array.
2. While the head of the linked list is not null and the head's value is present in `valuesToRemove`:
3. Move head to `head.next`.
ull, return null since all nodes erating from the head of the modified list:
6. For each node `current`, check if the value of the next node (`current.next`) is in the `valuesToRemove` set.
the next node in the list.

1. 初始化一個集合 `valuesToRemove`，並用 `nums` 數組中的值來填充這個集合。
2. 當鏈表的頭節點不為空且頭節點的值存在於 `valuesToRemove` 中時：
3. 將頭節點移動到 `head.next`。
4. 如果頭節點為空，返回 `null`，因為所有節點都已被移除。
5. 從修改後的鏈表頭開始迭代：
6. 對於每個節點 `current`，檢查下一個節點 (`current.next`) 的值是否存在於 `valuesToRemove` 集合中。
7. 如果存在，跳過下一個節點，將 `current.next` 更新為 `current.next.next`。
8. 如果不存在，將 `current` 指針移動到鏈表的下一個節點。
9. 返回修改後的鏈表頭。

這個算法的流程是依次檢查並刪除與 `nums` 集合中的值匹配的節點，最終返回刪除後的鏈表。
 */
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
        for(auto x:nums) s.insert(x);
         ListNode* newHead= new ListNode(-1);
        ListNode* temp=newHead;
        while(head){
            if(s.count(head->val)==0){
                newHead->next=new ListNode(head->val);
                newHead=newHead->next;
            }
            head=head->next;
        }
        return temp->next;
    }
};