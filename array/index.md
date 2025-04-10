## Array

### SubArray Indexing (Priority)
In array problems, such as binary search, sorting, partition, you will frequently need to process a sub-array. The practice to represent a subarray can be called subarray indexing. Without making a duplicate, there are more than one method to represent a subarray, here are three most common methods:
1. **Inclusive End Ranging:** Start Index + end Index (Inclusive), [Start, End].
2. **Exclusive End Ranging:** Start Index + end Index (Exclusive), [Start, End).
3. **Lengthing:** Start index + length, [Start, Start + Length)

| Senario | Inclusive | Exclusive | Length |
|--------|-------|-------| ------- |
| range  | for i in range(start, end + 1):|for i in range(start, end):|for i in range(start, start + length):|
| middle | (start + end) // 2 | (start + end) // 2  | start + length // 2 
| length    | end - start + 1 | end - start | length |
| last | end | end - 1 | start + length - 1|
| first half | (start, middle - 1) | (start, middle) | (start, start + length / 2) |
| second half | (middle, end) | (middle, end) | (middle, length - length / 2) |
| full array | (0, size - 1) | (0, size) | (0, size) |

I strongly recommend you follow a single pattern for array indexing from the beginning, and culture it as a habit, especially, don't mix approach #1 and #2 in your coding interview. From my experience, majority of candidates choose **Inclusive End Ranging**, because this is the most intuitive method. I frequently see them run into trouble. My strong recommendation in the guide is officially: **Exclusive End Ranging**, and **Lengthing** can be used as a supplement for some problems, as mathemetical conversion to **Exclusive End Ranging** is simple, here's why.
- Exclusive end ranging supports easier arithmetic calculation. No + 1 / -1 for most common operations.
- Many standard libraries are also inheritently using exclusive end ranging. Such as python's `range(start, end)`, slicing `arr[start:end]`, Cpp's standard library `std::find(data.begin(), data.begin() + n /*exclusive*/, target);`. Converting Inclusive end ranging to use these libraries is painful and error-prone.
- Avoids boundary mistakes. When using inclusive end ranging carelessly, you can easily encounter Out-of-Bound Error, (Segmentation fault in Cpp) ... While they are avoided in exclusive end ranging

Subarray indexing can be best practiced with **example**, if you are not sure your subarray indexing practice during an interview, Start a minimal example with 3 element, indicating start, end and size, use the example to verify your calculation. 

Now, let's check a practical problem.

### Example

**Convert Sorted Array to Binary Search Tree**

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

The question can be solved with straight-forward divide and conquor, but since it splits the array into three parts (left, root, and middle), it can give an uncomfortable indexing practice. Here I started out with **Lengthing**, not the cleanest, just to give you idea how to process indexes when they might be not obvious:


```
// Lengthing
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

**Exclusive end ranging** also effectively solves the problem, I am convinced that this produces the cleanist functional coding output.


```
// Exclusive End Ranging
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

you can practice the same example with **Inclusive End Ranging** if you still prefer it.