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
        // Approach 1 : Using Priority Queue , TC : klogk + N*k*logk, SC : O(k)
        // priority_queue<pair<int, ListNode*>,vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        // for(int i = 0; i < lists.size(); i++) {
        //     if(lists[i]) {
        //         pq.push({lists[i]->val, lists[i]});
        //     }
        // }

        // ListNode* dummyNode = new ListNode(-1);
        // ListNode* temp = dummyNode;
        // while(!pq.empty()) {
        //     auto it = pq.top();
        //     pq.pop();
        //     if(it.second->next) {
        //         pq.push({it.second->next->val, it.second->next});
        //     }
        //     temp->next = it.second;
        //     temp = temp -> next;
        // }
        // return dummyNode->next;

        if (lists.empty()) {
            return nullptr;
        }
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start + 1 == end) {
            return merge(lists[start], lists[end]);
        }
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        return dummy->next;

        
    }
};