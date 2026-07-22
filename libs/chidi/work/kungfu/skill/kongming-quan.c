// kongming-quan.c
// By Dream
#include <ansi.h>
inherit SKILL;

mapping *action = ({
    ([  "action":       "$N使一招「"+HIB+"空屋住人"+NOR+"」，双手轻飘飘地箍向$n$l",
        "force": 80,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N左掌一平,右掌一伸,一招「"+HIB+"空碗盛饭"+NOR+"」直拍$n的$l",
        "force": 120,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N身形绕$n一转，双手上撩,一招「"+HIB+"空钵装水"+NOR+"」击向$n$l",
        "force": 160,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N左掌一按,右掌一挥,一招「"+HIB+"虚怀若谷"+NOR+"」拍向$n的$l",
        "force": 200,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N使一招「"+HIB+"空山鸟语"+NOR+"」，$n的$l已围在$N的重重掌影之下",
        "force": 240,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N神色一敛，使出「"+HIB+"我心空明"+NOR+"」，围绕$n的$l接连出掌",
        "force": 300,
        "damage_type": "瘀伤"
    ]),
});
int valid_enable(string usage)
{
    return usage == "unarmed" || usage == "parry";
}

int effective_level() { return 21; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("kongming-quan", 1);
    if ( me->query("gender") == "无性" && lvl > 10)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的空明拳。\n");
    if ((int)me->query_skill("unarmed", 1) < 200)
        return notify_fail("你的基本内功火候还不够，无法领会空明拳。\n");
    if (me->query_skill("unarmed",1)<=lvl)
        return notify_fail("你的基本内功拳脚不够，再学下去会走火入魔的。\n");

  return 1;
}

int practice_skill(object me)
{
/*
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练空明拳必须空手。\n");
    if ((int)me->query("qi") < 300)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 200)
        return notify_fail("你的内力不够练空明拳。\n");
    me->receive_damage("qi", 50);
    me->add("neili", -100);
    return 1;
*/
 return notify_fail("空明拳只能通过「"+RED+"冥思"+NOR+"」来演练。\n");
}


mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *parry_msg = ({

       HIB "$n运起空明拳的“空”字决，$N的攻击忽然落空。\n"NOR,
       HIC "$n运起空明拳的“柔”字决，身形如蛇般缠着$N，$N的根本无计可施。。\n"NOR,
});

string query_parry_msg(object me,object weapon)
{
       if (me) me->set_temp("fight/parry",3*me->query_skill("kongming-quan",1)/10);
        return parry_msg[random(sizeof(parry_msg))];

}

string perform_action_file(string action)
{
      return __DIR__"kongming-quan/" + action;
}


