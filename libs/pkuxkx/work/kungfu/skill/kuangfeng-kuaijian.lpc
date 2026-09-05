// kuangfeng-kuaijian.c 狂风快剑
// modified by darken@SJ

inherit SKILL;
#include <combat.h>
#include <ansi.h>
mapping *action = ({
([  "action" : "$N纵身跃起手中$w轻挥，使出一式「风平浪静」斩向$n后颈",
    "damage" : 100,
    "force" : 100,
    "dodge"  : 20,
    "lvl"   : 0,
    "skill_name" : "风平浪静",
    "damage_type" : "刺伤"
]),
([  "action" : "$N手中$w连话三个弧形，一招「风起云涌」，向$n的右臂齐肩斩落",
    "damage" : 150,
    "dodge" : 40,
    "force" : 120,
    "lvl"   : 50,
    "skill_name" : "风起云涌",
    "damage_type" : "刺伤"
]),
([  "action" : "$N轻吁一声，刷刷刷刷四剑，使出「风卷残云」向$n胸，腹，腰，肩四处连刺",
    "damage" : 200,
    "dodge" : 60,
    "force" : 140,
    "lvl"   : 100,
    "skill_name" : "风卷残云",
    "damage_type" : "刺伤"
]),
([  "action" : "$N仰天一声清啸，斜行向前，一招「风流云散」，$w横削直击，迅捷无比，击向$n的$l",
    "damage" : 250,
    "dodge" : 80,
    "force" : 160,
    "lvl"   : 150,
    "skill_name" : "风流云散",
    "damage_type" : "刺伤"
]),
([  "action" : "$N手中$w一转使出一招「暴风骤雨」，只见剑剑不停，一剑快似一剑，刺入$n的$l",
    "damage" : 300,
    "dodge" : 100,
    "force" : 180,
    "lvl"   : 200,
    "skill_name" : "暴风骤雨",
    "damage_type" : "刺伤"
]),
([  "action" : "$N挥剑向前，剑带惊雷，卷起一阵狂风，以一式「疾风迅雷」劈中$n的$l。",
    "damage" : 350,
    "dodge" : 120,
    "force" : 200,
    "lvl"   : 250,
    "skill_name" : "疾风迅雷",
    "damage_type" : "刺伤"
]),
([  "action" : "$N跳跃半空，使出「风雨交加」，只见剑光连闪，向$n连刺七剑。",
    "damage" : 400,
    "dodge" : 140,
    "force" : 225,
    "lvl"   : 300,
    "skill_name" : "风雨交加",
    "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili", 1) < 100)
                return notify_fail("你的内力不够。\n"); 
        if ( me->query_skill("huashan-neigong", 1) < 100 )
                return notify_fail("你的华山内功火候太浅。\n");
        if( (int)me->query_skill("sword", 1) < 100 )
                return notify_fail("你的基本剑法还不够娴熟，无法学习「狂风剑法」。\n");
        if ((int)me->query_skill("huashan-jianfa", 1) < 150)
                return notify_fail("你的华山剑法太弱，无法学习到「狂风剑法」的精髓。\n");
        if (!me->query("huashan_newskills/jianzong") ||
            me->query("family/family_name")!="华山派" ) 
                return notify_fail("你不是华山剑宗弟子，无法学习「狂风剑法」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level=me->query_skill("kuangfeng-kuaijian",1);

        for(i = sizeof(action); i > 0; i--) 
                if(level >= action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力不够练「狂风剑法」。\n");
        if ((int)me->query("neili") < 30)
                return notify_fail("你的内力不够练「狂风剑法」。\n");
        if ((int)me->query_skill("huashan-jianfa", 1) < me->query_skill("kuangfeng-kuaijian", 1) )
                return notify_fail("你的华山剑法太弱，无法练习「狂风剑法」。\n");
        if (!me->query("huashan_newskills/jianzong") ||
            me->query("family/family_name")!="华山派") 
                return notify_fail("你不是华山剑宗弟子，无法练习「狂风剑法」。\n");
        me->receive_damage("qi", 30);
        me->add("neili",-7);
        return 1;
}

string perform_action_file(string action)
{
               return __DIR__"kuangfeng-kuaijian/" + action;
}

//狂风快剑增加攻速
int skill_speed(object me)
{
  int level;
  
  level=me->query_skill("kuangfeng-kuaijian", 1);
  if ( level<500 )
    return 20;
  else if ( level<1000 )
    return 40;
  else
    return 60;
}