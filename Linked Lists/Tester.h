#include <bits/stdc++.h>
#include "Functions.h"
using namespace std;
Node* copyLinkedList(Node* head){
    Node* newHead;
    Node* curr;
    Node* newCurr;
    Node* temp;
    if(head==NULL){
        newHead=NULL;
        return newHead;
    }
    newHead=new Node(head->value);
    curr=head->next;
    newCurr=newHead;
    while(curr!=NULL){
        temp=new Node(curr->value);
        newCurr->next=temp;
        newCurr=newCurr->next;
        curr=curr->next;
    }
    return newHead;
}

Node* addToEnd(Node* head, int v){
    if(head==NULL){
        head=new Node(v);
        return head;
    }
    Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    Node* temp=new Node(v);
    curr->next=temp;
    return head;
}

void printLinkedList(Node* head){
    Node* curr=head;
    while(curr!=NULL){
        printf("%d", curr->value);
        curr=curr->next;
    }
}

int test1(){
    Node* head=NULL;
    if(isEmpty(head)!=1){
        printf("Your solution to problem 1 is incorrect\n");
        printf("You get 0 out of 10 in it\n");
        return 0;
    }
    else{
        for(int i=0; i<5000; i++){
            head=addToEnd(head, rand());
            if(isEmpty(head)!=0){
                printf("Your solution to problem 1 is incorrect\n");
                printf("You get 5 out of 10 in it\n");
                return 5;
            }
        }
        head=NULL;
        if(isEmpty(head)!=1){
            printf("Your solution to problem 1 is incorrect\n");
            printf("You get 5 out of 10 in it\n");
            return 5;
        }
    }
    printf("Your solution to problem 1 is correct\n");
    printf("You get 10 out of 10 in it\n");
    return 10;
}

bool isThere(Node* head, int x){
    Node* curr=head;
    while(curr!=NULL){
        if(curr->value==x){
            return true;
        }
        curr=curr->next;
    }
    return false;
}

int test2(){

    int x=rand()%50+5;
    Node* head=new Node(x-rand()%50);
    Node* temp;
    Node* curr=head;
    for(int i=0; i<250; i++){
        temp=new Node(x-rand()%50-1);
        curr->next=temp;
        curr=curr->next;
    }
    temp=new Node(x);
    curr->next=temp;
    curr=curr->next;
    for(int i=0; i<250; i++){
        temp=new Node(x+rand()%50+1);
        curr->next=temp;
        curr=curr->next;
    }
    head=deleteAll(head, x);
    if(isThere(head, x)){
        printf("Your solution to problem 2 is incorrect, you get 0/10\n");
        return 0;
    }

    head=new Node(x);
    temp;
    curr=head;
    for(int i=0; i<250; i++){
        temp=new Node(x-rand()%50-1);
        curr->next=temp;
        curr=curr->next;
    }
    head=deleteAll(head, x);
    if(isThere(head, x)){
        printf("Your solution to problem 2 does not delete from the head if head->value=x\nYou get 5/10\n");
        return 5;
    }
    for(int i=0; i<500; i++){
        int value=rand()%10;
        if(value<5){
            temp=new Node(x-rand()%50-1);
        }
        else if(value>=5 && value<=8){
            temp=new Node(x+rand()%50+1);
        }
        else if(value>=9){
            temp=new Node(x);
        }
        curr->next=temp;
        curr=curr->next;
    }
    head=deleteAll(head, x);
    if(isThere(head, x)){
        printf("Your solution to problem 2 does not delete all instances of x from the linked list\nYou get 7/10\n");
        return 7;
    }

    head=new Node(x-1);
    temp;
    curr=head;
    for(int i=0; i<250; i++){
        temp=new Node(x);
        curr->next=temp;
        curr=curr->next;
    }
    for(int i=0; i<250; i++){
        temp=new Node(x+1);
        curr->next=temp;
        curr=curr->next;
    }
    head=deleteAll(head, x);
    if(isThere(head, x)){
        printf("Your solution 2 does not work if there is a lot of successive values of x in the middle.\n You get 8 out of 10\n");
        return 8;
    }
    head=new Node(x);
    temp;
    curr=head;
    for(int i=0; i<250; i++){
        temp=new Node(x);
        curr->next=temp;
        curr=curr->next;
    }
    for(int i=0; i<250; i++){
        temp=new Node(x+1);
        curr->next=temp;
        curr=curr->next;
    }
    head=deleteAll(head, x);
    if(isThere(head, x)){
        printf("Your solution 2 does not work if there is a lot of successive values of x at the start.\n You get 9 out of 10\n");
        return 9;
    }
    head=new Node(x);
    temp;
    curr=head;
    for(int i=0; i<250; i++){
        temp=new Node(x);
        curr->next=temp;
        curr=curr->next;
    }
    head=deleteAll(head, x);
    if(isThere(head, x)){
        printf("Your solution 2 does not work if all values are equal to x.\n You get 9 out of 10\n");
        return 9;
    }
    printf("Your solution 2 is correct\nYou get 10/10\n");
    return 10;
}

bool is_replaced(Node* oldhead, Node* newhead, int x, int y){
    Node* oldcurr=oldhead;
    Node* newcurr=newhead;
    while(oldcurr!=NULL && newcurr!=NULL){
        if(oldcurr->value==x && newcurr->value!=y){
            return false;
        }
        oldcurr=oldcurr->next;
        newcurr=newcurr->next;
    }
    if(oldcurr==NULL && newcurr==NULL){
        return true;
    }
    return false;
}

int test3(){
    int x=rand()%50+5;
    int y=x+5;
    Node* head=new Node(x-1-rand()%60);
    Node* temp;
    Node* curr=head;
    for(int i=0; i<100; i++){
        temp=new Node(x-1-rand()%60);
        curr->next=temp;
        curr=curr->next;
    }
    temp=new Node(x);
    curr->next=temp;
    curr=curr->next;
    for(int i=0; i<100; i++){
        temp=new Node(x+1+rand()%60);
        curr->next=temp;
        curr=curr->next;
    }
    Node* newHead=replaceAll(head, x, y);
    if(!is_replaced(head, newHead, x, y)){
        printf("Your solution 3 is not correct\n");
        printf("You get 0 out of 10\n");
        return 0;
    }
    head=new Node(x);
    for(int i=0; i<500; i++){
        if(rand()%3) temp=new Node(x-1-rand()%60);
        else temp=new Node(x);
        curr->next=temp;
        curr=curr->next;
    }
    newHead=replaceAll(head, x, y);
    if(!is_replaced(head, newHead, x, y)){
        printf("Your solution 3 replaces only the first appearance of x in the linked list\n");
        printf("You get 5 out of 10\n");
        return 5;
    }
    printf("Your solution 3 is correct\n");
    printf("You get 10 out of 10\n");
    return 10;
}

int test4(){
    set <int> s;
    Node* head=new Node(rand()%500);
    s.insert(head->value);
    Node* temp;
    Node* curr=head;
    for(int i=0; i<1000; i++){
        temp=new Node(rand()%500);
        s.insert(temp->value);
        curr->next=temp;
        curr=curr->next;
    }
    if(countFrequency(head)!=(int)s.size()){
        printf("Your solution to problem 4 is incorrect\n");
        printf("You get 0 out of 10 in it\n");
        return 0;
    }
    printf("Your solution to problem 4 is correct\n");
    printf("You get 10 out of 10 in it\n");
    return 10;
}

int test5(){
    stack <int> s;
    Node* head=new Node(rand()%500);
    s.push(head->value);
    Node* temp;
    Node* curr=head;
    for(int i=0; i<1000; i++){
        temp=new Node(rand()%500);
        s.push(temp->value);
        curr->next=temp;
        curr=curr->next;
    }
    Node* newHead=reverseLinkedList(head);
    Node* newCurr=newHead;
    bool correct=true;
    while(newCurr!=NULL && !s.empty()){
        if(newCurr->value!=s.top()){
            correct=false;
            break;
        }
        s.pop();
        newCurr=newCurr->next;
    }
    if(correct && s.empty() && newCurr==NULL){
        printf("Your solution 5 is correct\n");
        printf("You get 10/10 in it\n");
        return 10;
    }
    else{
        printf("Your solution 5 is incorrect\n");
        printf("You get 0/10 in it\n");
        return 0;
    }
}


void evaluate(){
    int sum=0;
    sum+=test1();
    sum+=test2();
    sum+=test3();
    sum+=test4();
    sum+=test5();
    printf("You got %d out of 50 in total\n", sum);
}
