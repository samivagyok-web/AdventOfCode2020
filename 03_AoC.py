import re

with open("03_AoC.txt", "r") as f:
	i = 0
	goodPassport = 0
	for line in f:
		pattern = re.compile(r'(byr:(19[2-8][0-9]|199[0-9]|200[0-2])|iyr:(201[0-9]|2020)|eyr:(202[0-9]|2030)|(hgt:((1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in)|hcl:#[A-Za-z0-9]{6}|ecl:(amb|blu|brn|gry|grn|hzl|oth)|pid:[0-9]{9}))')

		matches = pattern.finditer(line)

		for match in matches:
			print(match)
			i = i + 1

		if line == "\n":
			if (i == 7):
				goodPassport = goodPassport + 1

			i = 0

	print(f"{goodPassport} ervenyes utlevel van")