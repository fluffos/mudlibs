// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// 神照经神功 shenzhaojing.c

#include <ansi.h>
inherit FORCE;

int valid_force(string force) { return 1; }       

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("shenzhaojing", 1);
        return lvl /10 * lvl /10 * 15 * 24 / 10 / 20;
}

string *action_msg = ({
        "$N倏然跃近，击出一拳，这一拳无声无影，去势快极，向$n的胸口打去",
        "$N丝毫不动声色，右掌平伸，左掌运起神照经神功的劲力，呼的一声拍向$n",
        "$N身形微微一展，已然游走至$n跟前，陡然间双掌齐施，向$n猛拍而去",
        "$N退后一步，双掌回收，凌空划出一个圆圈，顿时一股澎湃的气劲直涌$n而出",
});

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 400 + random(120), 
                "attack": 80 + random(10), 
                "dodge" : 80 + random(10), 
                "parry" : 80 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int valid_enable(string usage)
{ 
        int lvl;
        lvl = (int)this_player()->query_skill("shenzhaojing", 1);

        if(lvl >= 180)    
                return usage == "force" || usage == "unarmed" || usage == "parry";
        else
                return usage == "force";
       
}

int valid_learn(object me)
{
        if (! me->query("family/family_name") || me->query("family/family_name") != "血刀门")
                return notify_fail("你无法从上面学到任何东西！\n");

        if ((int)me->query("str") < 32)
                return notify_fail("你先天膂力孱弱，无法修炼神照经神功。\n");

        if ((int)me->query("con") < 32)
                return notify_fail("你先天根骨孱弱，无法修炼神照经神功。\n");

        if ( me->query("gender") == "无性" && me->query("shenzhaojing", 1) > 29)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的神照经神功。\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("你的基本内功火候不足，不能学神照经神功。\n");

        if ((int)me->query_skill("unarmed", 1) < 200)
                return notify_fail("你的基本拳脚火候不足，不能学神照经神功。\n");

        if ((int)me->query("max_neili", 1) < 4000)
                return notify_fail("你的内力修为不足，不能学神照经神功。\n");

        if (me->query_skill("force", 1) < me->query_skill("shenzhaojing", 1))
                return notify_fail("你的基本内功水平不够，难以锻炼更深厚的神照经神功。\n");

        if (me->query_skill("unarmed", 1) < me->query_skill("shenzhaojing", 1))
                return notify_fail("你的基本拳脚水平不够，难以锻炼更深厚的神照经神功。\n");

        return ::valid_learn(me);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("shenzhaojing", 1);

        if (damage_bonus < 160
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "shenzhaojing"
           || me->query_skill_mapped("unarmed") != "shenzhaojing"
           || me->query_skill_prepared("unarmed") != "shenzhaojing")
                return 0;

        // 神照经神功所具有的既添设额外伤害又使对手中
        // 毒的max_hit 在所有武功中是绝无仅有的，但是
        // 它出现的几率以及伤害值又及毒性伤害相对于其
        // 他武功大大减弱。
        if (damage_bonus / 2 > victim->query_con())
        {
                victim->receive_wound("qi", (damage_bonus - 100) / 3, me);
                victim->affect_by("shenzhao",
                               ([ "level" : me->query("jiali") + random(me->query("jiali")),
                                  "id"    : me->query("id"),
                                  "duration" : lvl / 100 + random(lvl / 10) ]));
                return HIR "$n" HIR "一声惨嚎，全身骨骼格格格格爆声不"
                       "绝，肋骨、臂骨、腿骨同时断折。\n" NOR;
        }
}

int practice_skill(object me)
{
        return notify_fail("神照经神功只能用学(learn)的来增加熟练度。\n");
}

int difficult_level()
{
        return 400;
}

string perform_action_file(string action)
{
        return __DIR__"shenzhaojing/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"shenzhaojing/exert/" + action;
}

