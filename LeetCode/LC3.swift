/* LeetCode 3. Longest Substring Without Repeating Characters */
/* by jennyga */

func lengthOfLongestSubstring(_ s: String) -> Int {
    let asciiValues = s.compactMap { $0.asciiValue }.map { Int($0) }
    var lastIndexOfKey: [Int] = Array(repeating: -1, count: 256)
    var startIndex = 0
    var result = 0
    for endIndex in 0..<asciiValues.count {
        if lastIndexOfKey[asciiValues[endIndex]] != -1 {
            startIndex = max(startIndex, lastIndexOfKey[asciiValues[endIndex]] + 1)
        }
        lastIndexOfKey[asciiValues[endIndex]] = endIndex
        result = max(result, endIndex - startIndex + 1)
    }
    return result
}
