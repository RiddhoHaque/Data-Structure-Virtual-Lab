#include "functions.h"
#include <bits/stdc++.h>
using namespace std;
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

struct DSUBrute{
    int ara[1005];
    int n;
    DSUBrute(int n){
        this->n=n;
        for(int i=0; i<n; i++){
            ara[i]=i;
        }
    }

    void mergeSets(int a, int b){
        int sv=ara[a];
        for(int i=0; i<n; i++){
            if(ara[i]==sv){
                ara[i]=ara[b];
            }
        }
    }

    int query(int a, int b){
        if(ara[a]==ara[b]){
            return 1;
        }
        return 0;
    }
};


struct ChangingArraysBrute{
    int ara[100105];
    int n;
    ChangingArraysBrute(int a[], int n){
        this->n=n;
        for(int i=0; i<n; i++){
            this->ara[i]=a[i];
        }
    }

    void update(int x, int y){
        for(int i=0; i<n; i++){
            if(ara[i]==x){
                ara[i]=y;
            }
        }
    }

    int query(int i){
        return ara[i];
    }
};


bool randomDSUCheck(int lim){
    int a, b;
    DSU d=DSU(lim);
    DSUBrute db=DSUBrute(lim);
    queue < pair <int, int> > q;
    for(int i=0; i<5*lim; i++){
        a=rand()%lim;
        b=rand()%lim;
        if(rand()%2==1){
            //cout<<"Merging "<<a<<" "<<b<<endl;
            d.mergeSets(a, b);
            db.mergeSets(a, b);
            q.push({a, b});
        }
        else{
            //cout<<"Querying "<<a<<" "<<b<<endl;
            if(d.query(a, b)!=db.query(a, b)){
                cout<<"Your implementation for DSU is wrong\n";
                cout<<"The case in which your code gave a wrong output is written in debug.txt\n"<<endl;
                FILE* debug=fopen("debug.txt", "w");
                if(q.empty()) fprintf(debug, "In a DSU with %d elements, the merging operations were done on\n", lim);
                else fprintf(debug, "In a DSU with %d elements, the merging operations were done on\n", lim);
                while(!q.empty()){
                    fprintf(debug, "%d %d\n", q.front().first, q.front().second);
                    q.pop();
                }
                fprintf(debug, "The elements on which the query was done were: %d %d\n", a, b);
                fprintf(debug, "Expected Output: %d\n", db.query(a, b));
                fprintf(debug, "Your DSU's output: %d\n", d.query(a, b));
                print_marks(0, 10, 1);
                return false;
            }
            //cout<<db.query(a, b)<<" "<<d.query(a, b)<<endl;
        }
    }
    return true;
}
int ara[100105];
queue < pair <int, int> > q;

ChangingArrays ca=ChangingArrays(ara, 1);

bool randomChangingArrayCheck(int lim){
    for(int i=0; i<lim; i++){
        ara[i]=rand()%lim;
    }
    ca=ChangingArrays(ara, lim);
    ChangingArraysBrute cab=ChangingArraysBrute(ara, lim);
    //cout<<"Construction done\n";
    for(int i=0; i<2*lim; i++){
        if(rand()%2==1){
            int x=rand()%1000;
            int y=rand()%1000;
            ca.update(x, y);
            cab.update(x, y);
            q.push({x, y});
        }
        else{
            int ind=rand()%lim;
            if(ca.query(ind)!=cab.query(ind)){
                cout<<"Your solution to the changing arrays problem is wrong\n";
                cout<<"The case in which your code gave a wrong output is written in debug2.txt\n"<<endl;
                FILE* debug=fopen("debug2.txt", "w");
                fprintf(debug, "The array contained %d elements\n", lim);
                for(int i=0; i<lim; i++){
                    fprintf(debug, "%d ", ara[i]);
                }
                if(q.size()>0){
                    fprintf(debug, "\nThe updates done were:\n");
                    while(!q.empty()){
                        fprintf(debug, "%d %d\n", q.front().first, q.front().second);
                        q.pop();
                    }
                }
                else{
                    fprintf(debug, "\nNo updates were done\n");
                }
                fprintf(debug, "The index on which the query was done was %d\n", ind);
                fprintf(debug, "Expected Output: %d\n", cab.query(ind));
                fprintf(debug, "Your output: %d\n", ca.query(ind));
                print_marks(0, 10, 2);
                fclose(debug);
                return false;
            }
        }
    }
    while(!q.empty()) q.pop();
    return true;
}


void genRandomInputDSU(){
    char fileName[25], output[25];
    for(int i=0; i<5; i++){
        sprintf(fileName, "dsu%d.txt", i);
        sprintf(output, "out%d.txt", i);
        FILE* in=fopen(fileName, "w");
        FILE* out=fopen(output, "w");
        DSU dsu=DSU(100000);
        for(int j=0; j<2000000; j++){
            int op=rand()%100;
            int a=rand()%100000;
            int b=rand()%100000;

            if(op<70){
                fprintf(in, "0 %d %d\n", a, b);
                dsu.mergeSets(a, b);
            }
            else{
                fprintf(in, "1 %d %d\n", a, b);
                fprintf(out, "%d\n", dsu.query(a, b));
            }
        }
    }
}

int vv[100105];
void genRandomInputCA(){
    char fileName[25], output[25];
    for(int i=0; i<5; i++){
        sprintf(fileName, "ca%d.txt", i);
        sprintf(output, "caOut%d.txt", i);
        FILE* in=fopen(fileName, "w");
        FILE* out=fopen(output, "w");
        for(int i=0; i<100000; i++){
            vv[i]=rand()%100000;
            fprintf(in, "%d ", vv[i]);
        }
        fprintf(in, "\n");
        ChangingArrays ca=ChangingArrays(vv, 100000);
        for(int j=0; j<2000000; j++){
            int op=rand()%100;
            int ind=rand()%100000;
            int a=ca.query(ind), b;
            int mode=rand()%100;
            if(mode<90){
                ind=rand()%100000;
                b=ca.query(ind);
            }
            else b=rand()%100000;
            if(op<70){
                ca.update(a, b);
                fprintf(in, "0 %d %d\n", a, b);
            }
            else{
                ind=rand()%100000;
                fprintf(in, "1 %d\n", ind);
                fprintf(out, "%d\n", ca.query(ind));
            }
        }
    }
}

void test1(){
    printf("Testing your DSU implementation\n");
    int lim=5;
    for(int i=0; i<15; i++){
        if(i%5==0) lim+=10;
        if(randomDSUCheck(lim)==false){
            return;
        }
    }
    for(int i=0; i<5; i++){
        if(randomDSUCheck(1000)==false){
            return;
        }
    }
    char fileName[25], output[25];
    for(int i=0; i<5; i++){
        clock_t st_time=clock();
        sprintf(fileName, "dsu%d.txt", i);
        sprintf(output, "out%d.txt", i);
        FILE* in=fopen(fileName, "r");
        FILE* out=fopen(output, "r");
        DSU dsu=DSU(100000);
        int op, a, b;
        while(fscanf(in, "%d", &op)!=EOF){
            if(op==0){
                fscanf(in, "%d %d", &a, &b);
                dsu.mergeSets(a, b);
            }
            else{
                int ans;
                fscanf(in, "%d %d", &a, &b);
                fscanf(out, "%d", &ans);
                if(dsu.query(a, b)!=ans){
                    cout<<"Your solution gave the incorrect answer to a query for the input in file dsu"<<i<<".txt\n";
                    print_marks(5, 10, 1);
                    return;
                }
            }

        }
        clock_t ed_time=clock();
        if(exceedsTimeLimit(st_time, ed_time, 10, 1)){
            return;
        }
    }
    print_marks(10, 10, 1);
}


int bb[100105];
char fileName[25], output[25];

void test2(){
    for(int i=0; i<5; i++){
        clock_t st_time=clock();
        sprintf(fileName, "ca%d.txt", i);
        sprintf(output, "caOut%d.txt", i);
        //cerr<<fileName<<" "<<output<<endl;
        FILE* in=fopen(fileName, "r");
        FILE* out=fopen(output, "r");
        for(int j=0; j<100000; j++){
            int v=fscanf(in, "%d", &bb[j]);
            assert(v!=EOF);
        }
        ChangingArrays ca=ChangingArrays(bb, 100000);
        //cout<<"Constructed\n";
        //fflush(stdout);
        int op, a, b, ind;
        while(fscanf(in, "%d", &op)!=EOF){
            if(op==0){
                fscanf(in, "%d %d", &a, &b);
                ca.update(a, b);
            }
            else{
                int ans;
                fscanf(in, "%d", &ind);
                fscanf(out, "%d", &ans);
                if(ca.query(ind)!=ans){
                    cout<<"Your solution gave the incorrect answer to a query for an input in the file ca"<<i<<".txt\n";
                    print_marks(5, 10, 2);
                    return;
                }
            }
        }
        clock_t ed_time=clock();
        if(exceedsTimeLimit(st_time, ed_time, 10, 2)){
            return;
        }
        fclose(in);
        fclose(out);

    }
    print_marks(10, 10, 2);
}


void evaluate(){
    srand(time(NULL));
    test1();
    printf("Testing your solution to the changing arrays problem\n");
    if(randomChangingArrayCheck(10)){
        if(randomChangingArrayCheck(15)){
            if(randomChangingArrayCheck(20)){
                test2();
            }
        }
    }
    printf("You obtained %d out of %d\n", obtained_score, total_score);
}
