class SparseVector {
public:
    unordered_map<int,int> map;
    
    unordered_map<int,int> convertToMap(vector<int> &nums){
        unordered_map<int,int> map;
        
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0)
                map[i] = nums[i];
        }
        return map;
    }
    
    SparseVector(vector<int> &nums) {
        this -> map = convertToMap(nums);
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {       
       int ans = 0; 
       
       for(auto &[key,value] : vec.map){
            cout << "key = " << key << endl;
           cout << "value = " << value << endl;
           cout << "map[key] = " << map[key] << endl;
            ans += map[key] * value;    
       }
       return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);