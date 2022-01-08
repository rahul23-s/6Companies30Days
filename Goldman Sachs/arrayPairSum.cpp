// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool canPair(vector<int> &arr, int k)
    {
        unordered_map<int, int> remFreq;

        for (int val : arr)
        {

            remFreq[(val % k + k) % k]++;
        }
        for (int val : arr)
        {
            int rem = val % k;

            if (rem == 0)
            {
                int fq = remFreq[rem];
                if (fq % 2 == 1)
                    return false;
            }
            else if (2 * rem == k)
            {
                int fq = remFreq[rem];
                if (fq % 2 == 1)
                    return false;
            }
            else
            {
                int fq = remFreq[rem];

                int ofq = remFreq[k - rem];
                if (fq != ofq)
                    return false;
            }
        }
        return true;
    }
};
// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} // } Driver Code Ends