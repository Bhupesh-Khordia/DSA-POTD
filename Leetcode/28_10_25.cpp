class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int res=0;
        int totalSum=0;
        for (int num: nums) totalSum+=num;
        int leftSum=0, rightSum=0;
        for (int i=0; i<nums.size(); i++){
            leftSum+=nums[i];
            rightSum=totalSum-leftSum;
            if (nums[i]!=0) continue;
            if (leftSum==rightSum) res+=2;
            if (abs(leftSum-rightSum)==1) res+=1;
        }
        return res;
    }
};
