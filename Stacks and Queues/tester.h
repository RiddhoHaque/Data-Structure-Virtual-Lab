#include "functions.h"
#include <bits/stdc++.h>
#define XX first
#define YY second
using namespace std;
char sample[5][25]={"7+(7/7)+(7+7)*2-4", "4/2+2+2+(4/(8-6))", "1*(3-2)-3*2", "2*7+4/2-(2*2+3)", "(6+2)*(6+7-1)+2*9"};
char sample_postfix[5][25]={"777/+77+2*+4-","42/2+2+486-/+","132-*32*-","27*42/+22*3+-","62+67+1-*29*+"};
int sample_evaluation[5]={32,8,-5,9,114};
char operators[]={'-', '+', '*'};
string digits[]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

string concat(pair <string, int> p1, int ind, pair <string, int> p2){
    return "("+p1.XX+")"+operators[ind]+"("+p2.XX+")";
}

pair <string, int> generate_infix(int lim){
    if(lim<=10){
        int ind1=rand()%10;
        int ind2=rand()%10;
        int ind3=rand()%10;
        int ind4=rand()%2;
        //int ind4=1;
        int val=0;
        bool toSwap=false;
        if(ind4==0){
            val=(digits[ind1][0]-'0')-(digits[ind2][0]-'0')*(digits[ind3][0]-'0');
            if(val<0){
                toSwap=true;
                val*=-1;
            }
        }
        else{
            val=(digits[ind1][0]-'0')+(digits[ind2][0]-'0')*(digits[ind3][0]-'0');
        }
        if(toSwap) return {digits[ind2]+operators[2]+digits[ind3]+operators[ind4]+digits[ind1], val};
        return {digits[ind1]+operators[ind4]+digits[ind2]+operators[2]+digits[ind3], val};
    }
    int lim1=(lim-5)/2;
    int lim2=lim-lim1;
    pair <string, int> p1=generate_infix(lim1);
    pair <string, int> p2=generate_infix(lim2);
    int ind;
    if(p1.YY<100 && p2.YY<100)ind=rand()%3;
    else ind=rand()%2;
    if(ind==0){
        if(p1.YY>p2.YY) return {concat(p1, ind, p2), p1.YY-p2.YY};
        return {concat(p2, ind, p1), p2.YY-p1.YY};
    }
    if(ind==1){
        return {concat(p1, ind, p2), p1.YY+p2.YY};
    }
    return {concat(p1, ind, p2), p1.YY*p2.YY};
}


char infix[100105];
char postfix[100105];
void string_to_char_array(string str){
    int len=0;
    for(int i=0; i<str.size(); i++){
        infix[i]=str[i];
        len++;
    }
    infix[len]=0;
}

void print_marks(int m, int full_marks, int ques_no){
    printf("You get %d out of %d in Test %d\n", m, full_marks, ques_no);
}

int test1(){
    printf("Evaluating your stack implementation\n");
    printf("The push, pop, top and size functions are all being checked at once\n");
    stack <char> stk;
    Stack st;
    int cnt=50000, toss;
    char v;
    bool problem=false;
    bool problem_before_popping=false;
    bool isPopped=false;
    bool problem_with_size=false;
    clock_t st_time=clock();
    while(cnt>0){
        if(stk.empty()){
            v=rand()%100;
            stk.push(v);
            st.push(v);
        }
        else{
            toss=rand()%100;
            if(cnt>49500 || toss<75){
                stk.push(v);
                st.push(v);
            }
            else{
                isPopped=true;
                stk.pop();
                st.pop();
            }
        }
        if(!stk.empty()){
            if(st.top()!=stk.top()){
                problem=true;
                if(isPopped==false){
                    problem_before_popping=false;
                }
            }
        }
        if(stk.size()!=st.size()){
            problem_with_size=true;
        }
        cnt--;
    }
    clock_t ed_time=clock();
    if(!problem && !problem_with_size){
        if(((ed_time-st_time)*1.0)/(CLOCKS_PER_SEC*1.0)>3.0){
            printf("Your implementation is correct but inefficient\n");
            print_marks(17, 20, 1);
            return 17;
        }
        print_marks(20, 20, 1);
        return 20;
    }
    else if(!problem){
        printf("There seems to be a problem with your size function.\n");
        print_marks(15, 20, 1);
        return 15;
    }
    else if(!problem_before_popping){
        printf("There seems to be a problem with your stack implementation\n");
        printf("Please check your pop function\n");
        print_marks(15, 20, 1);
        return 15;
    }
    else{
        printf("Your stack implementation is incorrect, please try again\n");
        print_marks(0, 20, 1);
        return 0;
    }
}

int test2(){
    printf("Evaluating your queue implementation\n");
    printf("The push, pop, front and size functions are all being checked at once\n");
    queue <int> stk;
    Queue st;
    int cnt=50000, toss;
    int v;
    bool problem=false;
    bool problem_before_popping=false;
    bool isPopped=false;
    bool problem_with_size=false;
    clock_t st_time=clock();
    while(cnt>0){
        if(stk.empty()){
            v=rand()%100;
            stk.push(v);
            st.push(v);
        }
        else{
            toss=rand()%100;
            if(cnt>49500 || toss<75){
                stk.push(v);
                st.push(v);
            }
            else{
                isPopped=true;
                stk.pop();
                st.pop();
            }
        }
        if(!stk.empty()){
            if(st.front()!=stk.front()){
                problem=true;
                if(isPopped==false){
                    problem_before_popping=false;
                }
            }
        }
        if(stk.size()!=st.size()){
            problem_with_size=true;
        }
        cnt--;
    }
    clock_t ed_time=clock();
    if(!problem && !problem_with_size){
        if(((ed_time-st_time)*1.0)/(CLOCKS_PER_SEC*1.0)>3.0){
            printf("Your implementation is correct but inefficient\n");
            print_marks(17, 20, 2);
            return 17;
        }
        print_marks(20, 20, 2);
        return 20;
    }
    else if(!problem){
        printf("There seems to be a problem with your size function.\n");
        print_marks(15, 20, 2);
        return 15;
    }
    else if(!problem_before_popping){
        printf("There seems to be a problem with your queue implementation\n");
        printf("Please check your pop function\n");
        print_marks(15, 20, 2);
        return 15;
    }
    else{
        printf("Your queue implementation is incorrect, please try again\n");
        print_marks(0, 20, 2);
        return 0;
    }
}

char sample_paranthesis[3][15]={"((()()))", "())()()(())", "(()"};
char paranthesis[100105];
int test3(){
    printf("Checking your isBalanced function\n");
    if(isBalanced(sample_paranthesis[0], strlen(sample_paranthesis[0]))==0){
        printf("Your function identifies %s as imbalanced\n", sample_paranthesis[0]);
        print_marks(0, 10, 3);
        return 0;
    }
    if(isBalanced(sample_paranthesis[1], strlen(sample_paranthesis[1]))==1){
        printf("Your function identifies %s as balanced\n", sample_paranthesis[1]);
        print_marks(0, 10, 3);
        return 0;
    }
    if(isBalanced(sample_paranthesis[2], strlen(sample_paranthesis[2]))==1){
        printf("Your function identifies %s as balanced\n", sample_paranthesis[2]);
        print_marks(0, 10, 3);
        return 0;
    }
    clock_t st_time=clock();
    int lim=100000, sum=0;
    for(int i=0; i<lim; i++){
        if((lim-i)==sum){
            paranthesis[i]=')';
            sum--;
        }
        else if(sum>0){
            int toss=rand()%10;
            if(toss>6){
                paranthesis[i]=')';
                sum--;
            }
            else{
                paranthesis[i]='(';
                sum++;
            }
        }
        else{
            paranthesis[i]='(';
            sum++;
        }
    }
    paranthesis[lim]=0;
    if(isBalanced(paranthesis, lim)==0){
        printf("Your isBalanced checker identifies balanced sequences as imbalanced\n");
        print_marks(0, 10, 3);
        return 0;
    }
    lim=100000;
    sum=0;
    for(int i=0; i<lim; i++){
        if((lim-i)==sum){
            paranthesis[i]=')';
            sum--;
        }
        else if(sum>0){
            int toss=rand()%10;
            if(toss>6){
                paranthesis[i]=')';
                sum--;
            }
            else{
                paranthesis[i]='(';
                sum++;
            }
        }
        else if(sum==0){
            paranthesis[i]=')';
            sum--;
        }
        else{
            paranthesis[i]='(';
            sum++;
        }
    }
    paranthesis[lim]=0;
    if(isBalanced(paranthesis, lim)==1){
        printf("Your isBalanced checker does not correctly check if a closing bracket has a matching opening bracket\n");
        print_marks(0, 10, 3);
        return 0;
    }
    for(int i=0; i<lim; i++){
        if(i==lim-1){
            paranthesis[i]='(';
            sum++;
        }
        if(sum>0){
            int toss=rand()%10;
            if(toss>6){
                paranthesis[i]=')';
                sum--;
            }
            else{
                paranthesis[i]='(';
                sum++;
            }
        }
        else{
            paranthesis[i]='(';
            sum++;
        }
    }
    paranthesis[lim]=0;
    if(isBalanced(paranthesis, lim)==1){
        printf("Your isBalanced checker does not correctly check if an opening bracket has a matching closing bracket\n");
        print_marks(0, 10, 3);
        return 0;
    }
    clock_t ed_time=clock();
    if(((ed_time-st_time)*1.0)/(CLOCKS_PER_SEC*1.0)>3.0){
        printf("Your isBalanced checker is correct but inefficient\n");
        print_marks(7, 10, 3);
        return 7;
    }
    printf("Your isBalanced checker is correct and efficient\n");
    print_marks(10, 10, 3);
    return 10;
}


bool exceedsTimeLimit(clock_t st_time, clock_t ed_time){
    return ((ed_time-st_time)*1.0)/(CLOCKS_PER_SEC*1.0)>3.0;
}
#define BASE1 20
#define BASE2 25
#define MOD1 1000000007
#define MOD2 500000003

long long int encoding(char ch){
    if(ch=='+') return 11;
    if(ch=='-') return 12;
    if(ch=='*') return 13;
    if(ch=='/') return 14;
    return ch-'0'+1;
}

pair <long long, long long> genHash(){
    long long val1=0, val2=0;
    for(int i=0; postfix[i]; i++){
        val1*=BASE1;
        val1%=MOD1;
        val1+=encoding(postfix[i]);
        val2*=BASE2;
        val2%=MOD2;
        val2+=encoding(postfix[i]);
    }
    return {val1, val2};
}

int test4(){
    printf("Checking your infix to postfix conversion\n");
    for(int i=0; i<5; i++){
        getPostfix(sample[i], strlen(sample[i]), postfix);
        if(strcmp(postfix, sample_postfix[i])!=0){
            printf("For the infix %s, you are generating %s\n", infix, postfix);
            printf("The correct postfix is %s\n", sample_postfix[i]);
            print_marks(0, 10, 4);
            return 0;
        }
    }
    FILE* fp_in=fopen("big_infix.txt", "r");
    FILE* fp_post=fopen("big_postfix.txt", "r");
    fscanf(fp_in, "%s", infix);
    long long hash_a, hash_b;
    fscanf(fp_post, "%lld %lld", &hash_a, &hash_b);
    clock_t st_time=clock();
    getPostfix(infix, strlen(infix), postfix);
    clock_t ed_time=clock();
    if(hash_a!=genHash().XX || hash_b!=genHash().YY){
        printf("Your postfix generation is incorrect\n");
        print_marks(0, 10, 4);
        return 0;
    }
    if(exceedsTimeLimit(st_time, ed_time)){
        printf("Your postfix generation is too slow\n");
        print_marks(7, 10, 4);
        return 7;
    }
    printf("Your postfix converter is correct\n");
    print_marks(10, 10, 4);
    return 10;
}

int test5(){
    printf("Checking your postfix evaluator\n");
    printf("Note that for the postfix evaluator to correctly work, your infix to postfix converter must work perfectly\n");
    for(int i=0; i<5; i++){
        if(postfixEvaluation(sample_postfix[i], strlen(sample_postfix[i]))!=sample_evaluation[i]){
            printf("Your code evaluates %s to have value %d, when the actual value should be %d\n", sample_postfix[i], postfixEvaluation(sample_postfix[i], strlen(sample_postfix[i])), sample_evaluation[i]);
            print_marks(0, 10, 5);
            return 0;
        }
    }
    printf("\n");
    clock_t st_time=clock();
    for(int i=0; i<5; i++){
        pair <string, int> p=generate_infix(50000);
        string_to_char_array(p.XX);
        getPostfix(infix, strlen(infix), postfix);
        if(postfixEvaluation(postfix, strlen(postfix))!=p.YY){
            printf("Your postfix evaluator gives incorrect answers\n");
            print_marks(0, 10, 5);
            return 0;
        }
    }
    clock_t ed_time=clock();
    if(exceedsTimeLimit(st_time, ed_time)){
        printf("Your postfix evaluator should be more efficient\n");
        print_marks(7, 10, 5);
        return 7;
    }
    printf("Your postfix evaluator is correct\n");
    print_marks(10, 10, 5);
    return 10;
}

int testReversal(int no_of_elements){
    vector <int> elements;
    Stack s1, s2;
    for(int i=0; i<no_of_elements; i++){
        elements.push_back(rand()%100);
        s1.push(elements[i]);
    }
    s2=stackReversal(s1);
    if(s2.size()==no_of_elements){
        int c=0;
        while(s2.size()!=0){
            if(elements[c]!=s2.top()){
                return 0;
            }
            c++;
            s2.pop();
        }
        return 10;
    }
    return 0;
}

int test6(){
    printf("Testing your stack reverser\n");
    int val=testReversal(4);
    if(val==10){
        val=testReversal(5);
        if(val==10){
            clock_t st_time=clock();
            val=testReversal(100000);
            clock_t ed_time=clock();
            if(exceedsTimeLimit(st_time, ed_time)){
                printf("Your stack reverser is inefficient\n");
                print_marks(7, 10, 6);
                return 7;
            }
            if(val==10){
                printf("Your stack reverser is correct\n");
                print_marks(10, 10, 6);
                return 10;
            }
        }
    }
    print_marks(val, 10, 6);
    return val;
}

int test_median(int no_of_elements){
    assert(no_of_elements%2==1);
    int median=rand()%100+200;
    Queue q;
    for(int i=0; i<no_of_elements/2; i++){
        q.push(rand()%100);
    }
    q.push(median);
    for(int i=0; i<no_of_elements/2; i++){
        q.push(rand()%100);
    }
    clock_t st_time=clock();
    int res=getMiddleOfQueue(q);
    clock_t ed_time=clock();
    if(res!=median){
        printf("Your function for finding the middle value in a queue is incorrect\n");
        print_marks(0, 10, 7);
        return 0;
    }
    if(exceedsTimeLimit(st_time, ed_time)){
        printf("Your function for finding the middle value in a queue is inefficient\n");
        print_marks(7, 10, 7);
        return 7;
    }
    return 10;
}

int test7(){
    int val=test_median(5);
    if(val!=10) return val;
    val=test_median(99999);
    if(val!=10) return val;
    printf("Your function for finding the middle value in a queue is correct\n");
    print_marks(10, 10, 7);
    return 10;
}

int testQReversal(int no_of_elements){
    vector <int> elements;
    Queue s1, s2;
    for(int i=0; i<no_of_elements; i++){
        elements.push_back(rand()%100);
        s1.push(elements[i]);
    }
    s2=queueReversal(s1);
    if(s2.size()==no_of_elements){
        int c=no_of_elements-1;
        while(s2.size()!=0){
            if(elements[c]!=s2.front()){
                return 0;
            }
            c--;
            s2.pop();
        }
        return 10;
    }
    return 0;
}

int test8(){
    printf("Testing your queue reverser\n");
    int val=testQReversal(4);
    if(val==10){
        val=testQReversal(5);
        if(val==10){
            clock_t st_time=clock();
            val=testQReversal(100000);
            clock_t ed_time=clock();
            if(exceedsTimeLimit(st_time, ed_time)){
                printf("Your queue reverser is inefficient\n");
                print_marks(7, 10, 8);
                return 7;
            }
            if(val==10){
                printf("Your queue reverser is correct\n");
                print_marks(10, 10, 8);
                return 10;
            }
        }
    }
    print_marks(val, 10, 8);
    return val;
}


int evaluate(){
    srand(time(NULL));
    int sum=test1();
    sum+=test2();
    sum+=test3();
    sum+=test4();
    sum+=test5();
    sum+=test6();
    sum+=test7();
    sum+=test8();
    printf("You get %d out of 100 in total\n", sum);
    return sum;
}
