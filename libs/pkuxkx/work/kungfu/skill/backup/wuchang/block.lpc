// 定住相关的人
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        if( !objectp(target) )
	        return notify_fail("定谁？\n");

        message_vision(HIR "$N忽然诡异的一笑，蒙上了$n的眼睛。\n\n"NOR,me, target );

        tell_object(target, HIR "你突然什么都看不见了！\n" NOR);
        target->start_busy(0);
        target->set_temp("block_msg/all",1);
        return 1;
}
int exert(object me, object target)
{
        if( !objectp(target) )
                return notify_fail("定谁？\n");

        message_vision(HIR "$N忽然诡异的一笑，蒙上了$n的眼睛。\n\n"NOR,me, target );
        tell_object(target, HIR "你突然什么都看不见了！\n" NOR);
        target->start_busy(0);
        target->set_temp("block_msg/all",1);
        return 1;
}
