// Recursion

// https://www.geeksforgeeks.org/problems/factorial5739/1


class Solution {
  public:
    int factorial(int n) {
        if(n==0 || n==1) return 1; 
        return factorial(n-1) * n;
    }
};

// http://geeksforgeeks.org/problems/nth-fibonacci-number1335/1

int nthFibonacci(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}

int main(){
    p(10);
    return 0;
}