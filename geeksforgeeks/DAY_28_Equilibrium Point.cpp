Example 1:

Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 
3 
Explanation:  
equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2). 
Example 2:

Input:
n = 1
A[] = {1}
Output: 
1
Explanation:
Since there's only element hence its only the equilibrium point.

  OUTPUT:

class Solution{
    public:
    int equilibriumPoint(long long a[], int n) {
    
        if (n == 1) {
            return 1; 
        }
    
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += a[i]; 
        }
    
        long long leftSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum -= a[i]; 
    
            if (leftSum == totalSum) {
                return i + 1; 
            }
    
            leftSum += a[i]; 
        }
    
        return -1;
    }

};

