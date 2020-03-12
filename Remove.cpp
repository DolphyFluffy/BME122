#include <iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //iterate through linked list
        //see if data = val
        //remove it
        ListNode* cur;
        ListNode* prev = NULL;
        
        while(cur) {
            //remove first
            if(head->val == val) {
                cur = head;
                head = head->next;
                cur->next = NULL;
            } 
            else if(cur->val == val) {
                prev->next = cur;
                cur->next = NULL;
                cur = prev->next;
            }
            else if(cur->next == NULL) {
                 prev->next = NULL;
             } 
            prev = cur;
            cur = cur->next;
        }
        return head;
        
        
        
        
        /*
        while(cur) {
            while(cur != NULL) {
                if(cur->val == value) {
                    if(cur->next == NULL) {
                        prev->next = NULL;
                        cur = NULL;
                        delete(prev);
                    }
                    else {
                        prev->next = cur->next;
                        cur->next = NULL;
                    }
                }
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
        */
    }
};

int main() {
	Solution();
}
