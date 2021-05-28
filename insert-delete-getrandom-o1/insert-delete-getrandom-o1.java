class RandomizedSet {
    private ArrayList<Integer> nums = new ArrayList<>();
    private HashMap<Integer, Integer> map = new HashMap<>();

    /** Initialize your data structure here. */
    public RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (map.containsKey(val)){
            return false;
        }

        nums.add(val);
        map.put(val,nums.size() - 1);

        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!map.containsKey(val)){
            return false;
        }

        int index = map.get(val);
        int lastItem = nums.get(nums.size() - 1);
        int lastIndex = map.get(lastItem);

        int temp = nums.get(index);
        nums.set(index, nums.get(lastIndex));
        nums.set(lastIndex,temp);

        map.remove(val);
        if (index != lastIndex)
            map.put(lastItem,index);
        nums.remove(nums.size() - 1);

        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return nums.get(Math.abs(new Random().nextInt()) % nums.size());
    }
}