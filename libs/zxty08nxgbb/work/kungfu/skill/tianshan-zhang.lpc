inherit SKILL;
mapping *action = ({
([  "action": "$N使出一招「冰河开冻」，手中$w大开大阖扫向$n的$l",
    "force" : 80,
    "lvl" : 0,
    "damage_type": "挫伤"
]),
([  "action": "$N手中$w阵阵风响，一招「山风凛冽」向$n的$l攻去",
    "force" : 140,
    "lvl" : 13,
    "damage_type": "挫伤"
]),
([  "action": "$N举起$w，居高临下使一招「天山雪崩」砸向$n的$l",
    "force" : 200,
    "lvl" : 30,
    "damage_type": "挫伤"
]),
});

mapping *action2 = ({

([  "action": "$N一招「"+RED+"残阳照"+WHT+"雪"+NOR+"」，纵身飘开数尺，手中$w砸向$n的$l",
    "force" : 240,
    "lvl" : 45,
    "damage_type": "挫伤"
]),
([  "action": "$N使一招「"+BOLD+"回光幻电"+NOR+"」，手中$w幻一条疾光点向$n的$l",
    "force" : 270,
    "lvl" : 60,
    "damage_type": "挫伤"
]),
([  "action": "$N使出的「"+HIR+"风霜碎影"+NOR+"」，$w连挥杖影霍霍劈向$n的$l",
    "force" : 300,
    "lvl" : 75,
    "damage_type": "挫伤"
]),
});

mapping *action3 = ({

([  "action": RED"$N的$w"NOR RED"凭空一指，一招「"+HIB+"断石狼烟"+NOR+RED+"」点向$n的$l",
    "force" : 320,
    "lvl" : 90,
    "damage_type": "挫伤"
]),
([  "action": WHT"$N纵身一跃，手中$w"WHT"一招「"+HIY+"长空雷隐"+NOR+WHT+"」对准$n的$l扫去",
    "force" : 340,
    "lvl" : 105,
    "damage_type": "挫伤"
]),
([  "action": HIB"$N手中$w"HIB"中宫直进，一式「"+RED+"冰谷初虹"+HIB+"」对准$n的$l点去",
    "force" : 350,
    "lvl" : 120,
    "damage_type": "挫伤"
]),
([  "action": YEL"$N一招「"+MAG+"峰回路转"+YEL+"」，$w"NOR YEL"左右迂回向$n的$l点去",
    "force" : 380,
    "lvl" :  145,
    "damage_type": "挫伤"
]),
});
int practice_level(){   return 145;  }
mapping query_action(object me, object weapon)
{
        int i, level;
          mapping a_action;
        level   = (int) me->query_skill("tianshan-zhanfa",1);
          me = this_player();
        if (me->query_skill("tianshan-zhang",1)<401)  
    return action[random(sizeof(action))];
   
        if (me->query_skill("tianshan-zhang",1)>400
        && me->query_skill("tianshan-zhang",1)<1001)
    return action2[random(sizeof(action2))];
 
        if (me->query_skill("tianshan-zhang",1)>1000
        && me->query("zjb_dj/dj")>=5)
  return action3[random(sizeof(action3))];

    if (me->query_skill("tianshan-zhang",1)>1000
        && me->query("zjb_dj/dj")<5)
 return action2[random(sizeof(action2))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;

 // 第二等级的伤气
        if ( me->query_skill("tianshan-zhang",1)>400
         && me->query_skill("huagong-dafa",1)>300
         && me->query_skill("tianshan-zhang",1)<1001
&& (me->query("neili")*3) > victim->query("max_neili") ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
return HIB "$N你只听见「碰」的一声巨响，原来是$N通过手中兵器以化功大法的内劲重伤了$n！\n" NOR;
}

 //  第三等级的伤气
        if( me->query_skill("tianshan-zhang",1)>1000
       && me->query("zjb_dj/dj")>=5
    && me->query_skill("huagong-dafa",1)>500
&& (me->query("neili")*3) > victim->query("max_neili") ) {
                victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return HIR "$N趁手中重拐与$n身体接触的一刹那间释放出一股"HIW"化功大法"HIR"的真力侵入了$n的穴脉！！！\n" NOR;
  }      
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");

    if ((int)me->query("max_neili") < 80)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("staff", 1) <=me->query_skill("tianshan-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练天山杖法。\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"tianshan-zhang/" + action;
}

