class Solution {
public:
    // test
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;

        while(true){
            int pos = partition(nums,left,right);

            unsigned long x = nums.size() - k;
            if (pos < x){
                left = pos + 1;
            }else if (pos > x){
                right = pos - 1;
            }else {
                return nums[pos];
            }
        }

        return -1;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];

        int cur = left + 1;

        for(int i = left + 1; i <= right; i++){
            if (nums[i] <= pivot){
                swap(nums[i],nums[cur++]);
            }
        }

        swap(nums[cur - 1], nums[left]);

        return cur - 1;
    }
};