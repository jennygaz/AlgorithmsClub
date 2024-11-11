/* Leetcode 33. Search in Rotated Sorted Array */
/* by jennyga */

// Paste the function `search` into LeetCode to run it

func search(_ nums: [Int], _ target: Int) -> Int {
    let n = nums.count
    var low = 0
    var high = n - 1

    while low <= high {
        let mid = low + (high - low) / 2
        if nums[mid] == target { return mid }

        if nums[low] <= nums[mid] {
            if nums[low] <= target && target <= nums[mid] {
                high = mid - 1
            } else {
                low = mid + 1
            }
        } else if nums[mid] <= target && target <= nums[high] {
            low = mid + 1
        } else {
            high = mid - 1
        }
    }
    return -1
}
