/* Cracking the Coding Interview 1.2. Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

   Follow-up: Can you make this run in O(n) time) or is O(n log n) the best?
   
 */
/* by jennyga */
/*
 * Intuition: Assume the values are ASCII, even if they aren't it's possible to do it with Unicode, it's just more tedious
 */

func checkPermutation(_ s: String, of t: String) -> Bool {
    var lhsCounts: [Int] = Array(repeating: 0, count: 256)
    s.compactMap { $0.asciiValue }
      .forEach { lhsCounts[$0] += 1 }
    t.compactMap { $0.asciiValue }
      .forEach { lhsCounts[$0] -= 1 }
    return lhsCounts.allSatisfy { $0 == 0 }
}
