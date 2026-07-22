//cmaild.c
#include <login.h>

int check_mail(object user)
{
        string *maillist ,username,euid;
        int i,flag;

        euid=geteuid(user);
        flag=0;
        maillist=explode(read_file(CHECK_MAIL),"\n");
        for(i=0;i<sizeof(maillist);i++){
        if(maillist[i][0]=='#'
        || sscanf(maillist[i],"%s",username)!=1) continue;
        else
        if(euid==maillist[i]) flag=1;
        }
        return flag;
}
void add_mail(string arg)
{
        string  *maillist, userlist;
        int i;

        userlist="";
        maillist=explode(read_file(CHECK_MAIL),"\n");
        for(i=0;i<sizeof(maillist);i++){
        if(arg==maillist[i]) return ;
        userlist+=maillist[i]+"\n";
        }
        userlist+=arg+"\n";
        rm(CHECK_MAIL);
        write_file(CHECK_MAIL, userlist);
        return ;
}
void del_mail(object user)
{
        string *maillist,userlist,euid;
        int i,stat;

        userlist="";
        euid=geteuid(user);
        maillist=explode(read_file(CHECK_MAIL),"\n");
        for(i=0;i<sizeof(maillist);i++){
        if(euid!=maillist[i])
                userlist+=maillist[i]+"\n";
        }
        rm(CHECK_MAIL);
        write_file(CHECK_MAIL, userlist);
        return ;
}
