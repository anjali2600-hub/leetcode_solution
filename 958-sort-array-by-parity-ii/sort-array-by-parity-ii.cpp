class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size()-1;
        int i=0;
        int j=1;
        while(i<n)
        {
            if(nums[i]%2==0)
            {
                i=i+2;
            }
            else if(nums[j]%2!=0)
            {
                j=j+2;
            }
            else{
                int temp;
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
        return nums;
    }
};