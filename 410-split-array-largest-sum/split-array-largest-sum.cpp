class Solution {
public:


    int countarray(vector<int>& arr,int ways)
    {
        int split=1;
        int waysstudent=0;
        for(int i=0;i<arr.size();i++)
        {
            if(waysstudent+arr[i]<=ways)
            {
                waysstudent+=arr[i];
            }
            else{
                split++;
                waysstudent=arr[i];
            
            }
        }
        return split;
    }
    int splitArray(vector<int>& arr, int k) {
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int subarray=countarray(arr,mid);
            if(subarray>k)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};