// This is player's own skill (Write by Lonely@nt2)
// Create by 段青竹(Owoi) at Mon Jan  4 23:35:17 2021
// 九阴九阳混沌无极寂灭掌(yinyang-strike.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : ".",
	"attack" : 335,
	"damage" : 335,
	"force" : 330,
	"dodge" : 339,
	"parry" : 330,
	"lvl" : 0,
	"damage_type" : "内伤",
	"skill_name" : "混沌破阴阳"
 ]),
// ZHAOSHI : 1
([      "action" : ".",
	"attack" : 335,
	"damage" : 335,
	"force" : 330,
	"dodge" : 339,
	"parry" : 330,
	"lvl" : 12,
	"damage_type" : "内伤",
	"skill_name" : "游龙弑魂"
 ]),
// ZHAOSHI : 2
([      "action" : ".",
	"attack" : 335,
	"damage" : 335,
	"force" : 330,
	"dodge" : 339,
	"parry" : 330,
	"lvl" : 20,
	"damage_type" : "内伤",
	"skill_name" : "囚仙决"
 ]),
// ZHAOSHI : 3
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"九阴九阳混沌无极寂灭掌"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"九阴九阳混沌无极寂灭掌"+"。\n");
	return 1;
}

int valid_enable(string usage) { 
	return usage == "strike" || 
	       usage == "parry"; 
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
	level = (int)me->query_skill("yinyang-strike",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

mixed *query_actions() { return action; }

int query_effect_parry(object attacker, object me)
{
	int lvl;

	if (me->query_temp("weapon"))
		return 0;

	lvl = me->query_skill("yinyang-strike", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} 

string perform_action_file(string action) 
{
	return __DIR__ + "yinyang-strike" + "/" + action; 
}
