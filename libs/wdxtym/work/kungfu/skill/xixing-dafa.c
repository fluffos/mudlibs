// xixing-dafa.c 吸星大法
// by doing

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
	return 1;
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("xixing-dafa", 1);
	
	if (lvl >= 300 && me->query("family/family_name") == "日月神教")
		return lvl * lvl * 17 * 16 / 100 / 200;
	else
		return lvl * lvl * 15 * 16 / 100 / 200;
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("xixing-dafa", 1);

	if (me->query("character") == "光明磊落")
		return notify_fail("你心中暗道：这种害人武功，我学它作甚？\n");

	if (me->query("con") < 20)
		return notify_fail("你试着按照法门运转了一下内息，忽然"
				   "觉得脸热心跳，丹田却是一阵冰凉！\n");

/*if (lvl >= 10 && lvl < 50 && me->query("max_neili"))
		return notify_fail("你没有按照吸星大法的诀窍将内"
				   "力散去，现在还不敢妄自继续修行大法。\n");*/

	return ::valid_learn(me);
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mapping result;
	int ap, dp;
	int jiali;

	if ((int) me->query_skill("xixing-dafa", 1) < 80 ||
	    ! living(me))
		return;

	if ((jiali = ob->query("jiali")) < 1)
		return;

	ap = ob->query_skill("force");
	dp = me->query_skill("force");
	if (ap / 2 + random(ap) < dp)
	{
		if (me->query("neili") < me->query("max_neili") * 15 / 10)
			me->add("neili", jiali);

		result = ([ "damage" : -damage ]);

		switch (random(4))
		{
		case 0:
			result += ([ "msg" : HIM "$N" HIM "只觉得内力源源而泄"
					     "，不由得大吃一惊。"NOR"\n" ]);
			break;
		case 1:
			result += ([ "msg" : HIM "$N" HIM "只觉得发出的内力犹"
					     "如石沉大海，不知所踪。"NOR"\n" ]);
			break;
		case 2:
			result += ([ "msg" : HIM "$N" HIM "只觉得发出的内力犹"
					     "无影无踪，浑然不知着落。"NOR"\n" ]);
			break;
		default:
			result += ([ "msg" : HIM "$N" HIM "不住催动内力，但是"
					     "只觉得$n" HIM "竟似毫不费力。"NOR"\n" ]);
			break;
		}
		return result;
	}
}

int practice_skill(object me)
{
	return notify_fail("吸星大法只能用学的，或是从运用(exert)中增加熟练度。\n");
}
int difficult_level()
{
	object me;
	int lvl;

	if (me = this_player())
	{
	
	if (me->query("family/family_name") != "日月神教")
			return 500;
	}

	return 100;
}

string exert_function_file(string func)
{
	return __DIR__"xixing-dafa/" + func;
}
