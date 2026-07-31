// home.c

#include "/doc/help.h"
#include  <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string msg,file1,file2,str;
        object body, ob;
        file1="/d/wizard/wizard_room.c";
        seteuid("Root");
        if(!arg || arg == geteuid(me)) {
        file2="/u/"+geteuid(me)+"/workroom.c";

        arg = 0;
}
else {
        ob = new(LOGIN_OB);
        ob->set("id",arg);
        if( !ob->restore() ) return notify_fail( "没有这个玩家。\n");
        file2="/u/"+arg+"/workroom.c";
     }

        if(file_size(file2) <=0)
        {
                if(arg) return notify_fail(ob->query("name")+"没有自己的工作室。\n");
                else if( !get_dir("/u/"+geteuid(me)+"/")  )
        {
        if(mkdir("/u/"+geteuid(me)))
        write(GRN "\n你的目录建在 /u 下。\n\n" NOR);
        else return notify_fail("建立目录失败！\n");
        }
        str=read_file(file1);
        str = replace_string(str,"NAME",this_player()->name());
        write_file(file2,str);
        }
        if(arg) message_vision("$N去"+ob->query("name")+"家做客了。\n\n",me);
//        else if( stringp(msg = me->query("env/msg_home")) )
//            message_vision(msg + "\n", me);
//        else message_vision("$N回家去了。\n\n",me);
        me->move(file2);
return 1;
}

int help(object me)
{
 write(@HELP
指令格式 : home 或 home <sb>

利用此一指令可直接回到自己的工作室或到有工作室的巫师家做客。
如果你有 'msg_home' 这个设定, 则在场的人都会看到那个讯息.
HELP
    );
    return 1;
}

