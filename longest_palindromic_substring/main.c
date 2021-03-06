#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *longestPalindrome(char *s);

int main(){
    char test[] = "";
    char *longest = longestPalindrome(test);
    puts(longest);
    printf("%ld\n", strlen(longest));
    free(longest);
    return 0;
}

char *longestPalindrome(char *s){
    int sLen = strlen(s);
    int max = 0;
    int middle = 0;
    //scan for uneven palindrome
    for(int i = 0; i < sLen - max; ++i){
        int dif = 1;
        while(i - dif >= 0 && i + dif < sLen){
            if(s[i - dif] == s[i + dif]){
                ++dif;
            }
            else{
                break;
            }
        }
        if(dif > max){
            max = dif;
            middle = i;
        }
    }
    //scan for even palindrome
    if(max == 0){
        max = 1;
    }
    for(int i = max - 1; i < sLen - abs(max); ++i){
        if(s[i] == s[i + 1]){
            int dif = 1;
            while(i - dif >= 0 && i + dif + 1 < sLen){
                if(s[i - dif] == s[i + dif + 1]){
                    ++dif;
                }
                else{
                    break;
                }
            }
            if(dif >= abs(max)){
                max = -dif;
                middle = i;
            }
        }
    }
    char *result;
    int i;
    if(max > 0){
        int resLen = (2 * max - 1);
        result = (char*)malloc((resLen + 1) * sizeof(char));
        for(i = 0; i < resLen; ++i){
            result[i] = s[middle - max + 1 + i];
        }
    }
    else{
        max = - max;
        int resLen = (2 * max);
        result = (char*)malloc((resLen + 1) * sizeof(char));
        for(i = 0; i < resLen; ++i){
            result[i] = s[middle - max + 1 + i];
        }

    }
    result[i] = '\0';
    
    return result;
}