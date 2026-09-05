import os
import sys
import os.path
import re

words = file("words_data.txt","w+")

hash_word = {}

for root, dirs, files in os.walk(sys.argv[1]):	
	print "visit ",root
	if '.svn' in dirs:
		dirs.remove('.svn')  # don't visit .svn directories
	for f in files:		
		if os.path.splitext(f)[1] == ".o":
    		
			fd = file(root+"/"+f,"r")
			for line in fd.readlines():				
				line = line.replace(" ","")
				line = line.replace("\t","")
				line = line.replace("","")
				
				g = re.compile(".*,\"name\"\:\"(.+?)\",.*").match(line)
				if g <> None:
					if len(g.group(1)) <= 8 and g.group(1) not in hash_word:
						i = 0
						fail = False
						for c in g.group(1):
							if i%2 == 0 and (ord(c) < 176 or ord(c) > 248):
								fail = True;
								print "fail",g.group(1),ord(c),i
								break		
							i = i + 1
						if not fail:
							words.write(g.group(1)+"\n")
							hash_word[g.group(1)] = 1
			fd.close()
      
words.close()    				
    			
    				
