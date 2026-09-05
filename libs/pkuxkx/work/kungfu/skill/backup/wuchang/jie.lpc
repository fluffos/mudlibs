// 定住相关的人
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        if( !objectp(target) )
	        return notify_fail("定谁？\n");

        message_vision(HIR "$N飞起一脚，正中$n屁屁。\n\n"NOR,me, target );

        tell_object(target, HIR "你突然可以动了！\n" NOR);
        target->start_busy(0);
        return 1;
}
int exert(object me, object target)
{
        if( !objectp(target) )
                return notify_fail("定谁？\n");

        message_vision(HIR "$N飞起一脚，正中$n屁屁。\n\n"NOR,me, target );
        tell_object(target, HIR "你突然可以动了！\n" NOR);
        target->start_busy(0);
        return 1;
}
