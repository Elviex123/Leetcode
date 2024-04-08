class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
      int de = 1, in = 1;
      int tmpd = 1,tmpi = 1;
      for(int i = 1; i < nums.size(); i++){
        if(nums[i - 1] < nums[i]){
            tmpi++;
        }
        else{
            tmpi = 1;
        }
        in = max(tmpi,in);

        if(nums[i - 1] > nums[i]){
            tmpd++;
        }
        else{
            tmpd = 1;
        }
        de = max(tmpd,de);
      }
      return max(de,in);
    }
};