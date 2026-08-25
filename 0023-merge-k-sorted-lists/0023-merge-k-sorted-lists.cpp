class Solution {
public:

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        // Put first node of every list into heap
        for (ListNode* node : lists) {
            if (node != NULL)
                pq.push(node);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            ListNode* smallest = pq.top();
            pq.pop();

            // Add smallest node to answer
            tail->next = smallest;
            tail = tail->next;

            // Add next node of the same list
            if (smallest->next != NULL)
                pq.push(smallest->next);
        }

        return dummy->next;
    }
};