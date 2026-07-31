// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tianshan-zhang.c

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N使出一招「冰河开冻」，手中$w大开大阖扫向$n的$l",
        "$N手中$w飞舞，一招「山洪涌洌」势不可挡地攻向$n的$l",
        "$N手中$w阵阵风响，一招「山风凛冽」向$n的$l攻去",
        "$N手中$w斜摆，划出一道道圆弧，一式「冰天雪地」把$n的身影团团罩住",
        "$N一招「峰回路转」，$w左右迂回向$n的$l点去",
        "$N手中$w向外一揽，一式「鹰拿群鹭」，$w首尾截住$n退路，一收$w，击往$n的破绽",
        "$N将身一纵，跃在半空，$w高举过顶，大喝一声，使一招「天山雪崩」，手中$w幻出数十条杖影，将$n上盘要害尽数罩住",
});


int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 80)
                return notify_fail("你的内力不够。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int lvl_temp;
        
        lvl_temp = random((int)me->query_skill("tianshan-zhang", 1) + 
                   (int)me->query_skill("staff"));
                   
        if (((int)me->query_skill("staff", 1) >= 100) 
        &&  ((int)me->query_skill("tianshan-zhang", 1) >= 100)
        &&  ((int)me->query_skill("huagong-dafa",1) >= 100)
        &&  ((int)me->query("neili") >= 800)
        &&  (int)me->query_skill("poison", 1) >= 100  
        &&  (lvl_temp >= 140)) 
        {
                return ([
                        "action": BLU "$N嘿嘿一阵阴笑,伸手向杖端一抹,$w"BLU"旋转挥动，声势更为凌厉!" NOR,
                        "damage": 180,
                        "parry" : 90,
                        "dodge" : 90,
                        "attack": 100,
                        "damage_type": "砸伤"]);
        }
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(30),
                "attack": 70 - random(10),
                "dodge" : 70 - random(10),
                "parry" : 70 - random(10),
                "damage_type" : random(2)?"刺伤":"砸伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if (me->query_str() < 20)
                return notify_fail("你的臂力不够练天山杖法。\n");
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力不够练天山杖法。\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够。\n");
        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianshan-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
        mixed result;
        object weapon;
        string msg;
        int ap, dp;
        
        if (! objectp(weapon = me->query_temp("weapon"))
        ||  damage < 50)
                return 0;
        
        ap = me->query("level");
        ap += me->query_skill("staff");
        dp = me->query("level");
        dp += victim->query_skill("parry");

        ap = (ap + random(ap * 2)) / 2;
        
        if (me->query_temp("pifeng")) 
        {
                if (random(ap + dp) > ap) 
                {
                        msg = HIW "\n$N一声怒喝，手中"+(string)weapon->query("name")+HIW"舞地风声大作，本以复杂的招数更是难辨。\n" NOR;
                        victim->start_busy(random(2));

                        result = ([ "msg" : msg, "damage" : damage / 2 ]);
                }
                else if (random(ap + 2 * dp) > ap) 
                {
                        msg = YEL "\n$N将手中"+(string)weapon->query("name")+YEL"向$n脚下扫去，趁$n躲闪之际，猛地发出一击！\n" NOR;
                        victim->start_busy(1+random(3));

                        result = ([ "msg" : msg, "damage" : damage ]);
                }
                else
                {
                        msg = HIR "\n$N陡然杖法一变，风声渐轻，而招数变得诡异莫测，吞吐不定。\n" NOR;
                        victim->start_busy(random(2));
        
                        result = ([ "msg" : msg, "damage" : damage / 3]);
                }
                
                return result;
        }
}
