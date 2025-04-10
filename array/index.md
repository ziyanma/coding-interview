## Array

### Indexing (Priority)
In array problems, there are many examples that you would need to process a sub-array. There exists more than one ways to represent:
1. Start Index + End Index (Inclusive), [Start, End]
2. Start Index + End Index (Exclusive), [Start, End)
3. Start Index + Length, [Start, Start + Length)
4. As a fallback, you can always physically create the sub array.

I strongly recommend you follow a single pattern for array indexing from the beginning, and culture it as a habit, especially, don't mix approach #1 and #2 in your coding interview. 

My recommendation in this practical guide is officially: **Exclusive End Ranging**, and Length can be used as a supplement, as it is an easy alternative to exclusive end ranging, here's why.
- Though inclusive end ranging is more intuitive, exclusive end ranging supports easier arithmetic calculation. 
- Many standard libraries are also inheritently using exclusive end ranging. Such as python's `range(start, end)`, slicing `arr[start:end]`, Cpp's standard library `std::find(data.begin(), data.begin() + n /*exclusive*/, target);`. Converting Inclusive end ranging to use these libraries are error-prone.
- Avoids boundary mistakes. When using inclusive end ranging carelessly, you can easily encounter Out-of-Bound Error, (Segmentation fault in Cpp) ... While they are avoided in exclusive end ranging


Here are some examples:

| Senario | Inclusive | Exclusive | Length |
|--------|-------|-------| ------- |
| Range  | for i in range(start, end + 1):|for i in range(start, end):|for i in range(start, start + length):|
| Middle | (start + end) // 2 | (start + end) // 2  | start + length // 2 
| Length    | end - start + 1 | end - start | length |
| Last | end | end - 1 | start + length - 1|


Indexing can be best practiced with **example**, if you are not sure your indexing practice during an interview, Start an 3 element example. Let's check a practical problem.

### Example

**Convert Sorted Array to Binary Search Tree**

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

The question can be solved with straight-forward divide and conquor, but since it splits the array into three parts (left, root, and middle), it can give an uncomfortable indexing practice. Here I started out with approach # 3, not the cleanest, just to give you idea how to process indexes when they might be not obvious:


```
// Start index + Length
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size());
}

TreeNode* sortedArrayToBST(vector<int>& nums, int start, int size) {
    if (size == 0) {
        return nullptr;
    }
    if (size == 1) {
        return new TreeNode(nums[start]);
    } else {
        // [0, 1, 2]
        // start = 0, size = 3, halfSize = 1;
        // Left half should have start == 0, size == 1,
        // Middle should have index == 1
        // Right half should have start == 2, size == 1,

        int halfSize = size / 2;
        TreeNode * l = sortedArrayToBST(nums, start, halfSize);
        TreeNode * r = sortedArrayToBST(nums, start + halfSize + 1, size - halfSize - 1);
        return new TreeNode(nums[start + halfSize], l, r);
    }
}
```

As you can see, when uncertain, providing example with targeted value, efficiently improves your problem solving and reduces your calculation.

Using exclusive end ranging also effectively solves the problem, try on your own with Inclusive End Index ranging.


```
// Exclusive End Index Ranging
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size());
}

TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (end <= start) {
        return nullptr;
    }
    if (end == start + 1) {
        return new TreeNode(nums[start]);
    } else {
        int mid = (end + start) / 2;
        TreeNode * l = sortedArrayToBST(nums, start, mid);
        TreeNode * r = sortedArrayToBST(nums, mid + 1, end);
        return new TreeNode(nums[mid], l, r);
    }
}
```