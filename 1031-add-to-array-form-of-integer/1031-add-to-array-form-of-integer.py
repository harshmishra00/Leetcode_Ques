class Solution:
    def addToArrayForm(self, num, k):
        # convert array to integer
        x = int("".join(map(str, num)))
        # add k
        total = x + k
        # convert back to array of digits
        return [int(d) for d in str(total)]
