@inlinable
func compressString(_ str: String) -> String {
    var characters: [String] = []
    characters.reserveCapacity(str.count)
    let originalCharacters = str.characters.map { String($0) }
    var index = 0
    while index < originalCharacters.count {
        var pointer = index + 1
        var currentChar = originalCharacters[index]
        while pointer < originalCharacters.count && originalCharacters[pointer] == currentChar {
            pointer += 1
        }
        let difference = pointer - index
        characters.append(currentChar)
        characters.append(String(difference))
        index = pointer
    }
    return characters.count < str.count ? characters.joined() : str
}
