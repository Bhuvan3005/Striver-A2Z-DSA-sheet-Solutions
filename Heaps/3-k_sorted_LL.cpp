//Brute Force Approach:
//TC: O(NLOGN) where N=total nodes SC:O(N)
//Store all the nodes in pq and create linked list again


//Optimal Approach
//TC :O(Nlogk) where k=number of lists and N=total nodes
//SC :O(k)

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
        struct comp {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val; // should a come after b
            }
        };
    
        ListNode* mergeKLists(vector<ListNode*>& lists) {
    
            priority_queue<
                ListNode*,
                vector<ListNode*>,
                comp
            > pq;
    
            // Push head of each list
            for (auto head : lists) {
                if (head)
                    pq.push(head);
            }
    
            ListNode* dummy = new ListNode(0);
            ListNode* tail = dummy;
    
            while (!pq.empty()) {
                ListNode* node = pq.top();
                pq.pop();
    
                tail->next = node;
                tail = tail->next;
    
                if (node->next)
                    pq.push(node->next);
            }
    
            tail->next = nullptr;
    
            return dummy->next;
        }
    };