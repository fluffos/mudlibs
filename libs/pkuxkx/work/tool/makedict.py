f = file("fullme_words.txt","r")
f2= file("fullme_dict.txt","w+")
for line in f.readlines():
	line = line.replace("\n","")
	i = 0
	fail = False
	m1 = False
	for c in line:
		if i%2 == 0 and (ord(c) < 176 or ord(c) > 215):
			fail = True;
			print "fail",line,ord(c),i
			break
		elif i%2 == 0 :
			m1 = True
		elif i%2 == 1 and m1 and ord(c) == 245:
			fail = True
			break
		else:
			m1 = False
		i = i + 1
	if fail:
		continue
	while len(line) < 8:
		line = line + " "
	f2.write(line)

f.close()
f2.close()
