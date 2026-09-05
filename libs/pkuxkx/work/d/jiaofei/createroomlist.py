import os
import string

#python createroomlist.py > tmp.txt

for filename in os.listdir("."):
    
        if string.find(filename,".c") == len(filename) - 2:
            f = file(filename)
            if f <> None:
                for line in f.readlines():
                    if string.find(line,"inherit __DIR__\"jiaofeiroom.c\";") <> -1:
                        print "/d/jiaofei/"+filename

