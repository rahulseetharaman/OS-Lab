#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	//fcfs when all arrival times are same
	int n;
	cout<<"Enter the no. of processes"<<endl;
	cin>>n;
	vector<int>bts(n);
	for(int i=0;i<n;i++)
	{
		int bt;
		cout<<"Enter burst time for process "<<i<<endl;
		cin>>bt;
		bts[i]=bt;
	}
	vector<int>wt(n);
	vector<int>ct(n);
	int i;
	for(int i=0;i<n;i++)
	{
		if(i==0)
			ct[i]=bts[i];
		else
			ct[i]=ct[i-1]+bts[i];
	}
	// completion time and turnaround tim same as all processes are assumed to be arriving at time 0 sec.
	int tot=0;
	for(int i=0;i<n;i++)
	{
		wt[i]=ct[i]-bts[i];
		tot+=wt[i];
	}
	cout<<"Average waiting time is "<<tot/n;
	return 0;
}