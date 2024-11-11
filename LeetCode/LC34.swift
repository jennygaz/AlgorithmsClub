/* LeetCode 34. Find First and Last Position of Element in Sorted Array */
/* by jennyga */

@inlinable
func lowerBound<T>(from rangeStart: Int, upTo rangeEnd: Int, inside collection: [T], target: T, compare: (T, T) -> Bool) {
    var count = rangeEnd - rangeStart
    var it = 0
    var step = 0
    var first = rangeStart, last = rangeEnd
    while count > 0 {
        it = first
        step = count / 2
        it += step
        if compare(collection[it], target) {
            it += 1
            first = it
            count -= step + 1
        } else {
            count = step
        }
    }
    return first
}

@inlinable
func lowerBound<T: Comparable>(from rangeStart: Int, upTo rangeEnd: Int, inside collection: [T], target: T) {
    return lowerBound(from: rangeStart, upTo: rangeEnd, inside: collection, target: target, compare: <)
}

@inlinable
func upperBound<T>(from rangeStart: Int, upTo rangeEnd: Int, inside collection: [T], target: T, compare: (T, T) -> Bool) {
    var count = rangeEnd - rangeStart
    var it = 0
    var step = 0
    var first = rangeStart, last = rangeEnd

    while count > 0 {
        it = first
        step = count / 2
        it += step
        if !compare(target, collection[it]) {
            it += 1
            first = it
            count -= step + 1
        } else {
            count = step
        }
    }

    return first
}

@inlinable
func upperBound<T: Comparable>(from rangeStart: Int, upTo rangeEnd: Int, inside collection: [T], target: T) {
    return upperBound(from: rangeStart, upTo: rangeEnd, inside: collection, target: target, compare: <)
}

func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
    var result: [Int] = [-1, -1]
    var lhsIterator = lowerBound(0, nums.count, target)
    if lhsIterator < nums.count && nums[lhsIterator] == target {
        var rhsIterator = upperBound(0, nums.count, target)
        rhsIterator -= 1
        result[0] = lhsIterator
        result[1] = rhsIterator
        result[1] = max(result[0], result[1])
    }
    return result
}
