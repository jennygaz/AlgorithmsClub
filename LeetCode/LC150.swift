/* LeetCode 150 - Evaluate Reverse Polish Notation */
/* by jennygaz */
import Foundation

@inlinable
func operation(_ lhs: Int, _ rhs: Int, using token: String) -> Int {
    switch token {
    case "+": lhs + rhs
    case "-": lhs - rhs
    case "*": lhs * rhs
    case "/": lhs / rhs
    default: 0
    }
}
func evalRPN(_ tokens: [String]) -> Int {
    var stack: [Int] = []
    var result: Int = 0
    for token in tokens {
        switch token {
        case "+", "-", "*", "/": // Operator
            guard let rhs = stack.popLast() else { continue }
            guard let lhs = stack.popLast() else { continue }
            let partialResult = operation(lhs, rhs, using: token)
            stack.append(partialResult)
        default: // Operand (value)
            guard let value = Int(token) else { continue }
            stack.append(value)
        }
    }
    return stack.first!
}
