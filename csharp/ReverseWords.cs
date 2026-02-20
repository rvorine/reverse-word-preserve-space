using System;
using System.Collections.Generic;
using System.Text;

/// <summary>
/// Reverse words in a string while preserving the positions of spaces.
///
/// Example:
///   Input:  "Hello   World"
///   Output: "World   Hello"
/// </summary>
class ReverseWords
{
    public static string ReverseWordsPreserveSpaces(string s)
    {
        var words = new List<string>();
        foreach (var word in s.Split(' '))
        {
            if (word.Length > 0)
                words.Add(word);
        }
        words.Reverse();

        var result = new StringBuilder();
        int wordIndex = 0;
        int i = 0;

        while (i < s.Length)
        {
            if (s[i] == ' ')
            {
                result.Append(' ');
                i++;
            }
            else
            {
                int j = i;
                while (j < s.Length && s[j] != ' ') j++;
                result.Append(words[wordIndex++]);
                i = j;
            }
        }

        return result.ToString();
    }

    static void Main()
    {
        string[] testCases = {
            "Hello World",
            "Hello   World",
            "  Hello   World  ",
            "a b   c",
            "one two three four"
        };

        foreach (var tc in testCases)
        {
            Console.WriteLine($"Input:  '{tc}'");
            Console.WriteLine($"Output: '{ReverseWordsPreserveSpaces(tc)}'");
            Console.WriteLine();
        }
    }
}
