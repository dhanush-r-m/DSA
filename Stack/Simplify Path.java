class Solution {
    public String simplifyPath(String path) {
        Stack<String> s = new Stack<>();
        String[] p = path.split("/");

        for (String dir : p) {
            if (dir.equals("..")) {
                if (!s.isEmpty()) {
                    s.pop();  // Go up one directory
                }
            } else if (!dir.equals("") && !dir.equals(".")) {
                s.push(dir);  // Add directory to stack
            }
        }

        // Build the simplified path
        StringBuilder res = new StringBuilder();
        if (s.isEmpty()) {
            res.append("/");  // If stack is empty, it's the root
        } else {
            while (!s.isEmpty()) {
                res.insert(0, "/" + s.pop());
            }
        }

        return res.toString();
    }
}
