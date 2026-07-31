#include <ansi.h>

inherit SKILL;

int valid_learn(object me)
{
        object ob;
  
        if (me->query_skill("throwing", 1) < 40)
                return notify_fail("你的暗器技能不够娴熟。\n");

        if ((int)me->query_skill("throwing", 1) < (int)me->query_skill("pidi-shenzhen", 1))
                return notify_fail("你的基本暗器水平有限，难以领会更精妙的辟地神针。\n");

        return 1;
}

string	*msg = ({
"$N身子左侧，一式「月下踏径」，右手$w从身体下方突然甩出，直射向$n的$l",
"$w破空飞出，一式「长虹经天」，缓缓一个弧线，由左自右，绕向$n的$l，",
"$N双手连扬，一式「破云见日」，两把$w向$n撒出，笼罩$n的全身上下",
"$N向空中一撒，却是$n一招「秋日落叶」，十多枚$w由空中缓缓落下",
"$N身形急速向前滑动，一式「雪地追踪」，三枚$w向$n的胁下射去",
"$N一式「回首沧桑」，身体一转，反手掷出数枚$w，飞向$n的背部",
"$N凌空一纵，一招「雨打浮萍」，居高临下，手中$w疾射，直向$n的$l",
"$N一招「流星电闪」，手指弹出五枚$w，一点黑光射向$n的头部",
});

int valid_enable(string usage)
{
	return usage == "throwing" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))],
		"damage":(random(2)+2)*(me->query_skill("pidi-shenzhen",1)),
		"damage_type":"刺伤",
		"dodge":random(20)+20,
          "force":random(150)+me->query_skill("pidi-shenzhen",1),
                "post_action":
                  (: call_other, WEAPON_D, "throw_weapon" :)
	]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的气不够，没有办法练习辟地神针。\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够，没有办法练习辟地神针。\n");

        me->receive_damage("qi", 70);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pidi-shenzhen/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("pidi-shenzhen",1);
        level2= (int) me->query_skill("pidi-shenzhen",1);


if (random(6)==0 && level>=100 )
{
        victim->receive_damage("qi",level*2+100);
        victim->receive_wound("qi",level*3+100);
	return HIB"$N双手连扬,射出五枚暗器,$n双眼一黑，胸口正中一枚!\n"NOR;
}
}