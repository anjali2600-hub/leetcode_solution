class Solution {
public:
set<vector<int >>s;
void getallcomb(vector<int > arr,int i,int target,vector<vector<int>>&ans,vector<int >&combin){
    if(i==arr.size()||target<0){
        return;
    }
    if(target==0){
        if(s.find(combin)==s.end()){
        ans.push_back({combin});
        s.insert(combin);}
        return ;
    }
    combin.push_back(arr[i]);
    getallcomb(arr,i+1,target-arr[i],ans,combin);
    getallcomb(arr,i,target-arr[i],ans,combin);
    combin.pop_back();
    getallcomb(arr,i+1,target,ans,combin);

}
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int >combin;
        getallcomb(arr,0,target,ans,combin);

        return ans;

    }
};
