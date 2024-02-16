import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Runtime: beats 77.04% of users with Java
 * Memory: beats 23.08% of users with Java
 * Daily problem (Streak 3)
*/

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> m = new HashMap<>();
        for(int n : arr)
            m.put(n, m.getOrDefault(n, 0) + 1);

        List<Integer> cnt = new ArrayList<>(m.values());
        Collections.sort(cnt);

        for(int i = 0; i < cnt.size(); i++) {
            k -= cnt.get(i);
            if(k < 0) return cnt.size() - i;
        }

        return 0;
    }
}