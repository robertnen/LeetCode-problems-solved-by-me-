from ast import List


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n is 1:
            return 1

        freq_in = (n + 1) * [0]
        freq_out = (n + 1) * [0]

        for subTrust in trust:
            freq_in[subTrust[1]] += 1
            freq_out[subTrust[0]] = 1

        for _ in range(1, n + 1):
            if freq_in[_] == n - 1 and freq_out[_] == 0:
                return _

        return -1
