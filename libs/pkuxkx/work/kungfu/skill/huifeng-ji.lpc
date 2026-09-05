//回风神戟
// by mudy
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": HIW"$N"+HIW"暗使内力，一抖手中$w"+HIW"，$w"+HIW"顿时如闪电般直取"+HIW"$n"+HIW"，刺向"+HIW"$n"+HIW"的$l,让"+HIW"$n"+HIW"避无可避!"NOR,
        "dodge": 0,
        "damage": 240,
        "damage_type": "刺伤"
]),
([      "action": HIR"$N"+HIR"心中暗念回风神戟的上乘心法，以心运戟...\n$N"+HIR"手中$w"+HIR"受内力激发通体暗红，直取$n"+HIR"面门，$n"+HIR"只觉面部一阵灼热！"NOR,
        "dodge": 5,
        "damage": 345,
        "damage_type": "刺伤"
]),
([      "action": HIB"$N"+HIB"突然一侧身，看似要避，却是将$w"+HIB"在身上绕了一周，却将戟头向$n"+HIB"的$l连刺数招！"NOR,
        "dodge": 0,
        "damage": 455,
        "damage_type": "刺伤"
]),
([      "action": HIY"$N"+HIY"戟随心走，$w"+HIY"在$N"+HIY"手中旋转，身影却是如风而至.\n$N"+HIY"向$n"+HIY"微微一笑，戟头却是轻飘飘地向$n"+HIY"的$l点去！"NOR,
        "dodge": 0,
        "damage": 555,
        "damage_type": "刺伤"
]),
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "halberd") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

int practice_skill(object me)
{
return notify_fail("回风神戟只能用学(learn)的来增加熟练度。\n");
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string perform_action_file(string action)
{
        return __DIR__"huifeng-ji/" + action;
}
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
