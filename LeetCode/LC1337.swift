/* LeetCode 1337 - The K Weakest Rows in a Matrix */
/* by jennygaz */
import HeapModule /* requires swift-collections as package */

struct IndexedCount {
    let soldiers: Int
    let index: Int
}

extension IndexedCount: Comparable {
    static func < (_ lhs: IndexedCount, _ rhs: IndexedCount ) -> Bool {
        lhs.soldiers != rhs.soldiers
        ? lhs.soldiers < rhs.soldiers
        : lhs.index < rhs.index
    }
}

func kWeakestRows(_ mat: [[Int]], _ k: Int) -> [Int] {
    var currentRow = 0
    let partialResult = mat
      .map { row in
          defer { currentRow += 1 }
          return IndexedCount(soldiers: row.reduce(0, +), index: currentRow)
      }
    var heapified = Heap(partialResult)
    var kTimes = k
    var result: [Int] = []
    while kTimes > 0 {
        defer { kTimes -= 1 }
        let tmp = heapified.removeMin()
        result.append(tmp.index)
    }
    return result
}
