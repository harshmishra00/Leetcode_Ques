class Solution(object):
    def addBinary(self, a, b):
        decimal_a = int(a, 2)
        decimal_b = int(b, 2)

        sum_decimal = decimal_a + decimal_b

        return bin(sum_decimal)[2:]
        