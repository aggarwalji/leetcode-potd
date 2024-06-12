class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1,k=0;
        while(i<=j){
            if(nums[i]==2){
                swap(nums[i],nums[j]);
                j--;
            }
            else if(nums[i]==0){
                swap(nums[i],nums[k]);
                k++;
                i++;
            }
            else
                i++;
        }
    }
};