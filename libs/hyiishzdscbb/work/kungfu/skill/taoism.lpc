// taoism.c 道学心法
// modified by Venus Oct.1997

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
    int lvl;

    lvl = (int)me->query_skill("taoism", 1);

    if( (int)me->query("shen") < 0 )
   return notify_fail("你的邪气太重，无法修炼天师正道。\n");

    if(me->query("gender") == "无性" && lvl > 39)
   return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之
气，无法领会里面的阴阳变化之道。\n");

    if ((me->query_skill("buddhism",1) > 1) ||
        (me->query_skill("mahayana",1) > 1))
   return notify_fail("哈哈！"+RANK_D->query_respect(me)
      +"既入佛门，怎么却来学道家心法？\n");

    if ((me->query_skill("poison",1) > 1))
   return notify_fail("哈哈！"+RANK_D->query_respect(me)
      +"已经学了邪魔外道的毒技，怎么却来学道家心法？\n");

    return 1;
}

int practice_skill(object me)
{
    return notify_fail("天师正道只能靠学习来提高。\n");
}
