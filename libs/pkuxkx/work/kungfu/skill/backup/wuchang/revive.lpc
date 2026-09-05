// 定住相关的人
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        if( !objectp(target) )
	        return notify_fail("定谁？\n");

        message_vision(HIR "$N在$n的耳边大叫：“快醒醒！象猪一样睡觉会着凉的！！！，\n\n"NOR,me, target );

        tell_object(target, HIR "你突然可以动了！\n" NOR);
        target->start_busy(0);
        target->revive();
        return 1;
}
int exert(object me, object target)
{
        if( !objectp(target) )
                return notify_fail("定谁？\n");

        message_vision(HIR "$N在$n的耳边大叫：“快醒醒！象猪一样睡觉会着凉的！！！，\n\n"NOR,me, target );
        tell_object(target, HIR "你突然可以动了！\n" NOR);
        target->start_busy(0);
        target->revive();
        return 1;
}
