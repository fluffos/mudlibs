// qishang-quan.c 七伤拳
// modify by amis 2004-1-18

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N的一拳含刚猛之气，猛的击向$n的$l",
	"force" : 180,
        "dodge" : -5,
        "parry" : 5,
	"lvl" : 0,
	"skill_name" : "刚猛",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N以阴柔以气，对准$n的$l轻飘飘的挥了过去",
	"force" : 250,
        "dodge" : 5,
	"lvl" : 7,
	"skill_name" : "阴柔",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N以一股刚中带柔之气，一拳击向$n的$l",
	"force" : 280,
        "dodge" : 5,
        "parry" : 10,
	"lvl" : 15,
	"skill_name" : "刚中有柔",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双拳一握，动起柔刚之劲，缓缓的向$n击出",
	"force" : 310,
        "dodge" : -5,
	"lvl" : 25,
	"skill_name" : "柔中有刚",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N对准$n的$l，夹着劲风猛的横扫过去",
	"force" : 350,
        "dodge" : -5,
	"lvl" : 34,
	"skill_name" : "横出",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N呼的一拳，直向$n的$l送了过去，只觉一股劲力扑面而来",
	"force" : 380,
        "dodge" : 5,
	"lvl" : 40,
	"skill_name" : "直送",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N呼的一拳击向$n的$l，此拳去势之快，简直令人无法招架",
	"force" : 420,
        "dodge" : 5,
	"lvl" : 46,
	"skill_name" : "内缩",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一拳前伸，一拳在后，带着刚猛和阴柔之劲，攻向$n的身前身后",
	"force" : 440,
        "dodge" : 5,
	"damage": 10,
	"lvl" : 51,
	"skill_name" : "刚猛阴柔",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一拳击向$n的全身三十六道要穴，拳中竟带有三种不同劲力",
	"force" : 470,
        "dodge" : 10,
	"damage": 20,
	"lvl" : 57,
	"skill_name" : "三种劲力",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N暗吸一口真气，双拳平伸，带着四种不同之力击向$n的$l",
	"force" : 450,
        "dodge" : 10,
	"damage": 30,
	"lvl" : 64,
	"skill_name" : "四种劲力",
        "damage_type" : "内伤"
]),
([	"action" : "$N默运神功，双拳无形无定，带着五种劲力骤然击向$n的前胸",
	"force" : 450,
        "dodge" : 15,
	"damage": 35,
	"lvl" : 70,
	"skill_name" : "五种劲力",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N单拳一握，默运六种不同劲力又低又快的击向$n的小腹",
	"force" : 480,
        "dodge" : 25,
	"damage": 40,
	"lvl" : 74,
	"skill_name" : "六种劲力",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双目紧闭深运内力，猛的大喝了一声，以七种无比之劲力击向$n的全身",
	"force" : 530,
        "dodge" : 30,
	"damage": 50,
	"lvl" : 80,
	"skill_name" : "七种劲力",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return  usage=="parry"||usage=="unarmed"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练七伤拳必须空手。\n");
	if ( !me->query_skill("jiuyang-shengong"))
	if ( me->query_skill("shenghuo-shengong", 1) < 100)
                return notify_fail("你的圣火神功火候不够，无法学七伤拳。\n");
	if ( me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练七伤拳。\n");
//        if (!me->query("xie_qishang") && me->query_skill("qishang-quan", 1) > 50)
//                return notify_fail("你没有学过"HIR"七伤拳经"NOR"，无法再继续练习七伤拳。\n");
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
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int lvl;
	mapping myfam;
	myfam = (mapping)me->query("family");	
	lvl=me->query_skill("qishang-quan", 1);

          if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练七伤拳。\n");

          me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
          return __DIR__"qishang-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( !me->query_temp("qishang")) return 0;

	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
        victim->receive_wound("qi", (damage_bonus - 100) / 2 );
		if (wizardp(me))                
		{tell_object(me, sprintf( "伤害力：%d \n" NOR, damage_bonus));
		}
        	return HIR "只听"+victim->query("name")+"闷哼一声，脸色惨白，已被七伤拳所含各种内劲给震伤！\n"NOR;
        }
}
