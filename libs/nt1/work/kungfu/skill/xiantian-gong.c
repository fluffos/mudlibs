// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// xiantian-gong.c

#include <ansi.h>
inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("xiantian-gong", 1);
        return lvl / 10 * lvl / 10 * 15 * 25 / 10 / 20;
}

/*
int valid_force(string force)
{
        return force == "quanzhen-xinfa" ||
               force == "xuanmen-neigong";
}
*/

int valid_force(string force) { return 1; }

string *action_msg = ({
        "$N单掌一抖，运聚先天功功力，呼啸着向$n的$l处拍去",
        "$N右掌平伸，左掌运起先天功的劲力，猛地拍向$n的$l",
        "$N身形一展，右掌护住心脉，左掌中攻直进，贯向$n$l",
        "$N运转先天真气，双掌回圈，顿时一波澎湃的气劲直袭$n",
});

int valid_enable(string usage)
{ 
        int lvl;
        lvl = (int)this_player()->query_skill("xiantian-gong", 1);

        if (lvl >= 180)    
                return usage == "force" || usage == "unarmed" || usage == "parry";
        else
                return usage == "force";
       
}

int valid_learn(object me)
{
        if (me->query("character") != "光明磊落"
           && me->query("character") != "国士无双")
                return notify_fail("你只觉先天功正大恢弘，依自己的天性似乎难以领悟。\n");

        if ((int)me->query("int") < 28)
                return notify_fail("你的先天悟性不足，难以领会高深的先天功。\n");

        if ((int)me->query("con") < 32)
                return notify_fail("你的先天根骨孱弱，无法修炼高深的先天功。\n");

        if ( me->query("gender") == "无性" && me->query("xiantian-gong", 1) > 29)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的先天功。\n");

        if ((int)me->query_skill("taoism", 1) < 200)
                return notify_fail("你对道学心法的理解不够，难以领会先天功。\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("你的基本内功火候不足，难以领会先天功。\n");

        if ((int)me->query_skill("unarmed", 1) < 200)
                return notify_fail("你的基本拳脚火候不足，难以领会先天功。\n");

        /*
        if ((int)me->query("max_neili", 1) < 4000)
                return notify_fail("你的内力修为不足，难以领会先天功。\n");
        */

        if (me->query_skill("taoism", 1) < 320
           && me->query_skill("taoism", 1) < me->query_skill("xiantian-gong", 1))
                return notify_fail("你对道学心法的理解不够，难以锻炼更深厚的先天功。\n");

        if (me->query_skill("force", 1) < me->query_skill("xiantian-gong", 1))
                return notify_fail("你的基本内功水平不够，难以锻炼更深厚的先天功。\n");

        if (me->query_skill("unarmed", 1) < me->query_skill("xiantian-gong", 1))
                return notify_fail("你的基本拳脚水平不够，难以锻炼更深厚的先天功。\n");

        return ::valid_learn(me);
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(30),
                "attack": 70 + random(20),
                "dodge" : 70 + random(20),
                "parry" : 70 + random(20),
                "damage_type" : random(2)?"瘀伤":"内伤",
        ]);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("xiantian-gong", 1);

        if (damage_bonus < 150
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "xiantian-gong"
           || me->query_skill_mapped("unarmed") != "xiantian-gong"
           || me->query_skill_prepared("unarmed") != "xiantian-gong")
                return 0;

        if (damage_bonus / 6 > victim->query_con())
        {
                me->add("neili", -30);
                victim->receive_wound("qi", (damage_bonus - 100) / 3, me);
                return HIW "$N" HIW "先天功的潜力发挥了出来，突然间$n"
                       HIW "只感喉咙一甜，喷出一口鲜血！\n" NOR;
        }
}

int practice_skill(object me)
{
        return notify_fail("先天功只能用学(learn)来增加熟练度。\n");
}

int difficult_level()
{
        return 500;
}

string perform_action_file(string action)
{
        return __DIR__"xiantian-gong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"xiantian-gong/exert/" + action;
}

void skill_improved(object me) 
{ 
        int lvl, i; 
        
        i = me->query("int") / 3; 
        lvl = me->query_skill("xiantian-gong", 1); 
        
        if (lvl > 220 
        &&  me->query("can_exert/xiantian-gong/shentong") <= 60) 
        { 
                if (me->add("can_exert/xiantian-gong/shentong", random(i)) < 60) 
                { 
                        tell_object(me, HIC "你对先天功「" HIW "纯阳神通功" 
                                        HIC "」有了新的领悟。\n" NOR); 
                } else 
                { 
                        tell_object(me, HIC "你通晓了先天功「" HIW "纯阳神通功" 
                                        HIC "」的奥秘。\n" NOR); 
                        me->improve_skill("martial-cognize", 1500000); 
                        me->improve_skill("martial-cognize", 1500000); 
                        me->improve_skill("martial-cognize", 1500000); 
                } 
        }       
} 
