import os
import sys
import os.path
import re

words = file("words.txt","w+")

hash_word = {}

for root, dirs, files in os.walk(sys.argv[1]):	
	print "visit ",root
	if '.svn' in dirs:
		dirs.remove('.svn')  # don't visit .svn directories
	for f in files:		
		if os.path.splitext(f)[1] == ".c":
			print "open ",root+"/"+f
    		
			fd = file(root+"/"+f,"r")
			for line in fd.readlines():				
				line = line.replace(" ","")
				line = line.replace("\t","")
				line = line.replace("","")
				
				g = re.compile("set\(\"short\",.*?\"(.+)\".*?\)").match(line)
				if g <> None:
					print g.group(1)
					if len(g.group(1)) <= 8 and g.group(1) not in hash_word:
						words.write(g.group(1)+"\n")
						hash_word[g.group(1)] = 1
				else:					
					g = re.compile("set_name\(.*?\"(.+)\".*?,\(\{.+\}\)\)").match(line)
					if g <> None:
						print g.group(1)
						if len(g.group(1)) <= 8 and g.group(1) not in hash_word:
							words.write(g.group(1)+"\n")
							hash_word[g.group(1)] = 1
					else:					
						g = re.compile("set\(\"name\",.*?\"(.+)\".*?\)").match(line)
						if g <> None:
							print g.group(1)
							if len(g.group(1)) <= 8 and g.group(1) not in hash_word:
								words.write(g.group(1)+"\n")
								hash_word[g.group(1)] = 1
words.close()    				
    			
    				
