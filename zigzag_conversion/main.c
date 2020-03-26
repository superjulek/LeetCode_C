#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows);

int main(){
    char test[] = "ArekMieszkaWZgierzu";
    char *output = convert(test, 4);
    puts(output);
    free(output);
    return 0;
}

//Bad solution in terms of speed, but can display result

char *convert(char *s, int numRows){
    int sLen = strlen(s);
    int r = numRows;
    int c = (int)(sLen / (numRows * 2. - 2.) * (numRows - 1.) + 1);
    if(numRows == 1){
        c = sLen + 1;
        return s;
    }
    //printf("rows = %d columns = %d\n", r, c);
    char *result = (char*)calloc(sLen + 1, sizeof(char));
    //Allocate array
    char **arr = (char**)calloc(r, sizeof(char*));
    for(int i = 0; i < r; ++i){
        arr[i] = (char*)calloc(c, sizeof(char));
    }
    int col = 0;
    int row = 0;
    for(int i = 0; i < sLen; ++i){
        int pos = i % (numRows * 2 - 2);
        //printf("element pos %d to row %d col %d\n", pos, row, col);
        if(pos < numRows){
            arr[row][col] = s[i];
            if(row == numRows - 1){
                col++;
                row--;
            }
            else{
                row++;
            }
        }
        else{
            arr[row][col] = s[i];
            row--;
            col++;
        }
    }
    int counter = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            printf("%c\t", arr[i][j]);
            if(arr[i][j] != 0){
                result[counter] = arr[i][j];
                counter ++;
            }
        }
        printf("\n");
    }

    //Free array
    for(int i = 0 ; i < r; ++i){
        free(arr[i]);
    }
    free(arr);
    return result;
}