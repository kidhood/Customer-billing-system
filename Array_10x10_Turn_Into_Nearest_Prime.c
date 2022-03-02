#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 100

int intRandom(int min, int max);
int checkPrime(int n);
void initMatrix();
void turnNearestPrime(int a[MAXN][MAXN]);
void printArray();

int main(){
    int counter;
    int a[MAXN][MAXN];
    srand(time(NULL));
    initMatrix(a);
    printf("Before converting:\n");
    printArray(a);
    turnNearestPrime(a);
    printf("After converting:\n");
    printArray(a);
    return 0;
}
void printArray(int a[MAXN][MAXN]){
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
}
void turnNearestPrime(int a[MAXN][MAXN]){
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            for(int l = 0; ; l++){
                if (checkPrime(a[i][j] - l)){
                    a[i][j] = a[i][j] - l;
                    break;
                }
                if (a[i][j] <= INT_MAX - l && checkPrime(a[i][j] + l)){
                    a[i][j] = a[i][j] + l;
                    break;
                }
            }
}

void initMatrix(int a[MAXN][MAXN]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            a[i][j] = intRandom(1,100);  
        }
    }
}
int intRandom(int min, int max){
    int number = (rand() % ((max + 1) - min) + min);
    return number;
}
int checkPrime(int n){
    int flag;
    if(n == 0 || n == 1){
        flag = 1;
    }
    for(int i = 2; i <= (n/2); ++i){
        if(n % i == 0){
            flag = 1;
            break;
        }
        else flag = 0;
    }
    if(flag == 1){
        return 0;
    }
    if(flag == 0){
        return 1;
    }
}
 
 
