class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // m=nums1.size();
        // n=nums2.size();
        int i=0;
        int j=0;
        int id=0;
        vector<int> res(m+n);
        while(i<m and j<n){
            if(nums1[i]<=nums2[j]){
                res[id]=nums1[i];
                i++;
                id++;
            }
            else{
                res[id]=nums2[j];
                j++;
                id++;
            }
        }
        while(j<n){
            res[id]=nums2[j];
            id++;
            j++;
        }
        while(i<m){
            res[id]=nums1[i];
            id++;
            i++;
        }
        nums1 = res;
    }
};