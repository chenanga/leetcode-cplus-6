#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

bool myCmp(ListNode* a, ListNode* b) {
    return a->val > b->val;
}
class Solution {

public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(myCmp);
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* node = dummyNode;
        while (!pq.empty()) {
            node->next = pq.top();

            pq.pop();
            node = node->next;
            if (node->next != NULL)
                pq.push(node->next);
        }

        ListNode* ret = dummyNode->next;
        delete dummyNode;
        return ret;

    }
}; 



int main() {

    system("pause");
    return 0;
}