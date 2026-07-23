// jingang-quan.c -大金刚拳
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N盘膝而坐，二手合十，一式「莲花座」，双拳蓄势而发，击向$n的$l",
    "force" : 280,
    "dodge" : 5,
    "damage": 260,
    "lvl" : 0,
    "skill_name" : "莲花座",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「烈火锥」，双掌轮流下击，拳势如焰，吡啪爆响",
    "force" : 200,
    "dodge" : 5,
    "damage": 270,
    "lvl" : 20,
    "skill_name" : "烈火锥",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N腾空飞起，一式「八方雨」，双手双腿齐出，令$n无可躲藏",    
    "force" : 330,
    "dodge" : 15,
    "damage": 300,
    "lvl" : 40,
    "skill_name" : "八方雨",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双掌虚含，掌缘下沉，一式「掌心雷」，缓缓向$n推出",
    "force" : 370,
    "dodge" : 5,
    "damage": 220,
    "lvl" : 60,
    "skill_name" : "掌心雷",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一臂前伸，一臂后指，一式「五指山」，攻向$n的身前身后",    
    "force" : 320,
    "dodge" : 10,
    "damage": 315,
    "lvl" : 80,
    "skill_name" : "五指山",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「观音渡」，两手十指虚点$n的全身三十六道要穴",
    "force" : 380,
    "dodge" : 25,
    "damage": 325,
    "lvl" : 90,
    "skill_name" : "观音渡",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N两目内视，双手内笼，一式「天龙唱」，四面八方响起震人心魄的
龙吟",
    "force" : 450,
    "dodge" : 15,
    "damage": 335,
    "lvl" : 100,
    "skill_name" : "天龙唱",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N似笑非笑，双拳无形无定，一式「如来笑」，骤然击向$n的前胸",
    "force" : 530,
    "dodge" : 20,
    "damage": 350,
    "lvl" : 60,
    "skill_name" : "如来笑",
    "damage_type" : "瘀伤"
]),
(["action" :"$N双臂一挥，第一式「正见」打出，以通臂之势，拳消力不消，劲风直逼$n而去",
  "force" : 350,
  "dodge" : 15,
  "damage": 360,
  "lvl" : 5,
  "skill_name" : "正见",
  "damage_type" : "瘀伤"
]),
(["action" :"$N躬腰曲背，左臂一抡，架起一道气墙，接着右手握拳，对着$n，一招「正思」穿墙而出",
  "force" : 300,
  "dodge" : 110,
  "damage": 360,
  "lvl" : 15,
  "skill_name" : "正思",
  "damage_type" : "瘀伤"
]),
(["action" :"$N一个马步式「正业」，双拳凝力，跟着两臂相并，对准$n$l一式挥出，劲力异常",
  "force" : 320,
  "dodge" : 115,
  "damage": 360,
  "lvl" : 25,
  "skill_name" : "正业",
  "damage_type" : "瘀伤"
]),
(["action" :"$N使出一招「正语」，双臂连连挥动，拳风伴着口中的狮子吼，如猛兽下山般袭向$n",
  "force" : 340,
  "dodge" : 120,
  "damage": 360,
  "lvl" : 45,
  "skill_name" : "正语",
  "damage_type" : "瘀伤"
]),
(["action" :"$N单臂抡起一式「正命」打出，接着又是一拳相随，后浪推前浪，两波劲力合击$n",
  "force" : 360,
  "dodge" : 115,
  "damage": 360,
  "lvl" : 65,
  "skill_name" : "正命",
  "damage_type" : "瘀伤"
]),
(["action" :"$N挥出数拳，正当$n质疑这花拳之势时，一股劲风爆出，正对$p胸口，是招虚实的「正勤」",
  "force" : 380,
  "dodge" : 110,
  "damage": 360,
  "lvl" : 75,
  "skill_name" : "正勤",
  "damage_type" : "瘀伤"
]),
(["action" :"$N口颂佛经，打出一招「正念」，直轰$n前胸，拳风至刚至阳，正大光明，不带丝毫阴气",
  "force" : 360,
  "dodge" : 115,
  "lvl" : 85,
  "damage": 360,
  "skill_name" : "正念",
  "damage_type" : "瘀伤"
]),
(["action" :"只见$N合十而立，以这「正定」一招为本，以身为拳，劲力布满全身，重重压向$n",
  "force" : 450,
  "dodge" : 115,
  "damage": 360,
  "lvl" : 105,
  "skill_name" : "正定",
  "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="unarmed" ||usage=="parry"; }     

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练大金刚拳必须空手。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
   return notify_fail("你的混元一气功火候不够，无法学大金刚拳。\n")
;
    if ((int)me->query("max_neili") < 50)
   return notify_fail("你的内力太弱，无法练大金刚拳。\n");
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
    level   = (int) me->query_skill("jingang-quan",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[random(i)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("你的内力不够练大金刚拳。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"jingang-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIR"只见$n$l闷哼一声，吐出一口鲜血，已被易筋经的护体真气给击伤!\n"NOR;
}
}