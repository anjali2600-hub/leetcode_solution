
class Solution {
public:
    int lowerbound(vector<int>& mat, int m, int x) {
        int low = 0;
        int high = m - 1;
        int ans = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mat[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cnt_max = 0;
        int m = mat.size();
        int n = mat[0].size();
        int idx = 0;

        for (int i = 0; i < m; i++) {
            sort(mat[i].begin(), mat[i].end());

            int cnt_ones = n - lowerbound(mat[i], n, 1);

            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                idx = i;
            }
        }

        return {idx, cnt_max};
    }
};
