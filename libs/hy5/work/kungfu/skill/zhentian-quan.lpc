//震天拳
//cool 981010
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([	"action" : "$N马步一立，身子微曲，暗喝一声，一招「望月拜天」，一拳直捅$n的$l",
	"force" : 170,
	"dodge" : 0,
       "parry" : 10,
	"damage" : 170,
	"lvl" : 0,
	"skill_name" : "望月拜天",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N“哈哈”一笑，左拳由下至上，右拳平平击出，一招「跨日向天」，交替打向$n",
	"force" : 200,
	"dodge" :-5,
	"damage" : 170,
       "parry" : 5,
	"lvl" : 15,
	"skill_name" : "跨日向天",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N对$n一声大喝，使一招「长虹经天」，左拳击出，随即右拳跟上，两重力道打向$n的$l",
	"force" : 230,
	"dodge" : 0,
	"damage" : 170,
       "parry" : 10,
	"lvl" : 30,
	"skill_name" : "长虹经天",
	"damage_type" : "震伤"
]),
([	"action" : "$N闷喝一声，双拳向上分开，一记「举火烧天」，拳划弧线，左右同时击向$n的$l",
	"force" : 260,
	"dodge" : 0,
	"damage" : 170,
       "parry" : 0,
	"lvl" : 45,
	"skill_name" : "举火烧天",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N施出「一臂擎天」，一声大吼，一拳凌空打出，拳风直逼$n的$l",
	"force" : 290,
	"dodge" : 0,
	"damage" : 170,
       "parry" : 5,
	"lvl" : 60,
	"skill_name" : "一臂擎天",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一声长啸，双拳交错击出，一招「石破天惊」，拳风密布$n的前后左右",
	"force" : 310,
	"dodge" : 10,
	"damage" : 170,
       "parry" : 10,
	"lvl" : 70,
	"skill_name" : "石破天惊",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N怒吼一声，凌空飞起，一式「天崩地裂」，双拳居高临下，齐齐捶向$n",
	"force" : 350,
	"dodge" : 20,
	"damage" : 170,
       "parry" : -10,
	"lvl" : 80,
	"skill_name" : "天崩地裂",
	"damage_type" : "内伤"
]),
([	"action" : "$N仰天大笑，势若疯狂，衣袍飞舞，一招「无法无天」，拳风凌厉，如雨点般向$n打去",
	"force" : 380,
	"dodge" : -5,
	"damage" : 170,
       "parry" : -10,
	"lvl" : 90,
	"skill_name" : "无法无天",
	"damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"|| usage=="unarmed"; }
int valid_combine(string combo) { return combo=="chuanyun-tui"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练「震天拳」必须空手。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 25)
		return notify_fail("你的「玄天无极功」火候不够，无法学「震天拳」。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练「震天拳」。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xuantian-wuji",1);
        level2= (int) me->query_skill("xuantian-wuji",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xuantian-wuji")
{
        victim->receive_damage("qi",level*2+300);
        victim->receive_wound("qi",level*3+300);
	return HIB"$N脚踏八卦步,手捏太乙决,$N一声长啸，$n双眼一黑，吐出一口鲜血!\n"NOR;
}
}

mapping query_action(object me, object weapon)
{
	int i, level;
if (( (int)me->query_skill("cuff", 1) >= 120 ) 
        &&	( (int)me->query_skill("zhentian-quan", 1) >= 120 )
	&&      ( (int)me->query_skill("leg",1) >= 120 )
      &&      ( (int)me->query_skill("chuanyun-tui",1) >= 120 )
	&&      ( (int)me->query("neili") >= 500 )
      &&  (me->query_skill_prepared("leg") == "chuanyun-tui")
      && (me->query_skill_mapped("parry") != "zhentian-quan")
      && random(10)>8 ) {
		return ([
		"action": "$N手中招式突然加快，一招“拳腿双绝”，隔空向$n击出一拳，随即双腿连环踢出",
	       "parry":(int)me->query_skill("parry")/3,
	       	       "damage":(int)me->query_skill("unarmed")*2,
             "dodge":(int)me->query_skill("dodge")/10+(int)me->query_skill("leg")/15,
		"force": (int)me->query_skill("strike")+(int)me->query_skill("leg"),
		"damage_type": "内伤"
  ]);
	}

	level   = (int) me->query_skill("zhentian-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("qi") < 20)
		return notify_fail("你的内力不够练「震天拳」。\n");
	me->receive_damage("jing", 25);
	me->add("qi", -5);
	return 1;
}

