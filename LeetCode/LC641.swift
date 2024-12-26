/* LeetCode 641 - Design Circular Deque */
/* by jennygaz */
import Foundation

class MyCircularDeque {
    private var contents: [Int]
    private var frontIndex: Int
    private let maxCapacity: Int
    private(set) var count: Int = 0

    init(_ k: Int) {
        frontIndex = 0
        maxCapacity = k
        contents = Array(repeating: 0, count: k)
    }

    func insertFront(_ value: Int) -> Bool {
        guard !isFull() else { return false }
        if !isEmpty() {
            frontIndex = (frontIndex - 1 + maxCapacity) % maxCapacity
        }
        contents[frontIndex] = value
        count += 1
        return true
    }

    func insertLast(_ value: Int) -> Bool {
        guard !isFull() else { return false }
        let index = (frontIndex + count) % maxCapacity
        contents[index] = value
        count += 1
        return true
    }

    func deleteFront() -> Bool {
        guard !isEmpty() else { return false }
        frontIndex = (frontIndex + 1) % maxCapacity
        count -= 1
        return true
    }

    func deleteLast() -> Bool {
        guard !isEmpty() else { return false }
        count -= 1
        return true
    }

    func getFront() -> Int {
        guard !isEmpty() else { return -1 }
        return contents[frontIndex]
    }

    func getRear() -> Int {
        guard !isEmpty() else { return -1 }
        let index = (frontIndex + count - 1) % maxCapacity
        return contents[index]
    }

    func isEmpty() -> Bool { return count == 0 }

    func isFull() -> Bool { return count == maxCapacity }
}
