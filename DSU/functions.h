#include <bits/stdc++.h>
using namespace std;


/**
    In the following, you are
    to implement a disjoint set
    union data structure. You can
    assume the number of elements
    in the disjoint sets to be
    within 10^5, and that if there
    are n elements, all of them will be
    numbered from 0 to n-1.
**/
struct DSU{
    /**
        You can declare as many variables
        as you need, you will be merging
        non-intersecting sets of integer
        values.
    */

    /**
        Use the following constructor to
        complete any initialization that you
        may need. You can initially consider
        all elements to be in distinct sets.
    */

    DSU(int n){
    }
    /**
        Use the following function to merge the
        sets containing the elements a and b. If
        a and b already belong in the same set,
        do nothing.
    */

    int findRoot(int n){
        return 1;
    }

    void mergeSets(int a, int b){
    }

    /**
        The following function should return 1 if
        a and b belong to the same set, and 0 otherwise.
    */

    int query(int a, int b){
        return 0;
    }
};

/**
    The following function asks you to solve a problem where
    you'll need to perform the following operations efficiently:

    1. Query(int i): Return the value in the i-th index of the
    array.
    2. Update(int x, int y): Change all values in the array with
    value x to y.

    For example, if the array given initially is:

    1 4 2 5 7 1 4,

    and if the following operations are performed on it:

    Query(0): return 1
    Update(1, 2): The array becomes, 2 4 2 5 7 2 4
    Query(5): return 2
    Update(2, 3): The array becomes, 3 4 3 5 7 3 4
    Query(5): return 3

    Your code will have to be efficient enough to handle 10^5
    operations per second on an array of size 10^5 (i.e. if
    there are n elements in the array and q operations, an
    algorithm of time complexity O(n*q) will not work.) You can
    assume that the elements in the array will be within 0 to
    10^5.
*/

struct ChangingArrays{
    int ara[100105];
    int n;
    /**
        You can add as many variables/structures here as you need.
    */


    /**
        In the following constructor, you can add some lines to
        initialize your variables, but do not change the lines
        already written here.
    */
    ChangingArrays(int a[], int lim){
        n=lim;
        for(int i=0; i<lim; i++){
            ara[i]=a[i];
        }
    }

    /**
        The following function should perform the update operation
        as described above.
    */

    int findRoot(int a){
        return 1;
    }

    void update(int x, int y){

    }
    /**
        The following function should perform the query operation
        as described above.
    */

    int query(int i){
        return 1;
    }
};
