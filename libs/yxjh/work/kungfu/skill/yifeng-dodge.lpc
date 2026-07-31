//移风换影：  yifeng-dodge.c     2002.4.15
// written by yahoo
inherit SKILL;
string *dodge_msg = ({
        HIM"只见$n一式「"HIW"飘忽不相待"HIM"」，全身化做一缕清风，巧妙的躲过了$N这一招。\n"NOR,
        HIR"$n一式「"HIW"花自飘零水自流"HIR"」，向后飘出数丈之遥，优雅的避开了$N的凌厉攻势。\n"NOR,
      HIW"$n一式「"HIC"痴心白发换无情"HIW"」，瞬间已纵出数丈之远，避开了$N的凌厉杀招。\n"NOR,
       HIG"$n使出「"HIW"飞红万点愁如海"HIG"」，只见人影晃动,$N根本分不清楚哪个是真身。\n"NOR,
});
int valid_enable(string usage) { return (usage == "dodge"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("yifeng-dodge", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
         if (me) me->set_temp("fight/dodge",me->query_skill("yifeng-dodge",1)+random(me->query_skill("yifeng-dodge",1)));
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
              return notify_fail("你的体力太差了，不能练移风换影。\n");
        me->receive_damage("qi", 30);
        return 1;
}


