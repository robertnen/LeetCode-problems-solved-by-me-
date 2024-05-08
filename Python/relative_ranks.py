from ast import List

# Runtime: beats 91.13% of users with Python3
# Memory: beats 34.29% of users with Python3
# Daily problem (Streak 85)

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        scores = {score[i] : i for i in range(len(score))}
        score.sort(reverse=True)

        ans = ["" for _ in range(len(score))]

        for i in range(3, len(score)):
            ans[scores[score[i]]] = str(i + 1)

        ans[scores[score[0]]] = "Gold Medal"

        if len(score) > 1:
            ans[scores[score[1]]] = "Silver Medal"

        if len(score) > 2:
            ans[scores[score[2]]] = "Bronze Medal"

        return ans