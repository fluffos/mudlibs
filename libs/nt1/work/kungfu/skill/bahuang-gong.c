// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit FORCE;
int valid_force(string force) { return 1; } 

// 内力应该比太极神功强些
int query_neili_improve(object me)  
{
        int lvl; 
        lvl = (int)me->query_skill("bahuang-gong", 1); 
        return lvl * lvl * 24 * 15 / 100 / 200; 
}

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("bahuang-gong", 1);

        if (me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的八荒六合唯我独尊功。\n");

        if (me->query("class") == "bonze")
                return notify_fail("八荒六合唯我独尊功讲究阴阳调合，有违佛家六根清净之意，" +
                                   RANK_D->query_respect(me) + "欲修此功，已是罪过。\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{

        return notify_fail("八荒六合唯我独尊功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"bahuang-gong/" + func;
}

int help(object me)
{
        write(WHT"\n『八荒六合唯我独尊功』\n\n"CYN+
                 " 　　八荒六合唯我独尊功，其功法怪异，内力走向与所谓正统武学大相径\n"+
                 " 邻，与北冥神功及小无相功并列逍遥派三大内功绝技。然此功每格若干年\n"+
                 " 便需散功一次，并饮活物之血炼化内力方可恢复，否则凶险异常。\n"+
                 " 　　八荒六合唯我独尊功为中性内功，正运呈阳，逆运呈阴，相辅相呈却\n"+
                 " 又互相抵制，而灵鹫功武学的天山六阳掌则更可将此阴阳互助，刚柔并济\n"+
                 " 的玄妙之处发挥得淋漓尽致。\n\n"+

              WHT" 要求：基本内功　           "HIR"10"WHT" 级\n"NOR);

        return 1;
}
