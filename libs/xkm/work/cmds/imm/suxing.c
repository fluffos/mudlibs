 
#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;
        if (!arg) return notify_fail("指令格式: suxing <living>\n");
        ob = present(arg, environment(me));
        if (!ob) return notify_fail("找不到这个生物。\n");
        message_vision(HIR + "天空中一道神光倏然而下罩住了$n，$n慢慢睁开眼睛,缓缓从地上爬起来！！\n"+ NOR,me,ob);
        ob -> revive();
        return 1;
}
 
int help(object me)
{
   write(@HELP

指令格式: suxing <id>
 
使某人立刻由昏迷不醒状态恢复

HELP
   );
   return 1;
}

