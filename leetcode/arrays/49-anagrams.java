class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> um = new HashMap<>();
        List<List<String>> result = new ArrayList<>();

        for (String str : strs) {
            char[] schar = str.toCharArray();
            Arrays.sort(schar);

            String key = String.valueOf(schar);

            if (!um.containsKey(key)) {
                um.put(key, new ArrayList<>());
            }
            um.get(key).add(str);
        }

        for (List<String> s : um.values()) {
            result.add(s);
        }
        return result;
    }
}