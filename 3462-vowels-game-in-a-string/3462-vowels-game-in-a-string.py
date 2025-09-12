class Solution:
    def doesAliceWin(self, s):
        for c in s:
            if c in 'aeiou':
                return True
        return False
