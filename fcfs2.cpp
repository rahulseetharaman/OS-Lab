#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct process
{
	int a_time;
	int b_time;
	int index;
	process(int a_time,int b_time,int index)
	{
		this->a_time=a_time;
		this->b_time=b_time;
		this->index=index;
	}
};
bool compare(process p1,process p2)
{
	return p1.a_time<=p2.a_time;
}
int main()
{
	int n;
	cout<<"Enter the no. of processes"<<endl;
	cin>>n;
	vector<process>parr;
	vector<int>ct(n);
	vector<int>tat(n);
	vector<int>wt(n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		parr.push_back(process(a,b,i));
	}
	int tot=0;
	sort(parr.begin(), parr.end(),compare);
	for(int i=0;i<n;i++)
	{
		tot+=parr[i].b_time;
		ct[parr[i].index]=tot;
	}
	for(int i=0;i<n;i++)
	{
		tat[parr[i].index]=ct[parr[i].index]-parr[i].b_time;
		wt[parr[i].index]=tat[parr[i].index]-parr[i].a_time;
	}
	double wtime=0;
	cout<<"Waiting times are as follows"<<endl;
	for(int i=0;i<n;i++){
		cout<<wt[i]<<" ";
		wtime+=wt[i];
	}
	cout<<"Average waiting time is "<<wtime/n<<endl;
	return 0;

}