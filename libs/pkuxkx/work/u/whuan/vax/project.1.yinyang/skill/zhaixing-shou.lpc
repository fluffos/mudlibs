// zhaixing-shou.c -星宿摘星手
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([      "action" : HIM"$N怒极大吼一声，双手出招快如闪电，$n却见四面一片气劲织成的光网，连忙惊啸一声直往上跃。"NOR,
        "force" : 100,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 0,
        "skills_name" : "1",
        "damage_type" : "内伤"
]),
([      "action" : HIW"只见$N左手突发，一道光柱由掌心冲出，从$n胸前直穿而过."NOR,
        "force" : 120,
        "dodge" : 10,
        "parry" : 10,
        "damage": 5,
        "lvl" : 10,
        "skills_name" : "2",
        "damage_type" : "内伤"
]),
([      "action" : HIG"$N摘星手立即发出，一道柱状光华转眼飞射十公尺，直拍向$n的额头。"NOR,
        "force" : 150,
        "dodge" : 10,
        "parry" : 10,
        "damage": 10,
        "lvl" : 20,
        "skills_name" : "3",
        "damage_type" : "内伤"
]),
([      "action" : HIC"$N双手连环，万道光华分头而出，将$n的劲流震散。"NOR,
        "force" : 190,
        "dodge" : 15,
        "parry" : 15,
        "damage": 15,
        "lvl" : 30,
        "skills_name" : "4",

        "damage_type" : "内伤"
]),
([      "action" : HIY"$N摘星手一出，沉雷般的震响随之而起，一道游龙般的光柱径直往$n扑去。"NOR,
        "force" : 250,
        "dodge" : 20,
        "parry" : 20,
        "damage": 15,
        "lvl" : 40,
        "skills_name" : "5",
        "damage_type" : "内伤"
]),
([      "action" : HIB"$N双手往上一扬，一道光柱翻腾如游龙一般的往$n直迎过去，一神串的气爆声立即不断传出"NOR,
        "force" : 310,
        "dodge" : 25,
        "parry" : 25,
        "damage": 20,
        "lvl" : 50,
        "skills_name" : "6",
        "damage_type" : "内伤"
]),
([      "action" : HIR"$N两手忽然放大一倍，呈现铁青色，一上一下的挡在胸前，便顶一击，只听当的一声传出，那股手形内息四面溢散。"NOR,
        "force" : 380,
        "dodge" : 25,
        "parry" : 25,
        "damage": 25,
        "lvl" : 55,
        "skills_name" : "7",
        "damage_type" : "内伤"
])
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry" || usage=="throwing"; }
int valid_combine(string combo) { return combo=="xingxiu-duzhang"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练摘星手必须空手。\n");
        if ((int)me->query_skill("handu-xinfa", 1) < 30)
                return notify_fail("你的寒毒心法火候不够，无法学摘星手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练摘星手。\n");
        return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("zhaixing-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练摘星手。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}
string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});
string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
          return __DIR__"zhaixing-shou/" + action;
}

string query_yinyang()
{
	return "太阴";
}
