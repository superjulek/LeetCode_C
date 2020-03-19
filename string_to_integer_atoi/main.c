#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char *str);

int main(){
    char text[20] = "   -345 hello 23";
    printf("%d\n", myAtoi(text));
    return 0;
}

int myAtoi (char *str){
    char *tmp = (char*)malloc(strlen(str) * sizeof(char));
    int len = strlen(str);
    int captured = 0;
    int finish = 0;
    int tmpCnt = 0;
    for (int i = 0; i < len && finish == 0; ++i){
        switch (str[i]){
            case ' ':
            if(captured == 1){
                finish = 1;
            }
            break;
            case '-':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '+':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '0':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '1':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '2':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '3':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '4':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '5':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '6':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '7':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '8':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            case '9':
            tmp[tmpCnt] = str[i];
            tmpCnt ++;
            captured = 1;
            break;
            default:
            finish = 1;
            break;
        }
        tmp[tmpCnt] = 0;

    }
    long long result = atoll(tmp);
    free(tmp);
    if (result > INT_MAX){
        return INT_MAX;
    }
    if (result < INT_MIN){
        return INT_MIN;
    }
    return (int) result;
}