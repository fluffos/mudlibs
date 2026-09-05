inherit F_CLEAN_UP;

#include <ansi.h>

#define EMAIL_LIST "/data/email_list"

int main(object me,string arg)
{
        string username,server,file,name,email,*tmp=({});
        if(!arg||sscanf(arg,"%s@%s",username,server)!=2)
                return notify_fail("指令格式：register Email address(xxx@xxx.xxx....)\n");
        if(sizeof(file=read_file(EMAIL_LIST))<=0)
        {
                write_file(EMAIL_LIST,me->query("id")+":"+arg,1);
                return 1;
        }
        else
        {
                //write(file);
                tmp=explode(file,"\n");
                for(int i=0;i<sizeof(tmp);i++)
                {
                        if(sscanf(tmp[i],"%s:%s",name,email)!=2)
                        {
                                tmp-=({tmp[i]});
                                continue;
                        }
                        else
                        {
                                if(name==me->query("id"))
                                tmp-=({tmp[i]});
                        }
                        
                }
        tmp+=({me->query("id")+":"+arg});
        file=implode(tmp,"\n");
        file+="\n";
        write_file(EMAIL_LIST,file,1);
        write("你注册的Email为"+arg+"\n");
        return 1;
}
        return notify_fail("指令格式：register Email address(xxx@xxx.xxx....)\n");
                                
}

