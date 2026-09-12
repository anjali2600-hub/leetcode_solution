class Solution {
public:
int findmax(vector<int>& piles)
{
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}

long long calculatehours(vector<int>& piles,int hourly)
{
    long long total_hrs=0;
    int n=piles.size();
    for(int i=0;i<n;i++)
    {
        total_hrs += ceil((double)piles[i]/(double)hourly);
    }
    return total_hrs;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            long long totalH=calculatehours(piles,mid);
            if(totalH<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};