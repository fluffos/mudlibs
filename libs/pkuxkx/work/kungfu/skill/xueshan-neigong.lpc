// File         : xueshan-neigong.c
// Created By   : iszt, 2006-08-17

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int skill = me->query_skill("xueshan-neigong", 1);
        if( (int)me->query_skill("force", 1) < 10 )
                return notify_fail("你的基本内功根基不足，无法学习雪山内功。\n");
        if( skill > 20 && skill * 6 > me->query("max_neili") )
                return notify_fail("你的内力修为尚不足以支持你进一步修习内功。\n");
        if( skill > 20 && skill * 4 > me->query("neili") )
                return notify_fail("你目前的真气不足，强行修习内功极易走火。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("雪山内功心法繁复无比，你只能向师父请教，无法练习。\n");
}

string exert_function_file(string func)
{
        return __DIR__"xueshan-neigong/" + func;
}
