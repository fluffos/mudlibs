// 舞蝶步
// wudie-bu

inherit SKILL;
#include <ansi.h>

string *dodge_msg = ({
"但是$n一招·"HIR"近寒"HIW"食雨"HIB"草萋萋"NOR"·轻松躲过。\n",
"突然$n如"WHT""BLINK"蝴蝶"NOR"飞舞，一招·"HIY"著麦"HIG"苗风"HIM"柳映堤"NOR"·闪开了$N的攻击。\n",
"只见到$n身形一变，使出·"HIY"等是"CYN"有家"HIR"归未得"NOR"·向后轻飘飘的跳开。\n",
"却见$n毫不慌张的使出·"HIM"杜鹃"YEL"休向"HIW"耳边啼"NOR"·左右闪躲，避开了攻击！\n"});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 45 )
                return notify_fail("你的体力太差了，不能练舞蝶步。\n");
if ( (int)me->query("t") > 1 || (int)me->query("r") > 1  )
          return notify_fail("由于你的天性不够，你永远无法学到舞蝶步。\n");

        me->receive_damage("qi", 35);
        return 1;
}

