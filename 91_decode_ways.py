'''
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
'''

class Solution:
	def decode(self, a: str, b: str) -> int:
		if int(a) == 1:
			return 1
		elif int(a) == 2 and int(b) <= 6:
			return 1
		else:
			return 0

	def decode_single(self, a: str) -> int:
		if int(a) > 0:
			return 1
		else:
			return 0

	def numDecodings(self, s: str) ->int:
		if int(s[0]) == 0:
			return 0
		if len(s) == 1:
			return self.decode_single(s)
		elif len(s) == 2:
			return self.decode(s[0], s[1]) + self.decode_single(s[0]) * self.decode_single(s[1])
		else:
			res = [0 for _ in range(len(s))]
			res[-1] = self.decode_single(s[-1])
			res[-2] = self.decode(s[-2], s[-1]) + self.decode_single(s[-2]) * self.decode_single(s[-1])
			for i in range(-3, -len(s)-1, -1):
				res[i] = self.decode_single(s[i]) * res[i+1] + self.decode(s[i], s[i+1]) * res[i+2]
			return res[0]



if __name__ == '__main__':
	S = Solution()
	print(S.numDecodings('125222353122012'))
