// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// beiming-shengong.c 北冥神功

#include <ansi.h>;
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }
int valid_force(string force) { return 1; }

int query_neili_improve(object me)  
{
        int lvl; 
        
        lvl = (int)me->query_skill("beiming-shengong", 1); 
        return lvl /10 * lvl /10 * 28 * 15 / 10 / 20;  
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("beiming-shengong", 1);
        
        if (me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的北冥神功。\n");
                
        if ((int)me->query("con") < 24) 
                return notify_fail("算了吧，你先天根骨不好，别强学了。\n"); 
        
        if ((int)me->query("int") < 30) 
                return notify_fail("算了吧，你先天悟性不好，别强学了。\n"); 
                
        if (me->query_skill("force", 1) <= lvl)
                return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
                
        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("北冥神功无法简单的通过练习进步。\n");
}

string exert_function_file(string func)
{
        return __DIR__"beiming-shengong/" + func;
}

int difficult_level()
{
        return 400;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int jiali;

        if ((int) me->query_skill("beiming-shengong", 1) < 80 ||
            ! living(me))
                return;

        if ((jiali = ob->query("jiali")) < 1)
                return;

        ap = ob->query_skill("force") + ob->query_skill("dodge");
        dp = me->query_skill("force") + me->query_skill("dodge");
        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage" : -damage ]);

                switch (random(3))
                {
                case 0:
                        result += ([ "msg" : HIM "$N" HIM "只觉得内力源源而泻"
                                             "，不由得大吃一惊。\n" NOR ]);
                        break;
                case 1:
                        result += ([ "msg" : HIM "$N" HIM "只觉得发出的内力犹"
                                             "如石沉大海，不知所踪。\n" NOR ]);
                        break;

                default:
                        result += ([ "msg" : HIM "$N" HIM "不住催动内力，但是"
                                             "只觉得$n竟似毫不费力。\n" NOR ]);
                        break;
                }
                return result;
        }
}
