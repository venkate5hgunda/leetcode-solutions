class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numsMap;
        vector<int> result;
        for(int i=0;i<nums.size();++i) {
            if(numsMap.find(nums[i]) == numsMap.end()) {
                numsMap.insert({target-nums[i],i});
            }
            else {
                result.insert(result.begin(),i);
                result.insert(result.begin(),numsMap[nums[i]]);
                return result;
            }
        }
        return result;
    }
};
