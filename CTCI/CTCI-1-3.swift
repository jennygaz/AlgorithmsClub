/* Cracking the Coding Interview 1.3. URLify: Write a method to replace all spaces in a string with '%20'.
   You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please use a character array that you can perform this operation in place.)
 */
/* by jennyga */
/*
 Intuition: what happens if we move backwards instead of forward? We need to go through the string and count all characters, then use two pointers to swap values accordingly and update.
 */

func urlify(_ characters: inout [Character], trueLength: Int) {
    let offset = characters.count - trueLength
    var backIterator = characters.count - 1
    var stringEndIterator = characters.count - offset - 1
    while stringEndIterator > 0 {
        guard characters[stringEndIterator] == " " else {
            characters[backIterator] = characters[stringEndIterator]
            backIterator -= 1
            stringEndIterator -= 1
            continue
        }
        characters[backIterator] = "0"
        backIterator -= 1
        characters[backIterator] = "2"
        backIterator -= 1
        characters[backIterator] = "%"
        backIterator -= 1
        stringEndIterator -= 1
    }
}
