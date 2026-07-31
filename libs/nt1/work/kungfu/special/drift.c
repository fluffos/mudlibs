// drift.c 遁影擒踪
// Created by Lonely

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIY "遁影擒踪" NOR; }

int perform(object me, string skill)
{
        return notify_fail("这项技能可不再受到架力卸招之技的迷惑，不需要运用。\n");
}


