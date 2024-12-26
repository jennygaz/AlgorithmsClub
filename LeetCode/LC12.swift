/* LeetCode 12 - Integer to Roman */
/* by jennygaz */
import Foundation

func intToRoman(_ num: Int) -> String {
    let symbols: Dictionary<Int, String> = [
      1: "I", 4: "IV", 5: "V", 9: "IX", 10: "X", 40: "XL", 50: "L", 
      90: "XC", 100: "C", 400: "CD", 500: "D", 900: "CM", 1000: "M"
    ]
    var result: [[String]] = Array(repeating: [], count: 4)
    let keys: [Int] = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
    var currentPower = 1
    var currentDigitIndex = 0
    var tmpNum = num
    while tmpNum > 0 {
        var remainder = tmpNum % 10
        tmpNum /= 10
        while remainder > 0 {
            var keyIndex = 0
            while keyIndex < keys.count && remainder * currentPower - keys[keyIndex] >= 0 { 
                keyIndex += 1
            }
            keyIndex -= 1
            remainder -= keys[keyIndex] / currentPower
            result[currentDigitIndex].append(symbols[keys[keyIndex]]!)
        }
        currentPower *= 10
        currentDigitIndex += 1
    }
    let ans = result
      .reversed()
      .flatMap { $0 }
      .reduce("") { $0 + $1 }
    return ans
}
