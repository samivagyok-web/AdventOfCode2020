answer = [ ]
j = 97
for i in range(26):
	answer.append(j)
	j = j + 1

freq = [ ]
for i in range(26):
	freq.append(0)

sum = 0
members = -1
with open("05_AoC.txt", "r") as f:	
	for line in f:
		members = members + 1
		ans = line
		for i in range(len(ans)):
			if not ord(ans[i]) == 10:
				freq[ord(ans[i]) - 97] = freq[ord(ans[i]) - 97] + 1

		if (line == '\n'):
			for value in freq:
				if value == members:
					sum = sum + 1
			members = -1
			for i in range(26):
				freq[i] = 0
	print(sum)