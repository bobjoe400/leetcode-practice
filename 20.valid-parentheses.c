/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// @lc code=start

#define STACK_SIZE 100000

bool matches(char stack, char curr){
    return  (stack  == '(' && curr == ')') ||
            (stack  == '{' && curr == '}') ||
            (stack  == '[' && curr == ']');
}

bool isValid(char* s) {
    char stack[STACK_SIZE] = {0};
    uint32_t sp = STACK_SIZE;

    while(*s != '\0'){
        if(*s == '(' || *s == '{' || *s == '['){
            stack[--sp] = *s;
        } else if (*s == ')' || *s == '}' || *s == ']'){
            if(sp == STACK_SIZE){ // stack is empty
                return false; // no matching opener
            }

            if(!matches(stack[sp++], *s)){
                return false;
            }
        }

        s++;
    }

    if(sp != STACK_SIZE){ // stack isn't empty
        return false;
    }

    return true;
}
// @lc code=end

int main(){
    char* test_string = "()";

    isValid(test_string);
}

