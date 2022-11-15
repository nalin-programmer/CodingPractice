//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        int i = 0, j = 0 , ans = 1;
        map<int,int> mp;
        mp[arr[0]]++;
        while(j<N)
        {
            int mx = mp.rbegin()->first;
            int mn = mp.begin()->first;
            if(mx-mn <=1)
            {
                ans = max(ans,j-i+1);
                j++;
                mp[arr[j]]++;
            }
            else
            {
                mp[arr[i]]--;
                if(!mp[arr[i]]) mp.erase(arr[i]);
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends