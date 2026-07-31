// huanxi-chan.c 欢喜禅

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
    if( me->query("class") != "huanxi")
        return notify_fail("你非大轮寺弟子，学习欢喜禅有何用？\n");
    if( (int)me->query_skill("huanxi-chan", 1) >= 200 )
        return notify_fail("你不能再学习欢喜禅了。\n");
    return 1;
}

int practice_skill(object me)
{       
        return notify_fail("欢喜禅只能靠学习来提高。\n");
}
