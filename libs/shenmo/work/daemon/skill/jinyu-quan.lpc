// jinyu-quan.c 金玉拳
#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 

mapping *action = ({
([	"action" : "$N一招「金光灿烂」，双拳一上一下, 向$n挥去",
	"force"  : 120,
	"dodge"  : 10,
	"damage" : 220,
	"lvl"    : 0,
	"skill_name" : "金光灿烂",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「其利断金」，幻出一片拳影，气势如虹，击向$n的头部",
	"force"  : 140,
	"dodge"  : 20,
	"damage" : 130,
	"lvl"    : 20,
	"skill_name" : "其利断金",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N身影向上飘起，脸浮微笑，一招「蓝田美玉」，轻轻拍向$n的$l",
	"force"  : 150,
	"dodge"  : 20,
	"damage" : 145,
	"lvl"    : 40,
	"skill_name" : "蓝田美玉",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「金玉其外」，双拳一合，$n只觉到处是$N的拳影",
	"force"  : 160,
	"dodge"  : 25,
	"damage" : 160,
	"lvl"    : 60,
	"skill_name" : "金玉其外",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N绕着$n一转，满场游走，拳出如风，不绝击向$n，正是一招
「金玉满堂」",
	"force"  : 170,
	"dodge"  : 30,
	"damage" : 160,
	"lvl"    : 80,
	"skill_name" : "金玉满堂",
	"damage_type" : "瘀伤"
]),
([	"action" : "只见$N一个侧身退步，左手虚晃，突然猛跨两步，已到$n面前，
右拳陡出，事先绝无征兆，迅如崩雷，一招「点石成金」击向$n的前胸",
	"force"  : 180,
	"dodge"  : 35,
	"damage" : 180,
	"lvl"    : 100,
	"skill_name" : "点石成金",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「众口铄金」，扑向$n，似乎$n的全身都被拳影笼罩",
	"force"  : 280,
	"dodge"  : 30,
	"damage" : 200,
	"lvl"    : 120,
	"skill_name" : "众口铄金",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="wuluo-zhang"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("你的枯荣禅功火候不够，无法练金玉拳。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练金玉拳必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练金玉拳。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level,a,b,c,d,e;
        level   = (int) me->query_skill("jinyu-quan",1);
        a = me->query("neili");
// 注意，取后天属性时要注意某些心法可以增加临时属性。
        b = me->query_str();
        c = me->query_dex();
        d = me->query_con();
        e = me->query("jiali");
        if (a > 2000) a= 2000;
        if (a < 500) a= 500;
        if (level > 200) level = 200 + (level-200)/10;    
        if (random((int)me->query_skill("cuff")) >= 100 
         && ((int)me->query("neili") >= 500 )          
         && (me->query_skill_prepared("cuff") == "jinyu-quan")
         && random(10)> 5 ) {
               return ([
                "action":HIY"$N左掌一晃，随即右拳击出，紧跟着拳掌交错，上下前后连续击出三十六道劲风"NOR,
                "parry":(int)me->query_skill("parry", 1)/8,
                "dodge":(int)me->query_skill("dodge", 1)/6,
                "force": 650,
                "damage": 650,
                "damage_type": "内伤"
               ]);
        }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练金玉拳。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("jinyu-quan",1)) > 90 ) 
{
	  victim->receive_wound("qi", damage_bonus/2);
        return HIR "$n被一片拳影，顿时双眼一黑！\n" NOR;
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
