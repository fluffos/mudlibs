// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }



int practice_skill(object me)
{

   if( (int)me->query_skill("dragonforce",1) >= 200 )
     return notify_fail("你的龙神心法很难提高了，还是向你师父请教请教吧！\n");

   if( (int)me->query_temp("dragonforce_practice") < 1 )
     return notify_fail("你试着练功，可毫无进展，需要驯服更多的海兽以增进龙神心法。\n");

        if( (int)me->query("qi") < 30 )
                return notify_fail("你的气不够。\n");
   if( (int)me->query("qi") < 30 )
                return notify_fail("你的神不够。\n");
        if( (int)me->query("neili") < 10 )
                return notify_fail("你的内力不够");
        me->receive_damage("qi", 30);
   me->receive_damage("jing", 30);
        me->add("neili", -10);
  // me->add_temp("dragonforce_practice",-1);
        return 1;
}

