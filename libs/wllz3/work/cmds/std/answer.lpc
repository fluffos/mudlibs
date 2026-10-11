// answer.c
// Design By robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj;
        string dest;

        if(me->ban_say()) return 0;
        if(!arg || arg == "")
                return notify_fail("指令格式：answer <信息>|answer <使用者id><信息>\n");

        if(sscanf(arg,"%s %s",dest,arg) == 2) {
                obj = present(dest, environment(me));
        }
        else {
                if(!objectp(dest = me->query_temp("pending/ask")))
                        return notify_fail("没人问你，你回答什么？\n");
                obj = present(dest, environment(me));
        }
        if(!obj)
                return notify_fail("你身边没有这个人或询问的对象已经离开。\n");

        message_vision(CYN"$N回答$n：『"HIG+ arg + NOR + CYN"』\n"NOR,me,obj);
        return 1;
}
int help(object me)
{
    write(@HELP

指令格式：answer <信息>

这个指令可以让你方便，直接的回答某个人的信息。

HELP
);
    return 1;
}

