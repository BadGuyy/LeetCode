/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 链表节点相加法
        // 时间复杂度O(max(m,n))，空间复杂度O(max(m,n))
        ListNode *head = new 
        ListNode(0);
        ListNode *cur = head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            // 计算被加数每位的值，有值取值，无值取0
            int l1Val = 0, l2Val = 0;
            if (l1 != nullptr)
            {
                l1Val = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2Val = l2->val;
                l2 = l2->next;
            }

            // 计算和，有进位则值余10，进位等于1
            int digit = (l1Val + l2Val + carry);
            carry = digit / 10;
            digit %= 10;

            cur->next = new ListNode(digit);
            cur = cur->next;
        }
        return head->next;

        
        // 暴力直觉法，将链表转为数字，然后相加，再转为链表
        // 时间复杂度O(max(m,n))，空间复杂度O(max(m,n))
        // 不可行，因为数字可能很大，相加后很可能溢出
        // 可考虑使用大数类
        // int num1 = 0, num2 = 0;
        // stack<int> stack1, stack2;
        // while (l1 != nullptr)
        // {
        //     stack1.push(l1->val);
        //     l1 = l1->next;
        // }
        // while (l2 != nullptr)
        // {
        //     stack2.push(l2->val);
        //     l2 = l2->next;
        // }
        // while (!stack1.empty())
        // {
        //     num1 = num1 * 10 + stack1.top();
        //     stack1.pop();
        // }
        // while (!stack2.empty())
        // {
        //     num2 = num2 * 10 + stack2.top();
        //     stack2.pop();
        // }

        // int sum = num1 + num2;
        // ListNode *head = new ListNode(sum % 10);
        // ListNode *cur = head;
        // while (sum >= 10)
        // {
        //     sum /= 10;
        //     cur->next = new ListNode(sum % 10);
        //     cur = cur->next;
        // }
        // return head;
    }
};
// @lc code=end
