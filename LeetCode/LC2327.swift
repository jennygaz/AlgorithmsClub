/* LeetCode 2327 - Number of People Aware of a Secret */
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

func peopleAwareOfSecret(_ n: Int, _ delay: Int, _ forget: Int) -> Int {
    let mod: Int64 = 1_000_000_000 + 7
    var delays = Queue<(Int, Int64)>(from: [])
    var forgets = Queue<(Int, Int64)>(from: [])
    var answer: Int64 = 1
    var count: Int64 = 0
    delays.push((1 + delay, 1))
    forgets.push((1 + forget, 1))
    var index = 2
    while index <= n {
        if !forgets.isEmpty && forgets.front.0 == index {
            var current = forgets.popFront()
            count = (count - (current.1) + mod) % mod
            answer = (answer - (current.1) + mod) % mod
        }
        if !delays.isEmpty && delays.front.0 == index {
            var current = delays.popFront()
            count += current.1
            count %= mod
        }
        answer += count
        answer %= mod
        if count != 0 { delays.push((index + delay, count)) }
        if count != 0 { forgets.push((index + forget, count)) }
        index += 1
    }
    answer %= mod
    return Int(exactly: answer)!
}
