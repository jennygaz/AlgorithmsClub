/* LeetCode 918 - Maximum Sum Circular Subarray */
/* by jennygaz */
import Foundation

func maxSubarraySumCircular(_ nums: [Int]) -> Int {
    var total = 0
    var maxSum = nums[0]
    var currentMax = 0
    var minSum = nums[0]
    var currentMin = 0
    for num in nums {
        currentMax = max(currentMax + num, num)
        maxSum = max(maxSum, currentMax)
        currentMin = min(currentMin + num, num)
        minSum = min(minSum, currentMin)
        total += num
    }
    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum
}
