class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1,-1};
        }      

        int low=0, high=nums.size()-1,mid=0;

        int first = binarysearchFirst(nums, low, high, target);
        if (first ==-1) {
            return vector<int>{-1,-1};
        }
        int last = binarysearchLast(nums, first, high, target);
        return vector<int>{first,last};
    }

    int binarysearchFirst(vector<int>& nums, int low, int high, int target ) {
        int mid = low + (high-low)/2;
        while(low<=high){
            if (nums[mid]==target) {
                if (mid==0 || nums[mid-1] < target){
                    return mid;
                } else{
                    high = mid-1;
                }
            } else if (nums[mid]>target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return -1;
    }

        int binarysearchLast(vector<int>& nums, int low, int high, int target ) {
        int mid = low + (high-low)/2;
        while(low<=high){
            if (nums[mid]==target) {
                if (mid== high || nums[mid+1] > target){
                    return mid;
                } else{
                    low = mid+1;
                }
            } else if (nums[mid]>target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return mid;
    }
    
};

