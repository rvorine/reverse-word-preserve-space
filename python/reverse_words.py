def reverse_words_preserve_spaces(s):
    """
    Reverse words in a string while preserving the positions of spaces.

    Example:
        Input:  "Hello   World"
        Output: "World   Hello"
    """
    # Extract only the words (non-space tokens)
    words = s.split()
    words.reverse()

    result = []
    word_index = 0

    i = 0
    while i < len(s):
        if s[i] == ' ':
            result.append(' ')
            i += 1
        else:
            # Find end of current word in original string
            j = i
            while j < len(s) and s[j] != ' ':
                j += 1
            result.append(words[word_index])
            word_index += 1
            i = j

    return ''.join(result)


if __name__ == '__main__':
    test_cases = [
        "Hello World",
        "Hello   World",
        "  Hello   World  ",
        "a b   c",
        "one two three four",
    ]
    for tc in test_cases:
        print(f"Input:  '{tc}'")
        print(f"Output: '{reverse_words_preserve_spaces(tc)}'")
        print()
