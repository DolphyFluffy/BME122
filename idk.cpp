#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList {	//suitable to store singly-linked list or forward list
	ListNode* first; //pointer to the first node in the list (not the actual first node in the list)
	ListNode* last; //pointer to store the last node in the list
	int size; //used to store the number of nodes in the list
public:
	LinkedList() : first(NULL), last(NULL), size(0) { }
};

class SolutionTest {
public:
	LinkedList( int a[]) {
		L = new LinkedList();
	}
	
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //pointers starting from either end
        //find last node
        if(!head || !head->next) return true;
        
       
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
        
        while(cur) {
            if(!next) {
                if(cur->val == prev->val) {
                    same = true;
                }
               return same; 
            }
            if(cur->val == prev->val && elements%2 ==0)
               same = true;
            else if(next->val == prev->val && elements%2 != 0)
                same = true;
            if(!next->next) return same;
            prev = cur;
            cur = next;
            next = next->next;
        }
        return same;
        
    }
};

int main() {
	Solution();
}
