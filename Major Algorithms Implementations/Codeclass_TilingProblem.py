def CalculateTiles(i):
	#Sanity Check
	if(i<1):
		return 0
	#Base cases
	if(i==1 or i==2):
		return i
	return CalculateTiles(i-1) + 2*CalculateTiles(i-2)

size = 4		# 4X2 tile
print(CalculateTiles(4))