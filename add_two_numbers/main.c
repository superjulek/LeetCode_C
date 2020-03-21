#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(){
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode node1 = *l1;
    struct ListNode node2 = *l2;
    struct ListNode *result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *current = result;
    current->val = 0;
    int wasNull1 = 0;
    int wasNull2 = 0;
    while(wasNull1 == 0 || wasNull2 == 0){
        if(wasNull1 == 0){
            current->val += node1.val;
            if(node1.next == NULL){
                wasNull1 = 1;
            }
            else{
                node1 = *(node1.next);
            }

        }
        if(wasNull2 == 0){
            current->val += node2.val;
            if(node2.next == NULL){
                wasNull2 = 1;
            }
            else{
                node2 = *(node2.next);
            }

        }
        if(wasNull1 == 0 || wasNull2 == 0 || current->val > 9){
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            if(current->val > 9){
                current->val -= 10;
                current->next->val = 1;
            }
            else{
                current->next->val = 0;
            }
            current = current->next;

        }
    }
    current->next = NULL;
    return result;
}
