class Solution(object):
    def lengthOfLastWord(self, s):
        letter=s.split()
        return len(letter[-1])
        