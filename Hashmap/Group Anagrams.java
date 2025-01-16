class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs == null || strs.length == 0) // Changed && to || for a more accurate check
            return new ArrayList<>();
        
        Map<String, List<String>> frequencyStringsMap = new HashMap<>();
        
        for (String str : strs) {
            String frequencyString = getFrequencyString(str);
            
            if (frequencyStringsMap.containsKey(frequencyString)) {
                frequencyStringsMap.get(frequencyString).add(str);
            } else {
                List<String> strList = new ArrayList<>();
                strList.add(str);
                frequencyStringsMap.put(frequencyString, strList); // Fixed variable name
            }
        }
        
        return new ArrayList<>(frequencyStringsMap.values());
    }
private String getFrequencyString(String str) {
        int[] charCount = new int[26];
        for (char c : str.toCharArray()) {
            charCount[c - 'a']++;
        }
        
        StringBuilder sb = new StringBuilder();
        for (int count : charCount) {
            sb.append(count).append('#');
        }
        
        return sb.toString();
    }
}