// xishui.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

string query_name() { return "吸髓"ZJBR"大法"; }

int exert(object me, object target)
{
	int ap;
	int dp;
	int damage;
	string msg;

	if (target == me || ! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
                return notify_fail("「吸髓大法」只能在战斗中用在对手身上。\n");

	if (me->query_skill("huaxue-dafa", 1) < 100)
                return notify_fail("你的化血大法不够纯熟, 不能使用「吸髓大法」！\n");


	if ((int)me->query("neili") < 1000)
		return notify_fail("你的内力不够！");


	 msg = HIC "$N气贯丹田，顿时脸上一片紫青，双掌推出一股阴冷无比的气流。罩向$n。\n"NOR;

	ap = me->query_skill("force");
	dp = target->query_skill("force");

	me->start_busy(2);

	if( random(ap) > dp / 2)
	{
		damage = ap;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3 , me);
		if (target->query("neili") > damage * 3)
			target->add("neili", damage * 3);
		else
			target->set("neili", 0);

		 msg += WHT"$n只觉得一阵阴风袭来，一股寒劲直冲入脑髓、骨髓、血髓、脉髓。。。。\n"NOR;
		if (! target->is_busy())
			target->start_busy(1);

		target->set_temp("huaxue-dafa_xishui", 1);
		target->start_call_out((: call_other, __FILE__, "remove_effect", target :),
				       me->query_skill("huaxue-dafa") / 5);

	} else
		
msg += YEL"可是$p向旁边侧身一闪,躲过了这股阴冷无比的气流。\n"NOR;


	message_combatd(msg, me, target);

	return 1;
}

string finala(object me, object target, int damage)
{
        int lvl;
        lvl = me->query_skill("force");

        target->affect_by("tiezhang_yin",
                       (["level":me->query("jiali")+random(me->query("jiali")/2),
                          "id":me->query("id"),
                          "duration" : lvl / 50 + random(lvl / 50) ]));

        return HIW "霎那间$n" HIW "已被$N" HIW "吸髓大法拂中要"
               "害，不由得浑身一颤，难受之极。\n" NOR;
}

