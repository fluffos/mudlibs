#include <ansi.h>
#include <dbase.h>

inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object obj, *skll;
        int i;
        mapping skl;

        if(!arg) return notify_fail("你要恢复谁的数据?\n");
        obj = present(arg, environment(me));
        if(!obj) obj = present(arg, me);
        if(!obj) obj = find_player(arg);
        if(!obj) return notify_fail("找不到指定的人。\n");
        obj->clear_condition();
        obj->set("shen", 10*(int)obj->query("shen") /9);
        obj->set("combat_exp", 50*(int)obj->query("combat_exp") / 49);
        obj->add("potential",random(100));

        skl=obj->query_skills();
        skll=keys(skl);
        for (i=0;i<sizeof(skll);i++)
        skl[skll[i]]++; 
        write_file("/log/static/RESTORE_PLAYER",sprintf("%s(%s) restored by %s(%s) on %s\n",
                obj->name(1), obj->query("id"),
                this_player()->name(1),this_player()->query("id"),ctime(time()) ));
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : restoredata username 
 
用于恢复玩家数据。慎用！
 
HELP
    );
    return 1;
}
