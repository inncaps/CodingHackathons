
#python 3.x

#---Get one integer only
def getInt():

	while True:
	    try:
	        inp = int(input())
	    except ValueError:
	        print("Only integers allowed.")
	        continue
	    else:
	        break
	return inp

#---Get number of test cases and check limit
while True:
	_T = getInt()

	if _T <= 0 or _T > 100:
		print("Test cases cannot be less than 1 OR more than 100.")
	else:
		break

for i in range(1, _T + 1):

	#---Get Group number, Chocolate pcs and check limit
	while True:
		try:
			_N,_P = input().split()
			_N = int(_N)
			_P = int(_P)
		except ValueError:
			print("Only integers allowed.")
			continue
		if _N <= 0 or _N > 100:
			print("Group cannot be less than 1 OR more than 100.")
			continue
		if _P < 2 or _P > 3:
			print("Chocolate pcs cannot be less than 2 or more than 3.")
			continue
		else:
			break

	while True:
		_Gi = input().split()

		if len(_Gi) != _N:
			print("Does not match group number:", _N)
			continue
		try:
			for j in _Gi:
				num = int(j)
		except ValueError:
			print("Only integers allowed.")
			continue
		for j in _Gi:
			if num <= 0 or num > 100:
				print("Number of people in each group cannot be less than 1 OR more than 100")
				break
		else:
			break

	# print("No of Test Cases:", _T)
	# print("No of Groups:", _N)
	# print("No of Choc pcs:", _P)
	# print("No of people in Group:", _Gi)

	#--- y = The number of groups that will receive only fresh chocolate
	_y = 0

	#--- order = Order for group
	order = []

	#--- ordOther = Order for other
	orderOther = []

	for j in _Gi:
		num = int(j)
		if num % _P == 0:
			_y += 1
			order.append(num)
		else:
			orderOther.append(num)

	orderOther = sorted(orderOther, reverse=True)

	n = 0

	for j in orderOther:
		num = j
		if n > 0:
			num = j - (_P - n)
			if num <= 0:
				num = _P - n
		else:
			_y += 1

		ply = int(float(num)/float(_P))
		if ply <= 0:
			n = _P - num
		else:
			n = num - (ply * _P)
		order.append(j)

	print("Case #{}: {}".format(i, _y))
