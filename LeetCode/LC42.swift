/* LeetCode 42 - Trapping Rain Water */
/* by jennygaz */
import Foundation

func trap(_ height: [Int]) -> Int {
    var currentIndex = 0
    var stack: [Int] = []
    var totalArea = 0
    while currentIndex < height.count {
        let head = !stack.isEmpty ? stack.last! : 0
        guard height[head] < height[currentIndex] else {
            stack.append(currentIndex)
            currentIndex += 1
            continue
        }
        let floor = !stack.isEmpty ? stack.last! : 0
        while !stack.isEmpty && height[floor] == height[stack.last!] {
            stack.popLast()
        }
        let left = !stack.isEmpty ? stack.last! : 0
        let offset = currentIndex - left - 1
        let length = min(height[currentIndex], height[left]) - height[floor]
        let area = length * offset
        if area > 0 { totalArea += area }
        if stack.isEmpty {
            stack.append(currentIndex)
            currentIndex += 1
        }
    }
    return totalArea
}
