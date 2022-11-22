class Solution {
public:
   int minWay[10005];

int numSquares(int n) {
	minWay[0] = 0;
	for(int j=1;j<=n;j++)
	{
		minWay[j] = INT_MAX;
		for(int i=1;(i*i)<=j;i++)
		{
			minWay[j] = min(minWay[j],1+minWay[j-(i*i)]);
		}
	}
	return minWay[n];
}

};