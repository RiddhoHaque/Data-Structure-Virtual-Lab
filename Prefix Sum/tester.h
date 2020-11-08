#include <bits/stdc++.h>
#include "functions.h"
using namespace std;
int n;
int ara[100005];
int pre[100005];
int suf[100005];

int test1(){
    printf("Evaluating the first function\n");
    n=100000;
    for(int i=0; i<n; i++){
        ara[i]=rand()%1000-500;
    }
    clock_t st_time=clock();
    build_prefix_sum_array(n, ara, pre);
    clock_t ed_time=clock();
    int sum=0;
    bool correct=true;
    bool semi_correct=true;
    int mismatch_count=0;
    for(int i=0; i<n; i++){
        sum+=ara[i];
        if(sum!=pre[i]){
            correct=false;
            mismatch_count++;
        }
        if((sum-ara[0])!=(pre[i]-ara[0])){
            semi_correct=false;
        }
    }
    if(correct){
        if((((ed_time-st_time)*1.0)/(1.0*CLOCKS_PER_SEC))<3.0){
            printf("Congratulations, you have implemented the first function successfully!\n");
            printf("You get 10 out of 10 for this one!\n");
            return 10;
        }
        else{
            printf("Ooops, turns out your implementation for the first function is a bit slow.\n");
            printf("Let's make it faster now!\n");
            printf("Your current solution gets 8 out of 10\n");
            return 8;
        }
    }
    else if(semi_correct){
        printf("Oops, seems like you missed a corner case, try again!\n");
        printf("Your current solution gets 7 out of 10\n");
        return 7;
    }
    else if(mismatch_count<=5){
        printf("Almost there, keep trying!\n");
        printf("Your current solution gets 6 out of 10\n");
        return 6;
    }
    printf("Seems like your current solution is wrong.\n");
    printf("Your current solution gets 0 out of 10\n");
    return 0;
}

int test2(){
    printf("Evaluating the second function\n");
    suf[n]=0;
    suf[n-1]=ara[n-1];
    for(int i=n-2; i>=0; i--){
        suf[i]=suf[i+1]+ara[i];
    }
    bool check1=true;
    clock_t st_time=clock();
    for(int l=1; l<=1000; l++){
        for(int r=n-1; r>=n-1000; r--){
            if(get_range_sum(n, ara, pre, l, r)!=suf[l]-suf[r+1]){
                check1=false;
            }
        }
    }
    clock_t ed_time=clock();
    if(!check1){
        printf("Seems like your current solution is wrong.\n");
        printf("Your current solution gets 0 out of 10\n");
        return 0;
    }
    bool check2=true;
    for(int r=n-1; r>=n-100; r--){
        if(get_range_sum(n, ara, pre, 0, r)!=suf[0]-suf[r+1]){
            check2=false;
        }
    }
    if(!check2){
        printf("Oops, seems like you missed a corner case, try again!\n");
        printf("Your current solution gets 7 out of 10\n");
        return 7;
    }
    if((((ed_time-st_time)*1.0)/(1.0*CLOCKS_PER_SEC))<3.0){
            printf("Congratulations, you have implemented the second function successfully!\n");
            printf("You get 10 out of 10 for this one!\n");
            return 10;
    }
    else{
        printf("Ooops, turns out your implementation for the second function is a bit slow.\n");
        printf("Let's make it faster now!\n");
        printf("Your current solution gets 8 out of 10\n");
        return 8;
    }
}

int r, c;
int ara2[1005][1005];
int pre2[1005][1005];
int suf2[1005][1005];

int test3(){
    printf("Evaluating the third function\n");
    r=1000;
    c=995;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            ara2[i][j]=rand()%1000-500;
        }
    }
    for(int i=0; i<=r; i++) suf2[i][c]=0;
    for(int i=0; i<=c; i++) suf2[r][i]=0;
    for(int i=r-1; i>=0; i--){
        for(int j=c-1; j>=0; j--){
            suf2[i][j]=suf2[i+1][j]+suf2[i][j+1]-suf2[i+1][j+1]+ara2[i][j];
        }
    }
    clock_t st_time=clock();
    build_prefix_sum_array_2D(r, c, ara2, pre2);
    clock_t ed_time=clock();
    int mismatch_count=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(pre2[i][j]!=(suf2[0][0]-suf2[i+1][0]-suf2[0][j+1]+suf2[i+1][j+1])){
                mismatch_count++;
            }
        }
    }
    if(mismatch_count==0){
        if((((ed_time-st_time)*1.0)/(1.0*CLOCKS_PER_SEC))<3.0){
            printf("Congratulations, you have implemented the third function successfully!\n");
            printf("You get 10 out of 10 for this one!\n");
            return 10;
        }
        else{
            printf("Ooops, turns out your implementation for the third function is a bit slow.\n");
            printf("Let's make it faster now!\n");
            printf("Your current solution gets 8 out of 10\n");
            return 8;
        }
    }
    if(mismatch_count<=r){
        printf("Oops, seems like you missed a corner case, try again!\n");
        printf("Your current solution gets 7 out of 10\n");
        return 7;
    }
    printf("Seems like your current solution is wrong.\n");
    printf("Your current solution gets 0 out of 10\n");
    return 0;
}

int test4(){
    printf("Evaluating the fourth function\n");
    int mismatch_count=0;
    clock_t st_time=clock();
    for(int t=0; t<10; t++){
        for(int b=r-1; b>=r-10; b--){
            for(int l=0; l<10; l++){
                for(int rgt=c-1; rgt>=c-10; rgt--){
                    if(get_range_sum_2D(ara2, pre2, t, b, l, rgt)!=(suf2[t][l]-suf2[b+1][l]-suf2[t][rgt+1]+suf2[b+1][rgt+1])){
                        mismatch_count++;
                    }
                }
            }
        }
    }
    clock_t ed_time=clock();
    if(mismatch_count==0){
        if((((ed_time-st_time)*1.0)/(1.0*CLOCKS_PER_SEC))<3.0){
            printf("Congratulations, you have implemented the fourth function successfully!\n");
            printf("You get 10 out of 10 for this one!\n");
            return 10;
        }
        else{
            printf("Ooops, turns out your implementation for the fourth function is a bit slow.\n");
            printf("Let's make it faster now!\n");
            printf("Your current solution gets 8 out of 10\n");
            return 8;
        }
    }
    if(mismatch_count<=r){
        printf("Oops, seems like you missed a corner case, try again!\n");
        printf("Your current solution gets 7 out of 10\n");
        return 7;
    }
    printf("Seems like your current solution is wrong.\n");
    printf("Your current solution gets 0 out of 10\n");
    return 0;
}


int test_ara[100005];
int test5(){
    printf("Evaluating the fifth function\n");
    n=100000;
    for(int i=0; i<n; i++){
        ara[i]=rand()%1000-500;
        if(i==0) pre[0]=ara[0];
        else pre[i]=ara[i]+pre[i-1];
    }
    clock_t st_time=clock();
    get_original_array(n, pre, test_ara);
    clock_t ed_time=clock();
    int mismatch_count=0;
    for(int i=0; i<n; i++){
        if(ara[i]!=test_ara[i]){
            mismatch_count++;
        }
    }
    if(mismatch_count==0){
        if((((ed_time-st_time)*1.0)/(1.0*CLOCKS_PER_SEC))<3.0){
            printf("Congratulations, you have implemented the fifth function successfully!\n");
            printf("You get 10 out of 10 for this one!\n");
            return 10;
        }
        else{
            printf("Ooops, turns out your implementation for the fifth function is a bit slow.\n");
            printf("Let's make it faster now!\n");
            printf("Your current solution gets 8 out of 10\n");
            return 8;
        }
    }
    if(mismatch_count==1){
        printf("Oops, seems like you missed a corner case, try again!\n");
        printf("Your current solution gets 7 out of 10\n");
        return 7;
    }
    printf("Seems like your current solution is wrong.\n");
    printf("Your current solution gets 0 out of 10\n");
    return 0;
}

void evaluate(){
    srand(time(NULL));
    int sum=test1();
    printf("\n\n");
    sum+=test2();
    printf("\n\n");
    sum+=test3();
    printf("\n\n");
    sum+=test4();
    printf("\n\n");
    sum+=test5();
    printf("\n\n");
    printf("Your total marks is %d out of 50\n", sum);
}

