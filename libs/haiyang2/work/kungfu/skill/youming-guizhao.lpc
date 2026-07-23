// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// youming-guizhao.c 幽冥鬼爪

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N左爪前伸，带着丝丝蓝阴鬼气，一式「元神出窍」，猛得向$n的顶门插下",
        "$N双掌连拍，筑起一道气墙推向$n，忽然一爪「鬼魅穿心」冲破气墙直插$n的$l",
        "$N使出「血鬼锁」双爪游向$n扣住$l，气劲激发往左右两下一拉，便要将$n割成碎片",
        "$N双爪拢住$n，使一式「炼狱鬼嚎」，阴毒内功随爪尖透入$n体内，直袭各大关节",
        "$N力透指尖，向$n虚虚实实连抓十五爪，「妖风袭体」带动无数阴气缠住$n",
        "$N一式「索命妖手」，左爪上下翻动形成无数爪影，右臂一伸，鬼魅般抓向$n的$l",
        "$N探手上前，顺着$n的手臂攀缘直上，变手为爪，一招「孤魂驭魔」抓向$n的$l",
        "$N凌空飞落，一爪突前，「魔爪天下」积聚全身功力于指尖，快绝无比地插向$n",
});

int valid_enable(string usage) { return usage == "claw" || usage == "parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("练爪功必须空手。\n");
       if ((int)me->query_skill("claw", 1) < 50)
               return notify_fail("你的基本爪功火候不够，无法学习。\n");

       if ((int)me->query_skill("pidi-shenzhen", 1) < 50)
               return notify_fail("你的辟地神针火候不够，无法学习。\n");
       if ((int)me->query_skill("wudoumi-shengong", 1) < 50)
               return notify_fail("你的五斗米神功火候不够，无法学习。\n");
       if ((int)me->query_skill("zhougong-jian", 1) < 50)
               return notify_fail("你的周公剑火候不够，无法学习。\n");
       if ((int)me->query_skill("wuliang-jian", 1) < 50)
               return notify_fail("你的无量剑法火候不够，无法学习。\n");                                             

       if ((int)me->query("max_neili") < 1000)
               return notify_fail("你的内力太弱，无法练幽冥鬼爪。\n");
       return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(60),
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage" : 370 + random(10),	
                "damage_type" : "抓伤",
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query_skill("youming-guizhao", 1) < 199 )
                return notify_fail("你的幽冥鬼爪修为不够，只能用学(learn)的来增加熟练度。\n");
                
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练幽冥鬼爪必须空手。\n");
                
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
        
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练幽冥鬼爪。\n");
                
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"youming-guizhao/" + action;
}
int valid_combine(string combo) { return combo=="liuyang-zhang"; }

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
      int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("beiming-shengong",1);
        level2= (int) me->query_skill("beiming-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "beiming-shengong")
{

if (victim->query("neili") >= damage2)
{
victim->add("neili",-damage2);
me->add("neili",damage2);
}
	return HIW"$N突然使出北冥神功,$n全身内力如流水般源源不绝地流入$N的身体!\n"NOR;
}
        lvl  = me->query_skill("beiming-shengong", 1);
        if (lvl==0)
        lvl  = me->query_skill("bahuang-gong", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "bahuang-gong" &&
me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
        if (random(5)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
victim->apply_condition("ss_poison", 10 +
		victim->query_condition("ss_poison"));
}
                return HIW "$n" HIW "身上中了几道生死符!!\n" NOR;
        }
        else if (random(4)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-300);
if (me->query("neili") < me->query("max_neili"))
victim->add("neili",(random(lvl)+50));

return HIC "$n" HIC "全身功力如流水般源源不绝地流入$N的身体！\n" NOR;
        }

        if( damage_bonus < 30 ) return 0;

        if( random(3)==0 ) {
                victim->add("qi", -damage_bonus*2+30);
                victim->receive_wound("qi", (damage_bonus ) / 2+30 );
                return HIR "$n的伤口被$N力透指尖的一抓，阴毒内功随爪透入！\n";
        }
        if (me->query_temp("lingjiu/youming") 
        &&  ! me->query_temp("youming_hit")) 
        {
                me->set_temp("youming_hit", 1);
                me->set_temp("apply/name", ({ me->query("name") + "的鬼影" }));
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);       
                me->delete_temp("apply/name");
                me->delete_temp("youming_hit");
        }
}

