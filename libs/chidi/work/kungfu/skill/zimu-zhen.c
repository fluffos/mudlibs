// zimu-zhen.c 子母针法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N双手连环挥舞，一招「穿心针」，$w直奔$n的胸腹要害",
	"dodge":		-10,
	"damage":		200,
	"poison": 30,
	"lvl" : 0,
	"skill_name" : "穿心针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N身形晃动，一招「破气针」，手中$w如一串银线，往$n咽喉打去",
	"dodge":		-20,
	"damage":		300,
	"poison": 40,
	"lvl" : 60,
	"skill_name" : "破气针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N五指微张，一招「吸血针」，手中$w飞蚊般往$n全身叮去",
	"dodge":		-40,
	"damage":		400,
	"poison": 50,
 	"lvl" : 90,
	"skill_name" : "吸血针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N大喝一声，一招「摄魂针」，$w幻化出夺目光亮，打向$n",
	"dodge":		-50,
	"damage":		500,
	"poison": 60,
	"lvl" : 100,
	"skill_name" : "摄魂针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N错步一跃，一招「夺魄针」，$w带着阵阵阴风，打向$n全身",
	"dodge":		-60,
	"damage":		600,
	"poison": 70,
 	"lvl" : 110,
	"skill_name" : "夺魄针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N双目精芒闪动，一招「离别针」，手中$w全数脱手飞出，排山倒海般打向$n全身",
	"dodge":		-60,
	"damage":		700,
	"poison": 80,
	"lvl" : 120,
	"skill_name":  "离别针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N纵声长啸，一招「天魔针」，$w竟然带着一股强烈劲风，扫向$n",
	"dodge":		-70,
	"damage":		800,
	"poison": 90,
	"lvl" : 130,
	"skill_name" : "天魔针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N眼中杀气突然大盛，一招「地煞针」，$w飞蝗般打向$n全身",
	"dodge":		100,
	"damage":		900,
	"poison": 100,
	"lvl" : 200,
	"skill_name" : "地煞针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力够练子母连环针, 再多练练吧。\n");

	if ((int)me->query_skill("biyun-xinfa", 1) < 100)
		return notify_fail("你的碧云心法火候太浅。\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "throwing" )
		return notify_fail("你手上并没有暗器，怎么练？\n");

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
	level   = (int) me->query_skill("zimu-zhen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练子母针法。\n");
	me->receive_damage("qi", 5);
	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("zimu-zhen", 1) >= 50 )
		return __DIR__"zimu-zhen/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{object weapon;weapon=me->query_temp("weapon");
              
        if(weapon->query("name")=="子母飞针" && weapon->query("id")=="zimuzhen" && me->query_temp("marks/子母针") ){
          victim->apply_condition("zm_poison", random(me->query_skill("zimu-zhen")) + 10 +
	  victim->query_condition("zm_poison"));
	}
}
