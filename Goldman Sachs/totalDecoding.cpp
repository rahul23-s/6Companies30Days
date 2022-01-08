// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int CountWays(string str)
    {
        if (str.length() == 0 || str[0] == '0')
            return 0;
        if (str.length() == 1)
            return 1;

        int cnt1 = 1, cnt2 = 1;
        for (int i = 1; i < str.length(); i++)
        {
            int curr = str[i] - '0';
            int prev = (str[i - 1] - '0') * 10 + curr;
            int cnt = 0;
            if (curr > 0)
                cnt = (cnt + cnt2) % 1000000007;
            if (prev >= 10 && prev <= 26)
                cnt = (cnt + cnt1) % 1000000007;
            cnt1 = cnt2; //prev to prev
            cnt2 = cnt;  // prev
        }
        return cnt2 % 1000000007;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends