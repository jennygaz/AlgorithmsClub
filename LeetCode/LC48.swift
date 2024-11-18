/* LeetCode 48. Rotate Image */
/* by jennyga */

@inlinable
func getNextPosition(from position: (Int, Int), with size: Int) -> [Int] {
    // Always the solution is to use the second value as first
    // then get the complement of the first as the second
    [
      position.1,
      size - position.0 - 1
    ]
}

func rotate(_ matrix: inout [[Int]]) {
    let size = matrix.count
    let halfSize = size / 2
    for column in 0..<halfSize {
        for row in 0...(size % 2 == 1 ? halfSize : halfSize - 1) {
            // find the positions
            let current = [column, row]
            let firstNewPosition = getNextPosition(from: (column, row), with: size)
            let secondNewPosition = getNextPosition(from: (firstNewPosition[0], firstNewPosition[1]), with: size)
            let thirdNewPosition = getNextPosition(from: (secondNewPosition[0], secondNewPosition[1]), with: size)
            // copy the values
            let currentValue = matrix[column][row]
            let firstNewValue = matrix[firstNewPosition[0]][firstNewPosition[1]]
            let secondNewValue = matrix[secondNewPosition[0]][secondNewPosition[1]]
            let thirdNewValue = matrix[thirdNewPosition[0]][thirdNewPosition[1]]
            // reassign the values
            matrix[firstNewPosition[0]][firstNewPosition[1]] = currentValue
            matrix[secondNewPosition[0]][secondNewPosition[1]] = firstNewValue
            matrix[thirdNewPosition[0]][thirdNewPosition[1]] = secondNewValue
            matrix[current[0]][current[1]] = thirdNewValue
        }
    }
}
