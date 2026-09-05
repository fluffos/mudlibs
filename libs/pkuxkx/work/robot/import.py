from pysqlite2 import dbapi2 as sqlite3
import string

if __name__ == "__main__":

    db1 = sqlite3.connect("./question.db")
    c1 = db1.cursor()

    db = sqlite3.connect("./question2.db")
    c = db.cursor()
    c.execute("create table faq (id INTEGER PRIMARY KEY AUTOINCREMENT,question varchar(64),answer varchar(2048),author varchar(128));")
    c.execute("create unique index question on faq (question);")

    c.execute("create table prefaq (id INTEGER PRIMARY KEY AUTOINCREMENT,question varchar(64),answer varchar(2048),author varchar(128));")
    c.execute("create unique index prequestion on prefaq (question);")


    c1.execute("select question,answer,author from faq")
    for row in c1:               
        question = row[0]
        answer = row[1]
        author = row[2]
        sql = "insert into faq (question,answer,author) values ('%s','%s','%s')"%(question,answer,author)
        try:
            c.execute(sql)
        except Exception:
            continue


    db.commit()

    c.close()
    db.close()

    c1.close()
    db1.close()
