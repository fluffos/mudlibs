// shengang.c 混天气功混天神罡

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

 string query_name() { return "大闪避术"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	object weapon;  
	string msg;
	int skill;

		if ((int)me->query_temp("shan"))
                return notify_fail("你已经运起大闪避术了。\n");
		if ((int)me->query_skill("liujiu-xinjing", 1) < 150)
                return notify_fail("你的六九心经等级不够，难以施展大闪避术。\n");

        if ((int)me->query_dex() < 32)
                return notify_fail("你的身法不够，难以施展大闪避术。\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("你的内功火候不够，难以施展大闪避术。\n");

        if ((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("你的轻功修为不够，难以施展大闪避术。\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不够，难以施展大闪避术。\n");

        if ((int)me->query("neili") < 250)
                return notify_fail("你此时的内力不足，难以施展大闪避术。\n");

        msg = HIY "$N" HIY "一声清啸，身形一展，舞步宛如行云流水、道文飞"
              "扬，身法飞速提升。\n\n" NOR;

		skill = (int)me->query_skill("dodge", 1)*2;

		me->add_temp("dex", skill);
        me->set_temp("shan", 1);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);
	me->add("neili", -150);

	message_combatd(msg, me);
	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("shan"))
	{
		 me->add_temp("dex", -amount);
                me->delete_temp("shan");
                tell_object(me, "你的大闪避术运行完毕，将内力收回丹田。\n");
	}
}
