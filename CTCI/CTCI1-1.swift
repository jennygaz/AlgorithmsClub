/* Cracking the Coding Interview 1.1: 1.1. Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

   Food for thought: Is your approach feasible for Unicode too?

 */

/* by jennyga */

/*
 * Intuition: There are _only_ 256 -> 2^8 distinct ASCII values. But there are less than 2^21 Unicode code points.
 * Originally, we'd use an array of 256 values and that's it, if we fill one position then return false; otherwise, return true at the end.
 * However, to support Unicode we need to use constant space equal to 2^21 / 2^6 (for 64-bit integers as masks) UInt64, which is around 32k. This works.
 * To obtain each tuple of (section, index) for each value to map them into the bitset
 * we just need to divide the value by the size of each section, and get the modulo 64
 * However, this is quite easy in binary! To divide by 64 we simply move to the right 6 positions
 * and to get the modulo 64 we simply create a mask for the last 6 positions (64 - 1 yields all on bits for it)
 */

@inlinable
func divmod64(_ num: Int) -> (section: Int, mod: Int) {
    let mask = 64 - 1       // 63 means all on bits for the size of our UInt64 value
    let mod = num & mask    // modulo means just doing AND with the number
    let res = num & (~mask) // division is just turning those bits off then moving 6 to the right
    let section = res &>> 6
    return (section: section, mod: mod)
}

func isUnique(_ s: String) -> Bool {
    let maxElement = 2 << 15
    var bitset: [UInt64] = Array(repeating: 0, count: maxElement)
    for scalar in s.unicodeScalars {
        let value = scalar.value
        let (section, subIndex) = divmod64(value)
        guard bitset[section] & (1 << subIndex) == 0 else { return false }
        bitset[section] |= (1 << subIndex)
    }
    return true
}
