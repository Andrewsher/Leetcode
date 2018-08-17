class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def DecimaltoGray(x):
        	return x ^ (x >> 1)

        res = []

        for i in range(2 ** n):
        	res.append(DecimaltoGray(i))

        return res	
        
S = Solution()
print(S.grayCode(2))
