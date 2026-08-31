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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};
        
        if(head==NULL || head->next==NULL || head->next->next==NULL) return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos=1;
        int first = -1;
        int last = -1;
        int mindist = INT_MAX;

        while(curr->next!=NULL){
            int a = prev->val;
            int b = curr->val;
            int c = curr->next->val;

            if((a>b && c>b) || (b>a && b>c)){
                if(first ==-1){
                    first=pos;
                }
                else{
                    mindist = min(mindist, pos-last);
                }
                last = pos;
            }
            pos++;
            prev = curr;
            curr = curr->next;
        }
        if(first==last) return ans;
        int maxdist = last -first;
        return {mindist,maxdist};
    }
};