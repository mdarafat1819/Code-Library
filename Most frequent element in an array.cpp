 int majorityElement(vector<int>& nums) {
        int size = nums.size();

        sort(nums.begin(), nums.end());
        int mx = 1, cnt = 1;
        int major = nums[0];
        
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
            }else {
                cnt = 1;
            }
            if(mx < cnt) {
                mx = cnt;
                major = nums[i - 1];
            }

        }
    
        return major;
    }
