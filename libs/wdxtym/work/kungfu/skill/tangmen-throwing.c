// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tangmen-throwing.c

#include <ansi.h>

inherit SKILL;

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action":		"$N双手连环挥舞，一招"+(order[random(13)])+"「穿心针」"NOR"，$w直奔$n的胸腹要害",
	"dodge":		200,
        "force":		200,
	"damage":		60,
	"poison": 30,
	"lvl" : 0,
	"skill_name" : "穿心针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N身形晃动，一招"+(order[random(13)])+"「破气针」"NOR"，手中$w如一串银线，往$n咽喉打去",
	"dodge":		200,
	"force":		200,
	"damage":		80,
	"poison": 40,
	"lvl" : 60,
	"skill_name" : "破气针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N五指微张，一招"+(order[random(13)])+"「吸血针」"NOR"，手中$w飞蚊般往$n全身叮去",
	"dodge":		200,
	"force":		200,
	"damage":		180,
	"poison": 50,
 	"lvl" : 90,
	"skill_name" : "吸血针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N大喝一声，一招"+(order[random(13)])+"「摄魂针」"NOR"，$w幻化出夺目光亮，打向$n",
	"dodge":		290,
	"force":		200,
	"damage":		140,
	"poison": 60,
	"lvl" : 100,
	"skill_name" : "摄魂针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N错步一跃，一招"+(order[random(13)])+"「夺魄针」"NOR"，$w带着阵阵阴风，打向$n全身",
	"dodge":		270,
	"force":		200,
	"damage":		160,
	"poison": 70,
 	"lvl" : 110,
	"skill_name" : "夺魄针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N双目精芒闪动，一招"+(order[random(13)])+"「离别针」"NOR"，手中$w全数脱手飞出，排山倒海般打向$n全身",
	"dodge":		290,
	"force":		200,
	"damage":		180,
	"poison": 80,
	"lvl" : 120,
	"skill_name":  "离别针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N纵声长啸，一招"+(order[random(13)])+"「天魔针」"NOR"，$w竟然带着一股强烈劲风，扫向$n",
	"dodge":		207,
	"force":		200,
	"damage":		180,
	"poison": 90,
	"lvl" : 130,
	"skill_name" : "天魔针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N眼中杀气突然大盛，一招"+(order[random(13)])+"「地煞针」"NOR"，$w飞蝗般打向$n全身",
	"dodge":		290,
        "force":		200,
	"damage":		180,
	"poison": 100,
	"lvl" : 200,
	"skill_name" : "地煞针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 60)
                return notify_fail("你的内功心法火候不够，无法学唐门暗器。\n");

        if ((int)me->query_skill("dodge") < 60)
                return notify_fail("你的轻功火候不够，无法领悟唐门暗器。\n");

        if ((int)me->query("dex") < 30)
                return notify_fail("你的身法不够灵巧，无法学习唐门暗器。\n");

        if ((int)me->query("int") < 25)
                return notify_fail("你的悟性不够，无法学习唐门暗器。\n");

        if ((int)me->query_skill("throwing", 1) < (int)me->query_skill("tangmen-throwing", 1))
                return notify_fail("你的基本暗器水平有限，难以领会更高深的唐门暗器。\n");

        return 1;
}

int practice_skill(object me)
{
        //object weapon;

        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练唐门暗器。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tangmen-throwing/" + action;
}

