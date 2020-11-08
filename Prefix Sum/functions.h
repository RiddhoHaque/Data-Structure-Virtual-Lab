/**
This file contains several functions that are not implemented yet.
Your task is to implement them. The comments above the functions
provide instructions on what the functions should do. Read them
carefully.
**/


/**

In the following function, n represents the number of elements in the
array ara[]. You should assume that the elements of ara[] are in the
indices 0, 1, 2, ... , n-1. The function should fill up the indices in
the prefix_sum array. For each index i from 0 to n-1, prefix_sum's
elements should be filled up as follows:

prefix_sum[i]=ara[0]+ara[1]+ara[2]+...+ara[i]

Implement the function in an efficient manner.

**/

void build_prefix_sum_array(int n, int ara[], int prefix_sum[]){

}

/**
In the following function, n represents the number of elements in the
array ara[]. You should assume that the elements of ara[] are in the
indices 0, 1, 2, ... , n-1. If you have implemented the build_prefix_sum_array
function correctly, for each index i from 0 to n-1, prefix_sum's
elements will be filled up as follows:

prefix_sum[i]=ara[0]+ara[1]+ara[2]+...+ara[i]

The function also takes as arguments two integer values, l and r. The function's
current (incorrect) implementation returns 1. You should delete the current "return 1" line,
and in it's place, provide the correct implementation of the function so that it returns the
following sum, in the fastest possible way:

ara[l]+ara[l+1]+ara[l+2]+...ara[r]

You can assume that l<=r.

**/

int get_range_sum(int n, int ara[], int prefix_sum[], int l, int r){
    return 1;
}

/**

In the following function, r and c represent the number of rows and columns in the
array ara[][]. The array is filled up using 0-based indexing, that is the elements
of the array are found in rows 0 to r-1 and in columns 0 to c-1. The function should
fill up the indices in the prefix_sum array. For each index i from 0 to r-1, and for
each index j from 0 to c-1 prefix_sum's elements should be filled up as follows:

prefix_sum[i][j]=ara[0][0]+ara[0][1]+ara[0][2]+...+ara[0][j]
                +ara[1][0]+ara[1][1]+ara[1][2]+...+ara[1][j]
                +ara[2][0]+ara[2][1]+ara[2][2]+...+ara[2][j]
                +....
                +ara[i][0]+ara[i][1]+ara[i][2]+...+ara[i][j]

Implement the function in an efficient manner.

**/

void build_prefix_sum_array_2D(int r, int c, int ara[1005][1005], int prefix_sum[1005][1005]){
}


/**

In the following function, you are given a two-dimensional
array ara[][]. The array is filled up using 0-based indexing, that is the elements
of the array are found in rows 0 to r-1 and in columns 0 to c-1. If you have implemented
the build_prefix_sum_array function correctly, for each index i from 0 to r-1, and for each
index j from 0 to c-1, prefix_sum's elements will be filled up as follows:

prefix_sum[i][j]=ara[0][0]+ara[0][1]+ara[0][2]+...+ara[0][j]
                +ara[1][0]+ara[1][1]+ara[1][2]+...+ara[1][j]
                +ara[2][0]+ara[2][1]+ara[2][2]+...+ara[2][j]
                +....
                +ara[i][0]+ara[i][1]+ara[i][2]+...+ara[i][j]

The function also takes as arguments four integer values, t, b, l and r. The function's
current (incorrect) implementation returns 1. You should delete the current "return 1" line,
and in it's place, provide the correct implementation of the function so that it returns the
following sum, in the fastest possible way:

 ara[t][l]  +ara[t][l+1]  +ara[t][l+2]+  ...+ara[t][r]
+ara[t+1][l]+ara[t+1][l+1]+ara[t+1][l+2]+...+ara[t+1][r]
+ara[t+2][l]+ara[t+2][l+1]+ara[t+2][l+2]+...+ara[t+2][r]
+.....
+ara[b][l]  +ara[b][l+1]  +ara[b][l+2]+ ... +ara[b][r]

You can assume that t<=b and l<=r.

**/

int get_range_sum_2D(int ara[1005][1005], int prefix_sum[1005][1005], int t, int b, int l, int r){
    return 1;
}

/**
In the following function, you are given an n-sized prefix_sum[] array,
whose elements represent the prefix sum of the elements of an array ara[].
You need to find out what the original array ara[] was. In other words,
given the prefix_sum[] array, fill up the elements of the original array ara[].
**/

void get_original_array(int n, int prefix_sum[], int ara[]){

}
