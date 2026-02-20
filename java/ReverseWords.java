import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Reverse words in a string while preserving the positions of spaces.
 *
 * Example:
 *   Input:  "Hello   World"
 *   Output: "World   Hello"
 */
public class ReverseWords {

    public static String reverseWordsPreserveSpaces(String s) {
        List<String> words = new ArrayList<>();
        for (String word : s.split("\\s+")) {
            if (!word.isEmpty()) {
                words.add(word);
            }
        }
        Collections.reverse(words);

        StringBuilder result = new StringBuilder();
        int wordIndex = 0;
        int i = 0;

        while (i < s.length()) {
            if (s.charAt(i) == ' ') {
                result.append(' ');
                i++;
            } else {
                int j = i;
                while (j < s.length() && s.charAt(j) != ' ') j++;
                result.append(words.get(wordIndex++));
                i = j;
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        String[] testCases = {
            "Hello World",
            "Hello   World",
            "  Hello   World  ",
            "a b   c",
            "one two three four"
        };

        for (String tc : testCases) {
            System.out.println("Input:  '" + tc + "'");
            System.out.println("Output: '" + reverseWordsPreserveSpaces(tc) + "'");
            System.out.println();
        }
    }
}
