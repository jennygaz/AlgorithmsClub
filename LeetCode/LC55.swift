/* LeetCode 55 - Jump Game */
/* by jennyga */

func canJump(_ nums: [Int]) -> Bool {
    guard var maxIndex = nums.first else { return true }
    for index in 0..<nums.count {
        guard maxIndex < nums.count - 1 else { return true }
        guard !(nums[index] == 0 && maxIndex == index) else { return false }
        maxIndex = max(index + nums[index], maxIndex)
    }
    return true
}
