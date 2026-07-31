// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// huashan-shenfa.c 华山身法

#include <ansi.h>
#include <combat.h>

inherit SKILL;

string *dodge_msg = ({ 
        "$n两臂鹏举，纵上丈余，一式" HIR "「巨鹏亮翅」" NOR "顿时避开了$N的凌厉攻势。\n",
        "$n身随风飘，侧身向后倒纵，轻巧地一式" HIM "「风送紫霞」" NOR "，化解了$N的攻势。\n",
        "$n一式" MAG "「燕徊朝阳」" NOR "，长袖飘飘身形晃动，一转眼间便绕到了$N的身后。\n",
        "$n低头恭身，抱拳一式" HIC "「却别苍松」" NOR "，身子向后滑出，将$N的攻势化于无形。\n",
        "$n使出" HIY "「旭日初升」" NOR "，笔直跃起，在半空中化为「金雁横空」，飘落到一旁。\n",
        "$n一招" BLU "「晚月朗星」" NOR "，身形左右急速晃动，幻出数个身影，从容地破解$N的攻势。\n",
        "$n含笑飘身使出" YEL "「幻眼云湮」" NOR "，身形幻成一道白影，轻飘飘地闪到$N的左侧。\n",
        "$n凝气守中一招" CYN "「苍龙盘岭」" NOR "，身化长龙绕着$N急转，使其无从下手，攻势不攻自破。\n",
});

int valid_enable(string usage)
{
        return usage == "dodge";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb) 
{
        return dodge_msg[random(sizeof(dodge_msg))]; 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太差了，不能练华山身法。\n");
        
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够。\n");
                
        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

int query_effect_dodge(object attacker, object me) 
{
        int lvl;

        lvl = me->query_skill("huashan-shenfa", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

