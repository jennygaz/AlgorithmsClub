/* LeetCode 75. Sort Colors */
/* by jennyga */

func sortColors(_ nums: inout [Int]) {
    var counts: [Int] = Array(repeating: 0, count: 3)
    nums.forEach { counts[$0] += 1 }
    var index = 0
    for (color, count) in counts.enumerated() {
        var countCopy = count
        while countCopy > 0 {
            nums[index] = color
            index += 1
            countCopy -= 1
        }
    }
}
