class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(); // meri array ki length
        int i = 0;              // first posn
        int j = n - 1;          // second posn
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i+1, j+1};
            } else if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return {0};
            }
        }
        return {0};
    }
};