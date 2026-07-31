//xiaoyao /98/7/20

inherit SKILL;

int valid_learn(object me)
{
//        object ob;
// no this ob

        if( (int)me->query_skill("betting") >=  100)
                return notify_fail("赌之术到了这个程度只能从实赌中提高。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stealing" || usage=="perception";
}

int practice_skill(object me)
{
        if( (int)me->query_skill("betting") >=  100)
                return notify_fail("赌之术到了这个程度只能从实赌中提高。\n");
        return 1;
}

