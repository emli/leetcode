class Solution {
public:
    int t = 0;
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
    
        while(true){
            int pos = partition(nums,left,right);
            t++;
            unsigned long x = nums.size() - k;
            if (pos < x){
                left = pos + 1;
            }else if (pos > x){
                right = pos - 1;
            }else {
                cout <<"Количество операций = "<< t << endl;
                return nums[pos];
            }
        }
        
        return -1;
    }
     
    int partition(vector<int>& nums, int left, int right) {
        int pivot = left;
    
        while(left <= right){
            if (nums[left] > nums[pivot] && nums[right] < nums[pivot]){
                swap(nums[left++],nums[right--]);
            }
            if (nums[left] <= nums[pivot]){
                left++;
            }
            if (nums[right] >= nums[pivot]){
                right--;
            }
        }
        swap(nums[left - 1], nums[pivot]);
        return left - 1;
    }
};