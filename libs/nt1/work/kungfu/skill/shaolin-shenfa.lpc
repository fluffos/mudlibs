// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shaolin-shenfa.c 少林身法

inherit SKILL;
#include <ansi.h>

string *dodge_msg = ({
        "$n一式「一苇渡江」，前后脚脚尖脚跟相靠，身体如行云流水般滑出丈余。\n",
        "$n一式「雨燕掠波」，双臂前伸，全身贴地平飞，顿时闪过了$N的凌厉攻势。\n",
        "$n一式「移步换形」，足不动，手不抬，一转眼间便绕到了$N的身后。\n",
        "$n一式「分身化影」，一转身间，四面八方飘动着无数个$n的身影，令$N手无足措。\n",
        "$n一式「孤骛落日」，全身笔直，拔地而起，在半空中一转，已落到几丈远的地方。\n",
        "$n一式「鸿雁双飞」，两臂鹏举如翼，在剌剌风声中，从$N头顶横跃而过。\n",
        "$n一式「苍龙出水」，双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
        "$n一式「稚凤归巢」，身体如陀螺般急转，气流形成一个个漩涡，令$N陷身其间，动弹不得。\n",
});


int valid_enable(string usage)
{
        return usage == "dodge";
}

int valid_learn(object me) { return 1; }

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 70 )
                return notify_fail("你的体力太差了，不能练少林身法。\n");
        
        if( (int)me->query("neili") < 70 )
                return notify_fail("你的内力不够。\n");
                
        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shaolin-shenfa/" + action;
        
}
/*
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("shaolin-shenfa", 1) < 100 ||
            ! living(me))
                return;

        mp = ob->query_skill("martial-cognize", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("dodge", 1) / 2 +
             me->query_skill("shailin-shengfa", 1);

        // 一个经典的算法
        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);
                // 去掉所有的伤害写法

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIC "$n" HIC "一式「稚凤归巢」，身体如陀螺般急转，气流形成一个个漩涡，令$N陷身其间，动弹不得。\n" NOR]);
                        if (! ob->is_busy())
                        ob->start_busy(random(3)); 
                        break;

                case 1:
                        result += (["msg" : HIC "$n" HIC "一式「一苇渡江」，前后脚脚尖脚跟相靠，身体如行云流水般滑出丈余。\n" NOR]);
                        if (! ob->is_busy())
                        ob->start_busy(random(1)); 
                        break;

                default:
                        result += (["msg" : HIC "$n" HIC "一式「分身化影」，一转身间，四面八方飘动着无数个$n的身影，令$N手无足措。\n" NOR]);
                        break;
                }
                return result;
        }
}
*/

int query_effect_dodge(object victim, object me)
{
        int lvl;

        lvl = me->query_skill("shaolin-shenfa", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 100;
        if (lvl < 280) return 150;
        if (lvl < 350) return 200;
        return 250;
}

