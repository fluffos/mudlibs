#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": YEL"$N使出一招「天地如一」，$w大开大阖扫向$n的$l",
        "dodge": 100,
        "force": 25000,
        "damage": 290000,
        "damage_type": "劈伤"
]),
([      "action": MAG"$N手中$w阵阵风响，一招「尽入地狱」向$n的$l攻去",
        "dodge": 100,
        "force":25000,
        "damage": 290000,
        "damage_type": "挫伤"
]),
([      "action": CYN"$N举起$w，居高临下使一招「逍遥鬼哭」击向$n的$l",
        "dodge": 100,
        "force" :25000,
        "damage": 290000,
        "damage_type": "刺伤"
]),
([      "action": GRN"$N举起右手，口中念念有词，引下一道闪电，击向$n的$l",
        "dodge": 100,
        
        "force" :25000,
        "damage": 290000,
 
        "damage_type": "刺伤"
]),
([      "action": RED"$N一招「佛面无常」，$w左右迂回向$n的$l攻去",
        "dodge": 100,
        "force" :25000,
        "damage": 290000,
        "damage_type": "淤伤"
]),
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") ||(usage =="hammer")|| (usage=="whip")||(usage=="club") ||(usage =="literate") ||(usage =="halberd")||(usage =="force") ||(usage =="throwing") || (usage == "dodge") ||(usage =="strike")|| (usage == "sword") ||(usage == "blade")||(usage == "parry"); }

string *dodge_msg = ({
        MAG"只见人影一闪，$n已经躲过这一击。\n",
        YEL"天地之间扬起一阵风沙，$n的人影已经不知何处去了。\n",
        BLU"突然雷声阵阵，一片紫光保护住了$n。\n",
        GRN"狂风大作，将$N的攻势化为了云烟。\n",
});
string exert_function_file(string func)
{
        return __DIR__"wuchang/" + func;
}

string *parry_msg = ({
        GRN"只见天空一道闪电格开了$N的进攻。\n",
        YEL"突然远方传来悠扬的琵琶声，$N的攻势停在了半路。\n",
        RED"$n一闪，顿时电闪雷鸣，格开了$N。\n",
        CYN"但是$n身子一侧，风声大作，$N急忙收招。\n",
});


string query_dodge_msg(object weapon)
{
        
                return dodge_msg[random(sizeof(parry_msg))];
        
}

string query_parry_msg(object weapon)
{
        
                return parry_msg[random(sizeof(parry_msg))];
}
int practice_skill(object me)
{
 
        if( (int)me->query("qi") < 5 )
                return notify_fail("你的体力太差了，不能练万里独行。\n");
        me->receive_damage("qi", 1);
        return 1;
        }
