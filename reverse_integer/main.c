#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int reverse(int x);

int main(){
    int test = 1534236469;
    printf("%d\t%d\n", test,  reverse(test));
    return 0;
}

int reverse(int x){
    if(x == INT_MIN){
        return 0;
    }
    int minus = 1;
    if(x < 0){
        x = - x;
        minus = -1;
    }
    char tmp[16];
    sprintf(tmp, "%d", x);
    int len = strlen(tmp);
    for(int i = 0; i < len/2; ++i){
        char stemp = tmp[i];
        tmp[i] = tmp[len - 1 - i];
        tmp[len - 1 - i] = stemp;
    }
    long long result = atoll(tmp);
    long long max = INT_MAX;
    if(result > max){
        return 0;
    }
    return (int) minus * result;

}