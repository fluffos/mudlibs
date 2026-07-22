// pili-dan.c 霹雳弹
inherit SKILL;

int valid_enable(string usage) { return usage=="throwing" ; }
int valid_learn(object me)
{
        if (me->query("class")!="bonze" && (int)me->query_skill("pili-dan",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("你的临济十二庄火候不够，无法学霹雳弹。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练霹雳弹。\n");
        return 1;
}


int practice_skill(object me)
{       
        if (me->query("class")!="bonze" && (int)me->query_skill("pili-dan",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练霹雳弹。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"pili-dan/" + action;
}
