// sixiang-bufa.c
// created by doing

inherit SKILL;

string *dodge_msg = ({
    "只见$n脚步左移右移，于须毫之间避开了$N这一招。\n",
    "$n身子慕然向后一仰，避开了$N的凌厉攻势。\n",
    "$n身子微微一侧，跨前两步，让$N这一招扑了个空。\n",
    "但是$n身形飘忽，轻轻一纵，早已避开$N。\n",
    "$n忽前忽后，身随意转，将$N所有的后招全难落空。\n",
});

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{
	if (me->query_skill("dodge", 1) < 180)
		return notify_fail("你基本轻功水平不足，难以领悟四象步法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int query_effect_dodge(object attacker, object me)
{
	int lvl;

	lvl = me->query_skill("sixiang-bufa", 1);
	if (lvl < 50)  return 0;
	if (lvl < 100) return 20;
	if (lvl < 150) return 30;
	if (lvl < 200) return 40;
	if (lvl < 250) return 60;
	if (lvl < 300) return 70;
	if (lvl < 350) return 80;
	return 90;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太差了，不能练四象步法。\n");

	me->receive_damage("qi", 55);
	return 1;
}

