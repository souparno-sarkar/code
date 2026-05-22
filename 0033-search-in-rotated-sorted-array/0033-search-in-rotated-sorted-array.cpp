    /*STORY TIME : 
    STEP 1: Identify the sorted part of the array it may be the righthalf or lefthalf side of the
            array.
    STEP 2: After selecting the sorted half compare that the target lies between the half portion 
            of the array by compareing nums[low] || nums[right] with target as per the requirment
            && and also compare the terget with the nums[mid]
    STEP 3: After the comparison in the STEP 2 applay the binary search logic.
    */

class Solution {
public:
    int search(vector<int>& nums, int res) {
        int l = 0, h = nums.size()-1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == res)
                return mid;
            if (nums[mid] >= nums[l])
            {
                if (nums[l] <= res && res <=nums[mid]) 
                    h = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (nums[h] >= res &&
                    res >= nums[mid])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};