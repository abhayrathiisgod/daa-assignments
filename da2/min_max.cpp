#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void findMinAndMax(vector<int> const &nums, int low, int high, int &min, int &max)
{
    // if the array contains only one element

    if (low == high)                  
    {
        if (max < nums[low]) {        
            max = nums[low];
        }
 
        if (min > nums[high]) {     
            min = nums[high];
        }
 
        return;
    }
 
    // if the array contains only two elements
 
    if (high - low == 1)            
    {
        if (nums[low] < nums[high])       
        {
            if (min > nums[low]) 
            {      
                min = nums[low];
            }
 
            if (max < nums[high]) 
            {      // comparison 3
                max = nums[high];
            }
        }
        else 
        {
            if (min > nums[high]) 
            {      
                min = nums[high];
            }

            if (max < nums[low]) 
            {       
                max = nums[low];
            }
        }
        return;
    }

    int mid = (low + high) / 2;
    findMinAndMax(nums, low, mid, min, max);

    // recur for the right subarray
    findMinAndMax(nums, mid + 1, high, min, max);
}

int main()
{
    vector<int> v;
	int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    int max = INT_MIN, min = INT_MAX;

    findMinAndMax(v, 0, n - 1, min, max);

    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max << endl;

    return 0;
}