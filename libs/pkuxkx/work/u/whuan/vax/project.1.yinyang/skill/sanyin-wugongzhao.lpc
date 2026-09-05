//sanyin-wugongzhao.c 三阴蜈蚣抓
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N爪现青白，骨结隆起，自上而下撕扯$n的$l",
    "force" : 120,
    "dodge" : 10,
    "damage": 30,
    "damage_type" : "抓伤"
]),
([  "action" : "$N双手忽隐忽现，爪爪鬼魅般抓向$n的$l",
    "force" : 150,
    "dodge" : 20,
    "damage": 45,
    "damage_type" : "抓伤"
]),
([  "action" : "$N身形围$n一转，爪影纵横毫不留情对着$n的$l抓下",
    "force" : 180,
    "dodge" : 30,
    "damage": 55,
    "damage_type" : "抓伤"
]),
([  "action" : "$N一声怪叫，一爪横出直击$n的天灵盖",
    "force" : 240,
    "dodge" : 50,
    "damage": 100,
    "lvl"   : 100,
    "skill_name" : "唯我独尊" ,
    "damage_type" : "抓伤"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="chousui-duzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("练三阴蜈蚣爪必须空手。\n");
        if ((int)me->query("max_neili") < 200)
            return notify_fail("你的内力太弱，无法练三阴蜈蚣爪。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("sanyin-wugongzhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	object* ob;
	int i,skill,damage;

	skill = me->query_skill("jiuyin-baiguzhao",1);
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练三阴蜈蚣爪。\n");
	me->receive_damage("qi", 30);
        me->add("neili", -20);
	return 1;
}

string query_yinyang()
{
	return "纯阴";
}