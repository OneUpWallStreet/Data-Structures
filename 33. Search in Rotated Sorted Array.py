class Solution:
    def search(self, nums: List[int], target: int) -> int:
        

        def bs(l,r):

            if l <= r:

                mid = l + (r - l) //2

                if nums[mid] == target: return mid

                # Check if we are in left part of the array or right
                # We are in left
                if nums[l] <= nums[mid]:
                    # Target is greater then max value on left subarray
                    if target > nums[mid]: return bs(mid+1,r)
                    # Target is less then least value on left subarray
                    elif target < nums[l]: return bs(mid+1,r) 
                    # Target is present in left subarray
                    else: return bs(l,mid-1)
                # Else we are in right sorted portion
                else:
                    # If target is greater than max number on subarray 
                    if target > nums[r]: return bs(l,mid-1)
                    #  Target is less then middle, so we just look at left portion of subarray
                    elif target < nums[mid]: return bs(l,mid-1)
                    # Target is present in right portion of subarray
                    else: return bs(mid+1,r)
                    
            return -1
        
        return bs(0,len(nums)-1)