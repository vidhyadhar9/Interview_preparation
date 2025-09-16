/*question


here we will be given some rod of length n ,
we can cut the rod at any postions (integer)

and we need to maximize the product of the lengths of the pieces obtained by cutting the rod.

//approach -->
we will try to iterate from 1 to size n-1 ,we will try to explore the remaining sub rod 


7 --> 1 *(6)-->4*2 or 3*3 -->
7 ->2 --2*(5) or 2*(2*3)or 2*(1*4)
7 ->3 --3*(4) or 3*(1*3)or 3*(2*2)
o(2^n)-->approx

we can reduce dp -->o(n^2)
space o(n)
*/


// A Naive Recursive method to find maximum product
#include <iostream>
using namespace std;

// Utility function to get the maximum of two and three integers
int max(int a, int b) { return (a > b)? a : b;}
int max(int a, int b, int c) { return max(a, max(b, c));}

// The main function that returns maximum product obtainable
// from a rope of length n
int maxProd(int n)
{
    // Base cases
    if (n == 0 || n == 1) return 0;

    // Make a cut at different places and take the maximum of all
    int max_val = 0;
    for (int i = 1; i < n; i++)
      max_val = max(max_val, i*(n-i), maxProd(n-i)*i);

    // Return the maximum of all values
    return max_val;
}

/* Driver program to test above functions */
int main()
{
    cout << "Maximum Product is " << maxProd(10);
    return 0;
}




//opormise above one with dp as only oe variable is chnaging
//states -->o(n)