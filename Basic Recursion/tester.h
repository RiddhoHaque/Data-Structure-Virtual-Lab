#include <bits/stdc++.h>
#include "functions.h"
using namespace std;

void print_marks(int m, int full_marks, int ques_no){
    printf("You get %d out of %d in Test %d\n", m, full_marks, ques_no);
}


bool exceedsTimeLimit(clock_t st_time, clock_t ed_time){
    return ((ed_time-st_time)*1.0)/(CLOCKS_PER_SEC*1.0)>3.0;
}

int test1(){
    printf("Testing the first function\n");
    int n;
    for(int i=0; i<5; i++){
        n=2*(rand()%10+1);
        if(func(n)!=(n/2)*(n/2+1)){
            printf("Your implementation of func is incorrect. For n=%d, the expected value is %d, and your function returns %d\n", n, (n/2)*(n/2+1), func(n));
            print_marks(0, 10, 1);
            return 0;
        }
    }
    clock_t st_time=clock();
    n=50000-(rand()%20)*2;
    int val=func(n);
    if(val!=(n/2)*(n/2+1)){
        printf("Your implementation of func is incorrect. For n=%d, the expected value is %d, and your function returns %d\n", n, (n/2)*(n/2+1), val);
        print_marks(0, 10, 1);
        return 0;
    }
    clock_t ed_time=clock();
    if(exceedsTimeLimit(st_time, ed_time)){
        printf("Your implementation of func is correct but inefficient\n");
        print_marks(7, 10, 1);
        return 7;
    }
    printf("Your implementation of func is correct and efficient\n");
    print_marks(10, 10, 1);
    return 10;
}

int iterative_sum_of_digits(int n){
    int sum=0;
    while(n){
        sum+=(n%10)*(n%10);
        n=n/10;
    }
    return sum;
}

int getRandomNumberinRange(int a, int b){
    return rand()%(b-a+1)+a;
}

int test_sum_of_digits(int iter_limit, int low, int high){
    for(int i=0; i<iter_limit; i++){
        int n=getRandomNumberinRange(low, high);
        if(sum_of_digits_squared(n)!=iterative_sum_of_digits(n)){
            printf("Your implementation of sum_of_digits_squared is incorrect.\nFor n=%d, the expected value is %d, and your function returns %d\n", n, iterative_sum_of_digits(n), sum_of_digits_squared(n));
            print_marks(0, 10, 2);
            return 0;
        }
    }
    return 10;
}

int check_time_limit(char name_of_test[], int no_of_test, clock_t st_time, clock_t ed_time){
    if(exceedsTimeLimit(st_time, ed_time)){
        printf("Your implementation of %s is correct but inefficient\n", name_of_test);
        print_marks(7, 10, no_of_test);
        return 7;
    }
    printf("Your implementation of %s is correct and efficient\n", name_of_test);
    print_marks(10, 10, no_of_test);
    return 10;
}

int test2(){
    printf("Testing the sum of digits squared function\n");
    int n;
    clock_t st_clock=clock();
    int verdict=test_sum_of_digits(5, 1, 9);
    if(verdict==0) return 0;
    verdict=test_sum_of_digits(50, 11, 99);
    if(verdict==0) return 0;
    verdict=test_sum_of_digits(500, 111, 999);
    if(verdict==0) return 0;
    verdict=test_sum_of_digits(5000, 1111, 9999);
    if(verdict==0) return 0;
    verdict=test_sum_of_digits(50000, 11111, 99999);
    if(verdict==0) return 0;
    verdict=test_sum_of_digits(500000, 11111111, 99999999);
    if(verdict==0) return 0;
    clock_t ed_clock=clock();
    return check_time_limit("sum_of_digits_squared", 2, st_clock, ed_clock);
}

int check_for_array_of_length(int ara[], int len, bool st_max, bool ed_max){
    int mx=0;
    for(int i=0; i<len; i++){
        if(st_max && i==0){
            ara[i]=rand()%1000;
        }
        else if(st_max) ara[i]=getRandomNumberinRange(1, ara[0]-1);
        else if(ed_max && i==len-1){
            ara[i]=mx+1;
        }
        else{
            ara[i]=rand()+1;
        }
        mx=max(mx, ara[i]);
    }
    if(max_of_array(ara, len)!=mx){
        printf("Your max_of_array function is incorrect\n");
        if(len<=10){
            printf("For the following array:\n");
            for(int i=0; i<len; i++){
                printf("%d ", ara[i]);
            }
            printf("\n");
            printf("The max_of_array function says the max is %d\n", max_of_array(ara, len));
        }
        print_marks(0, 10, 3);
        return 0;
    }
    return 10;
}

int check_with_length(int ara[], int len){
    int verdict=check_for_array_of_length(ara, len, false, false);
    if(verdict==0){
        return 0;
    }
    verdict=check_for_array_of_length(ara, len, true, false);
    if(verdict==0){
        return 0;
    }
    verdict=check_for_array_of_length(ara, len, false, true);
    if(verdict==0){
        return 0;
    }
    return 10;
}

int check_correctness(int ara[]){
    int len=getRandomNumberinRange(8, 10);
    int verdict=check_with_length(ara, len);
    if(verdict==0){
        return 0;
    }
    len=500;
    verdict=check_with_length(ara, len);
    if(verdict==0){
        return 0;
    }
    len=9000;
    clock_t st_time=clock();
    for(int i=0; i<10; i++){
        verdict=check_with_length(ara, len);
        if(verdict==0){
            return 0;
        }
    }
    clock_t ed_time=clock();

    return check_time_limit("max_of_array", 3, st_time, ed_time);

}

int test3(){
    printf("Testing the max_of_array function\n");
    int ara[100000];
    return check_correctness(ara);
}

int test4(){
    printf("Testing your factorial function\n");
    int prod=1;
    if(factorial(0)!=prod){
        printf("%d! = %d, but your factorial function returns %d\n", 0, prod, factorial(0));
        print_marks(0, 10, 4);
        return 0;
    }
    for(int i=1; i<=10; i++){
        prod*=i;
        if(factorial(i)!=prod){
            printf("%d! = %d, but your factorial function returns %d\n", i, prod, factorial(i));
            print_marks(0, 10, 4);
            return 0;
        }
    }
    printf("Your factorial function is correct\n");
    print_marks(10, 10, 4);
    return 10;
}

int evaluate(){
    srand(time(NULL));
    int sum=test1();
    sum+=test2();
    sum+=test3();
    sum+=test4();
    printf("You get %d out of %d in total\n", sum, 40);
}
