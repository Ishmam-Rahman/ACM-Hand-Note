#include <iostream>
using namespace std;

int kadaneNeg(vector<int> arr)
{
    int n=arr.size();
	int max_so_far = arr[0];
	int max_ending_here = arr[0];

	for (int i = 1; i < n; i++)
	{
		max_ending_here = max_ending_here + arr[i];
		max_ending_here = max(max_ending_here, arr[i]);
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;
}

int main()
{
	int n; cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++) cin>>v[i];
	cout << "The sum of contiguous subarray with the largest sum is " ;
	cout<<kadaneNeg(v)<<endl;

	return 0;
}
