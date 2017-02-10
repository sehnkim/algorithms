def find(d, y, x, size):
	if len(d) == 1:
		return d

	str = ['','','','', '']
	if d[0] == 'x':
		step = 0
		for i in range(1, 5):
			if d[i + step] == 'x':
				str[i] += find(d[(i+step):])
				step += len(str[i])
				step -= 1
			else:
				str[i] += d[i + step]
		return d[0] + str[3] + str[4] + str[1] + str[2]


#print find('xbwxwbbwb')
print find('xxwwwbxwxbbbwwxxxwwbbbwwwwbb')



