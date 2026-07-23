// pixie-sword.c
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
    ([  "name":    "群邪辟易",
        "action":  "$N使一招「群邪辟易」，手中$w圈起，倏地刺出，银星点点，剑尖直向$n的$l刺去",
        "dodge":   50,
        "damage":  100,
        "damage_type":  "刺伤"
    ]),
    ([  "name":    "钟馗抉目",
        "action":  "$N一招「钟馗抉目」，剑随身转，围着$n身围疾刺，剑光霍霍罩向$n的$l",
        "dodge":   70,
        "damage":  150,
        "damage_type":  "刺伤"
    ]),
    ([  "name":    "花开见佛",
        "action":  "$N舞动$w，一招「花开见佛」挟著无数剑光刺向$n的$l",
        "dodge":   40,
        "damage":  100,
        "damage_type":  "刺伤"
    ]),
    ([  "name":    "流星赶月",
        "action":  "$N手中$w一声清啸，祭出「流星赶月」剑锋闪烁不定，银光飞舞，猛地里一剑挺出，直刺$n$l",
        "dodge":   30,
        "damage":  100,
        "damage_type":  "刺伤"
    ]),
    ([  "name":    "飞燕穿柳",
        "action":  "$N手中$w剑光暴长，一招「飞燕穿柳」往$n$l刺去",
        "dodge":   60,
        "damage":  100,
        "damage_type":  "刺伤"
    ]),
    ([  "name":    "江上弄笛",
        "action":  "$N手中$w化成一道光弧，直指$n$l，一招「江上弄笛」发出虎哮龙吟刺去",
        "dodge":   10,
        "damage":  100,
        "damage_type":  "刺伤"
    ]),
});

int valid_learn(object me)
{
    object ob;

    if ( (string)me->query("gender")=="女性" )
        return notify_fail("女子不能学辟邪剑法.\n");

//   if ( (string)me->query("gender")=="男性" )
//        return notify_fail("你必须先自宫,才能练辟邪剑法.\n");

    if( (int)me->query("max_neili") < 50 )
        return notify_fail("你的内力不够，没有办法练辟邪剑法。\n");
    if( !(ob = me->query_temp("weapon"))
      || (string)ob->query("skill_type") != "sword" )
          return notify_fail("你必须先找一把剑才能练剑法。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 5 )
       return notify_fail("你的内力或气不够，没有办法练习辟邪剑法！\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    //write("你按著所学练了一遍辟邪剑法。\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
    if( (int)me->query_skill("pixie-sword", 1)  % 10 == 0 ) {
        tell_object(me,
           RED "\n你突然觉得一股阴气冲上心头，只觉得想杀人....\n\n"NOR);
        me->add("shen", -2000);
    } else
    me->add("shen", -200);
}

string perform_action_file(string action)
{
    return __DIR__"pixie-sword/" + action;
}

