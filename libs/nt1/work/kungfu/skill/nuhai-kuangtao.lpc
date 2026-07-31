// Created by Lonely
// nuhai-kuangtao.c 

#include <combat.h>
#include <ansi.h>

inherit FORCE;

int valid_force(string force) { return 1; }       

int query_neili_improve(object me)  
{
        int lvl; 
        lvl = (int)me->query_skill("nuhai-kuangtao", 1); 
        return lvl / 100 * lvl * 20 * 15 / 200; 
}

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("nuhai-kuangtao", 1);


        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的怒海狂涛。\n");

        if ((int)me->query_skill("force", 1) < 10 
        ||  (int)me->query_skill("force", 1) < lvl)
                return notify_fail("你的基本内功火候还不够。\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("怒海狂涛只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"nuhai-kuangtao/" + func;
}


		
