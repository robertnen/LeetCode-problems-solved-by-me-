# Runtime: beats 82.33% of users with Python3
# Memory: beats 64.59% of users with Python3
# Daily problem (Streak 49)

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_t = {}
        t_s = {}

        for cS, cT in zip(s, t):
            if cS in s_t:
                if s_t[cS] != cT:
                    return False

            else:
                if cT in t_s:
                    return False

                s_t[cS] = cT
                t_s[cT] = cS

        return True