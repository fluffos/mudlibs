// lingxu-bu 凌虚步
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$n一式「"+HIG"雪地莲花"NOR+"」，身子掣忽一转，$N只觉的眼前一花，失去了目标。\n",
	"dodge"  : 40
]),
([	"action" : "$n一式「"+YEL"一狐冲天"NOR+"」，双脚点地，身子突然拔高了丈许，缓缓飘落在$N身后。\n",
	"dodge"  : 60
]),
([	"action" : "$n一式「"+CYN"移行幻影"NOR+"」，身行一晃，顿时无数条身影一下子出现在$N的面前。\n",
	"dodge"  : 80
]),
([	"action" : "$n一式「"+RED"狡兔三窟"NOR+"」，飘然向后一退，躲开$N的凌厉攻势。\n",
	"dodge"  : 100
]),
([	"action" : "$n一式「"+HIG"烟雨飘渺"NOR+"」，身体急转，化为一道白光，虚幻不定的出现在$N的周围。\n",
	"dodge"  : 120
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shaolin-shenfa");

	if (level < 120 )
		zhaoshu--;

	if (level < 80)
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}
int valid_learn(object me)
{
	return 1;
}
int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}
string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练凌虚步。\n");
	me->receive_damage("qi", 30);
	return 1;
}


