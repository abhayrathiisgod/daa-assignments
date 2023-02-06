#include<bits/stdc++.h>
using namespace std;
void MergeSortedIntervals(vector<int>& v, int s, int m, int e) 
{
	
	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) 
    {

		if (v[i] <= v[j]) 
        {
			temp.push_back(v[i]);
			++i;
		}
		else 
        {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) 
    {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) 
    {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}
void MergeSort(vector<int>& v, int s, int e) 
{
	if (s < e) 
    {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

int main() 
{

	int n;
	vector<int> v;

	cout << "Enter Size of Vector : ";
	cin >> n;
	v = vector<int>(n);
	cout << "Enter Elements of Vector : ";
	for (int i = 0; i < n; ++i) 
    {
		cin >> v[i];
	}

	MergeSort(v, 0, n - 1);

	cout << "\nVector Obtained After Sorting: ";
	for (int i = 0; i < n; ++i) 
    {
		cout << v[i] << ' ';
	}

}