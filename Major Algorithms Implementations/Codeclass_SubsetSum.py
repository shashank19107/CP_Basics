def subsetSum(arr, i, target):
	print(i, " ", target)
	if(target<0 or i >= len(arr)):
		return False
	if(target==0 or arr[i]==target):
		return True
	return subsetSum(arr, i+1, target-arr[i]) or subsetSum(arr, i+1, target)

a = [1,2,3,4,5,6]
tar = 9
print(subsetSum(a,0,tar))
