// swsb-shou.c 三无三不手
// By Kayin @ CuteRabiit Studio 99-4-16 15:40 new
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$N一招"HIW"「无孔不入」"NOR"，$n身前身後都是$w的影子同时点$n全身各处大穴",
	"dodge": (int)this_player()->query_skill("whip")/10,
	"damage":(int)this_player()->query_skill("whip"),
	"lvl" : 0,
	"skill_name" : "无孔不入",
	"damage_type":	"点穴"
]),
([	"action":"$N一招"HIY"「无所不至」"NOR"，手中$w点向$n周身诸处偏门穴道。",
	"dodge":(int)this_player()->query_skill("whip")/5,
	"damage":(int)this_player()->query_skill("whip")*2,
	"lvl" : 50,
	"skill_name" : "无所不至",
	"damage_type":	"点穴"
]),
([	"action":"$N一招"HIC"「无所不为」"NOR"，$w专打$n周身柔弱之处。",
	"dodge":(int)this_player()->query_skill("whip"),
	"damage":(int)this_player()->query_skill("whip")*3,
	"lvl" : 100,
	"skill_name" : "无所不为",
	"damage_type":	"内伤"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力不足，没有办法练三无三不手, 多练些内力再来吧。\n");

	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候太浅。\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条拂尘才能练尘法。\n");

	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("swsb-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练三无三不手。\n");
	me->receive_damage("qi", 5);
	return 1;
}


