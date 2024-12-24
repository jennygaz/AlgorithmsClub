/* LC 152 - Maximum Product Subarray */
/* by jennygaz */

@inlinable
func maxProduct(_ nums: [Int]) -> Int {
    var maxValue = Int.min
    var lhs = 1
    var rhs = 1
    for (leftNum, rightNum) in zip(nums, nums.reversed()) {
        lhs *= leftNum
        rhs *= rightNum
        maxValue = max(maxValue, lhs)
        maxValue = max(maxValue, rhs)
        if lhs == 0 {
            lhs = 1
        }
        if rhs == 0 {
            rhs = 1
        }
    }
    return maxValue
}
