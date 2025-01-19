class Solution {
    public boolean isAnagram(String s, String t) {

        if (s.equals(t)) {
            return true;
        }

        if (s.length() != t.length()) {
            return false;
        }

        int[] sCount = count(s);
        int[] tCount = count(t);

        for (int i = 0; i < 26; i++) {
            if (sCount[i] != tCount[i]) {
                return false;
            }
        }

        return true;
    }

    public int[] count(String s) {

        int[] charArr = new int[26];
        char[] sArr = s.toCharArray();

        for (int i = 0; i < sArr.length; i++) {
            charArr[sArr[i] - 'a']++;
        }

        return charArr;
    }
}