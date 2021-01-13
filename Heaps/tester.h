#include "functions.h"

int total_score, obtained_score;

void print_marks(int m, int full_marks, int ques_no){
    printf("You get %d out of %d in Test %d\n", m, full_marks, ques_no);
    total_score+=full_marks;
    obtained_score+=m;
}


bool exceedsTimeLimit(clock_t st_time, clock_t ed_time, int full_marks, int ques_no){
    if(((ed_time-st_time)*1.0)/(CLOCKS_PER_SEC*1.0)>3.0){
        printf("Your implementation is too slow\n");
        print_marks((full_marks*7)/10, full_marks, ques_no);
        return true;
    }
    return false;
}

int getRandom(int a, int b){
    return a+rand()%(b-a+1);
}


void print_case(int ara[], int lim, int mn, int res){
    printf("The values that were inserted onto the heap\n");
    printf("were as follows:\n");
    for(int i=0; i<lim; i++){
        printf("%d ", ara[i]);
    }
    printf("\n");
    printf("The number we expected to be extracted from the\n");
    printf("heap was %d and the number your heap extracted was %d\n", mn, res);
}

void test1(){
    printf("Testing your heap's insert and getMin operations\n");
    Heap h;
    int ara[105];
    for(int k=0; k<50; k++){
        h=Heap();
        for(int i=0; i<10; i++){
            ara[i]=i+1;
        }
        random_shuffle(ara, ara+10);
        int mn=ara[0], res;
        for(int i=0; i<10; i++){
            mn=min(mn, ara[i]);
            h.insertValue(ara[i]);
            res=h.getMin();
            if(mn!=res){
                printf("Your implementations of the insert and\ngetMin operations in your heap is wrong.\n");
                print_case(ara, i, mn, res);
                print_marks(0, 10, 1);
                return;
            }
        }
    }
    h=Heap();
    queue <int> q;
    int mn, v, res;
    clock_t st_time=clock();
    for(int i=0; i<100000; i++){
        v=rand();
        h.insertValue(v);
        res=h.getMin();
        if(i==0) mn=v;
        else mn=min(mn, v);
        q.push(v);
        if(mn!=res){
            printf("Your implementations of the insert and\nextract operations in your heap is wrong.\n");
            printf("The numbers we inserted onto your heap are printed in the debug.txt file\n");
            FILE* fp=fopen("debug.txt", "w");
            while(!q.empty()){
                fprintf(fp, "%d\n", q.front());
                q.pop();
            }
            printf("The number we expected to be extracted from the\n");
            printf("heap were %d and the number your heap extracted was %d\n", mn, res);
            print_marks(0, 10, 1);
            return;
        }
    }
    clock_t ed_time=clock();
    if(!exceedsTimeLimit(st_time, ed_time, 10, 1)){
        printf("The implementations of the insert and extract operations are correct and efficient\n");
        print_marks(10, 10, 1);
    }
    return;
}


void print_case_deletion(int ara[], int lim, int deleteLim, int mn, int res){
    printf("The values that were inserted onto the heap\n");
    printf("were as follows:\n");
    for(int i=0; i<=lim; i++){
        printf("%d ", ara[i]);
    }
    printf("\n");
    printf("The deleteMin function was then called %d times\n", deleteLim);
    printf("The number we expected to be extracted from the\n");
    printf("heap was %d and the number your heap extracted was %d\n", mn, res);
}

priority_queue <int, vector <int>, greater <int> > pq;

void test2(){
    printf("Testing the deleteMin function in the heap\n");
    Heap h;
    int ara[10005], lim;
    clock_t st_time=clock();
    for(int k=0; k<10; k++){
        if(k<5) lim=15;
        else lim=1000;
        for(int i=0; i<lim; i++){
            ara[i]=i+1;
        }
        random_shuffle(ara, ara+lim);
        int res, exp;
        h=Heap();
        while(!pq.empty()) pq.pop();
        for(int i=0; i<lim; i++){
            h.insertValue(ara[i]);
            pq.push(ara[i]);
            for(int j=0; j<i; j++){
                h.deleteMin();
                pq.pop();
                res=h.getMin();
                exp=pq.top();
                if(res!=exp){
                    printf("Your implementation of the deleteMin function is wrong.\n");
                    if(lim==15) print_case_deletion(ara, i, j+1, exp, res);
                    else{
                        printf("The numbers we inserted onto your heap are printed in the debug.txt file\n");
                        FILE* fp=fopen("debug.txt", "w");
                        for(int k=0; k<=i; k++){
                            fprintf(fp, "%d\n", ara[k]);
                        }
                    }
                    print_marks(0, 10, 2);
                    return;
                }
            }
            h.deleteMin();
            pq.pop();
            for(int j=0; j<=i; j++){
                h.insertValue(ara[j]);
                pq.push(ara[j]);
            }
        }
    }
    clock_t ed_time=clock();
    if(!exceedsTimeLimit(st_time, ed_time, 10, 2)){
        printf("The implementations of the delete operations are correct and efficient\n");
        print_marks(10, 10, 2);
    }
    return;
}

void evaluate(){
    srand(time(NULL));
    test1();
    test2();
    printf("You obtained %d out of %d\n", obtained_score, total_score);
}
