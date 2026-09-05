# -*- coding: cp936 -*-

#this robot act as a answerer
#it login to pkuxkx.net and get data from chat channel
#the answer is stored in sqlite and sent out with channel too

import pexpect
from pysqlite2 import dbapi2 as sqlite3
import time
import string
import re
import random
import traceback

trust_list = []
manager_list = ("yhzzyahoo","huacuozid","overflow")
advert_string = ["我是$ME$，有什么问题就问我吧。比如helpme ask 保卫襄阳。","我是$ME$，人称通天彻地美智囊，用helpme ask 问题，我给你解惑！","江湖中除了我，就属wiki有学问，尤其是 http://wiki.pkuxkx.com/，是每个新手都应该读的。"]
host="localhost 5555"    
username = "grobot"
password = "pkuxkx!@#123"

def publish_ad(client):
    global advert_string

    if random.randint(0,120) == 0:
        client.sendline("cemote "+ advert_string[random.randint(0,len(advert_string)-1)])
#    else:
#        if random.randint(0,120) == 0:
#            anounce_best_editor()
    
def anounce_best_editor():
    top3 = ""
    try:
        c.execute("select author,count(author) from faq group by author order by count(author) desc;")
        data = c.fetchall()
        data = data[:3]
        for row in data:
            name = row[0].encode('cp936')
            name = name.replace("(","")
            name = name.replace(")","")
            top3 = top3 + name+"，贡献"+str(row[1])+"条;"
        client.sendline("cemote 现在，大高手最佳编辑前三名的:"+top3+"他们是我们的榜样！")
    except Exception,inst:
        print "read best editor",inst

def read_userlist(c):
    global trust_list
    try:
        c.execute("select name from editor")
        data = c.fetchall()
        if len(data) > 0:
            trust_list = []
            for row in data:
                #print row[0]
                trust_list.append(row[0].encode('cp936'))
        else:
            trust_list = []
    except Exception,inst:
        print "read_userlist",inst
    print "read_userlist %d"%(len(trust_list))
           
        
def answer (row,client,name):
    result = row[1].encode("cp936").strip("\r\n")
    keywd = row[0].encode("cp936")
    author = row[2].encode("cp936")                                     
    
    cmd = "cemote $ME$告诉"+name+",$HIY$"+keywd+"$NOR$:$HIG$"+result+"$NOR$"
    if len(author) > 0:
        cmd = cmd + "$HIW$["+author+"提供]$NOR$"

    client.sendline(cmd)                  

def handle_other(line,client,c,db):    
    line = remove_color(line)
    restr = "[^\:]*\((.*)\)告诉你：(top10) ?(.*)\r\n"
    result = re.compile(restr).match(line)
    #print restr    
    if type(result) == type(None):
        #print "no match"
        return False
    #query the top 10 questions and return to user
    try:
        c.execute("select question from tobeanswer order by times desc limit 10")
    except Exception:
        return True
        
    cmd = "reply 目前被提问最多的十个问题是："
    for row in c:
        cmd = cmd + row[0].encode('cp936') + ","
    cmd += "谢谢。"      
      
    client.sendline(cmd)
    
def handle_ask(line,client,c,db):
    line = remove_color(line)
    result = re.compile(".*【求助】(.*)\(.+?\).*: ask (.+)\r\n").match(line)
            
    if type(result) == type(None):
        #print "no match:"+line
        return False
    question = result.group(2)
    question = string.strip(question,"\r\n")
    
    
    pos = string.find(question,chr(0x1b))
    if pos != -1:
        question = question[:pos]
    
    if len(question) < 3 or len(question) > 16:
        return True
    question = string.replace(question," ","")
    question = string.replace(question,".","")
    question = string.replace(question,"。","")                    
    question = string.replace(question,"㊣","")
    question = question.decode("cp936")
    name = result.group(1)
    name = remove_color(name)
    
    #print "query question 1"
    sql = "select question,answer,author from faq where question like '%"+question+"%';"
    
    try:
        c.execute(sql)
    except Exception, inst:
        print "query fail"
        print inst
        return True
    
    data = c.fetchall();
    if len(data) > 2:
        cmd = "cemote $ME$说，和"+question.encode("cp936")+"相关的问题有:"
        for row in data:                                        
            keywd = row[0].encode("cp936")
            cmd = cmd + keywd+","
        cmd = cmd + "不知道你想问哪个？"
        client.sendline(cmd)
        #print "query question 2"
        sql = "select question,answer,author from faq where question='"+question+"';"
        try:
            c.execute(sql)
        except Exception, inst:
            print "query fail"
            print inst
            return True
        data = c.fetchone()
        answer(data,client,name)
        return
    elif len(data) == 0:
        cmd = "cemote $ME$说，我居然不知道$HIY$"+question.encode("cp936")+"$NOR$，谁知道的请告诉我。tell grobot input "+question.encode("cp936")+"@@答案。"
        client.sendline(cmd)
        cmd = "cemote $ME$说，请向Yhzzyahoo或Overflow申请编辑权限。"
        client.sendline(cmd)
        
        c.execute("select times from tobeanswer where question='%s'"%(question))
        tobeanswer = c.fetchone()
        if type(tobeanswer) != type(None):
            times = int(tobeanswer[0]) + 1
        else:
            times = 1
        c.execute("replace into tobeanswer (question,times) values ('%s',%d)"%(question,times))
        db.commit()
        
    for row in data:
        answer(row,client,name)    
        
    return True
    
def handle_manage(line,client,c,db):
    
    line = remove_color(line)
    restr = "[^:]*\(("
    for id in manager_list:
        restr += id + "|"
    restr = restr[0:len(restr)-1]
    restr += ")\).*告诉你：(list|approve|refuse|delete|adduser|deluser|chauser) ?(.*)\r\n"
    try:         
        #print "match manager str"
        result = re.compile(restr).match(line)
        
        if type(result) == type(None):
            return False
               
        manager = remove_color(result.group(1))
        action = remove_color(result.group(2))
        number = remove_color(result.group(3)).strip()
        
        #print "==============",action
        if action == "list":
            #show all record in the prefaq table
            c.execute("select * from prefaq")
            count = 0
            cmd = "reply 待审核列表："
            client.sendline(cmd)
            for row in c:
                cmd = "reply "
                cmd += str(row[0]) + ":"+row[1].encode('cp936')+" "+row[2].encode('cp936') + "("+row[3].encode('cp936')+")"
                client.sendline(cmd)
                count += 1
                if count >= 5:            
                    time.sleep(1)
                    count = 0
        elif action == "approve":
            try:
                c.execute("select question,answer,author from prefaq where id="+number)
                data = c.fetchone()

                if len(data) == 3:
                    sql = "replace into faq (question,answer,author) values ('%s','%s','%s')"%data
                    c.execute(sql)
                   
                    sql = "delete from prefaq where id="+number
                    c.execute(sql)

                    sql = "delete from tobeanswer where question='"+data[0]+"'"
                    c.execute(sql)
                    
                    db.commit()
                    client.sendline("reply 审核"+data[0].encode('cp936')+"成功。")
            except Exception:
                client.sendline("reply 失败")
        elif action == "refuse":
            try:
                c.execute("delete from prefaq where id="+number)
                client.sendline("reply 拒绝第"+str(number)+"个词条成功。")
                db.commit()
            except Exception,inst:
                print inst
                client.sendline("reply 失败")
        elif action == "delete":
            try:
                question = number.decode('cp936')
                c.execute("delete from faq where question='"+question+"'")
                client.sendline("reply 删除"+number+"成功。")
                db.commit()
            except Exception,inst:
                print inst
                client.sendline("reply 失败")
        elif action == "adduser":
            if re.compile("[a-zA-z]+").match(number):
                c.execute("replace into editor (name,level) values ('%s',%d)"%(number.decode('cp936'),0))
                client.sendline("reply 添加用户"+number+"成功")                
                db.commit()
                read_userlist(c)
            else:
                client.sendline("reply 添加用户"+number+"失败。注意要输入ID。")                                
        elif action == "deluser":
            if re.compile("[a-zA-z]+").match(number):
                c.execute("delete from editor where name='%s'"%(number.decode('cp936')))
                client.sendline("reply 删除用户"+number+"成功")
                db.commit()
                read_userlist(c)
            else:
                client.sendline("reply 删除用户"+number+"失败。注意要输入ID。")                                
        elif action == "chauser":
            count = 0
            c.execute("select name from editor")
            cmd = "reply 授权用户名单："
            client.sendline(cmd)
            cmd = "reply "            
            for row in c:                
                cmd += row[0].encode('cp936') + ","
                count += 1
                if count >= 5: 
                    client.sendline(cmd)
                    time.sleep(1)
                    cmd = "reply " 
                    count = 0
                    
            if count > 0:                     
                client.sendline(cmd)
            
        else:
            client.sendline("reply 我们支持list,approve 序号,refuse 序号,delete 问题几条命令。详情请help grobot")   
    except Exception,inst:
        print "handle manage exception"
        print inst
        
    return True
    

def handle_input(line,client,c,db):    
    global trust_list
    line = remove_color(line)
    
    if len(trust_list) == 0:
        return False
        
    restr = "[^:]*\(("
    for id in trust_list:
        restr += id + "|"
    restr = restr[0:len(restr)-1]
    restr += ")\)告诉你：input (.+)@@(.+)\r\n"
    
    try:                
        #print "match for input"
        result = re.compile(restr).match(line)
        if type(result) == type(None):
            return False      
        author = remove_color(result.group(1))
        question = remove_color(result.group(2))
        answer = remove_color(result.group(3))  

        sql = u"replace into prefaq (question,answer,author) values ('%s','%s','%s')"%(question.decode('cp936'),answer.decode('cp936'),author.decode('cp936'))
        try:
            c.execute(sql)
            db.commit()
        except Exception,inst:
            print inst
        cmd = "reply 谢谢，你的输入已经进入候选问题库，稍后巫师将会人工审核。"
        client.sendline(cmd)
    except Exception,inst:
        print "handle input exception"
        print inst        

    return True        
    
        
        
def remove_color(arg):
    pos = string.find(arg,chr(0x1b))
    while pos != -1:
        pos2 = string.find(arg,'m',pos)
        if pos2 == -1:
            arg = string.replace(arg,chr(0x1b),"")
            break
        else:
            arg = arg[0:pos] + arg[pos2+1:]
            pos = string.find(arg,chr(0x1b))            
        
    return arg
    
if __name__ == "__main__":
    db = sqlite3.connect("./question.db")
    c = db.cursor()
    
    read_userlist(c)
    
    while True:
        try:
            client = pexpect.spawn("nc "+host)
            client.expect("您的英文名字")
            client.sendline(username)
            client.expect("请输入密码")
            client.sendline(password)
            client.sendline("y")
            client.sendline("MXP")
            time.sleep(5)
            while True:
                publish_ad(client)
                try:
                    line = client.readline()                    
                except pexpect.TIMEOUT:
                    print "timeout\r\n"
                    continue
								#print("line:"+line)
                if len(line) == 0:
                    client.terminate(True)
                    time.sleep(5)
                    break

                #print "handle_input"
                if handle_input(line,client,c,db):
                    continue
                #print "handle_manage"
                if handle_manage(line,client,c,db):
                    continue
                #print "handle_ask"                
                if handle_ask(line,client,c,db):
                    continue
                #print "handle_other"
                if handle_other(line,client,c,db):
                    continue                                    
        except KeyboardInterrupt:
            print "cancel"
            client.terminate(True)
            break
        except Exception, inst:
            traceback.print_exc()
            print " exception"
            client.terminate(True)
            time.sleep(15)                          
