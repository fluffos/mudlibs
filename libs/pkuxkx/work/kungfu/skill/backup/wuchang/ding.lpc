// 定住相关的人
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        if( !objectp(target) )
	        return notify_fail("定谁？\n");

        message_vision(HIR "$N突然诡异的一笑，手指指向$n，\n\n"NOR,me, target );

	tell_object(target, HIR "你突然全身力，再也不能动了！\n" NOR);
        target->start_busy(600);
        return 1;
}
int exert(object me, object target)
{
        if( !objectp(target) )
                return notify_fail("定谁？\n");

        message_vision(HIR "$N突然诡异的一笑，手指指向$n，\n\n"NOR,me, target );
        tell_object(target, HIR "你突然全身乏力，再也不能动了！\n" NOR);
        target->start_busy(600);
        return 1;
}
