public class ReverseString {

    public static char[] reverseStringLetters(String str) {
        char reversedStr[] = new char[str.length()];
        int i = 0;
        int j = str.length() - 1;
        for (; i <= j; ++i, --j) {
            reversedStr[i] = str.charAt(j);
            reversedStr[j] = str.charAt(i);
        }
        return reversedStr;
    }

    public static char[] reverseStringWords(String str) {
        char reversedWords[] = new char[str.length()];
        char[] reversedLetters = reverseStringLetters(str);
        for (int k = 0; k < reversedLetters.length; ++k) {
            int i = k;
            k += findSpace(reversedLetters, k);
            int j = k - 1;
            for (; i <= j; ++i, --j) {
                reversedWords[i] = reversedLetters[j];
                reversedWords[j] = reversedLetters[i];
            }
            if (k < reversedLetters.length) {
                reversedWords[k] = ' ';
            }
        }
        return reversedWords;
    }

    private static int findSpace(char[] str, int i) {
        int count = 0;
        for (; i < str.length && str[i] != ' '; ++i) {
            ++count;
        }
        return count;
    }

    public static void main(String[] args) {
        String str = new String("my name is harry");
        char[] strReversedLetters = reverseStringLetters(str);
        System.out.println(strReversedLetters);
        char[] strReversedWords = reverseStringWords(str);
        System.out.println(strReversedWords);
    }

}