#include <stdio.h>
#include <math.h>

#define line 3
#define column line

void main(void){
    // float arr[line][column] = {{3, 1}, {1, 2}};
    // float ans[line] = {45, 40};

    float arr[line][column] = {{-2, 1, 4},{3, -3, 3}, {5, 2, -2}};
    float ans[line] = {2, 1, 1};

    // float arr[line][column] = {{0, 3, 0},{0, 0, 1},  {3, 0, 0}};
    // float ans[line] = {1, 2, 1};

    // float arr[line][column] = {{0, 0, -2, 0}, {3, 0, 0, 0},{0, 1, 0, 0},{0, 0, 0, 1}};
    // float ans[line] = {1, 2, -4, 3};

    // float arr[line][column] = {{0, 1, 4, 0, -2}, {0, -4, 4, 0, -6}, {5, -2, 0, 0, 1}, {0, -3, 0, 2, 6}, {0, -6, 2, 0, -4}};
    // float ans[line] = {1, -4, 2, 3, 5};

    // float arr[line][column] = {{0, 1, 4, 3, -2, 7}, {3, 0, 3, 2, 6, -3}, {5, 2, 0, 10, 1, 2}, {2, -4, 4, 0, -6, -1}, {3, -6, 2, 6, 0, 5}, {1, 4, -1, 5, 2, 0}};
    // float ans[line] = {2, 1, -4, 3, 5, 5};
    
    /*8×8*/
    // float arr[line][column] = {{-2, 1, 4, 3, -2, 7, 2, 5}, {3, -3, 3, 2, 6, -3, -2, 7}, {5, 2, -2, 10, 1, 2, -2, 7}, {2, -4, 4, 1, -6, -1, -2, 7}, {3, -6, 2, 6, -4, 5, -2, 7}, {1, 4, -1, 5, -2, 1, -2, 7}, {-5, -6, -4, 6, -4, 5, -2, 7}, {3, 4, -1, -10, -2, -5, -2, 7}};
    // float ans[line] = {2, 1, -4, 3, 5, 5, 7, 3};

    /*9×9*/
    // float arr[line][column] = {
    // {-2, 1, 4, 3, -2, 7, 2, 5, 0}, 
    // {3, -3, 3, 2, 6, -3, -2, 7, 3}, 
    // {5, 2, -2, 10, 1, 2, -2, 7, 1}, 
    // {2, -4, 4, 1, -6, -1, -2, 7, 0}, 
    // {3, -6, 2, 6, -4, 5, -2, 7, 1}, 
    // {1, 4, -1, 5, -2, 1, -2, 7, 7}, 
    // {3, -6, -10, 6, -2, 5, -1, 7, 2}, 
    // {1, 4, -1, 5, -2, 1, -2, 7, 6}, 
    // {3, 4, -1, 2, -2, 1, -5 -2, 2}};
    // float ans[line] = {2, 1, -4, 3, 5, 5, 7, 3, 2};

    /*10×10*/
    // float arr[line][column] = {
    // {-2, 1, 4, 3, -2, 7, 2, 5, 0, 2}, 
    // {3, -3, 3, 2, 6, -3, -2, 7, 3, 4}, 
    // {5, 2, -2, 10, 1, 2, -2, 7, 1, 1}, 
    // {2, -4, 4, 1, -6, -1, -2, 7, 0, -1}, 
    // {3, -6, 2, 6, -4, 5, -2, 7, 1, 3}, 
    // {1, 4, -1, 5, -2, 1, -2, 7, 7, -2}, 
    // {3, -6, 2, -3, -4, 5, -1, 7, 2, 1}, 
    // {1, 3, -1, 6, -2, 6, -2, 7, 6, 5},
    // {1, 4, -3, 5, -2, 1, -2, 7, 6, 1}, 
    // {1, 4, -1, 5, -2, -11, -2, 7, 4, 5}};
    // float ans[line] = {2, 1, -4, 3, 5, 5, 7, 2, 3, 2};

    float res[line];

    /*対角成分が0かどうか調べる*/
    for(int i = 0; i < column; i++){
        if(arr[i][i] == 0){
            for(int j = i+1; j <= line-1; j++){
                if(arr[j][i] != 0){
                    for (int l = 0; l < column; l++){
                        float k = arr[i][l];
                        arr[i][l] = arr[j][l];
                        arr[j][l] = k;
                    }
                    float n = ans[i];
                    ans[i] = ans[j];
                    ans[j] = n;
                }
            }
        }
    }

    /*前進消去*/
    for(int i = 1; i < column; i++){
        for(int j = 0; j < i; j++){
            if(arr[i][j] != 0 && arr[j][j] != 0){
                float k = arr[i][j] / arr[j][j];
                ans[i] -= ans[j] * k;
                for(int l = 0; l < column; l++){
                    arr[i][l] -= arr[j][l] * k;  
                }
            }
        }
    }

    /*誤差を丸める*/
    for(int i = 0; i < column; i++){
        for(int j = 0; j < column; j++){
            arr[i][j] = round(arr[i][j]*10000) / 10000;
        }
    }



    /*行の入れ替え*/
    for(int h = 0; h < column; h++){
        for(int i = 0; i < column; i++){
            for(int j = i+1; j < column; j++){
                if(abs(arr[i][h]) < abs(arr[j][h])){
                    int all_zero = 1;
                    for(int m = h-1; m >= 0; m--){
                        if(arr[i][m] != 0 || arr[j][m] != 0){
                            all_zero = 0;
                            break;
                        }
                    }
                    if(all_zero){
                        for(int l = 0; l < column; l++){
                            float k = arr[i][l];
                            arr[i][l] = arr[j][l];
                            arr[j][l] = k;
                        }
                        float n = ans[i];
                        ans[i] = ans[j];
                        ans[j] = n;
                    }
                }
            }
        }
    }


    /*後退代入*/
    for(int i=column-1; i >= 0; i--){
        float k = 0;
        for(int j = column-1; j > i; j--){
            k += res[j] * arr[i][j];
        }
        k = ans[i] - k;
        res[i] = k / arr[i][i];
    }

    // for(int i = 0; i< column; i++){
    //     for(int j = 0; j < line; j++){
    //         printf("%f ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    /*解の表示*/
    for(int i = 0; i < column; i++){
        printf("x%d=%0.3f\n", i+1, res[i]);
    }
}