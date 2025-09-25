#include "stdint.h"
#include "string.h"
#include "stdio.h"

// @lc code=start
int firstUniqChar(char* s) {
    uint32_t index[26] = {0};
    uint32_t freq[26] = {0};
    uint32_t i = 0;
    uint8_t freq_index = 0;

    while(*s != '\0'){
        freq_index = ((uint8_t) *s) - 0x61;

        freq[freq_index] = freq[freq_index] + 1;
        index[freq_index] = i;
        
        s++;
        i++;
    }
    
    uint32_t cur_freq = 0;
    uint32_t curr_index = 0;
    uint32_t min_index = UINT32_MAX;

    for(i = 0; i < 26; i++){
        cur_freq = freq[i];
        curr_index = index[i];

        if (cur_freq == 1){
            if(curr_index < min_index){
                min_index = curr_index;
            }
        }
    }
    
    return min_index;
}

int main(){
    char c[] = {'l', 'e', 'e', 't', 'c', 'o' , 'd', 'e', '\0'};

    printf("%i\n", firstUniqChar(c));
}