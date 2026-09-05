// unexpell.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob;
        string *skname;
        mapping skills;
        int i;

        if( !arg || !ob = present(arg, environment(me)) )
                return notify_fail("你要将谁恢复数据？\n");

        if( !ob->is_character() )
                return notify_fail("你也不看看它是什么东西。\n");

        if( !userp(ob) )
                return notify_fail("你只能恢复玩家所扮演的人物。\n");

        ob->add("betrayer",-1);

        skills = ob->query_skills();

        if( mapp(skills) ) {
                skname = keys(skills);
                for(i=0; i<sizeof(skname); i++)
                        skills[skname[i]] *= 2;
        }

        log_file("wiz/unexpell",ob->name()+"恢复开除记录一次，时间："+ctime(time())+"\n"+"执行人："+getuid(me)+"\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : unexpell<某人>
 
这个指令可以让你恢复相关人的数据。去除判师记录，武功加一倍。
 
HELP
        );
        return 1;
}
