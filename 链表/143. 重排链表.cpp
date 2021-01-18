
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
        if (head == nullptr || head->next == nullptr) return;
        ListNode *slow = head, *fast = head, *pre;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        ListNode* l2 = reverseList(slow);
        head = mergeList(head, l2);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode *tmp_l1 = l1, *tmp_l2 = l2;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        l1->next = mergeList(l2, l1->next);
        return l1;
    }
};

================================================
class Solution {
public:
    void reorderList(ListNode* head) {
        // 找中点
        // 反序
        // merge队列
        if (head == nullptr) return;
        ListNode *mid = middleNode(head);
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeLists(l1, l2);

    }

    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    void mergeLists(ListNode* l1, ListNode* l2) {
        ListNode *l1_tmp = l1;
        ListNode *l2_tmp = l2;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;
            l1->next = l2;
            l1 = l1_tmp;
            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};

