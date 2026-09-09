class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum right side mein hai
                low = mid + 1;
            }
            else if (nums[mid] < nums[high]) {
                // Minimum mid ya left side mein hai
                high = mid;
            }
            else {
                // nums[mid] == nums[high]
                // Duplicate hai, high ko safely hata sakte hain
                high--;
            }
        }

        return nums[low];
    }
};