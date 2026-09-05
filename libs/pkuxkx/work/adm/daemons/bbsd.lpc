 //bbsd
//auto login bbs site and post
//Made by jason@pkuxkx 2001-10-9

//config file format

/****************************************************
site number:2
[smth.org]
bbs\npkuxkx\nxkxukp\nqqqqqq\nsmud\n\n
[ytht.net]
pkuxkx\npkuxkx\nqqqqqq\nsmud\n\n
****************************************************/

#include <net/socket.h>

#define CONFIG_FILE     "/adm/etc/bbsd.cfg"
#define CTRL_P  ""
#define CTRL_W  ""


inherit F_SAVE;

int debug=0;

int configUpdateTime;
int siteNumber;
mapping siteList=([]);

nosave int lineNum=0;
nosave int initOk=0;
nosave int siteNo=0;
nosave string *cfgLines=({});
nosave string fileStr="";
nosave string myTitle="";

string nextLine();
int filterCfgLines(string);
void close(int);
int connectSite();
int login_bbs(int fd);

//initialize,check config file
void create() {
        string configStr;
        string siteAddr,loginCmd;
        
        if((stat(CONFIG_FILE))[1] > configUpdateTime || !restore()) {
                lineNum=0;
                if(file_size(CONFIG_FILE) < 0) {
                        write("bbsd.cfg not exists!\n");
                        return;
                }
                //load config file
                if(!stringp(configStr=read_file(CONFIG_FILE))) {
                        write("bbsd.cfg read error!\n");
                        return;
                }
                cfgLines=explode(configStr,"\n");
                //filter comment lines and blank lines
                cfgLines=filter_array(cfgLines,"filterCfgLines",this_object());
                if(!arrayp(cfgLines) || sizeof(cfgLines) < 0) {
                        write("bbsd.cfg read error!\n");
                        return;
                }
                if(sscanf(cfgLines[0],"site number:%d",siteNumber)!=1 || siteNumber < 0) {
                        write("bad site number!\n");
                        return;
                }
                for(int i=0;i<siteNumber;i++) {
                        if(sscanf(nextLine(),"[%s]",siteAddr)!=1) {
                                write("cannt read siteAddr info!\n");
                                siteList=([]);
                                return;
                        }
                        loginCmd=nextLine();
                        if(!stringp(loginCmd) || loginCmd=="") {
                                write("cannt read loginCmd info!\n");
                                siteList=([]);
                                return;                 
                        }
                        siteList[siteAddr]=loginCmd;
                }
                initOk=1;
                write("bbsd initialize success at "+ctime(time())+"!\n");       
                save();
        }
}

string nextLine() {
        string o;
        if(!arrayp(cfgLines) 
        || sizeof(cfgLines) < 0 
        || lineNum > sizeof(cfgLines)-1) 
                o="";
        o=cfgLines[++lineNum];
        return o;
}

int filterCfgLines(string line) {
        int nflag=0;
        for(int i=0;i<sizeof(line);i++) {
                if(line[i..i]==" ") 
                        continue;
                if(line[i..i]=="#") 
                        return 0;
                else {
                        nflag=1;
                        break;
                }
        }
        if(!nflag) return 0;
        return 1;
}

string query_save_file() {
        return "/data/bbsd"; 
}

int doPost(int confirm,string postFile,string title) {
      if(base_name(previous_object())!="/cmds/arch/postbbs") return 0;
        if(!confirm || !initOk) return -1;
        if(!stringp(postFile) || file_size(postFile) < 0 || !fileStr=read_file(postFile)) return -2;
        if(!mapp(siteList) || siteNumber != sizeof(siteList) || siteNumber < 0) return -3;
        if(!title||title==""||sizeof(title)>24) return -4;
        myTitle=title;
        connectSite();
        return 1;
}

void read_callback(int fd,mixed val) {
        object me;
        if(debug) {
                if(objectp(me=find_player("jason")))
                      tell_object(me,sprintf("%O\n",val));
        }
}

void write_callback(int fd) {
        
}

void close(int fd) {
        object me;
        if(debug) {
                if(objectp(me=find_player("jason")))
                        tell_object(me,"close "+fd+"\n");
        }
        call_out("close_s",20,fd);
}

void close_s(int fd) {
        socket_close(fd);
}


int connectSite() {
        string *site=({});
        int fd,fc,fw;
        string ip,port;
        site=keys(siteList);
        
        if(siteNo > siteNumber-1) {
                siteNo=0;
                return -1;
        }
        if((fd=socket_create(STREAM,"read_callback"))<0) {
                write("socket_create error "+fd+"\n");
                return -2;
        }
        write(site[siteNo]+"\n");
        if(sscanf(site[siteNo],"%s %s",ip,port)!=2) {
                port="23";
                ip=site[siteNo];
        }
        if((fc=socket_connect(fd,ip+" "+port,"read_callback","write_callback"))!= EESUCCESS) {
                close(fd);
                write("socket_connect error "+fc+"\n");
                return -3;
        }
        remove_call_out("login_bbs");
        call_out("login_bbs",10,fd);
}

int login_bbs(int fd) {
        int fw;
        string *login=({});
        string loginCmd="";
        string nchar=" ";
        login=values(siteList);
        loginCmd=login[siteNo];
        for(int i=0;i<sizeof(loginCmd);i++) {
                if(loginCmd[i..i]=="\\") { //special control character
                        i++;
                        if(i >= sizeof(loginCmd)) break;
                        if(loginCmd[i..i]=="n" || loginCmd[i..i]=="N") { //enter
        
                                nchar[0]=10;
                                socket_write(fd,nchar); 
                                write(nchar);
                                continue;
                        }
                        else if(loginCmd[i..i]=="^") { //ctrl
                                i++;
                                if(i >= sizeof(loginCmd)) break;
                                nchar[0]=loginCmd[i] & 037;
                                socket_write(fd,nchar);
                                write(nchar);
                                continue;
                        }
                }
                socket_write(fd,loginCmd[i..i]);
                write(loginCmd[i..i]);
        }
        
        
        //post article
        
        //ctrl+P
        socket_write(fd,CTRL_P);
        socket_write(fd,"【北大侠客行】-"+myTitle+"\n\n");
        socket_write(fd,fileStr);
        socket_write(fd,CTRL_W);
        socket_write(fd,"L\n");
        write("write success!\n");
        siteNo++;
        close(fd);
        remove_call_out("connectSite");
        call_out("connectSite",2);
        return 1;
}

int turnDebug(int flag)
{
        return debug=flag>0?1:0;
}
