#include "functions.h"
#define TOP 1
#define LEFT 2
#define RIGHT 3
void print_marks(int m, int full_marks, int ques_no){
    printf("You get %d out of %d in Test %d\n", m, full_marks, ques_no);
}


bool exceedsTimeLimit(clock_t st_time, clock_t ed_time){
    return ((ed_time-st_time)*1.0)/(CLOCKS_PER_SEC*1.0)>3.0;
}

int getRandom(int a, int b){
    return a+rand()%(b-a+1);
}

void recursiveDelete(Node* root){
    if(root->left!=NULL) recursiveDelete(root->left);
    if(root->right!=NULL) recursiveDelete(root->right);
}

Node* createRandomBST(int nodes, int max_depth){
    Node* root=NULL;
    Node* curr=NULL;
    int curr_depth=0, v;
    stack <int> mx, mn;
    stack <Node*> par;
    mx.push(RAND_MAX);
    mn.push(-RAND_MAX);
    for(int i=0; i<nodes; i++){
        if(root==NULL){
            root=new Node(getRandom(mn.top(), mx.top()));
            //cout<<"Adding : "<<root->value<<" to root\n";
            curr=root;
            continue;
        }
        while(true){
            int go;
            if(max_depth==curr_depth){
                go=TOP;
            }
            else if(curr!=root){
                go=getRandom(1, 3);
            }
            else go=getRandom(2, 3);
            /*if(go==TOP){
                cout<<"Going top\n";
            }
            if(go==LEFT){
                cout<<"Going left\n";
            }
            if(go==RIGHT){
                cout<<"Going right\n";
            }*/
            if(go==TOP){
                curr=par.top();
                par.pop();
                mn.pop();
                mx.pop();
                curr_depth--;
            }
            else if(go==LEFT){
                par.push(curr);
                mn.push(mn.top());
                mx.push(curr->value-1);
                curr=curr->left;
                curr_depth++;
                if(mn.top()>mx.top()){
                    curr=par.top();
                    par.pop();
                    mn.pop();
                    mx.pop();
                    curr_depth--;
                    continue;
                }
            }
            else{
                par.push(curr);
                mn.push(curr->value+1);
                mx.push(mx.top());
                curr=curr->right;
                curr_depth++;
                if(mn.top()>mx.top()){
                    curr=par.top();
                    par.pop();
                    mn.pop();
                    mx.pop();
                    curr_depth--;
                    continue;
                }
            }
            if(curr==NULL){
                curr=new Node(getRandom(mn.top(), mx.top()));
                if(go==LEFT){
                    par.top()->left=curr;
                    //cout<<"Adding "<<curr->value<<" to "<<par.top()->value<<"'s left"<<endl;
                }
                else{
                    par.top()->right=curr;
                    //cout<<"Adding "<<curr->value<<" to "<<par.top()->value<<"'s right"<<endl;
                }
                break;
            }
        }
    }
    return root;
}
vector <int> v;
void dfs(Node* root){
    if(root->left!=NULL) dfs(root->left);
    v.push_back(root->value);
    if(root->right!=NULL) dfs(root->right);
}

int test1(){
    printf("Testing your inorder traversal implementation\n");
    Node* root;
    for(int i=0; i<getRandom(8, 12); i++){
        root=createRandomBST(1000, 15);
        valueSize=0;
        v.clear();
        dfs(root);
        inorderTraversal(root);
        recursiveDelete(root);
        for(int i=0; i<v.size(); i++){
            if(v[i]!=values[i]){
                printf("There seems to be a problem in your inorder traversal\n");
                print_marks(0, 10, 1);
                return 0;
            }
        }
    }
    printf("Your inorder traversal is correct\n");
    print_marks(10, 10, 1);
    return 10;
}

bool isSorted(){
    for(int i=1; i<(int)v.size(); i++){
        if(v[i-1]>=v[i]) return false;
    }
    return true;
}

bool isIn(int x){
    for(int i=0; i<v.size(); i++){
        int val=v[i];
        if(val==x) return true;
    }
    return false;
}

vector <int> original;

int test2(){
    printf("Testing your insertion to BST\n");
    Node* root;
    for(int i=0; i<getRandom(8, 12); i++){
        root=createRandomBST(1000, 15);
        v.clear();
        dfs(root);
        for(int i=0; i<v.size(); i++){
            int val=v[i];
            original.push_back(val);
        }
        for(int j=0; j<original.size()-1; j++){
            if(original[j]!=original[j+1]-1){
                if(rand()%10==0) addToBST(root, original[j]+1);
                else continue;
                v.clear();
                dfs(root);
                if(!isSorted() || !isIn(original[j]+1)){
                    printf("Your implementation of the insertion function is wrong.\n");
                    print_marks(0, 10, 2);
                    return 0;
                }
                recursiveDelete(root);
            }
        }
        recursiveDelete(root);
    }
    for(int i=0; i<getRandom(8, 12); i++){
        root=createRandomBST(1000, 15);
        v.clear();
        dfs(root);
        for(int i=0; i<v.size(); i++){
            int val=v[i];
            original.push_back(val);
        }
        for(int j=0; j<original.size()-1; j++){
            //if(original[j]!=original[j+1]-1){
            if(rand()%10==0) addToBST(root, original[j]);
            else continue;
            v.clear();
            dfs(root);
            if(!isSorted() || !isIn(original[j])){
                printf("Your implementation of the insertion function is wrong when the number is already in the tree.\n");
                print_marks(7, 10, 2);
                return 7;
            }
            //}
            recursiveDelete(root);
        }
    }
    printf("Your insertion function is correct\n");
    print_marks(10, 10, 2);
    return 10;
}

set <int> ss;

int test3(){
    printf("Testing your search function\n");
    Node* root=createRandomBST(2000, 15);
    v.clear();
    dfs(root);
    for(int i=0; i<v.size(); i++){
        int val=v[i];
        ss.insert(val);
    }
    clock_t st_time=clock();
    int status;
    for(int i=-1000000; i<=1000000; i++){
        status=searchInBST(root, i);
        if(status && ss.find(i)==ss.end()){
            printf("Your search function declares absent items as present\n");
            print_marks(0, 10, 3);
            return 0;
        }
        if(!status && ss.find(i)!=ss.end()){
            printf("Your search function declares present items as absent\n");
            print_marks(0, 10, 3);
            return 0;
        }
    }
    clock_t ed_time=clock();
    if(exceedsTimeLimit(st_time, ed_time)){
        printf("Your search function is too slow\n");
        print_marks(5, 10, 3);
        return 5;
    }
    printf("Your search function is correct\n");
    print_marks(10, 10, 3);
    return 10;
}

int test4(){
    printf("Checking your max function\n");
    Node* root=createRandomBST(1000, 15);
    v.clear();
    dfs(root);
    if(maxInTree(root)!=v[v.size()-1]){
        printf("Your max function is wrong\n");
        print_marks(0, 10, 4);
        return 0;
    }
    root=createRandomBST(1, 1);
    if(maxInTree(root)!=root->value){
        printf("Your max function does not work when there is only one node\n");
        print_marks(7, 10, 4);
        return 7;
    }
    printf("Your max function is correct\n");
    print_marks(10, 10, 4);
    return 10;
}

bool doctor_BST(Node* root, int mx, int mn, bool maxBounded, bool minBounded, bool isRoot){
    if(!isRoot && rand()%100==0){
        if(!minBounded) root->value=mx+1;
        else if(!maxBounded) root->value=mn-1;
        else if(rand()%2) root->value=mx+1;
        else root->value=mn-1;
        return true;
    }
    if(root->left!=NULL){
        bool value=doctor_BST(root->left, root->value-1, mn, true, minBounded, false);
        if(value) return true;
    }
    if(root->right!=NULL){
        bool value=doctor_BST(root->right, mx, root->value+1, maxBounded, true, false);
        if(value) return true;
    }
    return false;
}

int test5(){
    printf("Checking to see if you can detect if something is a BST\n");
    for(int i=0; i<100; i++){
        Node* root=createRandomBST(1000, getRandom(13,16));
        int bst=1;
        if(rand()%2==0){
            if(doctor_BST(root, RAND_MAX, -RAND_MAX, false, false, true)) bst=0;
        }
        if(isBST(root)!=bst){
            printf("Your isBST detection is wrong\n");
            print_marks(0, 10, 5);
            return 0;
        }
        recursiveDelete(root);
    }
    printf("Your isBST detection is correct\n");
    print_marks(10, 10, 5);
    return 10;
}

int test6(){
    printf("Checking your upper bound function\n");
    clock_t st_time, sum=0, ed_time;
    for(int i=0; i<1000; i++){
        Node* root=createRandomBST(1000, getRandom(13, 16));
        v.clear();
        dfs(root);
        for(int j=0; j<v.size()-1; j++){
            //cout<<v[j]<<" "<<upperBoundBST(root, v[j])<<" "<<v[j+1]<<endl;
            st_time=clock();
            if(upperBoundBST(root, v[j])!=v[j+1]){
                printf("Your upper bound solution is wrong\n");
                //cout<<"j="<<j<<endl;
                print_marks(0, 10, 6);
                return 0;
            }
            ed_time=clock();
            sum+=ed_time-st_time;
        }
    }
    if((sum*1.0)/CLOCKS_PER_SEC>=5){
        printf("Your upper bound finder is too slow\n");
        print_marks(7, 10, 6);
        return 7;
    }
    printf("Your upper bound finder is correct\n");
    print_marks(10, 10, 6);
    return 10;
}

void evaluate(){
    srand(time(NULL));
    int sum=test1();
    sum+=test2();
    sum+=test3();
    sum+=test4();
    sum+=test5();
    sum+=test6();
    printf("You get %d out of %d\n", sum, 60);
    return;
}
