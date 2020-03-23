#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int lengthOfLongestSubstring(char *s);

int main(){
    char text[] = "aab";
    printf("%d\n", lengthOfLongestSubstring(text));
    return 0;
}

int lengthOfLongestSubstring(char *s){
    int len = 0;
    int sLen = strlen(s);
    int i, j = 1, k;
    for(i = 0; i < sLen-len; ++i){
        for(; j < sLen; ++j){
            int wasBefore = 0;
            for(k = i; k < j; ++ k){
                if(s[k] == s [j]){
                    wasBefore = 1;
                    break;
                }
            }
            if (wasBefore == 1) {
                if (j-i > len){
                    len = j-i;
                }
                i = k;
                break;
            }
        }
        if (j-i > len){
            len = j-i;
        }
    }
    return len;
}
