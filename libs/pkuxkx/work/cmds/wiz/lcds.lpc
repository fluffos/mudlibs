#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{       mixed *cmds;
        object ob;
        int i;
        mapping my;
        seteuid(getuid(me));
        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁所在的环境提供以下指令？\n");
        } else
                return notify_fail("只有巫师能察看别人的状态。\n");
         
        cmds = ob->query_commands();
        write("该人物身上及四周的物品与所在的环境提供以下指令：\n");
        for(i = 0; i<sizeof(cmds); i++) {
                if( cmds[i][2]==me ) continue;
                printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
        }
        return 1;
}
 

int help(object me)
{
        write(@HELP
指令格式 : lcds
           lcds <对象名称>           (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)周围的指令。
 
see also : full
HELP
    );
    return 1;
} 
