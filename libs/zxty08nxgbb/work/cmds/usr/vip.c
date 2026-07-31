#include "/doc/help.h"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string msg;


        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");
        if (me->is_fighting()) return 0;
        if (me->is_ghost()) return 0;

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

天涯VIP详细说明,请查看以下网址：
http://www.jhfymud.cn/redirect.php?tid=470&goto=lastpost#lastpost
HELP
    );
    return 1;
}

