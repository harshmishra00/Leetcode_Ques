class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(nums.size()==1 && k==0) return {nums[0]};
        if(k>nums.size()){
            if(k+k+1>nums.size()){
            vector<int> vec;
            for(int i=0;i<nums.size();i++){
                vec.push_back(-1);
            }
            return vec;
        }  
        }
        if(k+k+1>nums.size()){
            vector<int> vec;
            for(int i=0;i<nums.size();i++){
                vec.push_back(-1);
            }
            return vec;
        }  

        vector<int> vec;
        for(int i=0;i<k;i++){
            vec.push_back(-1);
        }

        int left=0;
        int right=k+k+1;
        long long sum=0;
        for(int i=0;i<k+k+1;i++){
            sum+=nums[i];
        }
        vec.push_back(sum/(k+k+1));

        while(right<nums.size()){
            sum+=nums[right];
            sum-=nums[left];
            vec.push_back(sum/(k+k+1));
            left++;
            right++;
        }

        for(int i=0;i<k;i++){
            vec.push_back(-1);
        }

        return vec;
    }
};