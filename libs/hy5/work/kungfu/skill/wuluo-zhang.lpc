// wuluo-zhang.c 五罗轻烟掌
#include <ansi.h>
inherit SKILL;

string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 

mapping *action = ({
([  "action" : "$N屏息静气，手起一掌「轻烟袅袅」，轻轻柔柔地拍向$n",
    "force"  : 130,
    "dodge"  : 20,
	"damage" : 100,
    "lvl"    : 0,
	"skill_name" : "轻烟袅袅",
	"damage_type" : "瘀伤"
]),
([  "action" : "$N轻轻浅笑，绕到$n身后，左手做势温柔轻拥$n腰间。$n蹙
眉急躲，$N右手一招「烟雾缭绕」，无声无息向$n的$l拍到",
    "force"  : 150,
    "dodge"  : 20,
	"damage" : 130,
    "lvl"    : 20,
	"skill_name" : "烟雾缭绕",
	"damage_type" : "内伤"
]),
([  "action" : "$N一招「烟海云涛」，双掌幻化出一片掌影，如一阵轻烟，
将$n细细密密地笼罩于内",
    "force"  : 150,
    "dodge"  : 30,
	"damage" : 145,
    "lvl"    : 40,
	"skill_name" : "烟海云涛",
	"damage_type" : "瘀伤"
]),

([  "action" : "$N返身越出圈外，回首一招「云烟渺渺」，远远地向$n的$l
轻轻拍出两掌，掌风刮到，陡然变盛直让$n呼不出气来",
    "force"  : 200,
    "dodge"  : 25,
	"damage" : 155,
    "lvl"    : 60,
	"skill_name" : "云烟渺渺",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左掌从右掌内围翻出，轻飘飘地向$n拍去，看到$n起手招
架，右掌却自胸口疾速圈出，一招「烟雾弥漫」，赶超左掌，拍向$n的$l",
    "force"  : 250,
    "dodge"  : 70,
	"damage" : 110,
    "lvl"    : 80,
	"skill_name" : "烟雾弥漫",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双掌齐推，振起一阵劲风，一招「烟消云散」在一丈开外
击向$n",
    "force"  : 300,
    "dodge"  : 20,
	"damage" : 190,
    "lvl"    : 100,
	"skill_name" : "烟消云散",
    "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练五罗轻烟掌必须空手。\n");
	if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("你的枯荣禅功太弱，无法练五罗轻烟掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练五罗轻烟掌。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
    level = (int) me->query_skill("wuluo-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练五罗轻烟掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("wuluo-zhang",1)) > 90 ) 
{
	  if (!victim->is_busy())
	  victim->start_busy(3);
        return HIC "$n被$N无声无息,有如轻烟的掌法封住了招式！\n" NOR;
}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("kurong-changong",1);
        skill = me->query_skill("kurong-changong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "kurong-changong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;

if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}

if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}



msg = HIG"$N 深吸一口气！施展开一阳指诀，以纯阳指力遍布全身! 脸色红润多了。\n"NOR;
           if (!ob->is_busy() && random(3)==0)
{
msg += HIY"$n"+HIY+"被$N的纯阳指力反点! 结果点中了 "+ xue_name[random(sizeof(xue_name))] +NOR;
                ob->apply_condition("yyz_damage",30);
                ob->start_busy(3);  
}

//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}      
}
