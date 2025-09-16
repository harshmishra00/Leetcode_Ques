class Solution(object):
    def defangIPaddr(self, address):
        keyword="."
        replacement="[.]"
        result=address.replace(keyword,replacement)
        return result