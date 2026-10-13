class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {        vector<int>difference;
        int full_bag=0;
        for(int i=0;i<capacity.size();i++)
        {
            
                int diff=0;
                diff=capacity[i]-rocks[i];
                if(diff==0)
                full_bag++;
                else
                difference.push_back(diff);
                
            
        }

        sort(difference.begin(),difference.end());
        for(int i=0;i<difference.size();i++){
            if(additionalRocks>=difference[i])
            {
                additionalRocks-=difference[i];
                full_bag++;
            }
            else{
                break;
            }
        }
        return full_bag;
        
    }
};