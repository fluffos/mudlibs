// finger.c
#include <ansi.h>
inherit F_CLEAN_UP;

inherit F_MORE;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if( !arg ) {
    if (time()-me->query_temp("scan_time") < 5 && !wizardp(me))
                return notify_fail("不要频繁的查询，谢谢！\n");
    me->set_temp("scan_time",time());
		if( (int)me->query("jing") < 50 )
			return notify_fail("你的精神无法集中。\n");
                if(me->is_busy() )
                        return notify_fail("你正忙着呢。\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 50);
                if (wizardp(me))
                    start_more( FINGER_D->finger_all() );
                else
                        write( FINGER_D->finger_all() );
	} else {
		if( (int)me->query("jing") < 15 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) )
                        me->receive_damage("jing", 15);
    if(wizardp(me) && arg=="-ip")
    write( FINGER_D->finger_ip());
    else                        
		write( FINGER_D->finger_user(arg) );
	}
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : finger [使用者姓名]
 
这个指令, 如果没有指定使用者姓明, 会显示出所有正在线上玩家
的连线资料. 反之, 则可显示有关某个玩家的连线, 权限等资料.
 
see also : who
HELP
    );
    return 1;
}
 
