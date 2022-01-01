// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;

        cout << encode(str) << endl;
    }
    return 0;
} // } Driver Code Ends

/*You are required to complete this function */

string encode(string src)
{
    int count = 1;
    string encoded;
    encoded.append(1, src[0]);
    for (int i = 1; i < src.length(); i++)
    {
        if (src[i] == src[i - 1])
        {
            count++;
        }
        else
        {
            encoded += to_string(count);
            encoded.push_back(src[i]);
            count = 1;
        }
        }
    encoded += to_string(count);
    return encoded;
}
