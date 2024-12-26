/* LeetCode 2073 - Time Needed to Buy Tickets */
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
    var isEmpty: Bool { frontIndex == contents.count }
    var count: Int { contents.count - frontIndex }
}

func timeRequiredToBuy(_ tickets: [Int], _ k: Int) -> Int {
    let values: [(Int, Int)] = tickets.enumerated().map { ($0, $1) }
    var queue = Queue(from: values)
    var count = 0
    while !queue.isEmpty {
        let frontTicket = queue.front
        queue.popFront()
        if frontTicket.1 - 1 > 0 { queue.push((frontTicket.0, frontTicket.1 - 1)) }
        count += 1
        if frontTicket.0 == k && frontTicket.1 == 1 { break }
    }
    return count
}
