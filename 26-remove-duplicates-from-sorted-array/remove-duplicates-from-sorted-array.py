class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:

        j = 0
        h = 1
        if len(nums)==1:
            return 1
        while h != (len(nums) ):

            if nums[j] == nums[h]:
                nums.pop(j)

            else:
                j+=1
                h+=1

        return len(nums)