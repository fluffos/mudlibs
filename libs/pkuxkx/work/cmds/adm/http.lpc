//socket test h ttp
#include <net/socket.h>

string addrs;
string url;
int fail=0;

void close(int);
void write_s(int,string);

int main(object me,string arg)
{
        int fd,fc,fw;
        string addr,port;
        if(!arg) return 0;
        if(sscanf(arg,"%s %s %s",addr,port,url)!=3)
        {
                url="";
                if(sscanf(arg,"%s %s",addr,port)!=2)
                {
                        port="80";
                        addr=arg;
                }
        }
        write(addr+"\n");
        addrs=arg;
        if(fd=socket_create(STREAM,"read_callback")<0)
        {
                write("socket_create error "+fd+"\n");
                return 1;
        }
        if((fc=socket_connect(fd,arg,"read_callback","write_callback"))!= EESUCCESS)
        {
                close(fd);
                write("socket_connect error "+fc+"\n");
                return 1;
        }
        remove_call_out("write_s");
        call_out("write_s",2,fd,addr);
        remove_call_out("close");
        call_out("close",300,fd);
        return 1;       
}

void read_callback(int fd,mixed val)
{
        int fw;
        write(sprintf("Receive from %s for %O\n",addrs,val));
}

void write_callback(int fd)
{
        write("write callback\n");
}
void close(int fd)
{
        write(fd+" close!\n");
        socket_close(fd);
}

void write_s(int fd,string addr)
{
        int fw;
        write(addr+"\n");
        if((fw=socket_write(fd,"GET http://"+addr+url+"/index.html HTTP/1.0\r\n"+
        "accept: www/source; text/html; image/gif; image/jpeg; */*\r\n"+
        "User_Agent: myAgent\r\n\r\n"
        ))!=EESUCCESS)
        //if((fw=socket_write(fd,"http://www.jlu.edu.cn/XG/xg.htm HTTP/1.1\n"+
        //"accept: www/source; text/html; image/gif; image/jpeg; */*\n"+
        //"User_Agent: myAgent\n\n"
        //))!=EESUCCESS)
        //if((fw=socket_write(fd,"GET / HTTP/1.1"))!=EESUCCESS)
        {
                if(fail < 3)
                {
                fail++;
                remove_call_out("write_s");
                call_out("write_s",2,fd,addr);
                }
                else
                {
                        fail=0;
                        close(fd);
                }
        }
        else
        {
                write("socket_write sucess!\n");
        }
}

