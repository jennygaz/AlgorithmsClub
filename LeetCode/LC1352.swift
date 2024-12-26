/* LeetCode 1352 - Product of the Last K numbers */
/* by jennygaz */
import Foundation

class ProductOfNumbers {
    private var contents: [Int]
    private var currentCount: Int

    init() {
        contents = [1]
        currentCount = 1
    }

    func add(_ num: Int) {
        guard num > 0 else {
            currentCount = 1
            contents.append(1)
            return
        }
        contents.append(num * contents.last!)
        currentCount += 1
    }

    func getProduct(_ k: Int) -> Int {
        return k < currentCount
        ? contents.last! / contents[contents.count - k - 1]
        : 0
    }
}
