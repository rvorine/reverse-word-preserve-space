/**
 * Reverse words in a string while preserving the positions of spaces.
 *
 * Example:
 *   Input:  "Hello   World"
 *   Output: "World   Hello"
 */
fun reverseWordsPreserveSpaces(s: String): String {
    val words = s.split(Regex("\\s+")).filter { it.isNotEmpty() }.reversed().toMutableList()

    val result = StringBuilder()
    var wordIndex = 0
    var i = 0

    while (i < s.length) {
        if (s[i] == ' ') {
            result.append(' ')
            i++
        } else {
            var j = i
            while (j < s.length && s[j] != ' ') j++
            result.append(words[wordIndex++])
            i = j
        }
    }

    return result.toString()
}

fun main() {
    val testCases = listOf(
        "Hello World",
        "Hello   World",
        "  Hello   World  ",
        "a b   c",
        "one two three four"
    )

    for (tc in testCases) {
        println("Input:  '$tc'")
        println("Output: '${reverseWordsPreserveSpaces(tc)}'")
        println()
    }
}
