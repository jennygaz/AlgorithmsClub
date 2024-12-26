/* LeetCode 1700 - Number of Students Unable to Eat Lunch */
/* by jennygaz */
import Foundation

struct Queue<T> {
    private var contents: [T]
    private var frontIndex: Int

    init(from array: Array<T>) {
        self.contents = array
        self.frontIndex = 0
    }

    @discardableResult
    mutating func push(_ value: T) {
        contents.append(value)
    }

    @discardableResult
    mutating func popFront() -> T {
        let value = contents[frontIndex]
        frontIndex += 1
        return value
    }

    var front: T { contents[frontIndex] }
    var isEmpty: Bool { frontIndex != (contents.count - 1) }
    var count: Int { contents.count - frontIndex }
}

func countStudents(_ students: [Int], _ sandwiches: [Int]) -> Int {
    var queue = Queue<Int>(from: students)
    var count = 0
    var index = 0
    while queue.count > 0 && count != queue.count {
        if queue.front == sandwiches[index] {
            index += 1
            count = 0
        } else {
            queue.push(queue.front)
            count += 1
        }
        queue.popFront()
    }
    return queue.count
}
