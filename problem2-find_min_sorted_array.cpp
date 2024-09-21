class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int low = 0, high = nums.size() -1;
        int mid = 0;

        while(low<=high) {
            //first check we are in sorted range
            if (nums[low]<=nums[high]){
                return nums[low];
            }
            mid = low + (high - low)/2;
            //check the base if mid is minimum
            if ((mid == 0 || nums[mid]<nums[mid-1]) && (mid == high || nums[mid] < nums[mid+1])) {
                return nums[mid];
            } else if (nums[low] <=nums[mid]){ //left sorted array
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }

};
