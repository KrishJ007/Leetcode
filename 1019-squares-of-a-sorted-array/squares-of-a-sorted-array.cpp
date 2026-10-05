// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         vector<int> a;
//         vector<int> b;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             if (nums[i] >= 0) {
//                 a.push_back(nums[i]); // positive sorted vector
//             } else {
//                 b.push_back(nums[i]); //-ve sorted vector
//             }
//             if (a.size() == 0) {
//                 for (int i = 0; i < n; i++) {
//                     b[i] = b[i] * b[i];
//                     reverse(b.begin(), b.end());
//                     return b;
//                 }
//             }
//             if (b.size() == 0) {
//                 for (int i = 0; i < n; i++) {
//                     a[i] = a[i] * a[i];
//                     return a;
//                 }
//             }
//         }
//         int m = a.size();
//         int k = b.size();
//         int i = 0;
//         int j = 0;
//         int id = 0;
//         vector<int> res(m + k);
//         while (i < m and j < k) {
//             if(a[i]<=b[j]){
//                 res[id]=a[i];
//                 i++;
//                 id++;
//             }
//             else{
//                 res[id]=b[j];
//                 j++;
//                 id++;
//             }
//             while(j<k){
//                 res[id]=b[j];
//                 j++;
//                 id++;
//             }
//             while(i<m){
//                 res[id]=a[i];
//                 i++;
//                 id++;
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> a;
        vector<int> b;

        int n = nums.size();

        // Separate negative and positive numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0)
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        }

        // Square positive numbers
        for (int i = 0; i < a.size(); i++) {
            a[i] = a[i] * a[i];
        }

        // Square negative numbers
        for (int i = 0; i < b.size(); i++) {
            b[i] = b[i] * b[i];
        }

        // Reverse because squared negative numbers are descending
        reverse(b.begin(), b.end());

        int m = a.size();
        int k = b.size();

        int i = 0;
        int j = 0;
        int id = 0;

        vector<int> res(m + k);

        // Merge
        while (i < m && j < k) {
            if (a[i] <= b[j]) {
                res[id] = a[i];
                i++;
            }
            else {
                res[id] = b[j];
                j++;
            }
            id++;
        }

        // Remaining b
        while (j < k) {
            res[id] = b[j];
            j++;
            id++;
        }

        // Remaining a
        while (i < m) {
            res[id] = a[i];
            i++;
            id++;
        }

        return res;
    }
};