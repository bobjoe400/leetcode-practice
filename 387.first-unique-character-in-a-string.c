/*
 * @lc app=leetcode id=387 lang=c
 *
 * [387] First Unique Character in a String
 */

#include "stdint.h"

// @lc code=start
// @lc code=start
int firstUniqChar(char* s) {
    int arr[26] = {0};

    int i = 0;
    while(s[i] != '\0'){
        arr[s[i] - 97]++;
        i++;
    }

    i=0;
    while(s[i] != '\0'){
        if (arr[s[i] - 97] == 1){
            return i;
        }
        i++;
    }

    return -1;
}
// @lc code=end

