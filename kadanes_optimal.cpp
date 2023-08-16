// T.C - O(N), S.C - O(1)
// approach - dont carry forward the negative numbers if the sum is negative simply ignore it, to check for empty subarray where negative number is
// only the max number return 0
//ques: return the maximum sum from the subarray
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long sum=0, maxi = LONG_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>maxi)
        {
            maxi = sum;
        }
        if(sum<0)
        {
            sum=0;
        }
        
    }
    if(maxi<0)
        maxi=0;
    return maxi;
}
