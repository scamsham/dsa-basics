package leetcode.graphs;

public class Solution {
    public boolean dfsCycle(Map<Integer, List<Integer>> um, boolean[] visited, boolean[] recStack, int index){
        visited[index] = true;
        recStack[index] = true;

        List<Integer> children = um.get(index);

        if(children != null){
            for(int child: children){
                if(!visited[child]){
                    if(dfsCycle(um, visited, recStack, child)){
                        return true;
                    }
                }else if(recStack[child]){
                    return true;
                }
            }
        }

        recStack[index] = false;
        return false;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> um = new HashMap<>();
        boolean[] visited = new boolean[numCourses];
        boolean[] recStack = new boolean[numCourses];

        for(int[] prereq: prerequisites){
            int course = prereq[1];
            int nextCourse = prereq[0];

            if(!um.containsKey(course)){
                um.put(course, new ArrayList<Integer>());
            }

            um.get(course).add(nextCourse);
        }

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfsCycle(um, visited, recStack, i)){
                    return false;
                }
            }
        }

        return true;

    }
}{

}
