/**
 * Reverse words in a string while preserving the positions of spaces.
 *
 * Example:
 *   Input:  "Hello   World"
 *   Output: "World   Hello"
 */
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

// Test cases
const testCases = [
  'Hello World',
  'Hello   World',
  '  Hello   World  ',
  'a b   c',
  'one two three four',
];

testCases.forEach(tc => {
  console.log(`Input:  '${tc}'`);
  console.log(`Output: '${reverseWordsPreserveSpaces(tc)}'`);
  console.log();
});
