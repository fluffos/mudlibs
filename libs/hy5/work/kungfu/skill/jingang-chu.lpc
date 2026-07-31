// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jingang-chu.c, 金刚降魔杵

#include <ansi.h>;
inherit SKILL;


string *action_msg = ({
        "$N神色庄严，口宣佛号，使出一招「金刚再世」，手中$w扫向$n的$l",
        "$N满面怒容，口中大喝，大步踏上一式「金刚伏魔」，$w朝着$n当头砸下",
        "$N一招「金刚宣法」，口中念念有词，骤然眼放异光，抡起手中$w横扫$n的$l",
        "$N一招「引趣众生」，左臂弯夹$w，右展立，呼心金咒，单臂挥$w击向$n的$l",
        "$N一式「歌舞阎罗」，口唱轮回经，跨腿飞跳，$w首尾来回击向$n",
        "忽然间$N一脸悲珉之色，手中$w画个半弧使出「浮游血海」，勾向$n的$l",
        "$N一式「驱鬼御魔」，口中念着六字真言，把$w舞成一片黄雾，将$n罩在中央",
        "$N闭目运气鼓足内力，暴喝一声佛号施展「荡魔除妖」，手中$w飞云掣电般直射向$n的$l",
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 80)
                return notify_fail("你的内力不够。\n");
                
        if ((int)me->query_skill("staff", 1) < 
            (int)me->query_skill("jingang-chu", 1))
                return notify_fail("你的基本杖法火候太浅。\n");
        
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 320 + random(30), 
                "attack": 40 + random(10), 
                "dodge" : 40 + random(10), 
                "parry" : 40 + random(10), 
                "force" : 140 + random(10), 
                "damage_type" : random(2)?"挫伤":"瘀伤", 
        ]); 
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if (me->query_str() < 20)
                return notify_fail("你的臂力不够练金刚降魔杵。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练金刚降魔杵。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练金刚降魔杵。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -40);
}

string perform_action_file(string action)
{
        return __DIR__"jingang-chu/" + action;
}



int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("longxiang",1);
        skill = me->query_skill("longxiang", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIM"$N 口中喃喃念起「降妖伏魔咒」，内力汹涌而至，一层一层的加强。$n心神一乱，内力尽然提不起来！\n"NOR;
ob->set_temp("apply/attack", 0);
ob->set_temp("apply/defense", 0);
if (random(2)==0)
{
msg += HIM"$N"+HIM+"默念大明六字真言，手结摩利支天愤怒印! $n心神一荡，吐出一口鲜血!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           message_vision(msg, me, ob);
           return j;
}      
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "longxiang") 
             me->set_temp("xiuluo", 1);
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("jingang-chu",1)) > 100 ) 
{
	  victim->receive_wound("qi", damage_bonus/2);
        return HIR "$n被杖风扫中，顿时血流如注！\n" NOR;
}
        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "longxiang") 

if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("jingang-chu",1)) > 150  || random(8)==0) 
{
	  victim->receive_wound("qi", damage_bonus/2+30);
        return HIB "$N轻闭双眼，双手合一，口呼佛号：“遁！”，一道佛光从$N掌间飞出， 
只见淡淡的蓝光包围$n。！\n" NOR;
}
}