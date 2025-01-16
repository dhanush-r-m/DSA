class Solution {
    public boolean isHappy(int n) {
        Set<Integer> usedInteger = new HashSet<>();   
        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            if (sum == 1) {
                return true;
            }
            if (usedInteger.contains(sum)) {
                return false;
            }
            usedInteger.add(sum);
            n = sum;
        }
        return true;
    }
}