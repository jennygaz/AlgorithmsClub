/* LeetCode 143 - Reorder List */
/* by jennygaz */
import Foundation

// Returns the new head too
@inlinable
func reverseListInPlace(_ head: ListNode?) -> ListNode? {
    var current = head
    var previous: ListNode? = nil
    var next = current?.next
    while current != nil {
        current?.next = previous
        previous = current
        current = next
        next = next?.next
    }
    return previous
}

@inlinable
@discardableResult
func mergeLists(_ lhs: ListNode?, interweavedWith rhs: ListNode?) -> ListNode? {
    var lhsIt = lhs
    var rhsIt = rhs
    while lhsIt != nil && rhsIt != nil {
        let lhsNext = lhsIt?.next
        let rhsNext = rhsIt?.next
        lhsIt?.next = rhsIt
        rhsIt?.next = lhsNext
        lhsIt = lhsNext
        rhsIt = rhsNext
    }
    return lhs
}

func reorderList(_ head: ListNode?) {
    var count = 0
    var it = head
    while it != nil {
        it = it?.next
        count += 1
    }
    var halfway = head
    var halfcount = count / 2
    while halfcount > 1 { 
        halfway = halfway?.next
        halfcount -= 1
    }
    if count % 2 == 1 { halfway = halfway?.next }
    var latterHalf = halfway?.next
    halfway?.next = nil
    latterHalf = reverseListInPlace(latterHalf)
    var halfIt = latterHalf
    while halfIt != nil { halfIt = halfIt?.next }
    it = head
    _ = mergeLists(it, interweavedWith: latterHalf)
    return
}
