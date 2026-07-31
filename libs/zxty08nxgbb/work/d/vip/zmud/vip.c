#include "/doc/help.h"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string msg;

        if( !me->query("vip") )
                return notify_fail("你不是VIP。\n");
        if( stringp(msg = me->query("env/msg_home")) )
                message_vision(msg + "\n", me);
        me->move("/d/vip/" + geteuid(me) + "/room.c");
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : vip

HELP
    );
    return 1;
}
