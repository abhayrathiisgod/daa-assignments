#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x=*y;
    *y=temp;
}
int partition(vector<int> vect, int low, int high)
{   
    int pivot = vect[high];
    int i= (low-1);

    for(int j=low; j<=high; j++)
    {
        if(vect[j]<pivot)
        {
            i++;
            swap(&vect[i],&vect[j]);
        }
    }

    swap(&vect[i+1],&vect[high]);

    return i+1;

}
void quicksort(vector<int> &vect, int low, int high)
{
    if(low < high)
    {
        int pivot = partition(vect,low,high);
        quicksort(vect,low,pivot-1);
        quicksort(vect,pivot+1,high);
    }
}
void printans(vector<int> &vect)
{
    for(auto i: vect)
    {
        cout<<" "<<i<<",";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    vector<int> vect;
    for(int i=0; i<n; i++){
        cout<<"enter the "<<i+1<<" element"<<endl;
        int g;
        cin>>g;
        vect.push_back(g);
    }

    quicksort(vect,0,n-1);
    cout<<"Sorted array "<<endl;
    printans(vect);

    return 0;

}