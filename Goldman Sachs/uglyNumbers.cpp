// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n)
    {
        vector<ull> ugly(n + 1);
        int i2(0), i3(0), i5(0);
        ugly[0] = 1;
        for (int i = 1; i <= n; i++)
        {

            ugly[i] = min({2 * ugly[i2], 3 * ugly[i3], 5 * ugly[i5]});
            if (ugly[i] == 2 * ugly[i2])
                i2++;
            if (ugly[i] == 3 * ugly[i3])
                i3++;
            if (ugly[i] == 5 * ugly[i5])
                i5++;
        }
        return ugly[n - 1];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends