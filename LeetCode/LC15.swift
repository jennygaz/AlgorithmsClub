/* LeetCode 15. 3Sum */
/* by jennyga */

struct SumResult: Hashable {
    var first: Int
    var second: Int
    var third: Int
}

func threeSum(_ nums: [Int]) -> [[Int]] {
    let sortedNums = nums.sorted()
    var results = Set<SumResult>()
    for index in 0..<nums.count {
        if index > 0 && sortedNums[index] == sortedNums[index - 1] { continue }
        var lhs = index + 1
        var rhs = sortedNums.count - 1
        while lhs < rhs {
            let total = sortedNums[index] + sortedNums[lhs] + sortedNums[rhs]
            switch total {
            case _ where total == 0:
                results.insert(SumResult(
                                 first: sortedNums[index], 
                                 second: sortedNums[lhs], 
                                 third: sortedNums[rhs]))
                lhs += 1
                while sortedNums[lhs] == sortedNums[lhs - 1] && lhs < rhs { lhs += 1 }
            case _ where total > 0:
                rhs -= 1
            case _ where total < 0:
                lhs += 1
            default: break
            }
        }
    }
    let convertedResults = Array(results).map { sumResult in
        [sumResult.first, sumResult.second, sumResult.third]
    }
    return convertedResults
}
