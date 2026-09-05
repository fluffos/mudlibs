// yizhaoyun.c 一招晕类处理
// labaz added 2013/05/26
#include <ansi.h>

varargs void yizhaoyun(object target, object killer, int no_wait)
{
    int wait;
    wait = random(5);

    if (!living(target)) return;
	if (target->query("no_yizhaoyun"))
	{
		return notify_fail("你的绝招对此目标无效。\n");
	}
    if (no_wait || !wait)
    {
        target->receive_damage("qi", 0, killer);
        target->unconcious();
    }
    else
    {
        message_vision(NOR"\n\n$n"+NOR+HIR+"遭到"+NOR+"$N"+NOR+HIR+"的重创，意识渐渐模糊起来，随时都会昏迷。。。。。。\n\n"NOR, killer, target);
        if (intp(target->query_busy()) && target->query_busy()<=wait+1) target->start_busy(wait+1);
        call_out("call_unconcious", wait, target, killer);
    }
}

void call_unconcious(object target, object killer)
{
    if (!objectp(target) || !living(target) || target->is_ghost()) return;

    target->receive_damage("qi", 0, killer);
    target->unconcious();
}
