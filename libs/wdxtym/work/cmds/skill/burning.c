// burning.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(ROOT_UID);
}

int main(object me, string arg)
{
	int count;

	if (me->query_temp("burning"))
		return notify_fail("你现在正在怒火中，没有必要再发作一次。\n");

	if (me->query_craze() < 1000)
		return notify_fail("你现在还不够愤怒，无法让自己怒火燃烧。\n");

	message_vision(HIR "$N" HIR "一声大吼，两目登时精光四射，咄咄逼人，势不可挡。"NOR"\n", me);

	me->cost_craze(500 + random(300));
	count = me->query_skill("force") / 5;
	me->add_temp("apply/attack", count);
	me->set_temp("burning", 1);
	me->start_call_out(bind((: call_other, __FILE__, "remove_effect", me, count :), me),
			   1 + me->query_skill("force", 1) + random(100));

	return 1;
}

void remove_effect(object me, int count)
{
	if (me->query_temp("burning"))
	{
		me->delete_temp("burning");
		me->add_temp("apply/attack", -count);
		tell_object(me, "你心中的愤怒渐渐的平息了。\n");
	}
}

int help (object me)
{
	write(@HELP
指令格式: burning|fenu
 
这个指令让你将现在将积蓄的愤怒发泄出来，这样可以充分的提升你
的攻击能力。在发泄时会消耗你大量的愤怒。

see also : berserk
HELP );
	return 1;
}
