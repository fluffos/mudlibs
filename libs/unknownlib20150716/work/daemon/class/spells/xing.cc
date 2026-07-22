// xing.c
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{	
	object zhenshen;
	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要救醒谁？\n");
	
	if(living(target) ) return notify_fail("对方还活着，用不着你救！\n");
	if(me->query("rulaitask/guai")!=target)
	return notify_fail("苏醒暂时只能对如来妖使用！\n");
	if ( me->is_fight() )
		return notify_fail("你还在战斗，干这种事就死定啦！\n");
	
	if ( me->is_ghost() )
		return notify_fail("你已经是鬼了，还要干什么？\n");

	if( (int)me->query("max_mana") <2000 )
		return notify_fail("你的法力不够！\n");
	
	if( (int)me->query("daoxing") < 30000 )
		return notify_fail("你的道行不够，恐怕很难把人救醒。\n");
	
	if( (int)me->query("mana") - (int)me->query("max_mana") < 200)
		return notify_fail("你的法力不足！\n");

	me->receive_damage("sen", 30);
	me->add("mana", -200);

	if( (int)me->query_skill("spells", 1) - 30 < 10 ) {
		write("你失败了！\n");
                return 1;
        }

	message_vision("$N大叫一声：小宝贝，起床了。\n", me);
	target->revive();
	me->start_busy(2);	
  	return 1;
}
int help(object me)
{
write(@HELP
指令格式 : cast xing
 
这个指令可以把正在昏迷的人救醒。


HELP
    );
    return 1;
}
