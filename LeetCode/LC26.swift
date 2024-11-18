/* LeetCode 26. Remove Duplicates from Sorted Array */
/* by jennyga */
/*
 * Intuition: Make a bitset taking into account the constraints: each value between -100 and 100.
 * Then, just go in order and place the newly sorted unique elements in the array.
 */

@inlinable
func getSection(_ index: Int) -> Int? {
    switch index {
    case 0...63:    0
    case 64...127:  1
    case 128...191: 2
    case 192...255: 3
    default:        nil
    }
}
func removeDuplicates(_ nums: inout [Int]) -> Int {
    // We can use a bitmask of 256 values for this :)
    var seenValues: [UInt64] = Array(repeating: 0, count: 4)
    for num in nums {
        // Map them: -100 -> 0; 0 -> 100; 100 -> 200
        let index = num + 100
        guard let section = getSection(index) else { return -1 }
        seenValues[section] |= (1 << (index % 64))
    }
    var currentIndex = 0
    for num in 0...200 {
        guard let section = getSection(num) else { return -1 }
        let bitResult = seenValues[section] & 1 << (num % 64)
        // print(seenValues[section], 1 << (num % 64), bitResult)
        if bitResult != 0 {
            nums[currentIndex] = num - 100
            currentIndex += 1
        }
    }
    return currentIndex
}
