#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(){
        next=NULL;
    }
    Node(int v){
        value=v;
        next=NULL;
    }
};
