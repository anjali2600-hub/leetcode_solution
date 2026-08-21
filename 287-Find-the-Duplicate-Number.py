class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       vector<int>ans;
       unordered_set<int>s;
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
        int first=nums[i];
        if(s.find(first)!=s.end())
        {
            return first;

        }
        s.insert(first);
       }
         return -1; 
      
    }
};
