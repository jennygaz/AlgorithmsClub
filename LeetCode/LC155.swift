/* LeetCode 155 - Min Stack */
/* by jennygaz */

class MinStack {
    private var contents: [(Int, Int)] = []

    init() {
        contents = []
    }
    
    func push(_ val: Int) {
        guard !contents.isEmpty else {
            contents.append((val, val))
            return
        }
        let previousMin = contents.last!.1
        contents.append((val, min(previousMin, val)))
    }
    
    func pop() {
        guard !contents.isEmpty else { return }
        contents.popLast()
    }
    
    func top() -> Int {
        // guard !contents.isEmpty else { return } // not needed in this one
        return contents.last!.0
    }
    
    func getMin() -> Int {
        // guard !contents.isEmpty else { return } // not needed in this one
        return contents.last!.1
    }
}
