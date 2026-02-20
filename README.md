# Reverse Words — Preserve Spaces

<p align="center">
  <a href="https://www.instagram.com/lacopydepastel/">
    <img src="https://img.shields.io/badge/Instagram-%40lacopydepastel-E4405F?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram @lacopydepastel"/>
  </a>
  &nbsp;
  <a href="https://www.youtube.com/@rvorine">
    <img src="https://img.shields.io/badge/YouTube-%40rvorine-FF0000?style=for-the-badge&logo=youtube&logoColor=white" alt="YouTube @rvorine"/>
  </a>
</p>

> 👍 **Like** the video and **Subscribe** to the channel for more coding tutorials!

---

## 📖 Problem Statement

Given a string that contains words separated by **one or more spaces**, reverse the **order of the words** while keeping every space exactly in its original position.

### Example

| Input | Output |
|---|---|
| `"Hello World"` | `"World Hello"` |
| `"Hello   World"` | `"World   Hello"` |
| `"  Hello   World  "` | `"  World   Hello  "` |
| `"a b   c"` | `"c b   a"` |
| `"one two three four"` | `"four three two one"` |

---

## 💡 Solution Approach

1. **Extract words** — collect all non-space tokens in order.
2. **Reverse the word list** — reverse only the words, not the spaces.
3. **Rebuild the string** — walk through the original string character by character:
   - When a **space** is encountered, copy it as-is.
   - When a **word boundary** is encountered, place the next word from the reversed list.

This guarantees that every space stays exactly where it was in the original input.

---

## 📁 Repository Structure

```
.
├── c/
│   └── reverse_words.c
├── csharp/
│   └── ReverseWords.cs
├── java/
│   └── ReverseWords.java
├── javascript/
│   └── reverseWords.js
├── kotlin/
│   └── ReverseWords.kt
└── python/
    └── reverse_words.py
```

---

## 🐍 Python

**File:** [`python/reverse_words.py`](python/reverse_words.py)

```python
def reverse_words_preserve_spaces(s):
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
            j = i
            while j < len(s) and s[j] != ' ':
                j += 1
            result.append(words[word_index])
            word_index += 1
            i = j

    return ''.join(result)
```

**Run:**
```bash
python3 python/reverse_words.py
```

---

## 🌐 JavaScript

**File:** [`javascript/reverseWords.js`](javascript/reverseWords.js)

```javascript
function reverseWordsPreserveSpaces(s) {
  const words = s.split(/\s+/).filter(w => w.length > 0);
  words.reverse();

  let wordIndex = 0;
  let result = '';
  let i = 0;

  while (i < s.length) {
    if (s[i] === ' ') {
      result += ' ';
      i++;
    } else {
      let j = i;
      while (j < s.length && s[j] !== ' ') j++;
      result += words[wordIndex++];
      i = j;
    }
  }

  return result;
}
```

**Run:**
```bash
node javascript/reverseWords.js
```

---

## ☕ Java

**File:** [`java/ReverseWords.java`](java/ReverseWords.java)

```java
public static String reverseWordsPreserveSpaces(String s) {
    List<String> words = new ArrayList<>();
    for (String word : s.split("\\s+")) {
        if (!word.isEmpty()) words.add(word);
    }
    Collections.reverse(words);

    StringBuilder result = new StringBuilder();
    int wordIndex = 0, i = 0;

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
```

**Run:**
```bash
javac java/ReverseWords.java -d java/ && java -cp java/ ReverseWords
```

---

## 🎯 Kotlin

**File:** [`kotlin/ReverseWords.kt`](kotlin/ReverseWords.kt)

```kotlin
fun reverseWordsPreserveSpaces(s: String): String {
    val words = s.split(Regex("\\s+"))
        .filter { it.isNotEmpty() }.reversed().toMutableList()

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
```

**Run:**
```bash
kotlinc kotlin/ReverseWords.kt -include-runtime -d /tmp/ReverseWords.jar && java -jar /tmp/ReverseWords.jar
```

---

## 🔵 C

**File:** [`c/reverse_words.c`](c/reverse_words.c)

```c
void reverse_words_preserve_spaces(const char *s, char *result) {
    char *words[256];
    int num_words = split_words(s, words, 256);

    int word_index = num_words - 1;
    int i = 0, r = 0;
    int len = strlen(s);

    while (i < len) {
        if (s[i] == ' ') {
            result[r++] = ' ';
            i++;
        } else {
            int j = i;
            while (j < len && s[j] != ' ') j++;
            int wlen = strlen(words[word_index]);
            strncpy(result + r, words[word_index], wlen);
            r += wlen;
            word_index--;
            i = j;
        }
    }
    result[r] = '\0';
}
```

**Run:**
```bash
gcc -o reverse_words c/reverse_words.c && ./reverse_words
```

---

## 🟣 C#

**File:** [`csharp/ReverseWords.cs`](csharp/ReverseWords.cs)

```csharp
public static string ReverseWordsPreserveSpaces(string s)
{
    var words = new List<string>();
    foreach (var word in s.Split(' '))
        if (word.Length > 0) words.Add(word);
    words.Reverse();

    var result = new StringBuilder();
    int wordIndex = 0, i = 0;

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
```

**Run:**
```bash
dotnet-script csharp/ReverseWords.cs
# or
csc csharp/ReverseWords.cs -out:/tmp/ReverseWords.exe && mono /tmp/ReverseWords.exe
```

---

## ⏱️ Complexity

| Metric | Value |
|---|---|
| Time Complexity | O(n) — single pass through the string |
| Space Complexity | O(n) — storing the word list and result |

---

## 📜 License

This project is open source and available under the [MIT License](LICENSE).
