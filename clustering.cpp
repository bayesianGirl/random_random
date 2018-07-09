#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int ab[15]={0,0,3,3,0,40,6,5,6,7,9,40,6,5,3};
	vector<int> a;
	for (int j=0;j<15;++j)
	{
		a.push_back(ab[j]);
	}
	int num, i;
	vector<vector<int> > ints;
	vector<int> temp_int;
	while(a.size()>0)
	{
		i=0;
		num=a[i];
		for (size_t j=0;j<a.size();j++)
		{
			if (num==a[j])
			{
				temp_int.push_back(a[j]);
				a.erase(a.begin()+j);
				j=-1;
			}
		}
		ints.push_back(temp_int);
		temp_int.clear();
	}
	for (size_t i=0;i<ints.size();++i)
	{
		for (size_t j=0;j<ints[i].size();++j)
		{
			cout<<ints[i][j];
		}
		cout<<endl;
	}
}
