#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intToRoman(int num);

int main() {
    int a;
    printf("Podaj liczbe 1 - 3999\n");
    scanf("%d", &a);
    printf("%s\n", intToRoman(a));
}

char* intToRoman(int num) {
    int n = 10;
    int counter = 0;
    char* result = (char*)calloc(n, sizeof(char));
    int m = num / 1000; //number of 1000
    num -= m * 1000;
    int c = num / 100; //number of 100
    num -= c * 100;
    int x = num / 10; //number of 10
    num -= x * 10;
    int i = num; //number of 1
    //printf("%d %d %d %d\n", m, c, x, i);
    switch (m) {
    case 0:
        break;
    case 1:
        counter+=sprintf(result + counter, "M");
        break;
    case 2:
        counter += sprintf(result + counter, "MM");
        break;
    case 3:
        counter += sprintf(result + counter, "MMM");
        break;
    }
    switch (c) {
    case 0:
        break;
    case 1:
        counter += sprintf(result + counter, "C");
        break;
    case 2:
        counter += sprintf(result + counter, "CC");
        break;
    case 3:
        counter += sprintf(result + counter, "CCC");
        break;
    case 4:
        counter += sprintf(result + counter, "CD");
        break;
    case 5:
        counter += sprintf(result + counter, "D");
        break;
    case 6:
        counter += sprintf(result + counter, "DC");
        break;
    case 7:
        counter += sprintf(result + counter, "DCC");
        break;
    case 8:
        counter += sprintf(result + counter, "DCCC");
        break;
    case 9:
        counter += sprintf(result + counter, "CM");
        break;
    }
    switch (x) {
    case 0:
        break;
    case 1:
        counter += sprintf(result + counter, "X");
        break;
    case 2:
        counter += sprintf(result + counter, "XX");
        break;
    case 3:
        counter += sprintf(result + counter, "XXX");
        break;
    case 4:
        counter += sprintf(result + counter, "XL");
        break;
    case 5:
        counter += sprintf(result + counter, "L");
        break;
    case 6:
        counter += sprintf(result + counter, "LX");
        break;
    case 7:
        counter += sprintf(result + counter, "LXX");
        break;
    case 8:
        counter += sprintf(result + counter, "LXXX");
        break;
    case 9:
        counter += sprintf(result + counter, "XC");
        break;
    }
    switch (i) {
    case 0:
        break;
    case 1:
        counter += sprintf(result + counter, "I");
        break;
    case 2:
        counter += sprintf(result + counter, "II");
        break;
    case 3:
        counter += sprintf(result + counter, "III");
        break;
    case 4:
        counter += sprintf(result + counter, "IV");
        break;
    case 5:
        counter += sprintf(result + counter, "V");
        break;
    case 6:
        counter += sprintf(result + counter, "VI");
        break;
    case 7:
        counter += sprintf(result + counter, "VII");
        break;
    case 8:
        counter += sprintf(result + counter, "VIII");
        break;
    case 9:
        counter += sprintf(result + counter, "IX");
        break;
    }



    return result;
}