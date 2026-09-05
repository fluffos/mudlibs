from pysqlite2 import dbapi2 as sqlite3
import string

if __name__ == "__main__":

    db1 = sqlite3.connect("./question.db")
    c1 = db1.cursor()

    c.execute("create table faq (id INTEGER PRIMARY KEY AUTOINCREMENT,question varchar(64),answer varchar(2048),author varchar(128));")
    c.execute("create unique index question on faq (question);")

    c.execute("create table prefaq (id INTEGER PRIMARY KEY AUTOINCREMENT,question varchar(64),answer varchar(2048),author varchar(128));")
    c.execute("create unique index prequestion on prefaq (question);")

    c1.execute("create table editor (id INTEGER primary key AUTOINCREMENT,name vharchar(128),level INTEGER)")
    c1.execute("create unique index editor_name on editor (name)")
    
    c1.execute("create table tobeanswer (id INTEGER primary key AUTOINCREMENT,question vharchar(64),times INTEGER)")
    c1.execute("create unique index tobeanswer_question on tobeanswer (question)")