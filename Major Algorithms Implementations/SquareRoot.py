import decimal
t = int(input())
for i in range(t):
	n = int(input(""))
	beg = decimal.Decimal(0)
	end = decimal.Decimal(n)
	#print(abs(beg - end))
	while (abs(beg - end) > 0.0000000001):
		mid = decimal.Decimal((beg+end)/2)
		#print(mid)
		if( mid*mid > n):
			end = mid
		else:
			beg = mid
		 
		#print(ans," ",ans2)
	print((beg+end)/2)
