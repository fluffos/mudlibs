// marry 99.8
inherit SKILL;
#include <ansi.h>
mapping *action = ({
    ([  "action":       "$N使一招「痴心一片」，双拳飘移不定击向$n$l",
        "dodge": 10,
        "parry": -10,
        "force": 50,
        "damage_type": "瘀伤"
        ]),
});

mapping *action2 = ({
    ([  "action":       "$N倏忽欺至$n身前，一招「"HIB"妄想成狂"NOR"」直拍$n的$l",
        "dodge": 20,
        "parry": -10,
        "force": 100,
        "damage_type": "瘀伤"
    ]),
});

mapping *action3 = ({
    ([  "action":       RED"$N身形绕$n一转，一招「"HIY"临渊羡鱼"RED"」向$n$l接连出拳"NOR,
     "force" : this_player()->query_skill("cxwx-quan",1),
     "dodge" : this_player()->query_skill("dodge",1)/2,
     "damage" : this_player()->query("zjb_dj/dj")*180,
     "parry" : this_player()->query_skill("parry",1),
        "damage_type": "瘀伤"
        ]),
    ([  "action":       HIB"$N身形拔起，在半空一招「"HIW"难言之隐"HIB"」右掌猛击$n的$l"NOR,
     "force" : this_player()->query_skill("cxwx-quan",1),
     "dodge" : this_player()->query_skill("dodge",1)/2,
     "damage" : this_player()->query("zjb_dj/dj")*180,
     "parry" : this_player()->query_skill("parry",1),
        "damage_type": "瘀伤"
        ]),
});


int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练痴心妄想拳必须空手。\n");
        if ((int)me->query("max_neili") < 1000)
        return notify_fail("你的内力太弱，无法练痴心妄想拳。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
          mapping a_action;
        level   = (int) me->query_skill("cxwx-quan",1);
          me = this_player();
        if (me->query_skill("cxwx-quan",1)<401)  
    return action[random(sizeof(action))];
   
        if (me->query_skill("cxwx-quan",1)>400
        && me->query_skill("cxwx-quan",1)<1001)
    return action2[random(sizeof(action2))];
 
        if (me->query_skill("cxwx-quan",1)>1000
        && me->query("zjb_dj/dj")>=5)
  return action3[random(sizeof(action3))];

    if (me->query_skill("cxwx-quan",1)>1000
        && me->query("zjb_dj/dj")<5)
 return action2[random(sizeof(action2))];
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;

        if ( me->query_skill("cxwx-quan",1)>400
         && me->query_skill("cxwx-quan",1)<1001
&& (me->query("neili")*3) > victim->query("max_neili") ) {
             victim->receive_wound("qi", (damage_bonus - 100) / 8 , me);
return HIW "$N将慢脑子痴心妄想化成一股力道运于拳上，顿时打的$n鲜血狂喷！！\n" NOR;
}

        if( me->query_skill("cxwx-quan",1)>1000
       && me->query("zjb_dj/dj")>=5
&& (me->query("neili")*3) > victim->query("max_neili") ) {
                victim->receive_wound("qi", (damage_bonus - 100) / 3 , me);
return HIR "$N将慢脑子"HIC"痴心妄想"HIR"化成一股力道运于拳上，顿时打的$n鲜血狂喷！！\n" NOR;
  }      
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 10)
        return notify_fail("你的内力不够了！休息一下再练吧。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"cxwx-quan/" + action;
}

