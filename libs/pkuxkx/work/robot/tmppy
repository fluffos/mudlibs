from pysqlite2 import dbapi2 as sqlite3
import string

if __name__ == "__main__":

    db = sqlite3.connect("./question2.db")

    c = db.cursor()
    f = file("wupin.txt")
    for row in f.readlines():               
        try:
            c.execute(row)
        except Exception:
            continue

    f = file("npc.txt")
    for row in f.readlines():               
        try:
            c.execute(row)
        except Exception:
            continue


    db.commit()

    c.close()
    db.close()

