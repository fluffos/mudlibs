from pysqlite2 import dbapi2 as sqlite3
import string
import sys

db = sqlite3.connect("./question.db")
c = db.cursor()
c.execute("select question,answer,author from faq where question like '%"+sys.argv[1].decode('cp936')+"%';")
for row in c:                                        
    result = row[1].encode("cp936").strip("\r\n")
    keywd = row[0].encode("cp936")
    author = row[2].encode("cp936")                                     
                    
    print "1",keywd
    print "2",result
    print "3",author

