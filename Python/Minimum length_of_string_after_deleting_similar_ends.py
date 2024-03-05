# Runtime: beats 97.63% of users with Python3
# Memory: beats 75.83% of users with Python3
# Daily problem (Streak 21)

class Solution:
    def minimumLength(self, s: str) -> int:
        start = 0
        end = len(s) - 1

        while start < end and s[start] == s[end]:
            c = s[start]

            while c == s[end] and start <= end:
                end = end - 1

            while c == s[start] and start <= end:
                start = start + 1


        return end - start + 1
