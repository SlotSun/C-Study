//
// Created by SUN on 2019/8/10.
//

#ifndef STUDY_LEETCODE_H
#define STUDY_LEETCODE_H

#endif //STUDY_LEETCODE_H

//7.给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
int reverse(int x) {
    int max = 0x7fffffff, min = 0x80000000;//int的最大值最小值
    long rs = 0;//用long类型判断溢出
    for (; x; rs = rs * 10 + x % 10, x /= 10);//逆序，正负通吃，不用单独考虑负值
    return rs > max || rs < min ? 0 : rs;//超了最大值低于最小值就返回0
}
//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

int removeDuplicates(int *nums, int numsSize) {
    int i = 0;
    for (int j = i + 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。


//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

void reverseString(char *s, int sSize) {
    char temp;
    for (int i = 0; i < sSize / 2; ++i) {
        temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
}

//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
LinkList addTwoNumbers(LNode *l1, LNode *l2) {
    LNode *l3 = (LinkList) malloc(sizeof(LinkList));
    LNode *curr = l3;
    int carry = 0;
    while (l1 || l2) {
        int val1 = l1 ? l1->data : 0;
        int val2 = l2 ? l2->data : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        LinkList s = (LinkList) malloc(sizeof(LinkList));
        s->data = sum % 10;
        s->next = NULL;
        curr->next = s;
        curr = curr->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry) {
        LinkList s = (LinkList) malloc(sizeof(LinkList));
        s->data = carry;
        s->next = NULL;
        curr->next = s;
    }
    return l3;
}
//无重复字符的最长子串
int lengthOfLongestSubstring(char * s){
    int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};
    map[(int)*(s+start)] = 1;
    while( *(s+end) != 0 )
    {
        maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
        ++end;
        while( 0 != map[ (int)*(s+end) ] )//将要加入的新元素与map内元素冲突
        {
            map[ (int)*(s+start) ] = 0;
               ++start;
        }
        map[(int)*(s+end)] = 1;
    }

    return maxlen;
}

















































