/* LeetCode 122. Best Time to Buy and Sell Stock II */
/* by jennyga */

func maxProfit(_ prices: [Int]) -> Int {
    var maxResult = 0
    var start = prices.first!
    for index in 1..<prices.count {
        if start < prices[index] {
            maxResult += prices[index] - start
        }
        start = prices[index]
    }
    return maxResult
}
