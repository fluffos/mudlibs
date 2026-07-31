//穿云掌
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action"	: "$N一式"+HIW"「白云出岫」"+NOR"，双掌间升起一团淡淡的白雾，缓缓推向$n的$l。\n",
	"parry_msg"	: "$n一式"+HIW"「白云出岫」"+NOR"，双掌间升起一团淡淡的白雾，缓缓架住$N的攻击。\n",
        "dodge"		: 5,
        "parry"		: 5,
        "force"		: 30,
        "damage_type"	: "瘀伤"
]),
([      "action" 	: "$N并指如剑，一式"+RED"「白虹贯日」"+NOR"，疾向$n的$l戳去！\n",
	"parry_msg"	: "$n并指如剑，一式"+RED"「白虹贯日」"+NOR"，剑气如风，将$N的攻势架住！\n", 
        "dodge":     5,
        "parry":     5,
        "force" : 35,
        "damage_type" : "刺伤",
        "weapon" : "剑风",
]),
([      "action" : "$N使一式"+WHT"「穿云裂石」"+NOR"，顿时剑气纵横，猛地插往$n的$l！\n",
	"parry_msg"	: "$n使一式"+WHT"「穿云裂石」"+NOR"，顿时剑气纵横，逼得$N不得不撤招回防。\n",
        "force" : 50,
        "damage_type" : "刺伤",
        "weapon" : "剑气",
]),
([      "action" : "$N双掌隐隐泛出青气，一式"+HIG"「覆雨翻云」"+NOR"，一股气势磅礴的剑气直向$n$l击去！\n",
	"parry_msg"	: "$n双掌隐隐泛出青气，一式"+HIG"「覆雨翻云」"+NOR"，气势磅礴的剑气将$N攻击架住。\n",
        "dodge":     -5,
        "parry":     -5,
        "force" : 65,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形往上一纵，使出一式"+HIB"「云起龙骧」"+NOR"，双掌并拢，幻化龙形，笔直地向$n的$l插去！\n",
	"parry_msg"	: "$n身形往上一纵，使出一式"+HIB"「云起龙骧」"+NOR"，双掌并拢，幻化龙形，将$N的$w架开。\n",
        "dodge":     -10,
        "parry":     -5,
        "force" :    70,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形一变，使一式"+YEL"「烘云托月」"+NOR"，双掌带着萧刹的劲气，猛地击往$n的$l。\n",
	"parry_msg" : "$n身形一变，一式"+YEL"「烘云托月」"+NOR"，双掌带着萧刹的劲气将$N$w狠狠架开。\n",
        "dodge":     -15,
        "parry":     -10,
        "force" : 75,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式"+HIC"「拨雨撩云」"+NOR"，左掌凝重，右掌轻盈，同时向$n的$l击去！\n",
	"parry_msg" : "$n使一式"+HIC"「拨雨撩云」"+NOR"，左掌凝重，右掌轻盈，同时将$N的攻击架开。\n",
        "dodge":     -15,
        "parry":     -15,
        "force" : 80,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N突地一招"+HIY"「云出无心」"+NOR"，双掌挟着一阵风雷之势，猛地劈往$n的$l！\n",
	"parry_msg" : "$n突地一招"+HIY"「云出无心」"+NOR"，双掌挟着一阵风雷之势，将$n的$w劈得歪在一边。\n",
        "dodge":     -15,
        "parry":     -10,
        "force" : 100,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed"  || usage=="parry" ; }

mapping query_action(object me, object weapon)
{
	int i;
	if( me->query_temp("perform_CY") )
		return action[2];
	if( me->query_temp("perform_FY") )
		return action[3];
	if( me->query_temp("perform_YQ") )
		return action[4];
	if( me->query_temp("perform_YC") )
		return action[7];
				
	if( me->query_skill("chuanyun-zhang",1)<400 )
		return action[random(3)];
	i = me->query_skill("chuanyun-zhang",1)-400/100;
	if( i>6 )
		i = 6;
	if( i<0 )
		i = 0;	
	return action[2+random(i)];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练穿云掌必须空手。\n");
        if ((int)me->query_skill("xianfeng-yunti", 1) < 20)
                return notify_fail("你的仙风云体术火候不够，无法学穿云掌。\n");
        if ((int)me->query_maxforce() < 100)
                return notify_fail("你的内力太弱，无法练穿云掌。\n");
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 40)
                return notify_fail("你的内力不够练穿云掌。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shushan") +"/chuanyun-zhang/" + action;
}