/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * Exclusive End Indexing
 */
class SolutionExclusiveEndRanging {
public:
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
};


/**
 * Start + Length
 */
class SolutionWithLength {
public:
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
};