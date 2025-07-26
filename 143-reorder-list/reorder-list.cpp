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
    void reorderList(ListNode* head) {
        // Approach 1 : Using Stack, TC : O(N), SC : O(N)
        // stack<ListNode*> s;
        // ListNode* curr = head;
        // while(curr){
        //     s.push(curr);
        //     curr=curr->next;
        // }

        // curr = head;
        // unordered_map<ListNode*, bool> vis;

        // while(true) {
        //     ListNode* last = s.top();
        //     s.pop();
        //     ListNode* next = curr->next;
        //     vis[curr] = true;
        //     if(vis[last]){
        //         curr->next = NULL;
        //         break;
        //     }
        //     curr->next = last;
        //     vis[last] = true;
        //     curr = curr->next;
        //     if(vis[next]) {
        //         curr->next = NULL;
        //         break;
        //     }
        //     curr->next = next;
        //     curr = curr->next;
        // }

        // Approach 2 :

        // base case : LinkedList is empty
        if(!head) return;

        // Finding the middle with the help of two pointer approach
        ListNode *tmp = head, *half = head, *prev = NULL;
        while(tmp->next && tmp->next->next) {
            tmp = tmp->next->next;
            half = half->next;
        }

        // Adding one bit in case of lists with even length
        if(tmp->next) half = half->next;

        // Now reverse the second half
        while(half) {
            tmp = half->next;
            half->next = prev;
            prev = half;
            half = tmp;
        }
        half = prev;

        // After reversing the secind half, let's merge both the halfes
        while(head && half) {
            tmp = head->next;
            prev = half->next;
            head->next = half;
            half->next = tmp;
            head = tmp;
            half = prev;
        }

        // Base case : closing when we had even length arrays
        if(head && head->next) head->next->next = NULL;
    }
};