#include <stdio.h>
#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize){
    if(bitsSize == 1) return true;
    int i = 0;
    int a = 0;
    while(i < bitsSize){
        if(bits[i] == 0){
            a = 1;
        }
        else{
            a = 2;
        }
        i += a;
    }
    if(a == 1) return true;
    else return false;
}
int main(){
    int n = 4;
    char* set[3] = {1, 1, 1, 0};

    bool a = isOneBitCharacter(set, n);
    if(a == true) {
        printf("True\n");
    }
    else printf("False\n");

    return 0;
}