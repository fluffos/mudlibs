from pysqlite2 import dbapi2 as sqlite3
import string

if __name__ == "__main__":

    db = sqlite3.connect("./question.db")

    c = db.cursor()

    c.execute("update faq set author='maper,zhaoxing' where author='zhaoxing'")


    db.commit()

    c.close()
    db.close()

