/* LeetCode 238. Product of Array Except Self */
/* by jennyga */

func productExceptSelf(_ nums: [Int]) -> [Int] {
    guard nums.count > 2 else { return [nums[1], nums[0]] }
    var prefixValues = nums
    var postfixValues = nums
    for (lhs, rhs) in zip(1..<nums.count, (0..<(nums.count - 1)).reversed()) {
        prefixValues[lhs] *= prefixValues[lhs - 1]
        postfixValues[rhs] *= postfixValues[rhs + 1]
    }
    var result: [[Int]] = [[postfixValues[1]], [], [prefixValues[nums.count - 2]]]
    result[1] = Array(1..<(nums.count-1)).map { index in
        prefixValues[index - 1] * postfixValues[index + 1]
    }
    return result.flatMap { $0 }
}
