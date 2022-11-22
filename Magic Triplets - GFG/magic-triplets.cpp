//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int n = nums.size();
	    vector<int>v(nums.size(),0), v2(nums.size(),0);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j])++v[i];
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=n-1;j>i;j--){
	            if(nums[i]<nums[j])++v2[i];
	        }
	    }
	    
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans+=v[i]*v2[i];
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends