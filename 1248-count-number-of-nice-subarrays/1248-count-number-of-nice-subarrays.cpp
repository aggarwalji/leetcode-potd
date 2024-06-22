class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int oddCount=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1)
                oddCount++;
            if(oddCount ==k)
                count++;
            if(mp.find(oddCount -k)!=mp.end())
                count+=mp[oddCount-k];
            if(mp.find(oddCount)!=mp.end())
                mp[oddCount]++;
            else
                mp[oddCount]=1;
        }
        return count;
    }
};