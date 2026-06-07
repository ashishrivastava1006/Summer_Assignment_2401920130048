class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;int maxSum=INT_MIN;
        for(int value:nums)
        {
            currsum+=value;
            maxSum=max(currsum,maxSum);

        
        if(currsum<0){
        currsum=0;
    }
    }
    return maxSum ;
}
};
