/* LeetCode 1. TwoSum */
/* by jennyga */

func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    let keys = Set(nums)
    var indexForKey: [Int: [Int]] = Dictionary(minimumCapacity: keys.count)
    for (index, key) in nums.enumerated() {
        if indexForKey[key] == nil { indexForKey[key] = [] }
        indexForKey[key]!.append(index)
    }
    var idx: Int = 0
    var result: [Int] = [-1, -1]
    for key in keys {
        if key * 2 == target {
            if let indices = indexForKey[key], indices.count >= 2 {
                result[0] = indices[0]
                result[1] = indices[1]
                return result
            }
        } else if let indices = indexForKey[target - key] {
            result[0] = indexForKey[key]![0]
            result[1] = indices[0]
            return result
        }
    }
    return result
}
