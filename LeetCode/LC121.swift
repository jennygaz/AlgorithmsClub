/* LeetCode 121. Best Time to Buy and Sell Stock I */
/* by jennyga */

func maxProfit(_ prices: [Int]) -> Int {
    var transformedPrices: [Int] = Array(repeating: 0, count: prices.count)
    var currentMin: Int = 1_000_000
    for (index, price) in prices.enumerated() {
        currentMin = min(currentMin, price)
        transformedPrices[index] = currentMin
    }
    var maxDiff: Int = 0
    for (price, min) in zip(prices, transformedPrices) {
        let newDiff = price - min
        maxDiff = max(maxDiff, newDiff)
    }
    return maxDiff
}
