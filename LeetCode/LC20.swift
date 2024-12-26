/* LeetCode 20 - Valid Parentheses */
/* by jennygaz */
import Foundation

func isValid(_ s: String) -> Bool {
    var stack: [Character] = []
    var mapped: [Character: Character] = [
      "(": ")", ")": "(",
      "{": "}", "}": "{",
      "[": "]", "]": "["
    ]
    for char in s {
        
        switch char {
        case ")", "}", "]":
            guard stack.count >= 1 else { return false }
            let parentheses = stack.popLast()!
            guard let other = mapped[parentheses], other == char else { return false }
        case "(", "[", "{": stack.append(char)
        default: continue
        }
    }
    return stack.count == 0
}
