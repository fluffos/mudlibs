// qishang-quan.c -七伤拳
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : HIY"$N气凝如山，一式「金戈铁马」，双拳蓄势而发，击向$n的$l"NOR,
	"force" : 180,
	"dodge" : 50,
	"lvl" : 1,
	"skill_name" : "金戈铁马",
	"damage_type" : "内伤"
]),
([	"action" : HIG"$N身形凝重，劲发腰背，一式「木已成舟」，缓缓向$n推出"NOR,
	"force" : 200,
	"dodge" : 50,
	"damage": 100,
	"lvl" : 10,
	"skill_name" : "木已成舟",
        "damage_type" : "内伤"
]),
([	"action" : BLU"$N步伐轻灵，两臂伸舒如鞭，一式「水中捞月」，令$n无可躲闪"NOR,
	"force" : 250,
	"dodge" : 100,
	"damage": 150,
	"lvl" : 50,
	"skill_name" : "水中捞月",
        "damage_type" : "内伤"
]),
([	"action" : HIR"$N身形跃起，一式「火海刀山」，双拳当空击下，势不可挡"NOR,
	"force" : 270,
	"dodge" : 150,
	"damage": 200,
	"lvl" : 100,
	"skill_name" : "火海刀山",
        "damage_type" : "内伤"
]),
([	"action" : HIB"$N身形一矮，一式「土载万物」，两拳自下而上，攻向$n"NOR,
	"force" : 320,
	"dodge" : 210,
	"damage": 215,
	"lvl" : 140,
	"skill_name" : "土载万物",
        "damage_type" : "内伤"
]),
([	"action" : HIB"$N身形一转，一式「阴风惨惨」，攻向$n的身前身后"NOR,
	"force" : 380,
	"dodge" : 250,
	"damage": 350,
	"lvl" : 200,
	"skill_name" : "阴风惨惨",
        "damage_type" : "内伤"
]),
([	"action" : MAG"$N移形换位，步到拳到，一式「阳光普照」，四面八方都是拳影"NOR,
	"force" : 450,
	"dodge" : 315,
	"damage": 750,
	"lvl" : 400,
	"skill_name" : "阳光普照",
        "damage_type" : "内伤"
]),
([	"action" : MAG"$N长啸一声，向前踏出一步，双拳中宫直进，一式「七者皆伤」，骤然击向$n的前胸"NOR,
	"force" : 1200,
	"dodge" : 420,
	"damage": 1000,
	"lvl" : 500,
	"skill_name" : "七者皆伤",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

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
	level   = (int) me->query_skill("qishang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        return notify_fail("七伤拳只能用钻研(zuanyan)来增加熟练度。\n");
}
string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}

