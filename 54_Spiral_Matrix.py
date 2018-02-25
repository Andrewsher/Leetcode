class Solution:
    def spiralOrder(self, matrix):
        """

        :param matrix: List[List[int]]
        :return: List[int]
        """
        result = []
        if len(matrix) == 0:
            return result
        if len(matrix[0]) == 0:
            return result
        leftedge = 0
        rightedge = len(matrix[0]) - 1
        upedge = 0
        downedge = len(matrix) - 1

        while True:
            # 在最顶一行
            for j in range(leftedge, rightedge + 1, 1):
                result.append(matrix[upedge][j])
            upedge += 1
            if upedge > downedge:
                break

            # 在最右边一列
            for i in range(upedge, downedge + 1, 1):
                result.append(matrix[i][rightedge])
            rightedge -= 1
            if rightedge < leftedge:
                break

            # 在最底一行
            for j in range(rightedge, leftedge - 1, -1):
                result.append(matrix[downedge][j])
            downedge -= 1
            if downedge < upedge:
                break

            # 在最左边一列
            for i in range(downedge, upedge - 1, -1):
                result.append(matrix[i][leftedge])
            leftedge += 1
            if leftedge > rightedge:
                break

        return result

A = Solution()
x = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(A.spiralOrder(x))
