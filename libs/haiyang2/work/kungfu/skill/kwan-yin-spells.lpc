// art.c 琴棋书画
// cck 3/7/97
//cool 10/10/98

inherit SKILL;

int valid_enable(string usage)
{
        return (usage == "magic");
}


int valid_learn(object me)
{
        if( (int)me->query_skill("lamaism",1) < (int)me->query_skill("kwan-yin-spells",1)) {
                return notify_fail("你的密宗佛法修为不够，无法领悟更高深的观音六字明咒。\n");
        }

        if (me->query_skill("yujiamu-quan",1) < 120)
                return notify_fail("你现在的金刚瑜迦母拳不足已学习吧。\n");
        if (me->query_skill("dashou-yin",1) < 120)
                return notify_fail("你现在密宗大手印不足已学习吧。\n");
        if (me->query_skill("xiangmo-chu",1) < 120)
                return notify_fail("你现在的金刚降魔杵不足已学习吧。\n");
        if (me->query_skill("mingwang-jian",1) < 120)
                return notify_fail("你现在的不动明王剑不足已学习吧。\n");
        if (me->query_skill("shenkong-xing",1) < 120)
                return notify_fail("你现在的身空行不足已练已学习吧。\n");





	return 1;
}



string perform_action_file(string action)
{
    return __DIR__"kwan-yin-spells/" + action;
}


int practice_skill(object me)
{       
        object bug; 
        if (me->query_skill("kwan-yin-spells",1) < 120)
                return notify_fail("你现在的能力不足已练习，还是学习吧。\n");

        if (me->query_skill("yujiamu-quan",1) < 120)
                return notify_fail("你现在的金刚瑜迦母拳不足已学习吧。\n");
        if (me->query_skill("dashou-yin",1) < 120)
                return notify_fail("你现在密宗大手印不足已学习吧。\n");
        if (me->query_skill("xiangmo-chu",1) < 120)
                return notify_fail("你现在的金刚降魔杵不足已学习吧。\n");
        if (me->query_skill("mingwang-jian",1) < 120)
                return notify_fail("你现在的不动明王剑不足已学习吧。\n");
        if (me->query_skill("shenkong-xing",1) < 120)
                return notify_fail("你现在的身空行不足已练已学习吧。\n");

          if( (int)me->query("neili") < 110 )
                return notify_fail("你的法力不够。\n"); 
        if( (int)me->query("jing") < 100 )
                return notify_fail("你的精神无法集中。\n"); 
        me->add("neili", -50);
        me->receive_damage("jing", 50); 
        write("你闭目凝神，神游物外，开始修习观音六字明咒....\n");
        return 1;
}       
