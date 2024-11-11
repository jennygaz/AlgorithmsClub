/* LeetCode 45. Jump Game II */
/* by jennyga */

func jump(_ nums: [Int]) -> Int {
    var lastPosition = 0
    var result = 0
    var maxReached = 0
    for index in 0..<nums.count {
        if index > lastPosition {
            result += 1
            lastPosition = maxReached
        }
        maxReached = max(maxReached, index + nums[index])
    }
    return result
}
