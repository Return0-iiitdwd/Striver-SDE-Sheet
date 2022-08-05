// Link: - https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach - 1 (Three Pointers) Time: - O(n) Space: - O(1)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL, *cur = head, *nxt = NULL;
        while (cur != NULL)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

// Approach - 2 (Variation of Three Pointer) Time: - O(n) Space: - O(1)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newHead = NULL;

        while (head != NULL)
        {
            ListNode *nxt = head->next;
            head->next = newHead;
            newHead = head;
            head = nxt;
        }
        return newHead;
    }
};

// Approach - 3 (Recursion) Time: - O(n) Space: - O(n)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};