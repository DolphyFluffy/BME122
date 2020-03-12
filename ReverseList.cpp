#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	}
	
bool LinkedList::reverse_list() {
	if(!first)
		return NULL;
	else if(!first->next)
		return first;
	else{
		Node* prev = NULL;
		Node* cur = first;
		Node* next = NULL;
		while(cur) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		first = prev;
	}
	return true;
}


Pallindrome

ListNode* cur = head->next;
        ListNode* prev = head;
        bool same = false;
        ListNode* next = head->next->next;
        int elements = 0;
        
        while(cur) {
            prev = cur;
            cur = cur->next;
            elements++;
        }
        prev = head;
        cur = head->next;
        next = cur->next;
        
        while(cur) {
            if(!next) {
                if(cur->val == prev->val) {
                    same = true;
                }
               return same; 
            }
            if(cur->val == prev->val && elements%2 ==0)
               same = true;
            else if(next->val == prev->val && (elements%2 != 0))
                same = true;
            if(!next->next) return same;
            prev = cur;
            cur = next;
            next = next->next;
        }
        return same;


