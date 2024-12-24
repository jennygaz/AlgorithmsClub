/* 1.5. One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

   Follow-up: Does your solution hold up for checking 2 edits away? Can it be done in O(n + m)?
 */
/* by jennyga */

@inlinable
func isOneEditReplace(_ lhs: String, from rhs: String) -> Bool {
    var foundDifference = false
    for (a, b) in zip(lhs, rhs) {
        if a != b {
            if foundDifference { return false }
            foundDifference = true
        }
    }
    return true
}

@inlinable
func isOneInsertionAway(_ lhs: String, from rhs: String) -> Bool {
    var lhsChars = lhs.characters
    var rhsChars = rhs.characters
    var leftIndex = 0
    var rightIndex = 0
    while rightIndex < rhsChars.count && leftIndex < lhsChars.count {
        if lhsChars[leftIndex] != rhsChars[rightIndex] {
            if leftIndex != rightIndex { return false }
            rightIndex += 1
        } else {
            rightIndex += 1
            leftIndex += 1
        }
    }
    return true
}



func isOneEditAway(_ lhs: String, from rhs: String) -> Bool {
    if lhs.count == rhs.count {
        return isOneEditReplace(lhs, from: rhs)
    } else if lhs.count + 1 == rhs.count {
        return isOneInsertionAway(lhs, from: rhs)
    } else if lhs.count == rhs.count + 1 {
        return isOneInsertionAway(rhs, from: lhs)
    }
    return false;
}
