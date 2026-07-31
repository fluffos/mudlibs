// This is player's own skill (Write by Lonely@nt2)
// Create by 段青竹(Owoi) at Sun Nov 22 11:08:18 2020
// 玉女素心剑(yunvsuxin-sword.c)

#include <ansi.h>
inherit SKILL;	
		
int is_invent_skill() { return 1; }

mapping *action = ({
// ZHAOSHI : 0
([      "action" : "[1;32m$N纵身一跃，手握$w剑，顿时一式[花舞殇情]对准[1;32m$n[1;32m小腹轻轻地刺了三剑",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 0,
	"damage_type" : "刺伤",
	"skill_name" : "花谢殇情"
 ]),
// ZHAOSHI : 1
([      "action" : "[1;37m$N纵身一跃，手握$w[1;37m，顿时一式[月舞多情]对准$n[1;37m小腹轻轻地刺了九十九剑。",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 12,
	"damage_type" : "刺伤",
	"skill_name" : "月舞多情"
 ]),
// ZHAOSHI : 2
([      "action" : "[1;35m$N纵身一跃，手握$w[1;35m，顿时一式[花舞无情]对准$n[1;35m神灵穴轻轻地刺了九十九剑",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 20,
	"damage_type" : "刺伤",
	"skill_name" : "花舞无情"
 ]),
// ZHAOSHI : 3
([      "action" : "[1;37m$N纵身一跃，手握$w[1;37m，顿时一式[花谢殇情]对准$n[1;31m心口重重地刺了九剑",
	"attack" : 305,
	"damage" : 301,
	"force" : 299,
	"dodge" : 282,
	"parry" : 299,
	"lvl" : 30,
	"damage_type" : "刺伤",
	"skill_name" : "花谢殇情"
 ]),
// ZHAOSHI : 4
});

int valid_learn(object me)
{
	object weapon; 
	
	if (! objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");
		
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练" + "玉女素心剑" + "。\n");
		
	return 1;
}

int valid_enable(string usage) { 
	return usage == "sword" || 
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
	level = (int)me->query_skill("yunvsuxin-sword",1);
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

	lvl = me->query_skill("yunvsuxin-sword", 1);
	if (lvl < 80)  return 0;
	if (lvl < 200) return 50;
	if (lvl < 280) return 80;
	if (lvl < 350) return 100;
	return 120;
}

int practice_skill(object me)
{
	object weapon; 
	if (!objectp(weapon = me->query_temp("weapon")) || 
		(string)weapon->query("skill_type") != "sword") 
		return notify_fail("你使用的武器不对。\n");     
	
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
	return __DIR__ + "yunvsuxin-sword" + "/" + action; 
}
