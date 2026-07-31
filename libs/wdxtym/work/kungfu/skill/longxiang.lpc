//
// longxiang.c 龙象般若功
//

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
	return force == "mizong-neigong" || force == "xiaowuxiang";
}

void skill_improved(object me)
{
	int lvl;

	lvl = me->query_skill("longxiang", 1);
	if (lvl > 360)
		return;

	if (lvl % 30)
		write(HIY "你修炼成了第" + chinese_number(lvl / 30 + 1) +
		      "层龙象般若功！"NOR"\n");
	else
		write(HIR "你的第" + chinese_number(lvl / 30 + 1) +
		      "层龙象般若功又增进了一层。"NOR"\n");
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("longxiang", 1);
    if (lvl>=300) 
              return lvl * lvl * 15 * 25 / 100 / 200;
	else 
              return lvl * lvl * 15 * 15 / 100 / 200;
}

int valid_learn(object me)
{
	if ((int)me->query_skill("force", 1) < 70)
		return notify_fail("你的基本内功火候还不够。\n");

	if (me->query("gender") == "无性" && (int)me->query_skill("longxiang", 1) > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的龙象般若功。\n");

	if (me->query("str") < 24)
		return notify_fail("你先天膂力不足，无法学习刚猛的龙象般若功。\n");

	if (me->query("con") < 30)
		return notify_fail("龙象般若功修行的深处需要足够的先天根骨才能发挥出强大威力，你这点根骨还是别浪费时间了。\n");

	return ::valid_learn(me);
}

mixed valid_fdamage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp;

	if (random(3)==1 || (int) me->query("con") < 31 || (int) me->query_skill("longxiang", 1) < 100 || ! living(me))
		return;

	ap = ob->query_skill("force");
	dp = me->query_skill("force");

	if (ap / 2 + random(ap) < dp)
	{
		result = HIC "$N" HIC "一招击中$n" HIC "，却感觉$n" HIC "体内一股极其强烈的内劲忽然爆发出来。\n"+
				COMBAT_D->do_respond(me, ob, damage, (me->query("con")-28)*6, HIR "$P只觉一股暗劲反击而来，顿时一阵气血翻涌！"NOR"\n");
		return result;
	}
}

int practice_skill(object me)
{
	return notify_fail("龙象般若功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"longxiang/" + func;
}

int difficult_level()
{
	object me;
	int lvl;

	if (me = this_player())
	{
		// 有小无相功？难以学习。
		if (lvl = me->query_skill("xiaowuxiang", 1))
			return 3000;

		// 有九阳神功？较难学习。
		if (lvl = me->query_skill("jiuyang-shengong", 1))
			return 500;
	}

	return 100;
}
