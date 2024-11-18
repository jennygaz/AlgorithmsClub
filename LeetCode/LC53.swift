/* LeetCode 53. Maximum Subarray */
/* by jennyga */

func maxSubArray(_ nums: [Int]) -> Int {
    var maxSeen = -100_000
    var sum = 0
    for num in nums {
        sum += num
        maxSeen = max(maxSeen, sum)
        if sum <= 0 { sum = 0 }
    }
    return maxSeen
}
