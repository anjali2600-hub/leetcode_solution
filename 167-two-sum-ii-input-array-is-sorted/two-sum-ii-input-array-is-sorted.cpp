class Solution {
public:
int binarySearch(vector<int>& numbers,int sec,int fir)
{
   
    int low=0;
    int high=numbers.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(numbers[mid]==sec&& fir!=mid){
            return mid;

        }
        else if(numbers[mid]>sec)
        {
               high=mid-1;
            
        }
        else{
            low=mid+1;
         
            

        }
       
    }
     return -1;
}
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int i=0;i<numbers.size();i++)
        {
            int first=numbers[i];
            int second=target-first;
            int second_el=binarySearch(numbers,second,i);
            if(second_el!=-1)
            {
                return {i+1,second_el+1};
            }
        }
        return {-1,-1};
    }
};